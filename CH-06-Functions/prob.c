//!                                PROBLEM SOLVING 
/*PROBLEM NO 1:
WRITE TWO FUNCTION ONE TO PRINT 'HELLO' AND SECOND TO PRINT "GOOD BYE"
*/
#include <stdio.h>
#include <string.h>

void printHello();
void printGoodbye();


int main(){
    printHello();
    printGoodbye();
    return 0;
}

void printHello(){
    printf("hello\n");
}

void printGoodbye(){
    printf("goodbye\n");
}

/*PROBLEM NO 2
WRITE TWO FUNCTION "NAMASTE" IF THE USER IS INDIAN AND "BONJOUR" IF FRENCH.
*/
#include <stdio.h>
#include <string.h>

void namaste() {
    printf("NAMASTE\n");
}

void bonjour() {
    printf("BONJOUR\n");
}

int main() {
    char nationality[20];
    
    printf("Are you Indian or French? ");
    scanf("%s", nationality);
    
    if (strcmp(nationality, "Indian") == 0) {
        namaste();
    } else if (strcmp(nationality, "French") == 0) {
        bonjour();
    }
    
    return 0;
}

/*PROBLEM NO 3
Use the library function to calculate the square of a number given by the user.
*/
#include<stdio.h>
#include<math.h>
int main(){

    int n = 4 ;
    printf("%f", pow(n,2));     
    return 0;
}

void calculatePrice(float value){
     value = value + (0.18 * value );
     printf("final price is : %f,value");

}

/*PROBLEM NO 4
WRITE A FUNCTIONS TO CALCULATE AREA OF SQUARE,CIRCLE AND RECTANGLE 
*/
#include<stdio.h>
#include<math.h>

float squareArea(float side);
float circleArea(float rad);
float rectangleArea(float a, float b);
int main(){
    float a = 5.0;
    float b = 10.0;

    printf("area is : %f", rectangleArea(a,b));

    return 0;

}

float squareArea(float side){
    return side * side;

}

float circleArea(float rad){
    return 3.14 * rad * rad;
}

float rectangleArea(float a, float b ){
    return a*b;
}

//! PRACTICE QUESTION FROM RECURSION NOW

/*PROBLEM 5
Sum of first n natural number.
*/
#include<stdio.h>
int main(){
    int sum(int n);
    printf("sum is : %d", sum(5));

    return 0;
}

//recursive function
int sum(int n){
    if(n==1){
        return 1;
    }
    int sumNm1 = sum(n-1);  // sum of 1 to n 
    int sumN = sumNm1 + n;
    return sumN;
}
/*
explanation of problem no 6
In recursion
"All so know as recursion tree"
"n terms to (5)------------------------------------>
(sum(5)=15) = (sum(4)+5=10+5=15) = (sum(3)+4=6+4=10) =
(sum(2)+3=3+3=6) = (sum(1)+2=1+2=3 ("BASE CASE"))
*/

/*PROBLEM NO 6 
factorial of n 
*/

/*logic for this problem!
5! = 1*2*3*4*5 = 4!*5
4! = 1*2*3*4   = 3!*4
3! = 1*2*3     = 2!*3
2! = 1*2       = 1!*2
1! = 1         = 1

// fact(n)=fact(n+1)*n //

*/
#include<stdio.h>
int main(){
    int fact(int n);
    printf("factorial is  : %d", sum(5));

    return 0;
}

//recursive function
int fact(int n){
    if(n==1){
        return 1;
    }
    int factNm1 = fact(n-1);  // for sum 1 to n 
    int factN = factNm1 * n;
    return factN;
}

/*PROBLEM NO 7
WAF TO CONVERT DEGREE CELSIUS INTO FAHRENHEIT.
*/
#include<stdio.h>
int main(){
    float convertTemp(float celsius);
    float far = convertTemp(0);
    printf("far : %f", far);
    return 0;
}

float convertTemp(float celsius){
    float far = celsius * (9.0/5.0) + 32.0;
    return far;
}

/*PROBLEM NO 8
WRITE A FUNCTION TO CALCULATE PERCENTAGE OF A STUDENT FROM MARKS IN SCIENCE,
MATHS AND SANSKRIT
*/
#include<stdio.h>
int main(){
   int calcPercentage(int science, int maths , int sanskrit);
   int sc = 89;
   int maths = 90;
   int sanskrit = 97;
   printf("precentage is : %d", calcPercentage(sc, maths, sanskrit));
    return 0;
}

int calcPercentage(int science, int maths, int sanskrit){
    return ((science+maths+sanskrit)/3);
}

/*PROBLEM NO 9
WAF TO PRINT N TERMS OF THE "FIBONACCI SEQUENCE"

//ABOUT FIBONACCI SEQUENCE//
The Fibonacci sequence is a famous mathematical sequence where each number is the sum of the two preceding ones. 

The Fibonacci sequence is a series of numbers in which each number is the sum of the two that precede it. 
Starting at 0 and 1, the first 10 numbers of the sequence 
look like this: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on forever.

The Fibonacci sequence can be described using a mathematical equation: Xn+2= Xn+1 + Xn
*/

/* LOGIC FOR PROBLEM SOLVING 

fib(0),fib(1),fib(2),fib(3),fib(4),fib(05),fib(6),fib(7),fib(8)....
0,    1,    1,    2,    3,    5,     8,    13,   21.....

fib(2)= fib(0)+fib(1)
fib(3)= fib(1)+fib(2).. so on 

## fib(n)= fib(n-1)+fib(n-2) ##

*/
#include<stdio.h>

int main(){
    int fib(int n);
    print("%d", fib(6));

    return 0;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int fibNm1 = fib(n-1);
     int fibNm2 = fib(n-2);
    int fibN = fibNm1 + fibNm2;
 //   print("fib of %d is : %d ", n,fibN);
    return fibN;
}

/*PROBLEM NO 10
WAF TO FIND THE SUM OF DIGITS OF A NUMBER.
*/

#include <stdio.h>

int main() {
    int num, sum = 0, digit;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Handle negative numbers by converting to positive
    if (num < 0) {
        num = -num;
    }
    
    // Extract and add each digit
    while (num > 0) {
        digit = num % 10;      // Get last digit
        sum += digit;           // Add to sum
        num = num / 10;         // Remove last digit
    }
    
    printf("Sum of digits: %d\n", sum);
    
    return 0;
}

/*PROBLEM N0 11
WRITE A FUNCTION TO FIND SQUARE ROOT OF A NUMBER.
*/
#include <stdio.h>
#include <math.h>

int main() {
    double num, result;
    
    printf("Enter a number: ");
    scanf("%lf", &num);
    
    result = sqrt(num);  // Built-in square root function
    
    printf("Square root of %.2f = %.2f\n", num, result);
    
    return 0;
}

/*PROBLEM N0 12
WAF TO PRINT "HOT" OR "COLD" DEPEND ON THE TEMPERATURE USER ENTERS.
*/
#include <stdio.h>

void checkTemperature(int temp) {
    if (temp >= 30) {
        printf("HOT\n");
    }
    else {
        printf("COLD\n");
    }
}

int main() {
    int temp;
    
    printf("Enter temperature (in Celsius): ");
    scanf("%d", &temp);
    
    checkTemperature(temp);
    
    return 0;
}

/*PROBLEM NO 13
MAKE YOUR OWN POW FUNCTION.
*/
#include <stdio.h>

double power(double base, int exp) {
    // Base case
    if (exp == 0) {
        return 1;
    }
    
    // Handle negative exponent
    if (exp < 0) {
        return power(1 / base, -exp);
    }
    
    // Recursive case
    return base * power(base, exp - 1);
}

int main() {
    double base;
    int exponent;
    
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    
    printf("%.2f^%d = %.2f\n", base, exponent, power(base, exponent));
    
    return 0;
}