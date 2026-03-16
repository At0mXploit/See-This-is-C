# BCA Exam Solutions — 2021
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. What are keywords? Explain the compiling process of C program.

#### Keywords
Keywords are **reserved words** in C that have a fixed, predefined meaning. They cannot be used as variable names or identifiers.

C has **32 keywords** (ANSI C). Examples:

| Keywords | | | |
|----------|-|-|-|
| `int` | `float` | `char` | `double` |
| `if` | `else` | `while` | `for` |
| `do` | `switch` | `case` | `break` |
| `return` | `void` | `struct` | `union` |
| `sizeof` | `typedef` | `static` | `goto` |

```c
int marks = 80;    // int is a keyword
float price;       // float is a keyword
// int = 10;       // ERROR: keyword cannot be variable name
```

#### Compiling Process of C Program

The compilation process converts C source code into an executable program through these steps:

**Step 1: Writing Source Code**
- Programmer writes code in a `.c` file using an editor.
- Example: `hello.c`

**Step 2: Preprocessing**
- The **preprocessor** handles all lines starting with `#`.
- `#include` — inserts header file contents.
- `#define` — replaces macros with values.
- Output: expanded source code.

**Step 3: Compilation**
- The **compiler** converts preprocessed C code into **Assembly language**.
- Checks for syntax errors.
- If errors found, they are shown and compilation stops.

**Step 4: Assembling**
- The **assembler** converts Assembly code into **machine code** (binary).
- Output: object file (`.obj` or `.o`).

**Step 5: Linking**
- The **linker** combines object file with library files (like `stdio.h` functions).
- Output: executable file (`.exe`).

**Step 6: Loading and Execution**
- The **loader** loads the `.exe` into memory.
- Program runs and gives output.

```
Source Code (.c)
      ↓  Preprocessor
Expanded Code
      ↓  Compiler
Assembly Code
      ↓  Assembler
Object Code (.obj)
      ↓  Linker
Executable (.exe)
      ↓  Loader
Output on Screen
```

---

### Q3. Differentiate between iteration and recursion.

| Feature | Iteration | Recursion |
|---------|-----------|-----------|
| Definition | Repeats using loops (`for`, `while`, `do-while`) | Function calls itself |
| Termination | Loop condition becomes false | Base case is reached |
| Speed | Faster | Slower (function call overhead) |
| Memory | Less memory used | More memory (stack used for each call) |
| Code length | Can be longer | Usually shorter and cleaner |
| Stack overflow | No risk | Risk if base case is missing |
| Use case | Simple repetition | Problems with sub-problems (tree, fibonacci) |

**Iteration Example:**
```c
#include <stdio.h>

int main() {
    int i, sum = 0;
    for (i = 1; i <= 5; i++) {
        sum = sum + i;
    }
    printf("Sum = %d\n", sum);  // Sum = 15
    return 0;
}
```

**Recursion Example:**
```c
#include <stdio.h>

int sum(int n) {
    if (n == 0) return 0;       // base case
    return n + sum(n - 1);      // recursive call
}

int main() {
    printf("Sum = %d\n", sum(5));  // Sum = 15
    return 0;
}
```

---

### Q4. Define an array. Write a program to generate the following output using loop.
```
1
12
123
1234
12345
```

#### Array
An array is a collection of **same data type** elements stored in **continuous memory locations**, accessed using an index starting from 0.

**Syntax:** `datatype arrayname[size];`
**Example:** `int arr[5] = {10, 20, 30, 40, 50};`

#### Program:

```c
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
```

**Output:**
```
1
12
123
1234
12345
```

**How it works:**
- Outer loop `i` runs from 1 to 5 (controls rows).
- Inner loop `j` runs from 1 to `i` (prints numbers 1 to current row number).

---

### Q5. Define operator. Explain any four types of operators available in C.

#### Operator
An operator is a **symbol** that performs an operation on one or more operands (variables or values).

**Example:** In `a + b`, the `+` is the operator, and `a`, `b` are operands.

#### Four Types of Operators in C

---

**1. Arithmetic Operators**
Used to perform mathematical calculations.

| Operator | Meaning | Example | Result (a=10, b=3) |
|----------|---------|---------|---------------------|
| `+` | Addition | `a + b` | 13 |
| `-` | Subtraction | `a - b` | 7 |
| `*` | Multiplication | `a * b` | 30 |
| `/` | Division | `a / b` | 3 |
| `%` | Modulus (remainder) | `a % b` | 1 |

```c
int a = 10, b = 3;
printf("%d %d %d %d %d", a+b, a-b, a*b, a/b, a%b);
// Output: 13 7 30 3 1
```

---

**2. Relational Operators**
Used to compare two values. Returns 1 (true) or 0 (false).

| Operator | Meaning | Example | Result (a=10, b=5) |
|----------|---------|---------|---------------------|
| `==` | Equal to | `a == b` | 0 |
| `!=` | Not equal | `a != b` | 1 |
| `>` | Greater than | `a > b` | 1 |
| `<` | Less than | `a < b` | 0 |
| `>=` | Greater or equal | `a >= b` | 1 |
| `<=` | Less or equal | `a <= b` | 0 |

```c
int a = 10, b = 5;
if (a > b)
    printf("a is greater");  // Output: a is greater
```

---

**3. Logical Operators**
Used to combine multiple conditions.

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `&&` | AND | `a>0 && b>0` | 1 (both true) |
| `\|\|` | OR | `a>0 \|\| b<0` | 1 (one true) |
| `!` | NOT | `!(a==b)` | 1 |

```c
int a = 10, b = 5;
if (a > 0 && b > 0)
    printf("Both positive\n");   // Output: Both positive
```

---

**4. Assignment Operators**
Used to assign values to variables.

| Operator | Meaning | Example | Same as |
|----------|---------|---------|---------|
| `=` | Assign | `a = 5` | `a = 5` |
| `+=` | Add and assign | `a += 3` | `a = a + 3` |
| `-=` | Subtract and assign | `a -= 3` | `a = a - 3` |
| `*=` | Multiply and assign | `a *= 2` | `a = a * 2` |
| `/=` | Divide and assign | `a /= 2` | `a = a / 2` |
| `%=` | Modulus and assign | `a %= 2` | `a = a % 2` |

```c
int a = 10;
a += 5;
printf("%d", a);  // Output: 15
```

---

### Q6. Why function is required in C? Write a program to find smallest number from array using function.

#### Why Function is Required
1. **Reusability** — Write once, call many times anywhere.
2. **Modularity** — Break big program into small parts.
3. **Easy Debugging** — Fix errors in one place.
4. **Readability** — Code is clean and organized.
5. **Reduces Repetition** — No need to write same code again and again.

#### Program: Find Smallest Number from Array using Function

```c
#include <stdio.h>

int findSmallest(int arr[], int n) {
    int i, small;
    small = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < small) {
            small = arr[i];
        }
    }
    return small;
}

int main() {
    int arr[10], i, n, result;

    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    result = findSmallest(arr, n);

    printf("Smallest number = %d\n", result);

    return 0;
}
```

**Sample Output:**
```
How many numbers? 5
Enter 5 numbers:
Number 1: 45
Number 2: 12
Number 3: 78
Number 4: 3
Number 5: 56
Smallest number = 3
```

---

### Q7. Why DMA is used in C? Write a program to enter age of 20 students and count age between 18 and 25 using DMA.

#### Why DMA is Used
1. Memory size can be decided **at runtime** — no need to fix size at compile time.
2. **No memory waste** — allocate only what is needed.
3. Handles **large data** — uses heap memory which is much bigger than stack.
4. Memory can be **resized** using `realloc()`.
5. Useful when number of elements is not known in advance.

#### Program:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *age;
    int i, count = 0;
    int n = 20;

    age = (int*) malloc(n * sizeof(int));

    if (age == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter age of %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("Student %d age: ", i+1);
        scanf("%d", &age[i]);
    }

    for (i = 0; i < n; i++) {
        if (age[i] >= 18 && age[i] <= 25) {
            count++;
        }
    }

    printf("\nNumber of students with age between 18 and 25 = %d\n", count);

    free(age);
    return 0;
}
```

**Sample Output:**
```
Enter age of 20 students:
Student 1 age: 17
Student 2 age: 20
Student 3 age: 22
...
Number of students with age between 18 and 25 = 14
```

---

### Q8. Write a C program to generate the following output using graphics functions.
*(A rectangle with text "BCA Program" inside it)*

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw rectangle
    rectangle(200, 180, 440, 270);

    // Set text style
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    // Print text inside rectangle
    outtextxy(235, 215, "BCA Program");

    getch();
    closegraph();

    return 0;
}
```

**Functions used:**
- `initgraph()` — initializes graphics mode
- `rectangle(x1, y1, x2, y2)` — draws rectangle with given corners
- `settextstyle(font, direction, size)` — sets font style and size
- `outtextxy(x, y, text)` — prints text at given position
- `closegraph()` — closes graphics window

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. What is union? Write a C program to enter bid, title, price, pages of 100 books into structure variable called book and sort them in descending order by title using pointer.

#### Union
A **union** is a user-defined data type where all members **share the same memory location**. The size of the union equals the size of its **largest member**.

```c
union Data {
    int x;       // 4 bytes
    float y;     // 4 bytes
    char z;      // 1 byte
};
// Total size = 4 bytes (only largest)
```

Only **one member** can hold a value at a time. When you write to a new member, the old value is lost.

**Structure vs Union:**

| Feature | Structure | Union |
|---------|-----------|-------|
| Memory | Each member has own memory | All share same memory |
| Size | Sum of all members | Size of largest member |
| Access | All at same time | One at a time |

#### Program: Book Structure — Sort by Title (Descending) using Pointer

```c
#include <stdio.h>
#include <string.h>

struct Book {
    int bid;
    char title[50];
    float price;
    int pages;
};

int main() {
    struct Book b[100];
    struct Book *ptr[100];
    struct Book *temp;
    int i, j, n;

    printf("How many books (max 100)? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Book %d:\n", i+1);

        printf("Book ID : ");
        scanf("%d", &b[i].bid);

        printf("Title   : ");
        scanf(" ");
        gets(b[i].title);

        printf("Price   : ");
        scanf("%f", &b[i].price);

        printf("Pages   : ");
        scanf("%d", &b[i].pages);

        ptr[i] = &b[i];
    }

    // Bubble sort by title descending (Z to A)
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(ptr[j]->title, ptr[j+1]->title) < 0) {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }

    printf("\n--- Books sorted by Title (Descending Z to A) ---\n");
    printf("%-5s %-25s %-10s %-5s\n", "BID", "Title", "Price", "Pages");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-5d %-25s %-10.2f %-5d\n",
               ptr[i]->bid, ptr[i]->title, ptr[i]->price, ptr[i]->pages);
    }

    return 0;
}
```

**Sample Input:**
```
How many books? 3

Book 1: BID=1, Title=Zebra Guide, Price=400, Pages=300
Book 2: BID=2, Title=C Programming, Price=500, Pages=450
Book 3: BID=3, Title=Mathematics, Price=350, Pages=200
```

**Output:**
```
--- Books sorted by Title (Descending Z to A) ---
BID   Title                     Price      Pages
--------------------------------------------------
1     Zebra Guide               400.00     300
3     Mathematics               350.00     200
2     C Programming             500.00     450
```

---

### Q10. What is the use of data file in C? Write a program to accept 100 numbers, store odd numbers in odd.txt and even numbers in even.txt, then display odd numbers from odd.txt.

#### Use of Data File in C
1. **Permanent storage** — data is saved even after program ends.
2. **Large data** — store more data than fits in memory variables.
3. **Reuse** — data can be read again in future runs.
4. **Sharing** — files can be shared between programs.
5. **Backup** — important records are not lost.

#### Program:

```c
#include <stdio.h>

int main() {
    FILE *odd, *even, *read;
    int num, i, n = 100;
    int temp;

    odd  = fopen("odd.txt",  "w");
    even = fopen("even.txt", "w");

    if (odd == NULL || even == NULL) {
        printf("File creation failed!\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &num);

        if (num % 2 != 0) {
            fprintf(odd,  "%d\n", num);
        } else {
            fprintf(even, "%d\n", num);
        }
    }

    fclose(odd);
    fclose(even);

    printf("\nNumbers stored in odd.txt and even.txt successfully!\n");

    // Display odd numbers from odd.txt
    printf("\n--- Odd numbers from odd.txt ---\n");
    read = fopen("odd.txt", "r");

    if (read == NULL) {
        printf("Cannot open odd.txt\n");
        return 1;
    }

    while (fscanf(read, "%d", &temp) == 1) {
        printf("%d\n", temp);
    }

    fclose(read);

    return 0;
}
```

**Sample Output:**
```
Enter 100 numbers:
Number 1: 5
Number 2: 8
Number 3: 3
...

Numbers stored in odd.txt and even.txt successfully!

--- Odd numbers from odd.txt ---
5
3
...
```

**How it works:**
- Opens `odd.txt` and `even.txt` for writing.
- Reads 100 numbers one by one.
- If `num % 2 != 0` → writes to `odd.txt`, else writes to `even.txt`.
- After storing, opens `odd.txt` for reading and prints all odd numbers.

---

### Q11. What do you mean by system design tools? Explain any four design tools with suitable examples.

#### System Design Tools
System design tools are **methods and diagrams** used to plan and represent the logic of a program or system **before writing actual code**. They help programmers understand the problem and design the solution clearly.

---

**1. Algorithm**

An algorithm is a **step-by-step written procedure** to solve a problem in plain English (or pseudocode).

**Rules:**
- Must have a clear Start and Stop.
- Each step must be clear and unambiguous.
- Must produce a result.

**Example:** Algorithm to find largest of two numbers:
```
Step 1: Start
Step 2: Read A and B
Step 3: If A > B then
            Print "A is largest"
        Else
            Print "B is largest"
Step 4: Stop
```

---

**2. Flowchart**

A flowchart is a **graphical diagram** that shows the step-by-step flow of a program using standard symbols.

| Symbol | Shape | Purpose |
|--------|-------|---------|
| Oval | Rounded box | Start / End |
| Rectangle | Box | Process / Calculation |
| Diamond | Rhombus | Decision (Yes/No) |
| Parallelogram | Slanted box | Input / Output |
| Arrow | Line | Flow direction |

**Example:** Flowchart to check even or odd:
```
START
  ↓
Input N
  ↓
N % 2 == 0? → YES → Print "Even" → END
     ↓ NO
Print "Odd"
     ↓
    END
```

---

**3. Pseudocode**

Pseudocode is a **simplified, informal code** written in plain English that looks like a programming language but is not actual code. It is used to plan program logic before coding.

**Example:** Pseudocode to find sum of 5 numbers:
```
BEGIN
    SET sum = 0
    FOR i = 1 TO 5
        INPUT num
        sum = sum + num
    END FOR
    PRINT sum
END
```

**Advantages:**
- Easy to understand.
- Language independent.
- Can be converted to any programming language.

---

**4. Data Flow Diagram (DFD)**

A DFD shows **how data flows** through a system — where data comes from, where it goes, and how it is processed.

**Symbols:**
| Symbol | Meaning |
|--------|---------|
| Rectangle | External entity (user, system) |
| Rounded rectangle | Process |
| Arrow | Data flow |
| Open rectangle | Data store (file, database) |

**Example:** DFD for a Student Mark System:
```
Student → [Enter Marks] → [Calculate Result] → [Display Result] → Student
                               ↕
                        [Mark Database]
```

**Advantages:**
- Shows the big picture of the system.
- Easy to understand for non-programmers.
- Helps identify data inputs and outputs.

---
*End of Solutions*
