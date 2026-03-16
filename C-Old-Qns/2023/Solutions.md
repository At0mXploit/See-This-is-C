# BCA Exam Solutions — 2023
## Group B & Group C

---

## GROUP B — Attempt any SIX questions [6×5=30]

---

### Q2. Define programming technique. Differentiate between top-down and bottom-up approach with suitable example.

#### Programming Technique
A programming technique is a method or approach used to design and write a program to solve a problem. It defines how a program is structured and developed.

Common techniques:
- Procedural Programming
- Object Oriented Programming
- Top-Down Approach
- Bottom-Up Approach

#### Top-Down Approach
- The program is broken down from the **main problem** into smaller sub-problems.
- Start with the main module and divide it into smaller modules.
- Uses **stepwise refinement**.
- Common in structured/procedural programming.

**Example:**
```
Main Program
├── Read Input
├── Calculate Result
│   ├── Add numbers
│   └── Find average
└── Display Output
```

#### Bottom-Up Approach
- Start by building **small individual modules** first.
- Then combine them to build the full program.
- Common in Object Oriented Programming.

**Example:**
```
add()       → built first
subtract()  → built first
multiply()  → built first
        ↓
   Calculator Program (combined at end)
```

#### Difference Table

| Feature | Top-Down | Bottom-Up |
|---------|----------|-----------|
| Start from | Main problem | Small modules |
| Direction | Big → Small | Small → Big |
| Approach | Divide and conquer | Combine and build |
| Testing | Done at end | Each module tested first |
| Used in | Procedural programming | Object Oriented Programming |
| Example | C language programs | Java, C++ programs |

---

### Q3. Define Data Types. Explain different data types available in C programming.

#### Data Types
A data type defines the **type of data** a variable can store and the **size of memory** it occupies.

#### Data Types in C

**1. Primary (Basic) Data Types**

| Data Type | Size | Range | Example |
|-----------|------|-------|---------|
| `int` | 2 or 4 bytes | -32768 to 32767 | `int x = 10;` |
| `float` | 4 bytes | 3.4e-38 to 3.4e+38 | `float f = 3.14;` |
| `double` | 8 bytes | 1.7e-308 to 1.7e+308 | `double d = 3.14159;` |
| `char` | 1 byte | -128 to 127 | `char c = 'A';` |
| `void` | 0 bytes | No value | `void func(){}` |

**2. Derived Data Types**
Derived from primary data types.
- **Array** — collection of same type: `int arr[5];`
- **Pointer** — stores address: `int *p;`
- **Function** — returns a value

**3. User Defined Data Types**
Defined by the programmer.
- **struct** — group different data types
- **union** — shared memory
- **enum** — set of named integer constants
- **typedef** — rename existing type

```c
#include <stdio.h>

int main() {
    int age = 20;
    float height = 5.7;
    char grade = 'A';
    double salary = 45000.50;

    printf("Age    : %d\n", age);
    printf("Height : %.1f\n", height);
    printf("Grade  : %c\n", grade);
    printf("Salary : %.2lf\n", salary);

    return 0;
}
```

---

### Q4. Explain bitwise and conditional operator with example.

#### Bitwise Operators
Bitwise operators work on **binary bits** of integer values.

| Operator | Name | Description |
|----------|------|-------------|
| `&` | AND | 1 if both bits are 1 |
| `\|` | OR | 1 if at least one bit is 1 |
| `^` | XOR | 1 if bits are different |
| `~` | NOT | Flips all bits |
| `<<` | Left Shift | Shifts bits to left |
| `>>` | Right Shift | Shifts bits to right |

```c
#include <stdio.h>

int main() {
    int a = 6;   // binary: 0110
    int b = 3;   // binary: 0011

    printf("a & b  = %d\n", a & b);   // 0010 = 2
    printf("a | b  = %d\n", a | b);   // 0111 = 7
    printf("a ^ b  = %d\n", a ^ b);   // 0101 = 5
    printf("~a     = %d\n", ~a);       // -7
    printf("a << 1 = %d\n", a << 1);  // 1100 = 12
    printf("a >> 1 = %d\n", a >> 1);  // 0011 = 3

    return 0;
}
```
**Output:**
```
a & b  = 2
a | b  = 7
a ^ b  = 5
~a     = -7
a << 1 = 12
a >> 1 = 3
```

#### Conditional (Ternary) Operator
The conditional operator is the only **ternary operator** in C (takes 3 operands).

**Syntax:** `variable = (condition) ? value_if_true : value_if_false;`

```c
#include <stdio.h>

int main() {
    int a, b, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    max = (a > b) ? a : b;
    printf("Largest = %d\n", max);

    // Check even or odd
    printf("%d is %s\n", a, (a % 2 == 0) ? "Even" : "Odd");

    return 0;
}
```
**Sample Output:**
```
Enter two numbers: 10 20
Largest = 20
10 is Even
```

---

### Q5. Write a program to print the following pattern using loop.
```
U
UN
UNI
UNIV
UNIVE
UNIVER
UNIVERS
UNIVERSI
UNIVERSIT
UNIVERSITY
```

```c
#include <stdio.h>

int main() {
    char word[] = "UNIVERSITY";
    int i, j;
    int len = 10;

    for (i = 1; i <= len; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", word[j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Output:**
```
U
UN
UNI
UNIV
UNIVE
UNIVER
UNIVERS
UNIVERSI
UNIVERSIT
UNIVERSITY
```

---

### Q6. Define Array. Write a program to search an element from an array of 10 numbers.

#### Array
An array is a collection of **same data type** elements stored in **continuous memory locations**. Elements are accessed using an **index** starting from 0.

**Syntax:** `datatype arrayname[size];`

**Example:** `int arr[5] = {10, 20, 30, 40, 50};`

- `arr[0]` = 10, `arr[1]` = 20, etc.

#### Program: Linear Search in Array of 10 Numbers

```c
#include <stdio.h>

int main() {
    int arr[10], i, key, found;

    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    found = 0;
    for (i = 0; i < 10; i++) {
        if (arr[i] == key) {
            printf("%d found at position %d\n", key, i+1);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("%d not found in array.\n", key);
    }

    return 0;
}
```

**Sample Output:**
```
Enter 10 numbers:
Element 1: 5
Element 2: 12
Element 3: 33
...
Element 10: 90
Enter number to search: 33
33 found at position 3
```

---

### Q7. Define function. Write a program that finds x^y using function.

#### Function
A function is a block of code that performs a specific task. It can be called multiple times from anywhere in the program.

**Advantages:**
- Reusability of code
- Easy to debug
- Program becomes organized

**Syntax:**
```c
returnType functionName(parameters) {
    // body
    return value;
}
```

#### Program: Find x^y using function

```c
#include <stdio.h>

int power(int x, int y) {
    int result = 1, i;
    for (i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}

int main() {
    int x, y, ans;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter exponent (y): ");
    scanf("%d", &y);

    ans = power(x, y);

    printf("%d ^ %d = %d\n", x, y, ans);

    return 0;
}
```

**Sample Output:**
```
Enter base (x): 2
Enter exponent (y): 8
2 ^ 8 = 256
```

---

### Q8. Define pointer. Write a program to find sum of 10 numbers using pointer.

#### Pointer
A pointer is a variable that stores the **memory address** of another variable.

```c
int x = 10;
int *p = &x;    // p stores address of x
printf("%d", *p);  // prints 10
```

- `&x` — address of x
- `*p` — value at address stored in p

#### Program: Sum of 10 numbers using pointer

```c
#include <stdio.h>

int main() {
    int arr[10], i;
    int *p;
    int sum = 0;

    p = arr;   // pointer points to first element of array

    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", p+i);
    }

    for (i = 0; i < 10; i++) {
        sum = sum + *(p+i);
    }

    printf("Sum = %d\n", sum);

    return 0;
}
```

**Sample Output:**
```
Enter 10 numbers:
Number 1: 10
Number 2: 20
Number 3: 30
Number 4: 40
Number 5: 50
Number 6: 5
Number 7: 15
Number 8: 25
Number 9: 35
Number 10: 45
Sum = 275
```

---

## GROUP C — Attempt any TWO questions [2×10=20]

---

### Q9. What are the characteristics of a good program? Explain types of language processors. Explain any two system design tools.

#### Characteristics of a Good Program
1. **Correctness** — Gives correct output for all valid inputs.
2. **Reliability** — Works consistently without crashing.
3. **Efficiency** — Uses less memory and runs fast.
4. **Readability** — Code is easy to understand.
5. **Maintainability** — Easy to update and fix.
6. **Portability** — Can run on different machines/OS.
7. **User Friendly** — Easy to use interface.
8. **Well Documented** — Has proper comments and documentation.

#### Types of Language Processors

**1. Assembler**
- Converts **Assembly language** code into machine code (binary).
- Assembly language uses mnemonics like MOV, ADD, SUB.
- Output is called object code.

**2. Compiler**
- Converts entire **high-level language** (like C) into machine code at once.
- Shows all errors after complete scanning.
- Faster execution.
- Example: GCC compiler for C.

**3. Interpreter**
- Converts **high-level language** into machine code **line by line**.
- Stops at the first error it finds.
- Slower than compiler.
- Example: Python interpreter.

| Feature | Compiler | Interpreter |
|---------|----------|-------------|
| Translation | Whole program at once | Line by line |
| Speed | Faster | Slower |
| Error display | All errors at end | Stops at first error |
| Example | C, C++ | Python, BASIC |

#### Two System Design Tools

**1. Flowchart**
A flowchart is a **diagram** that shows the steps of a program using symbols.

| Symbol | Shape | Meaning |
|--------|-------|---------|
| Oval | Start/End | Terminal |
| Rectangle | Process | Calculation or action |
| Diamond | Decision | Yes/No condition |
| Parallelogram | Input/Output | Read or print |
| Arrow | Flow line | Direction of flow |

**Example:** Flowchart to find largest of two numbers:
```
START → Input A, B → Is A > B? → Yes → Print A → END
                               → No  → Print B → END
```

**2. Algorithm**
An algorithm is a **step-by-step procedure** written in plain English to solve a problem before coding.

**Example:** Algorithm to find sum of two numbers:
```
Step 1: Start
Step 2: Read values of A and B
Step 3: Calculate Sum = A + B
Step 4: Print Sum
Step 5: Stop
```

---

### Q10. Define file opening modes. Write a program to delete a specific record from a file.

#### File Opening Modes

| Mode | Meaning |
|------|---------|
| `"r"` | Open for reading. File must exist. |
| `"w"` | Open for writing. Creates new file or overwrites existing. |
| `"a"` | Open for appending. Adds data at end of file. |
| `"r+"` | Open for both reading and writing. File must exist. |
| `"w+"` | Open for reading and writing. Creates or overwrites. |
| `"a+"` | Open for reading and appending. |
| `"rb"` | Open binary file for reading. |
| `"wb"` | Open binary file for writing. |

#### Program: Delete a Specific Record from a File

```c
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp, *temp;
    char line[100];
    char del[100];

    fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("Current records in file:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    printf("\nEnter record to delete: ");
    scanf(" ");
    gets(del);

    fp = fopen("records.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline for comparison
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, del) != 0) {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");

    printf("Record deleted successfully!\n");

    printf("\nUpdated records:\n");
    fp = fopen("records.txt", "r");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}
```

**How it works:**
1. Opens `records.txt` and displays all records.
2. Asks user which record to delete.
3. Copies all records EXCEPT the deleted one into `temp.txt`.
4. Deletes original file using `remove()`.
5. Renames `temp.txt` back to `records.txt` using `rename()`.

**Sample records.txt:**
```
Ram Sharma
Sita Thapa
Hari Adhikari
Gita Karki
```

**Sample Run:**
```
Current records in file:
Ram Sharma
Sita Thapa
Hari Adhikari
Gita Karki

Enter record to delete: Sita Thapa
Record deleted successfully!

Updated records:
Ram Sharma
Hari Adhikari
Gita Karki
```

---

### Q11. Differentiate between structure and union. Create a structure named Student with members roll no, name, address. Write a program that displays name of only those students whose address is Kathmandu.

#### Structure vs Union

| Feature | Structure | Union |
|---------|-----------|-------|
| Keyword | `struct` | `union` |
| Memory | Separate memory for each member | All members share same memory |
| Size | Sum of all members | Size of largest member only |
| Access | All members at same time | Only one member at a time |
| Use | Store complete record | Save memory space |

**Example:**
```c
struct S { int a; float b; };  // size = 4+4 = 8 bytes
union  U { int a; float b; };  // size = 4 bytes (only largest)
```

#### Program: Student Structure with User Input

```c
#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    char address[50];
};

int main() {
    struct Student s[10];
    int i, n;

    printf("How many students? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Student %d:\n", i+1);

        printf("Roll No : ");
        scanf("%d", &s[i].rollno);

        printf("Name    : ");
        scanf(" ");
        gets(s[i].name);

        printf("Address : ");
        gets(s[i].address);
    }

    printf("\n--- Students living in Kathmandu ---\n");

    int found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(s[i].address, "Kathmandu") == 0) {
            printf("Roll No : %d\n", s[i].rollno);
            printf("Name    : %s\n", s[i].name);
            printf("Address : %s\n", s[i].address);
            printf("----------------------------\n");
            found++;
        }
    }

    if (found == 0) {
        printf("No students from Kathmandu.\n");
    } else {
        printf("Total: %d student(s) found.\n", found);
    }

    return 0;
}
```

**Sample Input:**
```
How many students? 4

Enter details of Student 1:
Roll No : 1
Name    : Ram Sharma
Address : Kathmandu

Enter details of Student 2:
Roll No : 2
Name    : Sita Thapa
Address : Pokhara

Enter details of Student 3:
Roll No : 3
Name    : Hari KC
Address : Kathmandu

Enter details of Student 4:
Roll No : 4
Name    : Gita Rai
Address : Butwal
```

**Output:**
```
--- Students living in Kathmandu ---
Roll No : 1
Name    : Ram Sharma
Address : Kathmandu
----------------------------
Roll No : 3
Name    : Hari KC
Address : Kathmandu
----------------------------
Total: 2 student(s) found.
```

---
*End of Solutions*
