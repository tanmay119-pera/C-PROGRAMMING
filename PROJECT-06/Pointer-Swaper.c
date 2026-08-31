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
CONCEPTS: Pointers, Functions, Pass-by-Reference, Memory Management
*/

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
    // Declare two integer variables (will store user input)
    int num1, num2;
    
    printf("=== Pointer Swapper Demo - Interactive Version ===\n\n");
    
    // INPUT CONSTRAINTS:
    // ==================
    // We're using 'int' data type which has limits:
    // - Minimum value: -2,147,483,648 (about -2.1 billion)
    // - Maximum value:  2,147,483,647 (about +2.1 billion)
    // - Range: approximately -2^31 to +2^31 - 1
    //
    // For this beginner project, we recommend:
    // - Use numbers between -1000 and 1000 (easy to track mentally)
    // - Avoid very large numbers (over 1 million) for clarity
    // - Decimal points will be ignored (int only stores whole numbers)
    //
    // Why these limits?
    // 1. 'int' = 4 bytes = 32 bits (1 bit for sign, 31 bits for value)
    // 2. Helps you see the swap clearly without dealing with huge numbers
    // 3. Prevents overflow errors (when number exceeds max value)
    
    printf("INPUT GUIDELINES:\n");
    printf("- Enter ANY whole number (integer)\n");
    printf("- Recommended range: -1000 to 1000\n");
    printf("- Maximum range: -2,147,483,648 to 2,147,483,647\n");
    printf("- Do NOT use decimals (e.g., 3.14 won't work)\n\n");
    
    // Get first number from user
    printf("Enter first number (num1): ");
    scanf("%d", &num1);
    
    // Get second number from user
    printf("Enter second number (num2): ");
    scanf("%d", &num2);
    
    printf("\n");
    
    // Print original values (what user entered)
    printf("=== BEFORE SWAP ===\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    printf("\nMemory addresses:\n");
    printf("Address of num1: %p\n", (void*)&num1);  // %p prints memory address
    printf("Address of num2: %p\n", (void*)&num2);
    
    // Call swap function, passing ADDRESSES (&) of the variables
    // & operator gives the address of a variable
    // This is pass-by-reference - the function works on actual variables
    // scanf("%d", &num1) also uses & to store input at that address
    printf("\n[Calling swap function...]\n\n");
    swap(&num1, &num2);
    
    // Print swapped values
    printf("=== AFTER SWAP ===\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    printf("\nMemory addresses (same as before!):\n");
    printf("Address of num1: %p\n", (void*)&num1);  // Address stays same
    printf("Address of num2: %p\n", (void*)&num2);  // Only VALUES changed
    
    printf("\n--- Why Pointers Matter ---\n");
    printf("Without pointers, you can't modify variables from inside a function.\n");
    printf("Pointers let you pass the ADDRESS, so the function can change the actual values.\n");
    printf("\nNotice: The addresses stayed the same, but the values swapped!\n");
    
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
   After:  num1[20]  num2[10] ✓

*/
