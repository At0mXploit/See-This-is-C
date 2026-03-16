# BCA Exam Solutions — 2022
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. Write a C program to generate the following output using loop.
```
10101
0101
101
01
1
```

```c
#include <stdio.h>

int main() {
    char pattern[] = "10101";
    int i, j;
    int len = 5;

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            printf("%c", pattern[j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Output:**
```
10101
0101
101
01
1
```

**How it works:**
- The string `"10101"` is stored in a char array.
- Outer loop `i` starts from 0 and goes to 4.
- Inner loop `j` starts from `i` (skipping earlier characters each time).
- Each row prints from position `i` to end of the string.

---

### Q3. How will you define pointer? Write a program that illustrates how pointer variable changes the value of normal variable.

#### Pointer
A pointer is a variable that stores the **memory address** of another variable.

```c
int x = 10;
int *p = &x;   // p stores address of x
```

- `&x` — gives the address of x
- `*p` — gives the value stored at the address (dereference)
- `p`  — gives the address itself

#### Program: Pointer changing value of normal variable

```c
#include <stdio.h>

int main() {
    int a = 50;
    int *p;

    p = &a;   // p points to a

    printf("Before change:\n");
    printf("Value of a = %d\n", a);
    printf("Address of a = %u\n", &a);
    printf("Value of p (address) = %u\n", p);
    printf("Value at p (*p) = %d\n", *p);

    *p = 100;   // changing value of a through pointer

    printf("\nAfter change using pointer:\n");
    printf("Value of a = %d\n", a);

    return 0;
}
```

**Output:**
```
Before change:
Value of a = 50
Address of a = 6422036
Value of p (address) = 6422036
Value at p (*p) = 50

After change using pointer:
Value of a = 100
```

Here `*p = 100` changes the value of `a` directly through the pointer.

---

### Q4. Write a C program to calculate sum of natural numbers up to N using recursive function.

```c
#include <stdio.h>

int sum(int n) {
    if (n == 0) return 0;       // base case
    return n + sum(n - 1);      // recursive call
}

int main() {
    int n, result;

    printf("Enter N: ");
    scanf("%d", &n);

    result = sum(n);

    printf("Sum of natural numbers up to %d = %d\n", n, result);

    return 0;
}
```

**Sample Output:**
```
Enter N: 5
Sum of natural numbers up to 5 = 15
```

**How recursion works for n=5:**
```
sum(5) = 5 + sum(4)
sum(4) = 4 + sum(3)
sum(3) = 3 + sum(2)
sum(2) = 2 + sum(1)
sum(1) = 1 + sum(0)
sum(0) = 0   ← base case
Result = 5+4+3+2+1+0 = 15
```

---

### Q5. Write a C program to calculate: 5x√y² + 5

**Expression:** `5x * sqrt(y²) + 5`  which simplifies to `5x * y + 5` (since √y² = y)

```c
#include <stdio.h>
#include <math.h>

int main() {
    float x, y, result;

    printf("Enter value of x: ");
    scanf("%f", &x);

    printf("Enter value of y: ");
    scanf("%f", &y);

    result = 5 * x * sqrt(y * y) + 5;

    printf("5x * sqrt(y^2) + 5 = %.2f\n", result);

    return 0;
}
```

**Sample Output:**
```
Enter value of x: 2
Enter value of y: 3
5x * sqrt(y^2) + 5 = 35.00
```

**(5 × 2 × √9 + 5 = 10 × 3 + 5 = 35)**

---

### Q6. Write a C program to copy contents of student.txt into another file called info.txt.

```c
#include <stdio.h>

int main() {
    FILE *source, *dest;
    char ch;

    source = fopen("student.txt", "r");
    dest   = fopen("info.txt", "w");

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

    printf("File copied successfully from student.txt to info.txt\n");

    fclose(source);
    fclose(dest);

    return 0;
}
```

**How it works:**
- `fopen("student.txt", "r")` — opens source file for reading.
- `fopen("info.txt", "w")` — creates/opens destination file for writing.
- `fgetc()` reads one character at a time until `EOF` (End of File).
- `fputc()` writes each character to `info.txt`.
- Both files are closed at the end.

---

### Q7. Why do you use DMA instead of array? Explain DMA with suitable example.

#### Why DMA instead of Array?

| Reason | Array | DMA |
|--------|-------|-----|
| Size | Fixed at compile time | Decided at runtime |
| Flexibility | Cannot resize | Can resize using `realloc()` |
| Memory use | May waste memory | Uses only what is needed |
| Large data | Limited by stack size | Uses heap (much larger) |
| Multiple sizes | Need multiple arrays | One pointer handles all |

**Main reason:** When we don't know the size of data in advance, arrays are wasteful. DMA lets us allocate exactly as much memory as we need, when we need it.

#### DMA Functions

| Function | Use |
|----------|-----|
| `malloc(size)` | Allocate memory (uninitialized) |
| `calloc(n, size)` | Allocate memory for n items (initialized to 0) |
| `realloc(ptr, size)` | Resize existing allocated memory |
| `free(ptr)` | Free/release allocated memory |

#### Example: DMA using malloc

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *p;

    printf("How many numbers to store? ");
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

    printf("Numbers entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }

    free(p);   // release memory
    printf("\nMemory freed.\n");

    return 0;
}
```

**Sample Output:**
```
How many numbers to store? 3
Enter 3 numbers:
Number 1: 10
Number 2: 20
Number 3: 30
Numbers entered: 10 20 30
Memory freed.
```

---

### Q8. Write a C program to generate the following output using graphics functions.
*(A circle with text "BCA" inside it)*

```c
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw circle at center (320, 240) with radius 80
    circle(320, 240, 80);

    // Set text style and print "BCA" inside circle
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(295, 228, "BCA");

    getch();
    closegraph();

    return 0;
}
```

**Functions used:**
- `initgraph()` — initializes graphics mode
- `circle(x, y, r)` — draws circle at center (x,y) with radius r
- `settextstyle(font, direction, size)` — sets text appearance
- `outtextxy(x, y, text)` — prints text at given position
- `closegraph()` — closes graphics window

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. Write a C program to store player name, runs scored, wickets taken of 20 cricketers using structure with pointer, then arrange players in order of maximum wickets to minimum wickets.

```c
#include <stdio.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
};

int main() {
    struct Player p[20];
    struct Player *ptr[20];
    struct Player temp;
    int i, j, n;

    printf("How many players (max 20)? ");
    scanf("%d", &n);

    // Input player details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Player %d:\n", i+1);

        printf("Name    : ");
        scanf(" ");
        gets(p[i].name);

        printf("Runs    : ");
        scanf("%d", &p[i].runs);

        printf("Wickets : ");
        scanf("%d", &p[i].wickets);

        ptr[i] = &p[i];   // pointer array points to each player
    }

    // Bubble sort by wickets (descending - max to min)
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (ptr[j]->wickets < ptr[j+1]->wickets) {
                // swap pointers
                struct Player *t = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = t;
            }
        }
    }

    // Display sorted players
    printf("\n--- Players sorted by Wickets (Max to Min) ---\n");
    printf("%-5s %-20s %-10s %-10s\n", "Rank", "Name", "Runs", "Wickets");
    printf("----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-10d %-10d\n", i+1, ptr[i]->name, ptr[i]->runs, ptr[i]->wickets);
    }

    return 0;
}
```

**Sample Input:**
```
How many players (max 20)? 4

Player 1: Rohit Sharma, Runs: 45, Wickets: 2
Player 2: Jasprit Bumrah, Runs: 10, Wickets: 5
Player 3: Virat Kohli, Runs: 82, Wickets: 0
Player 4: Ravindra Jadeja, Runs: 35, Wickets: 4
```

**Output:**
```
--- Players sorted by Wickets (Max to Min) ---
Rank  Name                 Runs       Wickets
----------------------------------------------
1     Jasprit Bumrah       10         5
2     Ravindra Jadeja      35         4
3     Rohit Sharma         45         2
4     Virat Kohli          82         0
```

---

### Q10. Write a C program to generate the following series using function:
**Sum = 1 + x/2! + x²/3! + x³/4! + ... + xⁿ/n!**

```c
#include <stdio.h>

// Function to calculate factorial
long int factorial(int n) {
    int i;
    long int fact = 1;
    for (i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

// Function to calculate power
float power(float x, int n) {
    int i;
    float result = 1;
    for (i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}

// Function to calculate the series sum
float seriesSum(float x, int n) {
    int i;
    float sum = 1;   // first term is 1

    for (i = 1; i <= n; i++) {
        sum = sum + power(x, i) / factorial(i + 1);
    }

    return sum;
}

int main() {
    float x, result;
    int n;

    printf("Enter value of x: ");
    scanf("%f", &x);

    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    result = seriesSum(x, n);

    printf("\nSum = 1");
    int i;
    for (i = 1; i <= n; i++) {
        printf(" + x^%d/%d!", i, i+1);
    }
    printf("\nSum = %.4f\n", result);

    return 0;
}
```

**Sample Output:**
```
Enter value of x: 2
Enter number of terms (n): 4

Sum = 1 + x^1/2! + x^2/3! + x^3/4! + x^4/5!
Sum = 1 + 2/2 + 4/6 + 8/24 + 16/120
Sum = 2.8
```

---

### Q11. Define SDLC. Explain software process models.

#### SDLC (Software Development Life Cycle)
SDLC is a structured process or framework used for **planning, creating, testing, and delivering** software. It defines a series of steps that guide the development of software from beginning to end.

**Phases of SDLC:**

| Phase | Description |
|-------|-------------|
| 1. Requirement Analysis | Gather what the user needs |
| 2. System Design | Plan architecture, database, UI |
| 3. Implementation (Coding) | Write actual code |
| 4. Testing | Find and fix bugs |
| 5. Deployment | Release to users |
| 6. Maintenance | Update and improve after release |

---

#### Software Process Models

Software process models define **how the SDLC phases are organized and executed**.

---

**1. Waterfall Model**

The oldest and simplest model. Each phase must be fully completed before moving to the next.

```
Requirement → Design → Coding → Testing → Deployment → Maintenance
```

| Advantages | Disadvantages |
|-----------|---------------|
| Simple and easy to understand | No going back to previous phase |
| Clear documentation | Not suitable for changing requirements |
| Works well for small projects | Testing done very late |

---

**2. Iterative Model**

Software is built in **repeated cycles** (iterations). Each iteration produces a working version.

```
Plan → Design → Build → Test → (repeat until complete)
```

| Advantages | Disadvantages |
|-----------|---------------|
| Early working software | Requires more planning |
| Easier to add changes | Can be complex to manage |

---

**3. Spiral Model**

Combines Waterfall and Iterative models. Each cycle (spiral) includes **risk analysis**.

```
Planning → Risk Analysis → Engineering → Evaluation → (next spiral)
```

| Advantages | Disadvantages |
|-----------|---------------|
| Good for large, risky projects | Expensive |
| Risk is managed at each stage | Requires expert risk assessment |

---

**4. Agile Model**

Focuses on **fast, small incremental releases** with constant customer feedback.

- Software is delivered in small chunks called **sprints** (1-4 weeks).
- Customer is involved throughout development.
- Changes are welcomed at any stage.

| Advantages | Disadvantages |
|-----------|---------------|
| Very flexible | Less documentation |
| Customer gets working software quickly | Hard to predict final cost |
| Easy to handle changes | Requires active customer involvement |

---

**5. V-Model (Verification and Validation)**

An extension of the Waterfall model. Each development phase has a corresponding **testing phase**.

```
Requirements ←→ Acceptance Testing
System Design ←→ System Testing
Architecture ←→ Integration Testing
Coding ←→ Unit Testing
```

| Advantages | Disadvantages |
|-----------|---------------|
| Testing planned from beginning | Expensive |
| Good for safety-critical systems | Not flexible for changing requirements |

---

#### Summary Comparison

| Model | Best For | Key Feature |
|-------|----------|-------------|
| Waterfall | Simple, fixed projects | Sequential phases |
| Iterative | Medium projects | Repeated cycles |
| Spiral | Large, risky projects | Risk analysis each cycle |
| Agile | Dynamic, changing projects | Fast sprints with feedback |
| V-Model | Safety critical projects | Testing at every stage |

---
*End of Solutions*
