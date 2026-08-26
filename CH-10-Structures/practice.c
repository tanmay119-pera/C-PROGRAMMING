//!                        PRACTICE QUESTION FOR STRUCTURE IN C PROGRAMMING

/*PROBLEM 1 
WAP TO STORE THE DATA OF 3 STUDENTS*/

#include<stdio.h>
#include<string.h>

//user defined
struct student {
    int roll;
    float cgpa;
    char name[100];
};

int main(){
    struct student s1;
    struct student s2;
    struct student s3;
    s1.roll = 18977;
    s1.cgpa = 9.2;
    s2.roll = 18978;
    s2.cgpa = 8.7;
    s3.roll = 18979;
    s3.cgpa = 9.0;
    strcpy(s1.name, "tanmay");
    strcpy(s2.name, "pearl");
    strcpy(s3.name, "anushka");


printf("student name = %s\n", s1.name);
printf("student roll no = %d\n", s1.roll);
printf("student cgpa = %f\n" , s1.cgpa);

printf("student name = %s\n", s2.name);
printf("student roll no = %d\n", s2.roll);
printf("student cgpa = %f\n" , s2.cgpa);

printf("student name = %s\n", s3.name);
printf("student roll no = %d\n", s3.roll);
printf("student cgpa = %f\n" , s3.cgpa);



return 0;
}
/*PROBLEM 2
ENTER ADDRESS (HOUSE NO, BLOCK, CITY, STATE) OF 5 PEOPLE*/

#include<stdio.h>
struct address {
    int houseNo;
    int blockNo;
    char city[100];
    char state[100];
};

void printAdd(struct address add);

int main(){
    struct address add [5];
    //input
    printf("enter info for a person 1 :");
    scanf("%d", &add[0].houseNo);
    scanf("%d", &add[0].blockNo);
    scanf("%d", &add[0].city);
    scanf("%d", &add[0].state); 

    printf("enter info for a person 2 :");
    scanf("%d", &add[1].houseNo);
    scanf("%d", &add[1].blockNo);
    scanf("%d", &add[1].city);
    scanf("%d", &add[1].state); 

    printf("enter info for a person 3 :");
    scanf("%d", &add[2].houseNo);
    scanf("%d", &add[2].blockNo);
    scanf("%d", &add[2].city);
    scanf("%d", &add[2].state); 

    printf("enter info for a person 4 :");
    scanf("%d", &add[3].houseNo);
    scanf("%d", &add[3].blockNo);
    scanf("%d", &add[3].city);
    scanf("%d", &add[3].state);

    printf("enter info for a person 5 :");
    scanf("%d", &add[4].houseNo);
    scanf("%d", &add[4].blockNo);
    scanf("%d", &add[4].city);
    scanf("%d", &add[4].state);

    printAdd(add[0]);
    printAdd(add[1]);
    printAdd(add[2]);
    printAdd(add[3]);
    printAdd(add[4]);


    return 0;
}

void printAdd(struct address add){
    printf("address is : %d, %d, %s\n, add.houseNo, add.blockNo, add.city, add.state ");
}

/*PRACTICE NO 3 
CREATE A STRUCTURE TO STORE VECTORS. THEN MAKE A FUNCTION TO RETURN SUM OF 2 VECTORS.*/
#include<stdio.h>
struct vector{
    int x;
    int y;
};

void calcSum(struct vector v1, struct vector v2, struct vector sum);

int main(){
    struct vector v1 = {5, 10};
    struct vector v2 = {3, 7};
    struct vector sum = {0};

    calcSum(v1, v2, sum);


    return 0;
}

void calSum(struct vector v1, struct vector v2, struct vector sum){
    sum.x = v1.x + v2.x;
    sum.y = v1.y + v2.y;

    printf("sum of x is : %d", sum.x);
    printf("sum of y is  : %d", sum.x);

    return 0;
}
/*PROBLEM 4
CREATE A STRUCTURE TO STORE COMPLEX NUMBERS.(USE ARROW OPERATOR)
*/
#include<stdio.h>
struct complex{
    int real;
    int img;
};

int main(){
    struct complex number1 = {5, 8};
    struct complex *ptr = &number1;
    printf("real part = %d\n", ptr->real);
    printf("img part = %d\n", ptr->img);

    return 0;
}

/*PROBLEM NO 6
YOU HAVE TO STORE THE MARKS OF 30 STUDENTS IN CLASS WHAT WILL YOU USE?
A.) ARRAY OF 10 FLOATS
B.) STRUCTURE 
*/

/* SOLUTION
A structure alone doesn't directly store 30 marks
BUT a structure could contain an array of 30 floats as a member*/

/*PROBLEM NO 7
MAKE A STRUCTURE TO STORE BANK ACCOUNT INFORMATION OF A CUSTOMER OF ABC BANK. ALSO, MAKE AN ALIAS FOR IT.
*/
#include <stdio.h>
#include <string.h>

// STRUCTURE TO STORE BANK ACCOUNT INFO
typedef struct {
    int accountNumber;           // UNIQUE ACCOUNT ID
    char customerName[50];       // CUSTOMER NAME
    char accountType[20];        // "SAVINGS", "CURRENT", "FIXED"
    float balance;               // ACCOUNT BALANCE
    char phoneNumber[15];        // CONTACT NUMBER
    int pinCode;                 // 4-DIGIT PIN
    char openingDate[20];        // DATE (E.G., "01-01-2024")
} BankAccount;                   // ALIAS CREATED HERE

// MAIN PROGRAM
int main() {
    BankAccount customer1;       // DECLARE USING ALIAS
    
    // INPUT CUSTOMER DATA
    printf("=== ABC BANK - ACCOUNT CREATION ===\n");
    printf("Enter Account Number: ");
    scanf("%d", &customer1.accountNumber);
    
    printf("Enter Customer Name: ");
    scanf("%s", customer1.customerName);
    
    printf("Enter Account Type (SAVINGS/CURRENT): ");
    scanf("%s", customer1.accountType);
    
    printf("Enter Initial Balance: ");
    scanf("%f", &customer1.balance);
    
    printf("Enter Phone Number: ");
    scanf("%s", customer1.phoneNumber);
    
    printf("Enter 4-Digit PIN: ");
    scanf("%d", &customer1.pinCode);
    
    printf("Enter Opening Date (DD-MM-YYYY): ");
    scanf("%s", customer1.openingDate);
    
    // DISPLAY CUSTOMER INFO
    printf("\n=== ACCOUNT CREATED ===\n");
    printf("Account Number: %d\n", customer1.accountNumber);
    printf("Customer Name: %s\n", customer1.customerName);
    printf("Account Type: %s\n", customer1.accountType);
    printf("Balance: ₹%.2f\n", customer1.balance);
    printf("Phone: %s\n", customer1.phoneNumber);
    printf("Opening Date: %s\n", customer1.openingDate);
    
    return 0;
}