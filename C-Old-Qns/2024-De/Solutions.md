# BCA Exam Solutions — December 2024
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. What type of programming approach is followed by C? Write the necessary steps for PDLC.

#### Programming Approach in C
C follows a **Procedural Programming** approach (also called structured programming).
- Program is divided into functions/procedures.
- Execution goes step by step from top to bottom.
- Code is reusable through functions.
- Examples of procedural languages: C, Pascal, FORTRAN.

#### Program Development Life Cycle (PDLC)
PDLC is a step-by-step process to develop a program.

| Step | Name | Description |
|------|------|-------------|
| 1 | Problem Analysis | Understand and define the problem clearly |
| 2 | Program Design | Plan logic using flowchart or algorithm |
| 3 | Coding | Write the actual source code |
| 4 | Compilation | Convert code to machine language, fix syntax errors |
| 5 | Testing & Debugging | Run the program, find and fix logical errors |
| 6 | Documentation | Write user manual and program explanation |
| 7 | Maintenance | Update program as needed after release |

---

### Q3. Is the break keyword mandatory in switch? List operators used in C. Explain logical operators with example.

#### Is break mandatory in switch?
**No, break is NOT mandatory** in a switch statement. But without break, execution will **fall through** to the next case automatically.

```c
#include <stdio.h>

int main() {
    int x = 2;
    switch(x) {
        case 1: printf("One\n");
        case 2: printf("Two\n");   // Executes
        case 3: printf("Three\n"); // Also executes (no break!)
        default: printf("Done\n");
    }
    return 0;
}
```
**Output without break:**
```
Two
Three
Done
```
So `break` is used to stop fall-through and exit the switch block.

#### Operators in C (based on utility)

| Type | Operators |
|------|-----------|
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Relational | `==`, `!=`, `>`, `<`, `>=`, `<=` |
| Logical | `&&`, `\|\|`, `!` |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=` |
| Increment/Decrement | `++`, `--` |
| Bitwise | `&`, `\|`, `^`, `~`, `<<`, `>>` |
| Ternary | `? :` |
| sizeof | `sizeof()` |

#### Logical Operators with Example

| Operator | Meaning | Returns true when |
|----------|---------|------------------|
| `&&` | AND | Both conditions are true |
| `\|\|` | OR | At least one condition is true |
| `!` | NOT | Condition is false |

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 5;

    if (a < b && b > c) {
        printf("Both true: AND works\n");
    }

    if (a > b || b > c) {
        printf("One true: OR works\n");
    }

    if (!(a == b)) {
        printf("a is not equal to b: NOT works\n");
    }

    return 0;
}
```
**Output:**
```
Both true: AND works
One true: OR works
a is not equal to b: NOT works
```

---

### Q4. What is nested loop? Write the difference between formatted and unformatted I/O in C.

#### Nested Loop
A loop inside another loop is called a **nested loop**. The inner loop runs completely for every one iteration of the outer loop.

```c
#include <stdio.h>

int main() {
    int i, j;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    return 0;
}
```
**Output:**
```
1 2 3
2 4 6
3 6 9
```

#### Formatted vs Unformatted I/O

| Feature | Formatted I/O | Unformatted I/O |
|---------|--------------|-----------------|
| Definition | Input/output with format specifiers | Input/output without format specifiers |
| Functions | `printf()`, `scanf()` | `getch()`, `getche()`, `putch()`, `gets()`, `puts()` |
| Format control | Yes (uses %d, %f, %s etc.) | No format control |
| Data types | Can handle int, float, char, string | Mainly for characters and strings |
| Header file | `<stdio.h>` | `<stdio.h>` / `<conio.h>` |
| Example | `printf("%d", x);` | `puts("Hello");` |

**Formatted example:**
```c
int x = 10;
printf("Value = %d", x);   // Output: Value = 10
scanf("%d", &x);
```

**Unformatted example:**
```c
char ch;
ch = getch();     // reads one character without echo
putch(ch);        // prints that character
gets(name);       // reads a string
puts(name);       // prints a string
```

---

### Q5. What is DMA? List memory management functions in C. Write a program to find sum of N numbers using DMA.

#### DMA (Dynamic Memory Allocation)
DMA is the process of allocating memory to a program **at runtime** (while the program is running) instead of at compile time. Memory is taken from the **heap**.

#### Memory Management Functions in C

| Function | Description |
|----------|-------------|
| `malloc(size)` | Allocates memory, does NOT initialize (garbage values) |
| `calloc(n, size)` | Allocates memory for n elements, initializes to 0 |
| `realloc(ptr, size)` | Resizes previously allocated memory |
| `free(ptr)` | Releases/frees the allocated memory |

#### Program: Sum of N numbers using DMA

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *p;
    float sum = 0;

    printf("Enter value of N: ");
    scanf("%d", &n);

    p = (int*) malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &p[i]);
        sum = sum + p[i];
    }

    printf("Sum = %.2f\n", sum);

    free(p);
    return 0;
}
```

**Sample Output:**
```
Enter value of N: 4
Enter 4 numbers:
Number 1: 10
Number 2: 20
Number 3: 30
Number 4: 40
Sum = 100.00
```

---

### Q6. Write a C program to read a string and reverse it without using string handling function.

```c
#include <stdio.h>

int main() {
    char str[100], rev[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf(" ");
    gets(str);

    // Find length manually
    len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Copy in reverse
    j = 0;
    for (i = len - 1; i >= 0; i--) {
        rev[j] = str[i];
        j++;
    }
    rev[j] = '\0';

    printf("Original : %s\n", str);
    printf("Reversed : %s\n", rev);

    return 0;
}
```

**Sample Output:**
```
Enter a string: Kathmandu
Original : Kathmandu
Reversed : udnamhtaK
```

---

### Q7. What is the difference between binary file and text file? Write a C program to copy contents of student.txt into info.txt.

#### Binary File vs Text File

| Feature | Text File | Binary File |
|---------|-----------|-------------|
| Data stored as | ASCII characters | Binary (0s and 1s) |
| Human readable | Yes | No |
| End of line | `\n` or `\r\n` | No special character |
| Size | Larger | Smaller |
| Open mode | `"r"`, `"w"`, `"a"` | `"rb"`, `"wb"`, `"ab"` |
| Example files | `.txt`, `.csv` | `.exe`, `.jpg`, `.mp3` |

#### Program: Copy student.txt to info.txt

```c
#include <stdio.h>

int main() {
    FILE *source, *dest;
    char ch;

    source = fopen("student.txt", "r");
    dest = fopen("info.txt", "w");

    if (source == NULL) {
        printf("Cannot open student.txt\n");
        return 1;
    }

    if (dest == NULL) {
        printf("Cannot create info.txt\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully!\n");

    fclose(source);
    fclose(dest);

    return 0;
}
```

**How it works:**
- Opens `student.txt` for reading.
- Opens `info.txt` for writing.
- Reads one character at a time using `fgetc()`.
- Writes each character to `info.txt` using `fputc()`.
- Stops when end of file (EOF) is reached.

---

### Q8. What is initgraph()? Write a C program to draw a circle, rectangle and ellipse with green background and red foreground.

#### initgraph()
`initgraph()` is a function in `graphics.h` used to **initialize the graphics mode** in Turbo C. It sets up the screen for drawing shapes.

**Syntax:**
```c
initgraph(int *gd, int *gm, char *path);
```
- `gd` — graphics driver (use DETECT for automatic)
- `gm` — graphics mode
- `path` — path to BGI driver files

#### Program:

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set green background
    setbkcolor(GREEN);

    // Set red foreground (for shapes)
    setcolor(RED);

    // Draw Circle (center x=150, y=150, radius=80)
    circle(150, 150, 80);

    // Draw Rectangle
    rectangle(300, 80, 500, 220);

    // Draw Ellipse (center x=400, y=350, xradius=100, yradius=60)
    ellipse(400, 350, 0, 360, 100, 60);

    outtextxy(200, 430, "Circle, Rectangle and Ellipse");

    getch();
    closegraph();

    return 0;
}
```

**Functions used:**
- `setbkcolor(GREEN)` — sets background color to green
- `setcolor(RED)` — sets drawing color to red
- `circle(x, y, r)` — draws a circle
- `rectangle(x1, y1, x2, y2)` — draws a rectangle
- `ellipse(x, y, start, end, xr, yr)` — draws an ellipse

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. Explain different methods of passing arguments to a function. Write a program to print Fibonacci sequence up to n terms using recursion.

#### Methods of Passing Arguments

**1. Call by Value**
- A copy of the value is passed.
- Changes inside function do NOT affect original variable.

```c
void show(int x) {
    x = 100;         // only local copy changes
}
int main() {
    int a = 10;
    show(a);
    printf("%d", a); // still 10
}
```

**2. Call by Reference**
- Address (pointer) of the variable is passed.
- Changes inside function DO affect the original variable.

```c
void change(int *x) {
    *x = 100;        // changes the actual variable
}
int main() {
    int a = 10;
    change(&a);
    printf("%d", a); // now 100
}
```

**3. Call by Address (using arrays)**
- Arrays are always passed by reference (address is passed automatically).

```c
void show(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
```

| Method | What is passed | Original modified? |
|--------|---------------|-------------------|
| Call by Value | Copy of value | No |
| Call by Reference | Address of variable | Yes |
| Array (by address) | Base address of array | Yes |

#### Program: Fibonacci using Recursion

```c
#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }

    return 0;
}
```

**Sample Output:**
```
Enter number of terms: 8
Fibonacci sequence:
0 1 1 2 3 5 8 13
```

---

### Q10. What is pointer? Write a C program that uses pointers to store cricket player's data (name, age, position, height) and display them.

#### Pointer
A **pointer** is a variable that stores the **memory address** of another variable.

```c
int x = 10;
int *p = &x;     // p stores address of x
printf("%d", *p); // *p gives value at that address = 10
```

**Key symbols:**
- `&` — address of operator
- `*` — dereference operator (get value at address)

**Why use pointers?**
- To pass variables by reference to functions.
- For dynamic memory allocation.
- To work with arrays and strings efficiently.

#### Program: Cricket Player Data using Pointers

```c
#include <stdio.h>

struct Player {
    char name[50];
    int age;
    char position[30];
    float height;
};

int main() {
    struct Player p1;
    struct Player *ptr;

    ptr = &p1;   // pointer to struct

    printf("Enter player name: ");
    scanf(" ");
    gets(ptr->name);

    printf("Enter age: ");
    scanf("%d", &ptr->age);

    printf("Enter position (Batsman/Bowler/AllRounder): ");
    scanf(" ");
    gets(ptr->position);

    printf("Enter height (in meters): ");
    scanf("%f", &ptr->height);

    printf("\n--- Cricket Player Details ---\n");
    printf("Name     : %s\n", ptr->name);
    printf("Age      : %d\n", ptr->age);
    printf("Position : %s\n", ptr->position);
    printf("Height   : %.2f m\n", ptr->height);

    return 0;
}
```

**Sample Output:**
```
Enter player name: Rohit Sharma
Enter age: 36
Enter position (Batsman/Bowler/AllRounder): Batsman
Enter height (in meters): 1.74

--- Cricket Player Details ---
Name     : Rohit Sharma
Age      : 36
Position : Batsman
Height   : 1.74 m
```

**Note:** `ptr->name` is same as `(*ptr).name` — arrow operator is used to access struct members through a pointer.

---

### Q11. What is nested structure? Create a structure Book with ISBN, Title, Author and Price. Read records of 10 books and display the book with highest and lowest price.

#### Nested Structure
When a structure contains another structure as a member, it is called a **nested structure**.

```c
struct Date {
    int day, month, year;
};

struct Student {
    char name[50];
    struct Date dob;   // nested structure
};
```

Here `Date` is nested inside `Student`.

#### Program: Book Structure — Highest and Lowest Price

```c
#include <stdio.h>

struct Book {
    char ISBN[20];
    char Title[50];
    char Author[40];
    float Price;
};

int main() {
    struct Book b[10];
    int i, high, low;

    for (i = 0; i < 10; i++) {
        printf("\nEnter details of Book %d:\n", i+1);

        printf("ISBN   : ");
        scanf(" ");
        gets(b[i].ISBN);

        printf("Title  : ");
        gets(b[i].Title);

        printf("Author : ");
        gets(b[i].Author);

        printf("Price  : ");
        scanf("%f", &b[i].Price);
    }

    // Find highest and lowest price index
    high = 0;
    low = 0;
    for (i = 1; i < 10; i++) {
        if (b[i].Price > b[high].Price) {
            high = i;
        }
        if (b[i].Price < b[low].Price) {
            low = i;
        }
    }

    printf("\n--- Book with HIGHEST Price ---\n");
    printf("ISBN   : %s\n", b[high].ISBN);
    printf("Title  : %s\n", b[high].Title);
    printf("Author : %s\n", b[high].Author);
    printf("Price  : Rs. %.2f\n", b[high].Price);

    printf("\n--- Book with LOWEST Price ---\n");
    printf("ISBN   : %s\n", b[low].ISBN);
    printf("Title  : %s\n", b[low].Title);
    printf("Author : %s\n", b[low].Author);
    printf("Price  : Rs. %.2f\n", b[low].Price);

    return 0;
}
```

**Sample Output:**
```
Enter details of Book 1:
ISBN   : 978-1
Title  : C Programming
Author : Dennis Ritchie
Price  : 450

Enter details of Book 2:
ISBN   : 978-2
Title  : Data Structures
Author : Lipschutz
Price  : 850

... (10 books entered)

--- Book with HIGHEST Price ---
ISBN   : 978-2
Title  : Data Structures
Author : Lipschutz
Price  : Rs. 850.00

--- Book with LOWEST Price ---
ISBN   : 978-1
Title  : C Programming
Author : Dennis Ritchie
Price  : Rs. 450.00
```

**How it works:**
- An array of 10 `Book` structs is declared.
- Details are entered using `gets()` and `scanf()`.
- A loop compares prices to track the index of highest (`high`) and lowest (`low`) priced book.
- Those two records are printed at the end.

---
*End of Solutions*
