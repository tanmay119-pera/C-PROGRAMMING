//!                                        RECURSION IN C PROGRAMMING  

//?  WHEN THE FUNCTION CALL ITSELF , IT IS CALLED RECURSION.
/*
Recursion happens when a function calls itself to solve a smaller piece of the same problem.

Think of it like opening a Russian nesting doll: each step reveals a smaller version of the whole, until you reach the very
end (the smallest, solid doll). In programming, you break a complex problem down into identically structured, smaller
problems until it's simple enough to solve directly.

The Two Rules of Recursion
For a recursive function to work correctly—and not crash your computer—it MUST have two distinct parts:

The Base Case (The Stopping Point): A condition that tells the function to stop calling itself. Without this, 
the function will loop infinitely until the program runs out of memory (a fatal error known as a "stack overflow").

The Recursive Case (The Action): The part where the function actually calls itself, 
but with a modified parameter that moves it one step closer to the Base Case.
*/
//? LETS DIVE INTO IT.....!!
#include<stdio.h>

void printHW(int count);

int main(){
    printHW(5);
    return 0;
}
//& THIS IS A RECURSIVE FUNCTION
void printHW(int count){
    if( count == 0 );{
    return;
}
    print("hello world\n");
    printHW(count-1);
}
//* IN TERMS OF MATH 
/*
F(x)=x^2 // here function calling itself
*/

//* NORMAL FUNCTION CALL 
/*
MAIN ---> F(X) -----> Y(X)
<----------| <---------|             

A normal function call happens when one function invokes a different function to perform a task. 
The calling function pauses, waits for the called function to finish its execution and return a result, and then resumes.
*/
#include <stdio.h>

// A standard function
int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Normal function call: main() calls multiply()
    int result = multiply(5, 4); 
    printf("Result: %d\n", result);
    return 0;
}

//* RECURSION FUNCTION CALL  
/*
MAIN ---> F(X) ---> F(X) ----> F(X)
<----------| <-------| <---------|

A recursive function call happens when a function invokes itself to solve a smaller instance of the same problem.

Every recursive function requires a base case—a strict condition where the function stops calling itself and returns
a value. Without a base case, the function will call itself infinitely, consuming all available memory and causing 
a program crash known as a "stack overflow."
*/
#include <stdio.h>

// A recursive function
int factorial(int n) {
    // Base case: stops the recursion
    if (n <= 1) {
        return 1;
    }
    // Recursive call: factorial() calls factorial()
    return n * factorial(n - 1);
}

int main() {
    // main() calls factorial() once, which then calls itself
    printf("Factorial of 5 is: %d\n", factorial(5)); 
    return 0;
}

//& PROPERTIES OF RECURSION 
/*
A. ANYTHING THAT CAN BE DONE WITH ITERATION, CAN BE DONE WITH RECURSION AND VICE-VERSA.
B. RECURSION CAN SOMETIMES GIVE THE MOST SIMPLE SOLUTION 
C."BASE CASE"IS THE CONDITION WHICH STOP RECURSION.(FOR MORE REF GO ON PROBLEM NO 5.)
D. ITERATION HAS INFINITE LOOP AND RECURSION HAS STACK OVERFLOW
*/