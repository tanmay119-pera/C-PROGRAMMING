//!                                         POINTERS IN C PROGRAMMING 

//&  A VARIABLE IS THAT STORES THE MEMORY ADDRESS OF ANOTHER VARIABLE.  
/*
Definition: A pointer is a variable that stores the memory address of another variable, rather
than storing a standard data value.

The Address-of Operator (&): Used to find out exactly where in memory a variable is stored. 
For example, &age gives you the memory address of the variable age.

The Dereference Operator (*): Used to access or modify the actual value stored at the memory address the pointer is holding.

Primary Uses:
Efficiency: Passing a pointer to a large chunk of data (like a struct) to a function avoids making a slow,
memory-heavy copy of that data.

Dynamic Memory: Pointers are required to use memory that is allocated while 
the program is running (using functions like malloc).

Data Structures: They connect complex data structures like linked lists and trees by pointing from one node to the next.
*/

//=====================================================================================================================================================================================

//^ POINTER 

/* SYNTAX
int age = 22;        * = value at address 
int *ptr = &age;     & = address of operator
int_age = *ptr;
*/
#include <stdio.h>
int main(){
    int age  = 22;
    int *ptr = &age;
    int _age = *ptr;

    printf("%d", _age);
    return 0;
}

//==========================================================================================================================================================

//* DECLARING POINTERS 
/*
int *ptr;
for storing integer variable address
example = int age = 22;

char *ptr;
for storing character variable address
exapmle = char star = '*';

float *ptr;
for storing float data type variable address 
example = float price = 100.00;
*/

//=============================================================================================================================================================

//* FORMAT SPECIFIER
/*
%d = integer ,%p = hexadecimal, %u = unsigned int 

printf("%p", &age); 

printf("%p" , ptr);  

printf("%p", &ptr);
*/
#include <stdio.h>
int main(){
    int age  = 22;
    int *ptr = &age;
    
    //&address

    printf("%p\n", &age); //^ it will us hexadecimal format. this is a vla of address of age 
    printf("%u\n", ptr);
    printf("%u\n", &ptr);

    return 0;
}

//===============================================================================================================================================================================================

//^ value 
#include<stdio.h>
int main (){
    int age = 22;
    int *ptr = &age;

    //value
    printf("%d\n", age);
    printf("%d\n", *ptr);
    printf("%d\n", age);

    return 0 ;
}

//========================================================================================================================================================================================================

//* POINTER TO POINTER.
//&A VARIABLE THAT STORES THE MEMORY ADDRESS OF ANOTHER POINTER.

# include<stdio.h>
int main(){
    float price = 1000.00;
    float *ptr = &price;
    float **pptr = &ptr;
    return 0;
}

//* POINTERS IN FUNCTION CALL 
/*
1. CALL BY VALUE :
We pass value of variable as argument.

2. CALL BY REFERENCE
We pass address  of variable as argument.
*/
// call by value & call by reference.

#include<stdio.h>
int main(){
    void square(int n);
    void _square(int* n);
    int number = 4;
    square(number);
    printf("number = %d\n" , number);
    return 0;
}

// call by value 
void square(int n){
    n = n * n;
    printf("square = %d\n" );
} 

// call by reference
void _square(int *n){
    *n = (*n) * (*n);
    printf("square = %d\n", *n );
    
}
