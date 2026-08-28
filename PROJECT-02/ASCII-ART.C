/*                                    PROJECT 2: ASCII Art Pattern Generator 

 *  A beginner-friendly C program that prints ASCII art patterns
 *  using nested loops.
 *
 *  Patterns included:
 *    1. Right Triangle
 *    2. Pyramid
 *    3. Diamond
 *    4. Hollow Square
 *    5. Christmas Tree
 *
 *  Concepts used: functions, function prototypes, nested for
 *                 loops, switch-case, if-else, do-while loop
 
 */

#include <stdio.h>

// ---------- Function prototypes ----------
// Declaring these up top lets main() call them even though
// their full code appears later in the file.
void printRightTriangle(int rows);
void printPyramid(int rows);
void printDiamond(int rows);
void printHollowSquare(int side);
void printChristmasTree(int rows);

int main() {
    int choice, size;
    char again;

    do {
        // -------- Display menu --------
        printf("\n===== ASCII Art Generator =====\n");
        printf("1. Right Triangle\n");
        printf("2. Pyramid\n");
        printf("3. Diamond\n");
        printf("4. Hollow Square\n");
        printf("5. Christmas Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter size (number of rows): ");
        scanf("%d", &size);

        // Basic validation - a pattern needs at least 1 row
        if (size <= 0) {
            printf("Size must be a positive number.\n");
        } else {
            // -------- Route to the right pattern function --------
            switch (choice) {
                case 1:
                    printRightTriangle(size);
                    break;
                case 2:
                    printPyramid(size);
                    break;
                case 3:
                    printDiamond(size);
                    break;
                case 4:
                    printHollowSquare(size);
                    break;
                case 5:
                    printChristmasTree(size);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        }

        // -------- Ask to continue --------
        printf("\nGenerate another pattern? (y/n): ");
        scanf(" %c", &again); // space skips leftover newline in input buffer

    } while (again == 'y' || again == 'Y');

    return 0;
}

// ------------------------------------------------------------
// Right Triangle
// Row i simply has i stars, so the count grows by 1 each row.
// Example (rows=4):
// *
// * *
// * * *
// * * * *
// ------------------------------------------------------------
void printRightTriangle(int rows) {
    printf("\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// ------------------------------------------------------------
// Pyramid
// Each row needs (rows - i) leading spaces to center it, then
// (2*i - 1) stars. The odd-number sequence (1,3,5,7...) is what
// makes the shape widen evenly on both sides.
// Example (rows=4):
//    *
//   ***
//  *****
// *******
// ------------------------------------------------------------
void printPyramid(int rows) {
    printf("\n");
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        for (int star = 1; star <= (2 * i - 1); star++) {
            printf("*");
        }
        printf("\n");
    }
}

// ------------------------------------------------------------
// Diamond
// A diamond is just a pyramid on top and an upside-down pyramid
// below it. The bottom half reuses the same space/star logic,
// just counting rows down instead of up.
// ------------------------------------------------------------
void printDiamond(int rows) {
    printf("\n");

    // Top half - identical logic to printPyramid()
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++)
            printf(" ");
        for (int star = 1; star <= (2 * i - 1); star++)
            printf("*");
        printf("\n");
    }

    // Bottom half - mirror image, shrinking back down
    for (int i = rows - 1; i >= 1; i--) {
        for (int space = 1; space <= rows - i; space++)
            printf(" ");
        for (int star = 1; star <= (2 * i - 1); star++)
            printf("*");
        printf("\n");
    }
}

// ------------------------------------------------------------
// Hollow Square
// Print a star only if we're on the first/last row OR the
// first/last column - everywhere else stays blank.
// ------------------------------------------------------------
void printHollowSquare(int side) {
    printf("\n");
    for (int i = 1; i <= side; i++) {
        for (int j = 1; j <= side; j++) {
            if (i == 1 || i == side || j == 1 || j == side) {
                printf("* ");
            } else {
                printf("  "); // inside of the square stays empty
            }
        }
        printf("\n");
    }
}

// ------------------------------------------------------------
// Christmas Tree
// The tree body reuses the pyramid logic, then we add a short
// trunk underneath made of '|' characters, centered under the
// widest row.
// ------------------------------------------------------------
void printChristmasTree(int rows) {
    printf("\n");

    // Tree body (same shape as the pyramid)
    for (int i = 1; i <= rows; i++) {
        for (int space = 1; space <= rows - i; space++)
            printf(" ");
        for (int star = 1; star <= (2 * i - 1); star++)
            printf("*");
        printf("\n");
    }

    // Trunk: a couple of centered '|' rows below the tree body
    for (int t = 1; t <= 2; t++) {
        for (int space = 1; space <= rows - 1; space++)
            printf(" ");
        printf("|\n");
    }
}