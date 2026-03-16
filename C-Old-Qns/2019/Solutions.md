# BCA Exam Solutions — 2019
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. What is software process model? Differentiate between cohesion and coupling in programming.

#### Software Process Model
A software process model is an abstract representation of a software development process. It describes the steps, activities, and order in which software is built and delivered.

Common models: Waterfall, Iterative, Spiral, Agile, V-Model.

#### Cohesion
Cohesion refers to how **closely related** the tasks inside a single module or function are.
- **High cohesion** = Good (function does one clear job)
- **Low cohesion** = Bad (function does many unrelated things)

**Example of High Cohesion:**
```c
float calculateTax(float salary) {   // only calculates tax
    return salary * 0.1;
}
```

#### Coupling
Coupling refers to how **dependent** two modules are on each other.
- **Loose coupling** = Good (modules work independently)
- **Tight coupling** = Bad (modules depend heavily on each other)

#### Cohesion vs Coupling

| Feature | Cohesion | Coupling |
|---------|----------|----------|
| Definition | Relation within a single module | Relation between two modules |
| Goal | High cohesion is desired | Low (loose) coupling is desired |
| Focus | Internal module design | Inter-module dependency |
| Good practice | Module does one job | Modules are independent |
| Bad practice | Module does many unrelated jobs | Modules heavily depend on each other |

---

### Q3. Define keywords and identifiers. Define rules for defining valid identifiers.

#### Keywords
Keywords are **reserved words** with fixed meaning in C. They cannot be used as variable names.

Examples: `int`, `float`, `char`, `if`, `else`, `while`, `for`, `return`, `void`, `struct`, `break`, `switch`, `do`, `sizeof`

C has **32 keywords** in ANSI C standard.

#### Identifiers
Identifiers are **names given by the programmer** to variables, functions, arrays, labels, etc.

```c
int age;        // age is an identifier
float salary;   // salary is an identifier
void display()  // display is an identifier
```

#### Rules for Valid Identifiers

1. Must start with a **letter (a-z, A-Z) or underscore (_)**.
   - ✅ `age`, `_name`, `marks1`
   - ❌ `1age`, `123val` (cannot start with digit)

2. Can contain **letters, digits (0-9), and underscore** only.
   - ✅ `total_marks`, `value2`
   - ❌ `total-marks`, `my name` (no special chars or spaces)

3. **No spaces** allowed.
   - ✅ `my_name`
   - ❌ `my name`

4. **Case sensitive** — `Age` and `age` are different identifiers.

5. **Cannot be a keyword**.
   - ❌ `int`, `float`, `return` cannot be identifiers

6. **No length limit** (but only first 31 characters are significant in ANSI C).

| Valid Identifiers | Invalid Identifiers | Reason |
|------------------|---------------------|--------|
| `age` | `1age` | Starts with digit |
| `_total` | `my value` | Contains space |
| `marks1` | `float` | Is a keyword |
| `student_name` | `my-name` | Contains `-` |

---

### Q4. List operators used in C based on utility. Explain the concept of bitwise operation.

#### Operators in C Based on Utility

| Type | Operators | Use |
|------|-----------|-----|
| Arithmetic | `+`, `-`, `*`, `/`, `%` | Math calculations |
| Relational | `==`, `!=`, `>`, `<`, `>=`, `<=` | Compare values |
| Logical | `&&`, `\|\|`, `!` | Combine conditions |
| Assignment | `=`, `+=`, `-=`, `*=`, `/=` | Assign values |
| Bitwise | `&`, `\|`, `^`, `~`, `<<`, `>>` | Bit-level operations |
| Increment/Decrement | `++`, `--` | Increase or decrease by 1 |
| Ternary | `? :` | Short if-else |
| sizeof | `sizeof()` | Size of data type |
| Comma | `,` | Separate expressions |

#### Bitwise Operations

Bitwise operators work directly on **binary bits** of integers.

| Operator | Name | Description |
|----------|------|-------------|
| `&` | AND | 1 if both bits are 1 |
| `\|` | OR | 1 if at least one bit is 1 |
| `^` | XOR | 1 if bits are different |
| `~` | NOT | Flips all bits (complement) |
| `<<` | Left Shift | Shifts bits left (multiply by 2) |
| `>>` | Right Shift | Shifts bits right (divide by 2) |

**Example with a=6 (0110) and b=3 (0011):**

```
a = 6 → binary: 0110
b = 3 → binary: 0011

a & b = 0010 = 2   (AND: both bits must be 1)
a | b = 0111 = 7   (OR:  at least one bit is 1)
a ^ b = 0101 = 5   (XOR: bits must be different)
~a    = ...11111001 = -7  (NOT: flip all bits)
a<<1  = 1100 = 12  (Left shift: multiply by 2)
a>>1  = 0011 = 3   (Right shift: divide by 2)
```

```c
#include <stdio.h>
int main() {
    int a = 6, b = 3;
    printf("a & b = %d\n", a & b);   // 2
    printf("a | b = %d\n", a | b);   // 7
    printf("a ^ b = %d\n", a ^ b);   // 5
    printf("~a    = %d\n", ~a);       // -7
    printf("a<<1  = %d\n", a << 1);  // 12
    printf("a>>1  = %d\n", a >> 1);  // 3
    return 0;
}
```

---

### Q5. Differentiate between while loop and do-while loop. Write a C program to find if input number is prime or composite.

#### while vs do-while

| Feature | while loop | do-while loop |
|---------|-----------|---------------|
| Syntax | `while(condition){ }` | `do{ }while(condition);` |
| Condition check | **Before** executing body | **After** executing body |
| Minimum executions | 0 (may not run at all) | 1 (always runs at least once) |
| Semicolon | No semicolon after condition | Semicolon after condition |
| Use when | Condition checked first | Body must run at least once |

**while example:**
```c
int i = 10;
while (i < 5) {
    printf("Hello");   // never runs
}
```

**do-while example:**
```c
int i = 10;
do {
    printf("Hello");   // runs once even though i > 5
} while (i < 5);
```

#### Program: Prime or Composite

```c
#include <stdio.h>

int main() {
    int n, i, flag;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("%d is neither prime nor composite.\n", n);
        return 0;
    }

    flag = 0;
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("%d is a PRIME number.\n", n);
    } else {
        printf("%d is a COMPOSITE number.\n", n);
    }

    return 0;
}
```

**Sample Output:**
```
Enter a number: 7
7 is a PRIME number.

Enter a number: 12
12 is a COMPOSITE number.
```

---

### Q6. What is DMA? Write a program to find the largest and smallest number in a list of n numbers using DMA.

#### DMA (Dynamic Memory Allocation)
DMA is the process of allocating memory **at runtime** from the heap using standard library functions. The size does not need to be fixed at compile time.

**Functions:**
| Function | Use |
|----------|-----|
| `malloc(size)` | Allocate memory (uninitialized) |
| `calloc(n, size)` | Allocate for n items (initialized to 0) |
| `realloc(ptr, size)` | Resize allocated memory |
| `free(ptr)` | Release memory back to system |

#### Program: Largest and Smallest using DMA

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, n, i;
    int max, min;

    printf("How many numbers? ");
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
    }

    max = p[0];
    min = p[0];

    for (i = 1; i < n; i++) {
        if (p[i] > max) max = p[i];
        if (p[i] < min) min = p[i];
    }

    printf("\nLargest  = %d\n", max);
    printf("Smallest = %d\n", min);

    free(p);
    return 0;
}
```

**Sample Output:**
```
How many numbers? 5
Enter 5 numbers:
Number 1: 34
Number 2: 7
Number 3: 89
Number 4: 23
Number 5: 56

Largest  = 89
Smallest = 7
```

---

### Q7. What is the difference between binary file and text file? Write a C program to write text "Welcome to BCA program" in a file test.txt.

#### Binary File vs Text File

| Feature | Text File | Binary File |
|---------|-----------|-------------|
| Data stored as | ASCII characters | Binary (0s and 1s) |
| Human readable | Yes | No |
| End of line | `\n` or `\r\n` | No special character |
| End of file | EOF character | No special EOF |
| File size | Larger | Smaller |
| Open mode | `"r"`, `"w"`, `"a"` | `"rb"`, `"wb"`, `"ab"` |
| Examples | `.txt`, `.csv` | `.exe`, `.jpg`, `.mp3` |
| Functions used | `fprintf`, `fscanf` | `fwrite`, `fread` |

#### Program: Write Text to test.txt

```c
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("test.txt", "w");

    if (fp == NULL) {
        printf("Cannot create file!\n");
        return 1;
    }

    fprintf(fp, "Welcome to BCA program\n");

    fclose(fp);

    printf("Text written to test.txt successfully!\n");

    // Read back and display to confirm
    char line[100];
    fp = fopen("test.txt", "r");
    printf("Content of test.txt:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}
```

**Output:**
```
Text written to test.txt successfully!
Content of test.txt:
Welcome to BCA program
```

**test.txt content:**
```
Welcome to BCA program
```

---

### Q8. Explain any four graphics functions in C. Write a program to draw two concentric circles with center (50, 50) and radius 75 and 125.

#### Four Graphics Functions

**1. `initgraph(int *gd, int *gm, char *path)`**
Initializes the graphics mode. Must be called before any graphics function.
```c
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
```

**2. `circle(int x, int y, int r)`**
Draws a circle with center (x,y) and radius r.
```c
circle(200, 200, 100);
```

**3. `rectangle(int x1, int y1, int x2, int y2)`**
Draws a rectangle with top-left corner (x1,y1) and bottom-right (x2,y2).
```c
rectangle(100, 100, 300, 250);
```

**4. `outtextxy(int x, int y, char *text)`**
Displays text at position (x,y) on screen.
```c
outtextxy(150, 200, "Hello");
```

#### Program: Two Concentric Circles

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Both circles share same center (50, 50)
    circle(50, 50, 75);    // inner circle, radius 75
    circle(50, 50, 125);   // outer circle, radius 125

    outtextxy(20, 180, "Concentric Circles");

    getch();
    closegraph();

    return 0;
}
```

**Concentric circles** share the **same center point** but have different radii. Here both circles have center (50, 50) but radius 75 and 125 respectively.

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. What is one dimensional array? How is it initialized? Write a C program to find sum of two matrices of order m×n.

#### One Dimensional Array
A one-dimensional array is a **linear collection** of elements of the same data type stored in continuous memory locations, accessed using a single index.

**Declaration:**
```c
datatype arrayname[size];
int marks[5];
```

**Initialization:**

1. **At declaration:**
```c
int arr[5] = {10, 20, 30, 40, 50};
```

2. **Partial initialization:**
```c
int arr[5] = {10, 20};   // rest are 0
```

3. **Without size (auto-size):**
```c
int arr[] = {10, 20, 30};  // size = 3 automatically
```

4. **Using loop:**
```c
int arr[5], i;
for (i = 0; i < 5; i++) {
    scanf("%d", &arr[i]);
}
```

5. **All zeros:**
```c
int arr[5] = {0};
```

**Accessing elements:** `arr[0]`, `arr[1]`, ..., `arr[n-1]`

#### Program: Sum of Two Matrices of Order m×n

```c
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, i, j;

    printf("Enter rows (m): ");
    scanf("%d", &m);

    printf("Enter columns (n): ");
    scanf("%d", &n);

    printf("\nEnter elements of Matrix A (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // Add matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nMatrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", b[i][j]);
        }
        printf("\n");
    }

    printf("\nSum Matrix C = A + B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Sample Output:**
```
Enter rows: 2
Enter columns: 2

Matrix A:        Matrix B:        Sum C:
 1  2             5  6             6  8
 3  4             7  8            10 12
```

---

### Q10. Define structure and union. Write a C program using structure to read records of 35 students with roll, name, address, marks and display students who obtained greater than 250 marks.

#### Structure
A structure is a user-defined data type that groups **different data types** under one name. Each member has its own memory.

```c
struct Student {
    int roll;
    char name[50];
    char address[50];
    float marks;
};
```

#### Union
A union is a user-defined data type where all members **share the same memory**. Size equals the largest member.

```c
union Data {
    int a;     // 4 bytes
    float b;   // 4 bytes
};
// Size = 4 (not 8)
```

#### Structure vs Union

| Feature | Structure | Union |
|---------|-----------|-------|
| Memory | Each member has own memory | All members share memory |
| Size | Sum of all members | Size of largest member |
| Access | All members at same time | One member at a time |

#### Program: Display Students with Marks > 250

```c
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    char address[50];
    float marks;
};

int main() {
    struct Student s[35];
    int i, n = 35, found = 0;

    printf("Enter records of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);

        printf("Roll    : ");
        scanf("%d", &s[i].roll);

        printf("Name    : ");
        scanf(" ");
        gets(s[i].name);

        printf("Address : ");
        gets(s[i].address);

        printf("Marks   : ");
        scanf("%f", &s[i].marks);
    }

    printf("\n--- Students with marks greater than 250 ---\n");
    printf("%-6s %-20s %-20s %-8s\n", "Roll", "Name", "Address", "Marks");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        if (s[i].marks > 250) {
            printf("%-6d %-20s %-20s %-8.2f\n",
                   s[i].roll, s[i].name, s[i].address, s[i].marks);
            found++;
        }
    }

    if (found == 0) {
        printf("No student scored more than 250 marks.\n");
    } else {
        printf("\nTotal students with marks > 250: %d\n", found);
    }

    return 0;
}
```

**Sample Output:**
```
--- Students with marks greater than 250 ---
Roll   Name                 Address              Marks
------------------------------------------------------------
3      Ram Sharma           Kathmandu            285.00
7      Sita Thapa           Pokhara              310.00
12     Hari KC              Lalitpur             275.50

Total students with marks > 250: 3
```

---

### Q11. What is a function? List its advantages. Explain function call by value and call by reference with example.

#### Function
A function is a **block of code** that performs a specific task. It can be called multiple times from anywhere in the program.

**Syntax:**
```c
returnType functionName(parameters) {
    // body
    return value;
}
```

**Types:**
- Library functions: `printf()`, `scanf()`, `sqrt()`
- User-defined functions: written by programmer

#### Advantages of Function
1. **Reusability** — Write once, use many times.
2. **Modularity** — Breaks big program into small manageable parts.
3. **Easy Debugging** — Fix error in one place, fixed everywhere.
4. **Readability** — Code is clean and easy to understand.
5. **Reduces Repetition** — No need to write same logic again.
6. **Team Work** — Different programmers can write different functions.

---

#### Call by Value

A **copy** of the actual argument is passed. Changes inside the function do **NOT** affect the original variable.

```c
#include <stdio.h>

void add10(int x) {
    x = x + 10;
    printf("Inside function: x = %d\n", x);
}

int main() {
    int a = 5;
    add10(a);
    printf("Outside function: a = %d\n", a);
    return 0;
}
```

**Output:**
```
Inside function: x = 15
Outside function: a = 5
```
Original `a` is unchanged because only a copy was passed.

---

#### Call by Reference

The **address** of the actual argument is passed using a pointer. Changes inside the function **DO** affect the original variable.

```c
#include <stdio.h>

void add10(int *x) {
    *x = *x + 10;
    printf("Inside function: *x = %d\n", *x);
}

int main() {
    int a = 5;
    add10(&a);
    printf("Outside function: a = %d\n", a);
    return 0;
}
```

**Output:**
```
Inside function: *x = 15
Outside function: a = 15
```
Original `a` is changed because the actual address was passed.

---

#### Comparison Table

| Feature | Call by Value | Call by Reference |
|---------|--------------|-------------------|
| What is passed | Copy of value | Address of variable |
| Original modified? | No | Yes |
| Memory | Extra memory for copy | No extra memory |
| Symbol used | Normal variable | Pointer (`*`, `&`) |
| Use when | Don't want to modify original | Want to modify original |

---
*End of Solutions*
