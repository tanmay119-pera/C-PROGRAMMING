# CHAPTER 2 : VARIABLES & DATA TYPES

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![GCC](https://img.shields.io/badge/Compiler-GCC_/_Clang-FCC624?style=for-the-badge&logo=gnubash&logoColor=black)](https://gcc.gnu.org/)
[![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)](https://code.visualstudio.com/)
[![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)](https://git-scm.com/)
[![License](https://img.shields.io/badge/License-MIT-2ea44f?style=for-the-badge)](LICENSE)

> A deep dive into memory fundamentals in C — understanding variables, standard data types, 32 reserved keywords, constants, format specifiers, and user input/output operations using `printf()` and `scanf()`.

---

## Table of Contents

- [What is a Variable?](#what-is-a-variable)
- [Rules for Naming Variables](#rules-for-naming-variables)
- [Data Types & Memory Sizes](#data-types--memory-sizes)
- [Constants in C](#constants-in-c)
- [The 32 C Keywords](#the-32-c-keywords)
- [Format Specifiers](#format-specifiers)
- [Input and Output (printf and scanf)](#input-and-output-printf-and-scanf)
- [Practice Problems and Solutions](#practice-problems-and-solutions)
- [License](#license)

---

## What is a Variable?

A **variable** is a named location in the computer's memory (RAM) used to hold data that can change during program execution.

```text
Memory (RAM)
┌──────────────┬──────────────┬──────────────┐
│  Variable    │   Data Type  │ Stored Value │
├──────────────┼──────────────┼──────────────┤
│  age         │   int        │ 24           │
│  pi          │   float      │ 3.14         │
│  star        │   char       │ '*'          │
└──────────────┴──────────────┴──────────────┘
```

### Syntax for Variable Declaration & Initialization:

```c
// Declaration: tells compiler the data type and name
int age;

// Initialization: assigns a value to the variable
age = 22;

// Declaration + Initialization in a single line:
float pi = 3.14;
char star = '*';

// Modifying a variable value:
age = 24; // Old value 22 is overwritten with 24
```

---

## Rules for Naming Variables

Identifiers in C must adhere to the following rules:

1. **Starting Character**: Must start with an alphabet letter (`a-z`, `A-Z`) or an underscore (`_`).
2. **No Leading Digits**: Cannot begin with a number (e.g. `1number` is invalid, but `number1` is valid).
3. **Allowed Characters**: Can contain letters, digits, and underscores only.
4. **No Special Symbols or Spaces**: Commas, blank spaces, and symbols (`$`, `@`, `-`, `#`) are prohibited.
5. **Case Sensitivity**: C is strictly case-sensitive (`age`, `Age`, and `AGE` refer to three completely different variables).
6. **No Reserved Keywords**: You cannot use C keywords (e.g. `int`, `float`, `return`, `if`) as variable names.
7. **Best Practice**: Variable names should be descriptive and meaningful (e.g. `final_price` instead of `fp`).

---

## Data Types & Memory Sizes

Data types specify the type and size of data a variable can store:

| Data Type | Keyword | Size (Bytes) | Range / Description | Format Specifier |
| :--- | :--- | :---: | :--- | :---: |
| **Character** | `char` | 1 | `-128` to `127` (ASCII characters) | `%c` |
| **Unsigned Character** | `unsigned char` | 1 | `0` to `255` | `%c` |
| **Short Integer** | `short int` | 2 | `-32,768` to `32,767` | `%hd` |
| **Integer** | `int` | 2 or 4 | `-2,147,483,648` to `2,147,483,647` | `%d` or `%i` |
| **Unsigned Integer** | `unsigned int` | 2 or 4 | `0` to `4,294,967,295` | `%u` |
| **Long Integer** | `long int` | 4 or 8 | Large integer values | `%ld` |
| **Floating Point** | `float` | 4 | Single-precision decimal (~6-7 decimal digits) | `%f` |
| **Double Precision** | `double` | 8 | Double-precision decimal (~15 decimal digits) | `%lf` |
| **Extended Precision** | `long double` | 10, 12 or 16 | High-precision scientific computations | `%Lf` |

---

## Constants in C

A **constant** is a fixed value that cannot be altered during program execution.

### Types of Constants:
- **Integer Constants**: `10`, `25`, `0`, `-5`
- **Real (Floating-point) Constants**: `3.14`, `-0.005`, `2.5`
- **Character Constants**: `'a'`, `'Z'`, `'#'`, `'7'` (enclosed in single quotes)

### Creating Constants in Code:

```c
#include <stdio.h>
#define PI_MACRO 3.14159  // 1. Using Preprocessor Macro

int main() {
    const float PI = 3.14;        // 2. Using 'const' keyword
    const int MAX_USERS = 100;
    const char HASH = '#';

    // PI = 3.1415; // ERROR: assignment of read-only variable 'PI'
    return 0;
}
```

---

## The 32 C Keywords

Keywords are reserved identifiers that have predefined meanings to the compiler. They cannot be used as variable or function names:

```text
┌───────────┬───────────┬───────────┬───────────┐
│ auto      │ break     │ case      │ char      │
│ const     │ continue  │ default   │ do        │
│ double    │ else      │ enum      │ extern    │
│ float     │ for       │ goto      │ if        │
│ int       │ long      │ register  │ return    │
│ short     │ signed    │ sizeof    │ static    │
│ struct    │ switch    │ typedef   │ union     │
│ unsigned  │ void      │ volatile  │ while     │
└───────────┴───────────┴───────────┴───────────┘
```

---

## Format Specifiers

Format specifiers act as placeholders inside `printf()` and `scanf()` to tell the compiler which data type to format or read:

| Specifier | Data Type | Example Usage | Output |
| :---: | :--- | :--- | :--- |
| `%d` / `%i` | `int` | `printf("Age: %d", 22);` | `Age: 22` |
| `%f` | `float` | `printf("Pi: %.2f", 3.14159);` | `Pi: 3.14` |
| `%c` | `char` | `printf("Symbol: %c", '*');` | `Symbol: *` |
| `%lf` | `double` | `printf("Value: %lf", 99.987);` | `Value: 99.987000` |
| `%s` | `string` | `printf("Hello %s", "World");` | `Hello World` |

---

## Input and Output (printf and scanf)

### 1. Printing with `printf()`

```c
#include <stdio.h>

int main() {
    int age = 22;
    float pi = 3.14;
    char star = '*';

    printf("Age is %d\n", age);
    printf("Value of pi is %.2f\n", pi);
    printf("Character is %c\n", star);
    return 0;
}
```

### 2. Taking User Input with `scanf()`

`scanf()` reads formatted input from standard input (the keyboard). The **`&` (Address-of)** operator passes the exact memory address of the variable so `scanf` can store the value directly into RAM:

```c
#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age); // '&age' points to the memory location of variable age

    printf("Your age is: %d\n", age);
    return 0;
}
```

---

## Practice Problems and Solutions

### Problem 1: Sum of Two Numbers
Write a C program to take two integers from the user and calculate their sum.

```c
#include <stdio.h>

int main() {
    int a, b, sum;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    sum = a + b;
    printf("Sum of %d and %d is: %d\n", a, b, sum);
    return 0;
}
```

---

### Problem 2: Calculate Area of a Square
Write a C program to calculate the area of a square given its side length ($Area = side \times side$).

```c
#include <stdio.h>

int main() {
    float side, area;

    printf("Enter the side of the square: ");
    scanf("%f", &side);

    area = side * side;
    printf("Area of the square is: %.2f\n", area);
    return 0;
}
```

---

### Problem 3: Calculate Area of a Circle
Write a C program to calculate the area of a circle given its radius ($Area = \pi \times r^2$).

```c
#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    printf("Area of the circle is: %.2f\n", area);
    return 0;
}
```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

**Made with ❤️ for Beginners** • **Author: Adesh Srivastava (Tanmay)**

