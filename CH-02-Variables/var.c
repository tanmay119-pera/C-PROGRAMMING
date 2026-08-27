//                                         VARIABLE AND DATATYPES                                                  
/*
================================================= VARIABLE =======================================================================

VARIABLE IS THE NAME OF A MEMORY LOCATION WHICH STORES SOME DATA

A variable in C is a named memory location used to store data. The value of a variable
 can change while the program is running.

Definition:
A variable is a named memory location that stores a value of a specific data type, and its value can be modified 
during program execution.

Rules for Naming Variables
1. Must start with a letter (A-Z, a-z) or underscore (_).
2. Cannot start with a number.
3. Can contain letters, digits, and underscores.
4. Cannot use C keywords like int, float, return, or if.
5. Variable names are case-sensitive (age and Age are different). 
6. 1st letter is alphabet or '_'
7. No comma/blank space
8. No other symbol other than'_' 
9. variable name should be meaningful 

=================================================== DATA TYPES ==========================================================

Data types                                 size in bytes

1. char or signed char                        1

2. unsigned char                              1

3. int or signed int                          2

4. unsigned int                               2

5. short int or unsigned short int            2

6. signed short int                           2

7. long int or signed long int                4

8. unsigned long int                          4 

9. float                                      4

10. double                                    8

11. long double                               10 

================================================== CONSTANTS ==========================================================
VALUES THAT DO NOT CHANGE(FIXED)
Types 

Integer constants   1,2,3,0,-1,-2

Real constants   3.14, 2.5, 0.0

Character constants  'a','A','1','@','#'

=================================================== KEYWORDS =========================================================
Keywords are reserved words that have a special meaning in C. They cannot be used as variable nameS. and there
are 32 keywords in C. They are as follows:

auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto,
if, int, long, register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned,
void, volatile, while   

================================================= COMMENTS =========================================================

LINES STARTING WITH '//' ARE CALLED SINGLE LINE COMMENTS
LINES STARTING WITH '/*' AND ENDING WITH '*/

/*=============================================== OUTPUT ============================================================

CASES(format specifier) for printf() function

1.integers
printf("age is %d",age);

2.real numbers
printf("values of pi is %f",pi);

3.characters
printf("character is %c",star);

================================================ INPUT ============================================================

scanf() function is used to take input from user. It is used with '&' operator before variable name.
The '&' operator is used to get the address of the variable.
1. integers
scanf("%d",&age); // for integer

2. float
scanf("%f",&pi); // for float

3. characters
scanf("%c",&star); // for character

========================== COMPILATION AND EXECUTION OF C PROGRAM =====================================================

1. Write the code in a text editor and save it with .c extension.
2. Open the terminal and navigate to the directory where the file is saved.
3. Compile the code using the command: gcc filename.c -o outputname
4. Run the compiled program using the command: ./outputname












*/



// Example of variable //

#include<stdio.h>

int main(){

    int number = 25;
    char star = '*';
    int age = 22;
    age = 24;
    float pi = 3.14;

    int a = 30;
    int A = 40;
    
    int _age = 22;

    int final_price = 100;

    return 0;
}

// data types (int),(float),(char) //

void data_types_example(void){
    int age = 22;
    float pi = 3.14f;
    char hashtag = '#';
}

// Example of constant //

#include<stdio.h>

int main(){
    const int MAX_SIZE = 100;
    const float PI = 3.14;
    const char HASH = '#';
    return 0;
}

// program structure //

#include<stdio.h>
int main(){                     // C is case sensitive language
    printf("Hello World");
    return 0;
}

// THIS IS A COMMENT //
/* THIS IS A COMMENT */

// OUTPUT //

#include<stdio.h>
int main(){
    int age = 22;
    float pi = 3.14;
    char star = '*';   
    printf("age is %d\n",age); // %d is format specifier for integer , /n for new line or next line
    printf("value of pi is %f\n",pi); // %f is format specifier for float
    printf("character is %c\n",star); // %c is format specifier for char
    return 0;
}

// INPUT //
#include<stdio.h>
int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d",&age); // %d is format specifier for integer,'&' operator is used to get the address of the variable
    printf("Your age is: %d",age);
    return 0;
}
