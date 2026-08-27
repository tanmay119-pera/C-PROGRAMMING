//!                                           PROBLEM SOLVING 
/*PROBLEM NO 1
WAP A PROGRAM TO CHECK IF A STUDENT PASSED OR FAILED.
marks>30 is PASS
marks <= 30 is FAIL 
*/
#include<stdio.h>

int main(){
    int marks;
    printf("enter number(0-100): ");
    scanf("%d", &marks);
    if (marks <= 30) {
        printf("FAIL \n");
    } else {
        printf("PASS \n");
    }

    return 0;
} 

/*PROBLEM NO 2
WAP TO GIVE GRADE TO A STUDENT MARKS<30 IS C
30 <= MARKS <70 IS B
70 <= MARKS <90 IS A 
90 <= MARKS <=100 IS A+ 
*/
#include<stdio.h>

int main(){
    int marks;
    printf("enter number(0-100): ");
    scanf("%d", &marks);

    if(marks<30) {
        printf("C \n");
    }
    else if (marks >= 30 && marks < 70){
        printf("B \n");
    }
    else if (marks >= 70 && marks < 90){
        printf("A \n");
    }
    else{
        printf("A+ \n");
    }

    return 0 ;

}

/*PROBLEM NO 3 
WAP TO FIND NUMBER OF CHARACTER ENTERED BY THE USER IS UPPER CASE OR NOT?
*/

#include<stdio.h>

int main(){
    char ch;
    printf("enter the character :");
    scanf(" %c", &ch);

    if(ch >= 'A' && ch <= 'Z'){
        printf("character is in upper case\n");
    }
    else if (ch >= 'a' && ch <= 'z'){
        printf("character is in lower case\n");
    }
    else{
        printf("character is not an alphabetic letter\n");
    }

    return 0;

}
/*PROBLEM NO 4(star)
WAP TO CHECK WEATHER TO CHECK IF A GIVEN NUMBER IS ARMSTRONG NUMBER OR NOT 
*/

#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, sum = 0, digitCount = 0;
    
    // Input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    originalNum = num;
    
    // Count the number of digits
    int temp = num;
    while (temp != 0) {
        digitCount++;
        temp /= 10;
    }
    
    // Calculate sum of each digit raised to the power of digitCount
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digitCount);
        temp /= 10;
    }
    
    // Check if Armstrong number
    if (sum == originalNum) {
        printf("%d is an Armstrong Number\n", originalNum);
    } else {
        printf("%d is NOT an Armstrong Number\n", originalNum);
    }
    
    return 0;
}

/*PROBLEM 5
WAP TO CHECK IF THE GIVEN NUMBER IS A NATURAL NUMBER."HINT;(NATURAL NUMBER STARTS FROM 1)"
*/
#include <stdio.h>
int main(){
    int num;
    printf("ENTER YOUR NUM: ");
    scanf("%d", &num);

    if (num >= 1) {
        printf("It is a natural number\n");
    } else {
        printf("It is not a natural number\n");
    }

    return 0;
}
