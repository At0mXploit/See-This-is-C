# BCA Exam Solutions — Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. Define software process model. Explain software development life cycle.

#### Software Process Model
A software process model is an abstract representation of a software development process. It describes the activities and steps involved in building software.

Common models:
- **Waterfall Model** – Each phase is completed one by one in order.
- **Iterative Model** – Software is built in repeated cycles.
- **Spiral Model** – Combines iterative development with risk analysis.
- **Agile Model** – Focuses on small, fast, incremental delivery.

#### Software Development Life Cycle (SDLC)
SDLC is a step-by-step process for planning, building, testing, and delivering software.

| Phase | Description |
|-------|-------------|
| 1. Requirement Analysis | Gather what the user needs |
| 2. System Design | Plan the architecture and database |
| 3. Implementation | Write the code |
| 4. Testing | Find and fix bugs |
| 5. Deployment | Release to users |
| 6. Maintenance | Update and improve after release |

---

### Q3. Explain call by value and call by reference with suitable example.

#### Call by Value
A copy of the value is passed. Changes inside the function do NOT affect the original.

```c
#include <stdio.h>

void change(int a) {
    a = 100;
}

int main() {
    int x = 10;
    change(x);
    printf("x = %d", x);  // Still 10
    return 0;
}
```
**Output:** `x = 10`

#### Call by Reference
The address is passed using a pointer. Changes inside the function DO affect the original.

```c
#include <stdio.h>

void change(int *a) {
    *a = 100;
}

int main() {
    int x = 10;
    change(&x);
    printf("x = %d", x);  // Now 100
    return 0;
}
```
**Output:** `x = 100`

| Feature | Call by Value | Call by Reference |
|---------|--------------|-------------------|
| What is passed | Copy of value | Address of variable |
| Original modified? | No | Yes |

---

### Q4. What is dynamic memory allocation? What are the limitations of static memory allocation? Explain malloc() and calloc() with example.

#### Limitations of Static Memory Allocation
- Size must be fixed at compile time.
- Cannot increase or decrease size during runtime.
- Wastage of memory if too much is allocated.
- Risk of overflow if too little is allocated.

#### Dynamic Memory Allocation
It allows us to allocate memory at runtime using functions from `stdlib.h`.

#### malloc()
Allocates memory but does NOT initialize it (contains garbage values).

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *p;
    p = (int*) malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++) {
        p[i] = i + 1;
    }
    for (i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}
```
**Output:** `1 2 3 4 5`

#### calloc()
Allocates memory and initializes all values to ZERO.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *p;
    p = (int*) calloc(5, sizeof(int));
    for (i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}
```
**Output:** `0 0 0 0 0`

| Feature | malloc() | calloc() |
|---------|----------|----------|
| Initializes memory | No | Yes (to 0) |
| Arguments | 1 | 2 |

---

### Q5. What is recursion? Write a program to display Fibonacci series up to 15th term using recursion.

#### Recursion
Recursion is when a function calls itself. It must have:
1. A **base case** to stop.
2. A **recursive call** to continue.

```c
#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int i;
    printf("Fibonacci Series:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", fib(i));
    }
    return 0;
}
```

**Output:**
```
Fibonacci Series:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
```

---

### Q6. Explain null pointer and void pointer with suitable example.

#### Null Pointer
A pointer that points to nothing. It is assigned NULL.

```c
#include <stdio.h>

int main() {
    int *p = NULL;
    if (p == NULL) {
        printf("Pointer is null\n");
    }
    return 0;
}
```
**Output:** `Pointer is null`

#### Void Pointer
A pointer that can store address of any data type. Must be cast before use.

```c
#include <stdio.h>

int main() {
    int x = 10;
    float f = 3.14;
    void *p;

    p = &x;
    printf("Int: %d\n", *(int*)p);

    p = &f;
    printf("Float: %.2f\n", *(float*)p);

    return 0;
}
```
**Output:**
```
Int: 10
Float: 3.14
```

| Feature | Null Pointer | Void Pointer |
|---------|-------------|--------------|
| Value | NULL | Any address |
| Use | Mark empty pointer | Generic pointer |

---

### Q7. Write a program to draw a circle and rectangle with output text "BCA Exam 2081" using graphics function.

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    circle(200, 150, 80);
    rectangle(350, 80, 550, 220);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(150, 300, "BCA Exam 2081");

    getch();
    closegraph();
    return 0;
}
```

- `circle(x, y, r)` — draws circle at center (x,y) with radius r
- `rectangle(x1, y1, x2, y2)` — draws rectangle
- `outtextxy(x, y, text)` — prints text at position

---

### Q8. What do you mean by conditional statement? Write a program to calculate sum and average of weight of five persons using an array.

#### Conditional Statement
A statement that executes code based on a condition being true or false.

Types: `if`, `if-else`, `else if`, `switch`, ternary `? :`

```c
if (mark >= 40)
    printf("Pass");
else
    printf("Fail");
```

#### Program:

```c
#include <stdio.h>

int main() {
    float weight[5], sum = 0, avg;
    int i;

    printf("Enter weights of 5 persons:\n");
    for (i = 0; i < 5; i++) {
        printf("Person %d: ", i+1);
        scanf("%f", &weight[i]);
        sum = sum + weight[i];
    }

    avg = sum / 5;

    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}
```

**Sample Output:**
```
Enter weights of 5 persons:
Person 1: 55
Person 2: 60
Person 3: 72
Person 4: 48
Person 5: 65
Sum = 300.00
Average = 60.00
```

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. Define cohesion and coupling. What do you mean by keywords, operators and header files? Describe the types of operator used in C programming.

#### Cohesion
Cohesion means how focused a module or function is on doing one task.
- **High cohesion** = good (function does one clear job)
- **Low cohesion** = bad (function does many unrelated things)

#### Coupling
Coupling means how dependent two modules are on each other.
- **Tight coupling** = bad (modules depend heavily on each other)
- **Loose coupling** = good (modules work independently)

#### Keywords
Keywords are reserved words with fixed meaning in C. They cannot be used as variable names.

Examples: `int`, `float`, `char`, `if`, `else`, `while`, `for`, `return`, `void`, `struct`, `break`, `switch`

#### Header Files
Header files contain built-in function declarations. They are included using `#include`.

| Header File | Use |
|-------------|-----|
| `<stdio.h>` | printf, scanf |
| `<math.h>` | sqrt, pow |
| `<string.h>` | strlen, strcpy |
| `<stdlib.h>` | malloc, free |
| `<conio.h>` | getch, clrscr |

#### Types of Operators in C

**1. Arithmetic Operators**
| Operator | Meaning | Example |
|----------|---------|---------|
| `+` | Addition | `a+b` |
| `-` | Subtraction | `a-b` |
| `*` | Multiplication | `a*b` |
| `/` | Division | `a/b` |
| `%` | Modulus | `a%b` |

**2. Relational Operators**
| Operator | Meaning |
|----------|---------|
| `==` | Equal to |
| `!=` | Not equal |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater or equal |
| `<=` | Less or equal |

**3. Logical Operators**
| Operator | Meaning |
|----------|---------|
| `&&` | AND |
| `\|\|` | OR |
| `!` | NOT |

**4. Assignment Operators**
`=`, `+=`, `-=`, `*=`, `/=`, `%=`

**5. Increment / Decrement**
`++a`, `a++`, `--a`, `a--`

**6. Bitwise Operators**
`&`, `|`, `^`, `~`, `<<`, `>>`

**7. Ternary Operator**
```c
max = (a > b) ? a : b;
```

**8. sizeof Operator**
```c
printf("%d", sizeof(int));  // 4
```

---

### Q10. Why do we need break and continue? Differentiate binary file and text file. Write a program to extract prime numbers from "Number.txt" and write them to "Prime.txt".

#### break
Exits the loop immediately.
```c
for (i = 1; i <= 10; i++) {
    if (i == 5) break;
    printf("%d ", i);
}
// Output: 1 2 3 4
```

#### continue
Skips the current iteration and goes to the next.
```c
for (i = 1; i <= 5; i++) {
    if (i == 3) continue;
    printf("%d ", i);
}
// Output: 1 2 4 5
```

#### Binary File vs Text File

| Feature | Text File | Binary File |
|---------|-----------|-------------|
| Stores data as | Characters (ASCII) | Binary (0s and 1s) |
| Human readable | Yes | No |
| File extension | .txt | .exe, .jpg |
| Open mode | "r", "w" | "rb", "wb" |
| Size | Larger | Smaller |

#### Program:

```c
#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    FILE *r, *w;
    int num;

    r = fopen("Number.txt", "r");
    w = fopen("Prime.txt", "w");

    if (r == NULL) {
        printf("Cannot open Number.txt\n");
        return 1;
    }

    while (fscanf(r, "%d", &num) == 1) {
        if (isPrime(num)) {
            fprintf(w, "%d\n", num);
            printf("%d\n", num);
        }
    }

    fclose(r);
    fclose(w);
    printf("Done! Primes written to Prime.txt\n");
    return 0;
}
```

**Number.txt:**
```
2 5 8 11 15 17 20 23 25 29
```

**Prime.txt output:**
```
2
5
11
17
23
29
```

---

### Q11. Differentiate between structure and union. Create a structure "Employee" having Name, Department, Address, Salary, and Age as members. Display the name of employees having age between 30 and 50 who are living in Kathmandu.

#### Structure vs Union

| Feature | Structure | Union |
|---------|-----------|-------|
| Memory | Separate memory for each member | Shared memory for all members |
| Size | Sum of all members | Size of largest member only |
| Access | All members at same time | One member at a time |
| Keyword | `struct` | `union` |

---

#### Program with User Input:

```c
#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[50];
    char Department[30];
    char Address[50];
    float Salary;
    int Age;
};

int main() {
    struct Employee e[10];
    int i, n;

    printf("How many employees? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i+1);

        printf("Name: ");
        scanf(" ");
        gets(e[i].Name);

        printf("Department: ");
        gets(e[i].Department);

        printf("Address: ");
        gets(e[i].Address);

        printf("Salary: ");
        scanf("%f", &e[i].Salary);

        printf("Age: ");
        scanf("%d", &e[i].Age);
    }

    printf("\n--- Employees aged 30-50 living in Kathmandu ---\n");

    int found = 0;
    for (i = 0; i < n; i++) {
        if (e[i].Age >= 30 && e[i].Age <= 50 && strcmp(e[i].Address, "Kathmandu") == 0) {
            printf("\nName       : %s\n", e[i].Name);
            printf("Department : %s\n", e[i].Department);
            printf("Address    : %s\n", e[i].Address);
            printf("Salary     : %.2f\n", e[i].Salary);
            printf("Age        : %d\n", e[i].Age);
            found++;
        }
    }

    if (found == 0) {
        printf("No employee found.\n");
    } else {
        printf("\nTotal: %d employee(s) found.\n", found);
    }

    return 0;
}
```

#### Sample Input:
```
How many employees? 3

Enter details of Employee 1:
Name: Ram Sharma
Department: IT
Address: Kathmandu
Salary: 45000
Age: 35

Enter details of Employee 2:
Name: Sita Thapa
Department: HR
Address: Pokhara
Salary: 38000
Age: 42

Enter details of Employee 3:
Name: Gita Karki
Department: Finance
Address: Kathmandu
Salary: 40000
Age: 45
```

#### Sample Output:
```
--- Employees aged 30-50 living in Kathmandu ---

Name       : Ram Sharma
Department : IT
Address    : Kathmandu
Salary     : 45000.00
Age        : 35

Name       : Gita Karki
Department : Finance
Address    : Kathmandu
Salary     : 40000.00
Age        : 45

Total: 2 employee(s) found.
```

---
*End of Solutions*
