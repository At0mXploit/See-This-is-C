# BCA Exam Solutions — 2020
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. What is computer programming? Differentiate between top-down and bottom-up approach of programming.

#### Computer Programming
Computer programming is the process of writing **instructions (code)** that a computer can execute to perform a specific task. It involves designing, writing, testing, and maintaining source code in a programming language like C, Java, Python, etc.

**Example:**
```c
#include <stdio.h>
int main() {
    printf("Hello World");
    return 0;
}
```
This is a simple C program — an example of computer programming.

#### Top-Down vs Bottom-Up Approach

| Feature | Top-Down | Bottom-Up |
|---------|----------|-----------|
| Start from | Main/big problem | Small individual modules |
| Direction | Big → Small | Small → Big |
| Method | Divide big problem into sub-problems | Build small parts then combine |
| Testing | Modules tested after all are made | Each module tested independently |
| Used in | Procedural programming (C) | Object Oriented Programming (C++, Java) |
| Advantage | Easy to understand overall structure | Easy to test individual parts |

**Top-Down Example:**
```
Main Program (Calculator)
├── Add()
├── Subtract()
├── Multiply()
└── Divide()
```
Start with `Calculator`, then break into `Add`, `Subtract`, etc.

**Bottom-Up Example:**
```
Add()        → built and tested first
Subtract()   → built and tested first
Multiply()   → built and tested first
      ↓
  Calculator (combined at end)
```
Build small functions first, then combine into `Calculator`.

---

### Q3. What is the purpose of sizeof operator? Write a C program to swap two integers without using third variable.

#### sizeof Operator
The `sizeof` operator returns the **size in bytes** of a variable or data type. It is a compile-time operator.

**Syntax:** `sizeof(datatype)` or `sizeof(variable)`

```c
#include <stdio.h>

int main() {
    printf("Size of int    = %d bytes\n", sizeof(int));
    printf("Size of float  = %d bytes\n", sizeof(float));
    printf("Size of double = %d bytes\n", sizeof(double));
    printf("Size of char   = %d bytes\n", sizeof(char));
    return 0;
}
```
**Output:**
```
Size of int    = 4 bytes
Size of float  = 4 bytes
Size of double = 8 bytes
Size of char   = 1 byte
```

**Purpose:**
- Find memory size of data types.
- Used in `malloc()` to allocate correct memory: `malloc(n * sizeof(int))`.
- Helps write portable code that works on different machines.

#### Program: Swap Two Integers Without Third Variable

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: a = %d, b = %d\n", a, b);

    // Swap using arithmetic
    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swap : a = %d, b = %d\n", a, b);

    return 0;
}
```

**Sample Output:**
```
Enter two numbers: 10 20
Before swap: a = 10, b = 20
After swap : a = 20, b = 10
```

**How it works (a=10, b=20):**
```
a = 10 + 20 = 30
b = 30 - 20 = 10
a = 30 - 10 = 20
```

---

### Q4. Write a C program to find all possible roots of quadratic equation ax² + bx + c = 0.

The roots of `ax² + bx + c = 0` are found using:
```
x = (-b ± sqrt(b²- 4ac)) / 2a
```
The **discriminant** `D = b² - 4ac` determines the type of roots:
- `D > 0` → Two distinct real roots
- `D = 0` → Two equal real roots
- `D < 0` → Two complex (imaginary) roots

```c
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, D, root1, root2, realpart, imagpart;

    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    D = b*b - 4*a*c;

    printf("\nDiscriminant D = %.2f\n", D);

    if (D > 0) {
        root1 = (-b + sqrt(D)) / (2*a);
        root2 = (-b - sqrt(D)) / (2*a);
        printf("Two distinct real roots:\n");
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    }
    else if (D == 0) {
        root1 = -b / (2*a);
        printf("Two equal real roots:\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }
    else {
        realpart = -b / (2*a);
        imagpart = sqrt(-D) / (2*a);
        printf("Two complex roots:\n");
        printf("Root 1 = %.2f + %.2fi\n", realpart, imagpart);
        printf("Root 2 = %.2f - %.2fi\n", realpart, imagpart);
    }

    return 0;
}
```

**Sample Outputs:**
```
// Case 1: D > 0
Enter coefficients a, b, c: 1 -5 6
Root 1 = 3.00
Root 2 = 2.00

// Case 2: D = 0
Enter coefficients a, b, c: 1 -2 1
Root 1 = Root 2 = 1.00

// Case 3: D < 0
Enter coefficients a, b, c: 1 1 1
Root 1 = -0.50 + 0.87i
Root 2 = -0.50 - 0.87i
```

---

### Q5. Why is array required in programming? Write a C program to input age of 30 employees and find second largest age from array.

#### Why Array is Required
1. Store **multiple values** of same type in one variable.
2. Avoids declaring many separate variables (e.g. `age1, age2, age3...`).
3. Easy to process data using **loops**.
4. Elements are stored in **continuous memory** — fast access.
5. Useful for **sorting, searching, and calculations** on large data.

#### Program: Second Largest Age from 30 Employees

```c
#include <stdio.h>

int main() {
    int age[30], i, n;
    int largest, second;

    n = 30;

    printf("Enter age of %d employees:\n", n);
    for (i = 0; i < n; i++) {
        printf("Employee %d age: ", i+1);
        scanf("%d", &age[i]);
    }

    largest = age[0];
    second = -1;

    // Find largest first
    for (i = 1; i < n; i++) {
        if (age[i] > largest) {
            largest = age[i];
        }
    }

    // Find second largest
    for (i = 0; i < n; i++) {
        if (age[i] != largest) {
            if (second == -1 || age[i] > second) {
                second = age[i];
            }
        }
    }

    printf("\nLargest age = %d\n", largest);
    printf("Second largest age = %d\n", second);

    return 0;
}
```

**Sample Output:**
```
Enter age of 30 employees:
Employee 1 age: 25
Employee 2 age: 45
Employee 3 age: 38
...
Largest age = 58
Second largest age = 55
```

---

### Q6. What is recursive function? Write a C program to generate Fibonacci series up to 13th term using recursion.

#### Recursive Function
A recursive function is a function that **calls itself** to solve a smaller version of the same problem. It must have:
1. **Base case** — condition to stop the recursion.
2. **Recursive case** — function calling itself with a reduced value.

```c
int factorial(int n) {
    if (n == 0) return 1;           // base case
    return n * factorial(n - 1);   // recursive call
}
```

#### Program: Fibonacci Series up to 13th term using Recursion

```c
#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;   // base case 1
    if (n == 1) return 1;   // base case 2
    return fib(n-1) + fib(n-2);   // recursive call
}

int main() {
    int i;

    printf("Fibonacci series up to 13th term:\n");
    for (i = 0; i < 13; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}
```

**Output:**
```
Fibonacci series up to 13th term:
0 1 1 2 3 5 8 13 21 34 55 89 144
```

**How recursion works for fib(4):**
```
fib(4) = fib(3) + fib(2)
fib(3) = fib(2) + fib(1)
fib(2) = fib(1) + fib(0)
fib(1) = 1
fib(0) = 0
Result = 3
```

---

### Q7. What is the advantage of pointer? Write a C program to store 10 integers and find minimum and maximum using DMA.

#### Advantages of Pointer
1. **Pass by reference** — can modify original variable through function.
2. **Dynamic memory** — used with `malloc()`, `calloc()` for DMA.
3. **Array handling** — arrays and pointers work together efficiently.
4. **Speed** — direct memory access is faster.
5. **Return multiple values** — function can return multiple values via pointers.

#### Program: Min and Max of 10 numbers using DMA

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int i, n = 10;
    int min, max;

    p = (int*) malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &p[i]);
    }

    min = p[0];
    max = p[0];

    for (i = 1; i < n; i++) {
        if (p[i] < min) min = p[i];
        if (p[i] > max) max = p[i];
    }

    printf("\nMinimum = %d\n", min);
    printf("Maximum = %d\n", max);

    free(p);
    return 0;
}
```

**Sample Output:**
```
Enter 10 integers:
Number 1: 45
Number 2: 12
Number 3: 78
Number 4: 3
Number 5: 56
Number 6: 91
Number 7: 23
Number 8: 67
Number 9: 34
Number 10: 8

Minimum = 3
Maximum = 91
```

---

### Q8. What is the use of initgraph()? Write a program to draw line, circle, and rectangle using graphics functions.

#### initgraph()
`initgraph()` is a function in `graphics.h` used to **initialize the graphics mode** in Turbo C. Without calling this, no graphics functions will work.

**Syntax:**
```c
initgraph(int *gd, int *gm, char *path);
```
- `gd` — graphics driver (use `DETECT` for automatic detection)
- `gm` — graphics mode (set automatically when DETECT is used)
- `path` — path to BGI driver folder

#### Program: Draw Line, Circle, and Rectangle

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw a Line
    line(50, 50, 250, 50);
    outtextxy(120, 60, "Line");

    // Draw a Circle
    circle(150, 180, 70);
    outtextxy(130, 175, "Circle");

    // Draw a Rectangle
    rectangle(300, 100, 500, 250);
    outtextxy(370, 170, "Rectangle");

    getch();
    closegraph();

    return 0;
}
```

**Functions used:**
- `initgraph()` — starts graphics mode
- `line(x1, y1, x2, y2)` — draws a line from point (x1,y1) to (x2,y2)
- `circle(x, y, r)` — draws circle at center (x,y) with radius r
- `rectangle(x1, y1, x2, y2)` — draws rectangle with corner coordinates
- `outtextxy(x, y, text)` — prints label text at given position
- `closegraph()` — ends graphics mode

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. What is structure? Write a C program to enter id, name and address of 25 employees and sort them in ascending order using pointer.

#### Structure
A **structure** is a user-defined data type that groups different types of variables under one name.

```c
struct Employee {
    int id;
    char name[50];
    char address[50];
};
```

Each variable inside struct is called a **member**. Members can be of different data types unlike array.

#### Program: 25 Employees — Sort by ID Ascending using Pointer

```c
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char address[50];
};

int main() {
    struct Employee e[25];
    struct Employee *ptr[25];
    struct Employee *temp;
    int i, j, n;

    printf("How many employees (max 25)? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i+1);

        printf("ID      : ");
        scanf("%d", &e[i].id);

        printf("Name    : ");
        scanf(" ");
        gets(e[i].name);

        printf("Address : ");
        gets(e[i].address);

        ptr[i] = &e[i];
    }

    // Bubble sort by ID ascending
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (ptr[j]->id > ptr[j+1]->id) {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }

    printf("\n--- Employees sorted by ID (Ascending) ---\n");
    printf("%-5s %-20s %-20s\n", "ID", "Name", "Address");
    printf("-------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-20s\n", ptr[i]->id, ptr[i]->name, ptr[i]->address);
    }

    return 0;
}
```

**Sample Input:**
```
How many employees? 3

Employee 1: ID=3, Name=Sita Thapa,    Address=Pokhara
Employee 2: ID=1, Name=Ram Sharma,    Address=Kathmandu
Employee 3: ID=2, Name=Hari Adhikari, Address=Lalitpur
```

**Output:**
```
--- Employees sorted by ID (Ascending) ---
ID    Name                 Address
-------------------------------------------
1     Ram Sharma           Kathmandu
2     Hari Adhikari        Lalitpur
3     Sita Thapa           Pokhara
```

---

### Q10. Is break keyword mandatory in switch? Write a program to calculate arithmetic operations (+, -, *, /) using switch case.

#### Is break Mandatory in Switch?
**No, break is NOT mandatory.** But without `break`, execution **falls through** to the next case automatically even if the case doesn't match.

**Without break (fall-through):**
```c
int x = 2;
switch(x) {
    case 1: printf("One\n");
    case 2: printf("Two\n");    // matches
    case 3: printf("Three\n"); // also runs! (fall-through)
    default: printf("Done\n"); // also runs!
}
// Output: Two  Three  Done
```

**With break (correct):**
```c
switch(x) {
    case 2: printf("Two\n"); break;  // stops here
    case 3: printf("Three\n"); break;
}
// Output: Two
```

So `break` is used to **exit the switch block** after a matching case executes.

#### Program: Arithmetic Operations using Switch

```c
#include <stdio.h>

int main() {
    float a, b, result;
    char op;

    printf("Enter first number : ");
    scanf("%f", &a);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &b);

    switch(op) {
        case '+':
            result = a + b;
            printf("%.2f + %.2f = %.2f\n", a, b, result);
            break;

        case '-':
            result = a - b;
            printf("%.2f - %.2f = %.2f\n", a, b, result);
            break;

        case '*':
            result = a * b;
            printf("%.2f * %.2f = %.2f\n", a, b, result);
            break;

        case '/':
            if (b == 0) {
                printf("Error! Division by zero.\n");
            } else {
                result = a / b;
                printf("%.2f / %.2f = %.2f\n", a, b, result);
            }
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
```

**Sample Outputs:**
```
Enter first number : 10
Enter operator: +
Enter second number: 5
10.00 + 5.00 = 15.00

Enter first number : 20
Enter operator: /
Enter second number: 4
20.00 / 4.00 = 5.00

Enter first number : 8
Enter operator: /
Enter second number: 0
Error! Division by zero.
```

---

### Q11. What do you mean by SDLC? Explain the Waterfall model with advantages and disadvantages.

#### SDLC (Software Development Life Cycle)
SDLC is a **structured process** used for planning, designing, developing, testing, and delivering software. It provides a step-by-step framework that guides the entire software development process from start to finish.

**Goal:** To produce high-quality software that meets user requirements on time and within budget.

---

#### Waterfall Model

The Waterfall Model is the **oldest and simplest** software process model. It follows a **linear, sequential** approach where each phase must be fully completed before moving to the next. It is called "Waterfall" because phases flow downward like a waterfall.

```
1. Requirement Analysis
         ↓
2. System Design
         ↓
3. Implementation (Coding)
         ↓
4. Testing
         ↓
5. Deployment
         ↓
6. Maintenance
```

#### Phase Descriptions

| Phase | Description |
|-------|-------------|
| **Requirement Analysis** | Gather and document all user requirements |
| **System Design** | Plan architecture, database, UI based on requirements |
| **Implementation** | Write actual source code |
| **Testing** | Find and fix bugs and errors |
| **Deployment** | Release the software to users |
| **Maintenance** | Fix problems and update after release |

#### Advantages of Waterfall Model

1. **Simple and easy to understand** — phases are clear and well-defined.
2. **Good documentation** — each phase produces clear documents.
3. **Easy to manage** — progress is easy to track stage by stage.
4. **Works well for small projects** where requirements are fixed and clear.
5. **Each phase has a clear start and end** — no overlap.

#### Disadvantages of Waterfall Model

1. **No going back** — once a phase is done, it is hard to go back and make changes.
2. **Not suitable for changing requirements** — bad if user changes needs midway.
3. **Testing done very late** — bugs found only at testing stage, which is costly to fix.
4. **Customer sees product only at the end** — no early feedback.
5. **Risky for complex projects** — not flexible for large or uncertain projects.

#### When to Use Waterfall Model
- Requirements are clearly defined and will not change.
- Project is small and short.
- Technology is well understood.

---
*End of Solutions*
