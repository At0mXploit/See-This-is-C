/*
 * list.c — Unified implementation of ls, ls -l, ls -la, ls -R
 *
 *
 * Usage:
 *   ./list              → basic ls   (current directory)
 *   ./list -l           → ls -l      (long format)
 *   ./list -la          → ls -la     (long format + hidden files)
 *   ./list -R           → ls -R      (recursive)
 *   ./list -la /tmp     → combine flags + custom path
 *   ./list -Rla /etc    → all flags at once
 *
 * Flags supported:  -l  -a  -R  (and any combination)
 * Flags can be combined: -la -lR -laR -Rla etc.
 *
 */

// 1. Parse command-line arguments (flags and paths)
// 2. Open the target directory using opendir()
// 3. Read directory entries using readdir()
// 4. Optionally call stat() / lstat() on each entry for metadata
// 5. Sort the entries (alphabetically by default)
// 6. Format and print results to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h> // For opendir, readdir, closedir, struct dirent
#include <sys/stat.h> // For lstat, struct stat, S_IS* macros
#include <sys/types.h> // For mode_t, uid_t, gid_t
#include <pwd.h> // getpwuid = usernaame from UID 
#include <grp.h> // getgrgid = group name for GID 
#include <time.h> // localtime, strftime 
#include <unistd.h> // readlink 
 
static int flag_l = 0; // -l 
static int flag_a = 0; // -a for hiddne files 
static int flag_R = 0; // -R for recurse into subdirectories 
                    
void parse_args(int argc, char *argv[], const char **out_path) {
  *out_path = "."; // default is current directory 
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      // Argument starts with '-' so it contains flags 
      // walk every chars after the dash 
      for (int j = 1; argv[i][j] != 0; j++) {
        switch (argv[i][j]) {
          case 'l': flag_l = 1; break;
          case 'a': flag_a = 1; break;
          case 'R': flag_R = 1; break;
          default:
              fprintf(stderr, "list: wrong option bruv '-%c'\n", argv[i][j]);    
              exit(1);
        }
      }
    } else {
      *out_path = argv[i]; // If not flag treat it as directory path 
    }
  } 
}
 
// Convert st_mode filed (bitmask) from struct stat into 
// familiar string like "-rwxr-xr-x"
/*
 * mode_to_str()
 *   mode    — st_mode value from lstat()
 *   buf     — output buffer (must be at least 11 bytes)
 *
 * Layout of the 10 characters:
 *   [0]      file type  (- d l c b p s)
 *   [1][2][3] owner     rwx  (with setuid → s/S in [3])
 *   [4][5][6] group     rwx  (with setgid → s/S in [6])
 *   [7][8][9] other     rwx  (with sticky → t/T in [9])
 *   [10]     null terminator
 */

void mode_to_str(mode_t mode, char *buf) {
  // Character 0 = File Type 
    if      (S_ISREG(mode))  buf[0] = '-';   // regular file      
    else if (S_ISDIR(mode))  buf[0] = 'd';   // directory         
    else if (S_ISLNK(mode))  buf[0] = 'l';   // symbolic link     
    else if (S_ISCHR(mode))  buf[0] = 'c';   // character device  
    else if (S_ISBLK(mode))  buf[0] = 'b';   // block device      
    else if (S_ISFIFO(mode)) buf[0] = 'p';   // named pipe / FIFO 
else if (S_ISSOCK(mode)) buf[0] = 's';   // socket            
    else                     buf[0] = '?';  // unknown           

  // Character 1-3 = owner (user) perms
  buf[1] = (mode & S_IRUSR) ? 'r' : '-';
  buf[2] = (mode & S_IWUSR) ? 'w' : '-';
  // Exectute bit for owner: 
  // setuid + execture = s 
  // setuid, no execture = S 
  // exectue, no setuid = x 
  // neither of them = -

  if (mode & S_ISUID)
      buf[3] = (mode & S_IXUSR) ? 's' : 'S';
  else
      buf[3] = (mode & S_IXUSR) ? 'x' : '-';
 
  // Characters 4-6: group permissions 
  buf[4] = (mode & S_IRGRP) ? 'r' : '-';
  buf[5] = (mode & S_IWGRP) ? 'w' : '-';
  // setgid same to setuid above 
  if (mode & S_ISGID)
      buf[6] = (mode & S_IXGRP) ? 's' : 'S';
  else
      buf[6] = (mode & S_IXGRP) ? 'x' : '-';

  // Characters 7-9: other permissions 
  buf[7] = (mode & S_IROTH) ? 'r' : '-';
  buf[8] = (mode & S_IWOTH) ? 'w' : '-';
   // Sticky bit:
   // sticky + execute  → 't'
   // sticky, no execute→ 'T'
   // execute, no sticky→ 'x'
   //neither           → '-'
  if (mode & S_ISVTX)
    buf[9] = (mode & S_IXOTH) ? 't' : 'T';
  else
    buf[9] = (mode & S_IXOTH) ? 'x' : '-';

  buf[10] = '\0';
}

// Collect all directory entry into dynamic array of string and sort them alphabetically with qsort and strcmp 

int cmp_alpha(const void *a, const void *b) {
    // Cast the void pointer to a pointer to a string pointer.
    // a and b are pointers to elements of the array, each element is a 'char *'
    const char * const *sa = (const char * const *)a; // sa points to a string
    const char * const *sb = (const char * const *)b; // sb points to a string

    return strcmp(*sa, *sb); // compare the strings alphabetically
}

char **collect_entries(DIR *dir, int *count) {
    char **names = NULL; // dynamic array to store filenames
    int capacity = 0;    // current allocated capacity of the array
    *count = 0;          // number of entries collected so far

    struct dirent *ent;

    // readdir returns one entry at a time 
    while ((ent = readdir(dir)) != NULL) {
        // skip hidden files when -a is not set 
        if (!flag_a && ent->d_name[0] == '.') 
            continue;

        // grow the array when full 
        if (*count >= capacity) {
            capacity = capacity ? capacity * 2 : 16;
            names = realloc(names, (size_t)capacity * sizeof(char *));
            if (!names) { perror("realloc"); exit(1); }
        }

        // strdup allocates fresh copy of name on heap 
        names[*count] = strdup(ent->d_name);
        if (!names[*count]) { perror("strdup"); exit(1); }

        (*count)++; // increment the number of entries collected
    }

    // sort the collected names alphabetically 
    if (*count > 0)
        qsort(names, (size_t)*count, sizeof(char *), cmp_alpha);

    return names; // return the array of strings
}

// Two print modes:
// print_basic() = just file name used by plain ls 
// print_long() = full -l line: perms link owner group size time name 

void print_basic(const char *name)
{
    printf("%s\n", name);
}

// Print long 
// Steps:
// Build full path (dirpath + "/" + "name")
// call lstat() (does not follow symlinks and shows links itself)
// build perm string 
// look up owner / group names 
// format timestamp 
// if symlink, read target with readlink() 
// printf everything with alignment 

void print_long(const char *dirpath, const char *name) {
  // build full file path 
  char fullpath[4096];
  snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, name);
  // lstat - fills struct stat with metadata 
  struct stat sb;
  if (lstat(fullpath, &sb) < 0) {
    // If failed likely perms error or path error dunno man 
    perror(fullpath);
    return;
  }
  // permission strings 
  char perm[11];
  mode_to_str(sb.st_mode, perm);
  // owner username 
  struct passwd *pw = getpwuid(sb.st_uid);
  const char *owner = pw ? pw->pw_name : "?"; // fallback "?" if not found 
  // group name 
  struct group *gr = getgrgid(sb.st_gid);
  const char *group = gr ? gr->gr_name : "?";
  // modification time 
  // locatime() = convert time_t to struct tm 
  // strftime() formats struct tm into human readable string 
  char timebuf[32];
  struct tm *tm_info = localtime(&sb.st_mtime);
  strftime(timebuf, sizeof(timebuf), "%b %e %H:%M", tm_info);
  // symlink 
  char link_suffix[1100] = ""; // empty by default 
  if (S_ISLNK(sb.st_mode)) {
    char target[1024];
    // readlink fills target with symlink destination 
    // it does not null terminate so we need to do it ourself 
    ssize_t len = readlink(fullpath, target, sizeof(target) - 1);
    if (len >= 0) {
        target[len] = '\0';
        snprintf(link_suffix, sizeof(link_suffix), " -> %s", target);
    }
  }
  // print the formatted line 
  printf("%s %3lu %-10s %-10s %8lld %s %s%s\n",
          perm,
          (unsigned long)sb.st_nlink, // number of hard links
          owner,
          group,
          (long long)sb.st_size, // size in bytes
          timebuf,
          name,
          link_suffix); // "" or " -> target" 
 }

// List directory 
/*
 * list_dir()
 *   path — directory to list
 *
 * Behavior summary based on flags:
 *
 *   flag_l=0, flag_a=0, flag_R=0  →  ls       basic names, no hidden
 *   flag_l=1, flag_a=0, flag_R=0  →  ls -l    long format, no hidden
 *   flag_l=1, flag_a=1, flag_R=0  →  ls -la   long format + hidden
 *   flag_l=0, flag_a=0, flag_R=1  →  ls -R    recursive basic
 *   (any combination works)
 */ 

void list_dir(const char *path)
{
    // Open the directory
    DIR *dir = opendir(path);
    if (!dir) {
        // opendir fails if: path doesn't exist, is not a directory,
        // or we lack read permission
        perror(path);
        return;
    }
 
    // When recursive: print a header "path:" before listing
    if (flag_R) {
        printf("\n%s:\n", path);
    }
 
    // Collect and sort all entries
    int count = 0;
    char **names = collect_entries(dir, &count);
    closedir(dir);   // done reading; close the DIR* stream
 
    // Print each entry
    for (int i = 0; i < count; i++) {
        if (flag_l) {
            // -l mode: print full metadata line
            print_long(path, names[i]);
        } else {
            // basic mode: just the name
            print_basic(names[i]);
        }
    }
 
    // Recursive mode: descend into subdirectories
    if (flag_R) {
        for (int i = 0; i < count; i++) {
 
            // Skip the special entries . and .. to avoid infinite loops
            if (strcmp(names[i], ".") == 0) continue;
            if (strcmp(names[i], "..") == 0) continue;
 
            // Build the full path to the child entry
            char childpath[4096];
            snprintf(childpath, sizeof(childpath), "%s/%s", path, names[i]);
 
            // lstat the child to check if it's a directory
            struct stat sb;
            if (lstat(childpath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
                // It's a directory — recurse
                // Do NOT follow symlinks to prevent loops like: dir/link -> dir
                list_dir(childpath);
            }
        }
    }
 
    // Free all allocated memory
    for (int i = 0; i < count; i++) free(names[i]);
    free(names);
}

int main(int argc, char *argv[])
{
    const char *path;
 
    // parse command-line flags and extract the target path 
    parse_args(argc, argv, &path);
 
    // Print non-recursive header when NOT in -R mode 
    if (!flag_R) {
        printf("%s:\n", path);
    }
 
    // run the listing
    list_dir(path);
 
    return 0;
}
