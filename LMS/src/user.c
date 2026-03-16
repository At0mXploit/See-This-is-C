#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define USER_FILE "data/users.dat"

static User *users = NULL;
static int userCount = 0;

void initUsers() {
    FILE *fp = fopen(USER_FILE, "rb");

    if (!fp) {
        userCount = 0;
        users = NULL;
        return;
    }

    fread(&userCount, sizeof(int), 1, fp);
    users = malloc(sizeof(User) * userCount);
    fread(users, sizeof(User), userCount, fp);
    fclose(fp);
}

void freeUsers() {
    FILE *fp = fopen(USER_FILE, "wb");
    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);
    fclose(fp);

    free(users);
}

static int usernameExists(const char *name) {
    for (int i = 0; i < userCount; i++)
        if (strcmp(users[i].username, name) == 0)
            return 1;
    return 0;
}

int signupUser() {
    User u;

    printf("Choose username: ");
    scanf("%49s", u.username);

    if (usernameExists(u.username)) {
        printf("Username already exists!\n");
        return 0;
    }

    printf("Choose password: ");
    scanf("%49s", u.password);

    User *temp = realloc(users, sizeof(User) * (userCount + 1));
    if (!temp) {
        printf("Memory error!\n");
        return 0;
    }

    users = temp;
    users[userCount++] = u;

    printf("Account created successfully.\n");
    return 1;
}

int loginUser() {
    char uname[50], pass[50];

    printf("Username: ");
    scanf("%49s", uname);

    printf("Password: ");
    scanf("%49s", pass);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, uname) == 0 &&
            strcmp(users[i].password, pass) == 0) {
            printf("Login successful.\n");
            return 1;
        }
    }

    printf("Invalid credentials.\n");
    return 0;
}

void printAllUsers() {
    printf("\nUsername\n");
    printf("-----------\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s\n", users[i].username);
    }
}

