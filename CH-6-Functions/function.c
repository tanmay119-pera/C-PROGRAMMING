//!                                    "  FUNCTION IN C PROGRAMMING "

//? BLOCK OF CODE THAT PERFORMS PARTICULAR TASK. TAKE ARGUMENT = DO WORK = RETURN RESULT
//? IT CAN BE USED MULTIPLE TIMES, INCREASE CODE REUSABILITY.

/*
A function is a self-contained block of code designed to perform a specific, reusable task.

Think of it as a mini-program within your main program: you can give it inputs (parameters), it performs a specific operation, 
and it optionally gives you an output (a return value). Functions are the building blocks of C — in fact, main() is itself a 
function where every C program begins.

Why Use Functions?

Reusability: Write the code once, use it multiple times without rewriting it.
Modularity: Break down a massive, complex problem into smaller, manageable chunks.
Maintainability: If a bug exists in a specific calculation, you only have to fix it in one place.

The Anatomy of a C Function
A standard function has three core stages in a C program:

Declaration (Prototype): Tells the compiler the function's name, what it takes in, and what it returns before it's actually used.
Definition: The actual body of the function containing the logic.
Call: The moment you actually execute the function from elsewhere in your code. 
*/

//========================================================================================================================================================

//* SYNTAX 1
/*
FUNCTION PROTOTYPE 
void printHello();

"TELL THE COMPILER"
*/

//* SYNTAX 2
/*
FUNCTION DEFINITION 
void printHello(){
    printf("Hello");
}

"DO THE WORK"
*/

//* SYNTAX 3 
/*FUNCTION CALL
int main(){
    printHello();
    return 0;
}

"USE THE WORK "
*/

#include<stdio.h>
// declaration/prototype
void printHello();

int main(){
    printHello();// function call
    printHello();
    printHello();
    return 0;
}
// function definition
void printHello(){
    printf("hello!\n");
    printf("practice code daily");
}

// function call
int main(){
    printHello();
    return 0;
} // use the work 

//=====================================================================================================================================================================

//* PROPERTIES OF FUNCTION 
/*
> EXECUTION ALWAYS STARTS FROM MAIN.
> A FUNCTION GETS CALL DIRECTLY OR INDIRECTLY FROM MAIN.
>THERE CAN BE MULTIPLE FUNCTION IN A PROGRAM.
*/

//========================================================================================================================================================================

//* FUNCTION TYPES
/*
> LIBRARY FUNCTION
Special in built function like 
scanf(),printf()

> USER DEFINED 
declared and defined by programmer 
*/

//==========================================================================================================================================================================

//* PASSING ARGUMENT 
/*
function can take(PARAMETER)a value and give some value(RETURN VALUE).
EXAMPLE 
void printHello();
     ----------
void printTable (int n);
     -----------
int sum(int a, int b);
---
*/
// EXAMPLE NO 1 
#include<stdio.h>
int main(){

    int sum(int a, int b);


    int a,b;
    printf("enter your first number : ");
    scanf("%d", &a);
    printf("enter your second number : ");
    scanf("%d", &b);

    int s = sum(a,b);
    printf("sum is %d : " ,s);

    return 0;
}

int sum(int x, int y){
    return x+y ;
}

// EXAMPLE NO 2 
#include<stdio.h>
int main(){

    int sum(int a, int b);
    void printTable(int n);

    int n;
    printf("enter your number : ");
    scanf("%d", &n);

    printTable(n); // argument(actual parameter) 

    return 0;
}
  
int sum(int x, int y){
    return x+y ;
}

void printTable(int n){ // parameter (formal parameter)
     for(int i=1; i<=10; i++){
        printf("%d\n",i*n);
     }
}

//* ARGUMENT VS PARAMETER 
/*
 >ARGUMENT                        >PARAMETER 

VALUE THAT ARE PASSED IN          VALUES FUNCTION AND DECLARATION AND
FUNCTION CALL.                    DEFINITION.

USE TO SEND VALUE.                USE TO RECEIVE VALUE.

ACTUAL PARAMETER.                  FORMAL PARAMETER. 
*/

//! NOTE 
/*
A.FUNCTION CAN ONLY RETURN ONE VALUE AT ONE TIME.

B.CHANGES TO PARAMETER FUNCTION DONT CHANGE THE VALUE IN CALLING FUNCTION.
(BECAUSE A COPY OF ARGUMENT IS PASSED TO THE FUNCTION) 
*/

// FOR EXAMPLE

#include<stdio.h>
int main(){
     void calculatePrice(float value);
     float value = 100;
     calculatePrice(value);
    return 0;
}

void calculatePrice(float value){
     value = value + (0.18 * value );
     printf("final price is : %f,value");

}

 