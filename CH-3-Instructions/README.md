# CHAPTER 3: INSTRUCTION & OPERATORS

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![GCC](https://img.shields.io/badge/Compiler-GCC_/_Clang-FCC624?style=for-the-badge&logo=gnubash&logoColor=black)](https://gcc.gnu.org/)
[![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)](https://code.visualstudio.com/)
[![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)](https://git-scm.com/)
[![License](https://img.shields.io/badge/License-MIT-2ea44f?style=for-the-badge)](LICENSE)

> Master how C executes code — exploring Type Declaration Instructions, Arithmetic Operations, Type Conversion, Operator Precedence & Associativity, Relational & Logical Operators, and step-by-step problem-solving.

---

## Table of Contents

- [Types of Instructions in C](#types-of-instructions-in-c)
- [1. Type Declaration Instructions](#1-type-declaration-instructions)
- [2. Arithmetic Instructions](#2-arithmetic-instructions)
- [3. Control Instructions](#3-control-instructions)
- [Type Conversion (Implicit vs Explicit)](#type-conversion-implicit-vs-explicit)
- [Complete Operator Precedence Table](#complete-operator-precedence-table)
- [Operator Precedence & Associativity in Action](#operator-precedence--associativity-in-action)
- [Comprehensive Classification of Operators](#comprehensive-classification-of-operators)
- [Practice Problems and Solutions](#practice-problems-and-solutions)
- [License](#license)

---

## Types of Instructions in C

**Instructions** are individual statements executed by the computer. In C, instructions are classified into three primary categories:

```text
┌─────────────────────────────────────────────────────────────┐
│                    Instructions in C                        │
├──────────────────────────────┬──────────────────────────────┤
│ 1. Type Declarations         │ Declares variable types      │
│ 2. Arithmetic Instructions   │ Mathematical computations    │
│ 3. Control Instructions      │ Flow of program execution    │
└──────────────────────────────┴──────────────────────────────┘
```

---

## 1. Type Declaration Instructions

Variables must always be **declared before they are used**:

### Valid vs Invalid Declarations:

| Valid Declarations | Invalid Declarations | Reason for Error |
| :--- | :--- | :--- |
| `int a = 22;` | `int a = 22, b = a;` | Valid if sequential, invalid if `b` uses undeclared variable |
| `int a, b, c; a = b = c = 1;` | `int a = b = c = 1;` | `b` and `c` are not declared yet |
| `int d = 1, e;` | `int d = 1; e = 2;` | `e` is missing a data type |
| `char name[] = "John";` | `name = "John";` | Missing data type declaration |

```c
#include <stdio.h>

int main() {
    // Valid declarations
    int a = 22;
    int b = a;
    int c = b + 1;
    int d = 1, e;

    int x, y, z;
    x = y = z = 10; // Chained assignment after declaration

    return 0;
}
```

---

## 2. Arithmetic Instructions

Arithmetic instructions perform calculations using operands and operators:

$$\text{Variable (LHS)} = \text{Operand 1} \quad [\text{Operator}] \quad \text{Operand 2} \quad (\text{RHS})$$

> **Critical Rule**: There must always be a **single variable on the Left-Hand Side (LHS)**.

| Valid Arithmetic Operations | Invalid Operations | Reason |
| :--- | :--- | :--- |
| `a = b + c;` | `b + c = a;` | LHS cannot be an expression |
| `a = b * c;` | `a = bc;` | Missing `*` multiplication operator |
| `a = b / c;` | `a = b ^ c;` | `^` is bitwise XOR, not power |
| `a = pow(b, c);` | `a = b ** c;` | `**` is not valid syntax in C |

### Modulus Operator (`%`)
The modulus operator `%` returns the **remainder** of integer division. The sign of the result matches the sign of the numerator (left operand):

- `8 % 3 = 2`
- `3 % 2 = 1`
- `-3 % 2 = -1`
- `3 % -2 = 1`

---

## 3. Control Instructions

Control instructions manage the execution order of statements:

1. **Sequence Control**: Statements run line-by-line in the exact order they appear.
2. **Decision Control**: Executes specific code paths based on conditions (`if`, `else if`, `else`, `switch`).
3. **Loop Control**: Repeats a code block until a condition is met (`for`, `while`, `do-while`).
4. **Case Control**: Selects execution branches based on variable values (`switch-case`).

---

## Type Conversion (Implicit vs Explicit)

When operands of different data types are used in an expression:

### Implicit Conversion Rules:
- `int` $\text{op}$ `int` $\rightarrow$ `int` (e.g. `3 / 2` $\rightarrow$ `1`)
- `int` $\text{op}$ `float` $\rightarrow$ `float` (e.g. `3.0 / 2` $\rightarrow$ `1.500000`)
- `float` $\text{op}$ `float` $\rightarrow$ `float` (e.g. `3.0 / 2.0` $\rightarrow$ `1.500000`)

### Explicit Type Conversion (Type Casting):
Forces a value to be treated as another type:

```c
#include <stdio.h>

int main() {
    int a = (int)1.999999; // Truncates decimal part -> 1
    printf("Value of a: %d\n", a);
    return 0;
}
```

---

## Complete Operator Precedence Table

When multiple operators appear in a single expression, precedence determines which operation runs first:

| Priority | Category | Operators | Associativity |
| :---: | :--- | :--- | :---: |
| **1** | Logical NOT / Unary | `!`, `++`, `--`, `+`, `-` | Right to Left |
| **2** | Multiplicative | `*`, `/`, `%` | Left to Right |
| **3** | Additive | `+`, `-` | Left to Right |
| **4** | Relational (Inequalities) | `<`, `<=`, `>`, `>=` | Left to Right |
| **5** | Equality | `==`, `!=` | Left to Right |
| **6** | Logical AND | `&&` | Left to Right |
| **7** | Logical OR | `\|\|` | Left to Right |
| **8** | Assignment | `=`, `+=`, `-=`, `*=`, `/=`, `%=` | Right to Left |

---

## Operator Precedence & Associativity in Action

When operators share the **same precedence level**, **associativity (Left to Right)** decides the evaluation order:

### Example 1:
$$\text{Expression: } x = 4 \times 3 / 6 \times 2$$

1. $4 \times 3 = 12$
2. $12 / 6 = 2$
3. $2 \times 2 = 4$
4. **Final Result:** $x = 4$

### Example 2:
$$\text{Expression: } A = 4 + 9 \times 10$$

1. Multiplicative has higher priority: $9 \times 10 = 90$
2. Additive: $4 + 90 = 94$
3. **Final Result:** $A = 94$

---

## Comprehensive Classification of Operators

### 1. Relational Operators (True = 1, False = 0)

| Operator | Meaning | Example (`a = 5, b = 10`) | Result |
| :---: | :--- | :--- | :---: |
| `==` | Equal to | `a == b` | `0` (False) |
| `!=` | Not equal to | `a != b` | `1` (True) |
| `>` | Greater than | `a > b` | `0` (False) |
| `<` | Less than | `a < b` | `1` (True) |
| `>=` | Greater than or equal to | `a >= 5` | `1` (True) |
| `<=` | Less than or equal to | `b <= 10` | `1` (True) |

### 2. Logical Operators

| Operator | Name | Behavior |
| :---: | :--- | :--- |
| `&&` | **Logical AND** | Returns `1` only if **both** operands are non-zero (True). |
| `\|\|` | **Logical OR** | Returns `1` if **at least one** operand is non-zero (True). |
| `!` | **Logical NOT** | Inverts the truth value (`!1` $\rightarrow$ `0`, `!0` $\rightarrow$ `1`). |

### 3. Compound Assignment Operators

| Operator | Example | Equivalent To |
| :---: | :--- | :--- |
| `+=` | `a += 2;` | `a = a + 2;` |
| `-=` | `a -= 3;` | `a = a - 3;` |
| `*=` | `a *= 4;` | `a = a * 4;` |
| `/=` | `a /= 2;` | `a = a / 2;` |
| `%=` | `a %= 3;` | `a = a % 3;` |

---

## Practice Problems and Solutions

### Problem 1: Explicit Type Casting
What will be stored in variable `a`?

```c
#include <stdio.h>

int main() {
    int a = (int)1.999999;
    printf("Value of a: %d\n", a); // Output: 1 (decimal truncated)
    return 0;
}
```

---

### Problem 2: Operator Precedence Evaluations

```c
#include <stdio.h>

int main() {
    int r1 = 5 * 2 - 2 * 3;     // (10) - (6) = 4
    int r2 = 5 * 2 / 2 * 3;     // (10 / 2) * 3 = 5 * 3 = 15
    int r3 = 5 * (2 / 2) * 3;   // 5 * (1) * 3 = 15
    int r4 = 5 + 2 / 2 * 3;     // 5 + (1 * 3) = 5 + 3 = 8

    printf("5 * 2 - 2 * 3   = %d\n", r1);
    printf("5 * 2 / 2 * 3   = %d\n", r2);
    printf("5 * (2 / 2) * 3 = %d\n", r3);
    printf("5 + 2 / 2 * 3   = %d\n", r4);
    return 0;
}
```

---

### Problem 3: Check Even / Divisibility by 2
Write a C program to check whether an integer is divisible by 2.

```c
#include <stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    // Prints 1 if divisible by 2 (Even), 0 if odd
    printf("Is Divisible by 2 (1 = Yes, 0 = No): %d\n", x % 2 == 0);
    return 0;
}
```

---

### Problem 4: Validity Analysis

| Code Snippet | Valid / Invalid | Explanation |
| :--- | :---: | :--- |
| `int a = 8 ^ 8;` | **Valid** | `^` is bitwise XOR, evaluates to `0` |
| `int x; int y = x;` | **Valid** | Sequential declaration and assignment |
| `int x, y = x;` | **Invalid** | `x` is used before its value is initialized |
| `char stars = '**';` | **Invalid** | Character constant can only hold 1 character |

---

### Problem 5: Logical Condition Checks

```c
#include <stdio.h>

int main() {
    // (a) Sunday and Snowing
    int isSunday = 1;
    int isSnowing = 1;
    printf("Sunday & Snowing: %d\n", isSunday && isSnowing); // Output: 1

    // (b) Check if a number is a 2-digit number (> 9 and < 100)
    int num;
    printf("Enter a number to check 2-digit status: ");
    scanf("%d", &num);
    printf("Is 2-digit number: %d\n", (num > 9 && num < 100));

    return 0;
}
```

---

## License

This project is licensed under the [MIT License](LICENSE).

---

**Made with ❤️ for Beginners** • **Author: Adesh Srivastava (Tanmay)**
```

