// !                                          INSTRUCTIONS AND OPERATORS                                            //
/* 

INSTRUCTIONS IN C:

THESE ARE STATEMENTS IN A PROGRAM 

TYPES 

1. TYPE DECLARATIONS: 
   - Variable declarations specify the type and name of a variable.
   - Function declarations specify the return type, name, and parameters
   
2. ARITHMETIC INSTRUCTIONS: 
   - Addition (+), Subtraction (-), Multiplication (*), Division (/), Modulus (%) 

3. CONTROL INSTRUCTIONS: 
   - Conditional statements (if, else if, else) 
   - Loops (for, while, do-while) 
   - Switch statements
*/

/*INSTRUCTIONS 

type declarations instructions = declare var before using it                          

VALID                      INVALID 
int a=22;                  int a =22;
int b=a;                   int b =a;
int c = b+1;               int c = b+2;
int d = 1,e;               int d = 2, e;

int a,b,c;
a=b=c=1;                   int a,b,c=1;

*/

#include <stdio.h>

int main() {
    int a = 22; // Valid type declaration
    int b = a;  // Valid type declaration
    int c = b + 1; // Valid type declaration
    int d = 1, e; // Valid type declaration
    return 0;

    int age = 25; // Valid type declaration
   // name = "John"; // Invalid type declaration (missing type)
   char name[] = "John"; // Valid type declaration
        return 0;
}

// ARITHMETIC INSTRUCTIONS // 

/* a+b="operand 1(operator) operand 2" 
NOTE - SINGLE VARIABLE ON THE LHS 
 
 VALID OPERATIONS          INVALID OPERATIONS.

 a=b+c                     b+c=a
 a=b*c                     a=bc
 a=b/c                     a=b^c

NOTE - POW(X,Y)FOR X TO THE POWER OF Y  

MODULAR OPERATOR (%) 
RETURNS THE REMAINDER OF A DIVISION OPERATION

3%2=1
-3%2=-1

TYPE CONVERSION IN C :
IS DONE AUTOMATICALLY WHEN OPERANDS OF DIFFERENT TYPES ARE USED IN AN EXPRESSION.

int op int = int 

int op float = float

float op float = float

operator precedence in C:

(*, /, % (left to right))  = x=4+9*10

+,- = (left to right) 

 = x=4*3/6*2

associativity for same precedence operators is left to right
x=4*3/6*2
4*3=12
12/6=2
2*2=4
x=4 

CONTROL INSTRUCTIONS:
used to control the flow of execution of a program.

1. sequence control: statements are executed in the order they appear in the program.

2.decision control: allows the program to make decisions based on certain conditions. 
(if, else if, else, switch)

3.loop control: allows the program to repeat a block of code multiple times. 
(for, while, do-while)

4.case control: allows the program to execute different blocks of code based on the value of a variable.
(switch, case)


*/ 

#include <stdio.h>
#include <math.h>


int main(){
   int a = 1, b = 2;

   int sum = a + b;// Valid addition operation

   int multiply = a * b;// Valid multiplication operation

   int x, y = a * b;// Valid multiplication operation

   int power = pow(a, b); // Valid operation using pow function
   
   int A = 4+9*10; // Valid operation with operator precedence

   printf("%d\n",8%3); // Valid modular operation

   printf("Sum: %d\n", sum);// Valid addition operation

   printf("Multiply: %d\n", multiply);// Valid multiplication operation

   printf("Modular: %d\n", 8%3); // Valid modular operation

   printf("Power: %d\n", power);// Valid operation using pow function

   printf("Division: %f\n", 3.0/2.0); // Valid division operation// conversion to float

   printf("Division: %d\n", 3/2); // Valid division operation// conversion to int

   printf("Precedence: %d\n", A); // Valid operation with operator precedence

// example of sequence control
   int num1 = 5;
   int num2 = 10;
// example of decision control
   if (num1 < num2) {
      printf("%d is less than %d\n", num1, num2);
   } else {
      printf("%d is not less than %d\n", num1, num2);
   }
// example of loop control
   for (int i = 0; i < 5; i++) {
      printf("Iteration %d\n", i);
   }
// example of case control
   int day = 3;
   switch (day) {
      case 1:
         printf("Monday\n");
         break;
      case 2:
         printf("Tuesday\n");
         break;
      case 3:
         printf("Wednesday\n");
         break;
      case 4:
         printf("Thursday\n");
         break;
      case 5:
         printf("Friday\n");
         break;
      default:    
         printf("Weekend\n");
   }
   return 0;//
}

/*

OPERATORS IN C:

A.) ARITHMETIC OPERATORS: 
   - Addition (+), Subtraction (-), Multiplication (*), Division (/), Modulus (%)

B.) RELATIONAL OPERATORS: 
   - Equal to (==), Not equal to (!=), Greater than (>), Less than (<), Greater than or equal to (>=), 
   Less than or equal to (<=)

C.) LOGICAL OPERATORS:
   - Logical AND (&&), Logical OR (||), Logical NOT (!)

D.) BITWISE OPERATORS:
   - Bitwise AND (&), Bitwise OR (|), Bitwise XOR (^), Bitwise NOT (~), Left shift (<<), Right shift (>>)

E.) ASSIGNMENT OPERATORS:
   - Assignment (=), Addition assignment (+=), Subtraction assignment (-=), Multiplication assignment (*=),
    Division assignment (/=), Modulus assignment (%=)

F.) TERNARY OPERATOR:
   - Conditional operator (?:)

OPERATOR PRECEDENCE IN C:

PRIORITY            OPERATOR
   1                 !

   2                 *, /, %

   3                 +, -

   4                 <, <=, >, >=

   5                 ==, !=

   6                 &&

   7                 ||

   8                  =


*/

//!NOTE: IN C PROGRAMMING(1=TRUE(OR ANY INTEGER),0=FALSE)1 ==1 IS TRUE,1 == 0 IS FALSE,0 == 0 IS TRUE,0 == 1 IS FALSE.

#include <stdio.h>

// relational operators
int main() {
    int a = 5, b = 10;

    printf("a == b: %d\n", a == b); // Equal to

    printf("a != b: %d\n", a != b); // Not equal to

    printf("a > b: %d\n", a > b);   // Greater than

    printf("a < b: %d\n", a < b);   // Less than

    printf("a >= b: %d\n", a >= b); // Greater than or equal to
    
    printf("a <= b: %d\n", a <= b); // Less than or equal to

// logical operators
    int x = 1, y = 0;
    int result = (x && y) || (!x && !y); // Logical expression

    printf("x && y: %d\n", x && y); // Logical AND

    printf("x || y: %d\n", x || y); // Logical OR

    printf("!x: %d\n", !x);         // Logical NOT

    printf("Result: %d\n", result);  // Logical expression result

// assignment operators
    int c = 5;

    c += 2; // Addition assignment
    printf("c after += 2: %d\n", c);

    c -= 3; // Subtraction assignment 
   printf("c after -= 3: %d\n", c);

    c *= 4; // Multiplication assignment
    printf("c after *= 4: %d\n", c);

    c /= 2; // Division assignment
    printf("c after /= 2: %d\n", c);

    c %= 3; // Modulus assignment
    printf("c after %%= 3: %d\n", c);

    return 0;
}