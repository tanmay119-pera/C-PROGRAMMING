/*PROBLEM NO 1 
PRINT THE NUMBER FROM 0 TO 10(USING FOR LOOP ONLY)
*/

#include<stdio.h>
int main(){
    int i = 0;
    for(i = 0; i <= 10; i=i+1){
        printf("%d\n", i);
    }
    return 0;
}

/*PROBLEM NO 2 
PRINT THE NUMBER FROM 0 TO N, IF N IS GIVEN BY USER "N=4"(USING WHILE LOOP)&(FOR LOOP)
*/
//WHILE LOOP

#include<stdio.h>
int main(){
    int n;
    printf("enter your number :");
    scanf("%d",&n);

        int i = 0;
        while(i<=n){
            printf("%d\n ,i");
            i++;
        }
    return 0;
}

// FOR LOOP 

#include<stdio.h>
int main(){
    int n;
    printf("enter your number :");
    scanf("%d",&n);

        for(int i=0; i<=n; i++){
            printf("%d\n",i);
        }
    return 0;
}

/* PROBLEM 3
PRINT THE SUM OF FIRST N NATURAL NUMBERS.(N=4),ALSO PRINT THEM IN REVERSE.
*/

#include<stdio.h>

int main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum = sum +i; //sum += i
    }

    printf("sum is %d", sum);

    for(int i=n; i>=1; i--){ // for reverse
        printf("%d\n",i);
    }

    return 0;
}

//? for reverse

#include<stdio.h>

int main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);
    
int sum = 0;
for (int i=1, j=n; i<=n && j>=1; i++,j--){
    sum = sum + i; //sum += i
    printf("%d\n",j);
}
 printf("sum is %d \n", sum);

 return 0;

}

/*PROBLEM 4
PRINT THE TABLE OF A NUMBER INPUT BY THE USER.(N=2)
*/

#include<stdio.h>

int main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);

    for(int i=1; i<10; i++){
        printf("%d\n",n*i);
    }
    return 0 ;
}

/*PROBLEM 5
KEEP TAKING NUMBERS AS INPUT FROM USER UNTIL USER ENTERS AN ODD NUMBER.
*/

#include<stdio.h>

int main(){
    int n;
    do{
    printf("enter number : ");
    scanf("%d",&n);
    printf("%d\n",n);

    if(n % 2 != 0){
        break;
    }
} while(1);
printf("thank you");
return 0;
}
 
/*PROBLEM 6
KEEP TAKING NUMBERS AS INPUT FROM USER UNTIL USER ENTERS A NUMBER WHICH IS MULTIPLE OF 7. 
*/

#include<stdio.h>

int main(){
    int n;
    do{
    printf("enter number : ");
    scanf("%d",&n);
    printf("%d\n",n);

    if(n % 7 == 0){ // MULTIPLE OF 7 
        break;
    }
} while(1);
printf("thank you");
return 0;
}

/*PROBLEM 7
PRINT ALL NUMBERS FROM 1 TO 10 EXCEPT FOR 6.
*/

#include<stdio.h>
int main(){
    for(int i=1; i<=10; i++){
        if(i == 6){ // SKIP
            continue; 
        }
        printf("%d\n",i);
    }
    return 0;

}

/*PROBLEM 8
PRINT ALL THE ODD NUMBERS FROM 5 TO 50.
*/
#include<stdio.h>
int main(){
    for(int i=5; i<=50; i++){
        if(i%2 != 0){
             printf("%d\n",i);
        }// ODD 
    }
    return 0;

}

/*PROBLEM 9
PRINT THE FACTORIAL OF A NUMBER N.
*/

//! THIS CAN ONLY STORE SMALL INTEGER DATATYPES. SO WE HAVE USE SMALL NUMS ONLY.

#include<stdio.h>

int main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);

    int fact = 1;
    for(int i = 1; i<=n; i++){
        fact = fact*i;
    }

    printf("final factorial is %d",fact);

    return 0;

}

/*PROBLEM 10
PRINT REVERSE OF THE THE TABLE FOR A NUMBER N.
*/
#include<stdio.h>

int main(){
    int n;
    printf("enter number : ");
    scanf("%d",&n);

    for(int i=10; i>=1; i--){
        printf("%d\n", n*i);
        }
        return 0;
}

/* PROBLEM NO 11
CALCULATE THE SUM OF ALL NUMBERS BETWEEN 5 AND 50.(INCLUDING 5 AND 50)
*/
#include<stdio.h>

int main(){
    int sum = 0;
    for(int i=5; i<=50; i++){
        sum += i;
    }
        printf("sum is %d\n", sum);
        
        return 0;
}

/*PROBLEM NO 12 
SEARCH ON WHAT A "NESTED LOOP" IS AND PRINT THIS PATTERN USING IT.
*****
*****
*****
***** 
*/

/* SOLUTION
A nested loop is simply a loop inside another loop, where one loop is placed within the body of another loop. 
The inner loop runs completely for every single iteration of the outer loop, creating a layered repetition structure
*/

#include <stdio.h>

int main() {
    // Outer loop - controls rows
    for (int i = 0; i < 4; i++) {
        // Inner loop - controls columns (asterisks per row)
        for (int j = 0; j < 5; j++) {
            printf("*");
        }
        printf("\n");  // Newline after each row
    }
    return 0;
}

/* PROBLEM NO 13
WAP TO CHECK IF A NUMBER IS PRIME OR NOT.
*/
#include <stdio.h>

int main() {
    int num, i, isPrime = 1;
    
    // Taking input from user
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Prime numbers are greater than 1
    if (num <= 1) {
        printf("%d is NOT a prime number.\n", num);
        return 0;
    }
    
    // Loop to check divisibility from 2 to num-1
    for (i = 2; i < num; i++) {
        if (num % i == 0) {  // If num is divisible by i
            isPrime = 0;      // Not a prime number
            break;            // Exit the loop
        }
    }
    
    // Displaying the result
    if (isPrime == 1) {
        printf("%d is a PRIME number.\n", num);
    } else {
        printf("%d is NOT a prime number.\n", num);
    }
    
    return 0;
}

/*PROBLEM NO 14
WAP TO PRINT PRIME NUMBERS IN A RANGE.
*/
#include <stdio.h>

int main() {
    int start, end, i, j, isPrime;
    
    printf("Enter starting number: ");
    scanf("%d", &start);
    
    printf("Enter ending number: ");
    scanf("%d", &end);
    
    printf("\nPrime numbers between %d and %d are:\n", start, end);
    
    // Loop through each number in the range
    for (i = start; i <= end; i++) {
        isPrime = 1;  // Assume number is prime
        
        // Check if i is divisible by any number from 2 to i-1
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;  // Not a prime number
                break;
            }
        }
        
        // Print if number is prime
        if (isPrime && i > 1) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}
