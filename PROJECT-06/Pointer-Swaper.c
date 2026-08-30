//!                                        PROJECT -6 : POINTER SWAPPER IN C

/*PROJECT OVERVIEW:

This program demonstrates how to swap two numbers using POINTERS in C.
It's a beginner-friendly project that teaches the fundamentals of:
- Pointers and memory addresses
- Dereferencing pointers
- Pass-by-reference vs Pass-by-value
- Function parameters with pointers

WHY THIS PROJECT MATTERS:
Swapping is one of the most basic operations in programming, used everywhere:
- Sorting algorithms (bubble sort, quick sort, merge sort)
- Data structure operations (tree rotations, array rearrangements)
- Algorithm implementations across DSA concepts

HOW IT WORKS:
Instead of just passing values (which can't be modified), we pass ADDRESSES.
The swap() function then uses these addresses to modify the ACTUAL variables.

DIFFICULTY: Beginner (Foundation level for DSA preparation)
CONCEPTS: Pointers, Functions, Pass-by-Reference, Memory Management*/

#include <stdio.h>

// Function to swap two numbers using pointers
// Parameters: Two pointers to integers (pass-by-reference)
void swap(int *a, int *b) {
    // Dereference the pointers to access the actual values
    // *a means "the value at the address stored in a"
    
    // Create a temporary variable to hold one value during swap
    int temp = *a;      // Copy value from first pointer into temp
    
    *a = *b;            // Put value from second pointer into first location
    
    *b = temp;          // Put original value (stored in temp) into second location
    
    // After this function returns, the original variables are swapped!
}

int main() {
    // Declare two integer variables
    int num1 = 10;
    int num2 = 20;
    
    printf("=== Pointer Swapper Demo ===\n\n");
    
    // Print original values
    printf("Before swap:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    // Call swap function, passing ADDRESSES (&) of the variables
    // & operator gives the address of a variable
    // This is pass-by-reference - the function works on actual variables
    swap(&num1, &num2);
    
    printf("\nAfter swap:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    printf("\n--- Why Pointers Matter ---\n");
    printf("Without pointers, you can't modify variables from inside a function.\n");
    printf("Pointers let you pass the ADDRESS, so the function can change the actual values.\n");
    
    return 0;
}

/* 
=== KEY CONCEPTS ===

1. POINTERS: A pointer is a variable that stores a MEMORY ADDRESS
   - Declaration: int *ptr;
   - & operator: "address of" (gives address of a variable)
   - * operator: "dereference" (access value at that address)

2. PASS-BY-REFERENCE vs PASS-BY-VALUE:
   - Normal function: copies the VALUE (original not changed)
   - With pointers: passes the ADDRESS (original CAN be changed)

3. THE SWAP LOGIC:
   - We can't just do: a = b; b = a; (would lose first value)
   - So we use temp to hold one value temporarily
   - Then move values around

4. HOW IT WORKS IN MEMORY:
   Before: num1[10]  num2[20]
   Step 1: temp = 10
   Step 2: num1 = 20
   Step 3: num2 = 10 (from temp)
   After:  num1[20]  num2[10]*/
