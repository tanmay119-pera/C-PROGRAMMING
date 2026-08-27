//!                                          ARRAY IN C PROGRAMMING   

//& COLLECTION OF SIMILAR DATA TYPES STORED AT CONTIGUOUS MEMORY LOCATIONS AND THIS IS KNOW AS ARRAY IN C PROGRAMMING.
/*
An array in C is a collection of items of the same data type stored at contiguous (side-by-side) memory locations.

Think of an array like a row of identical lockers. Instead of creating five separate variables (like score1, score2, score3, etc.),
you can create a single array called scores that holds all five values under one name.

Arrays in C are powerful but come with a few strict rules that trip up almost every new programmer.
Keep these core concepts in mind:

1. Indexing Starts at 0: The very first element in an array is at index 0, not 1. If you have an array of size 5, 
the valid indexes are 0, 1, 2, 3, and 4.

2. No Bounds Checking: This is the most dangerous part of C arrays! If you create an array of 5 items and try to access
the 10th item (e.g., scores[10]), C will not stop you. It will just read whatever random data happens to be in 
that memory spot, which can crash your program (a "Segmentation Fault") or cause weird bugs.

3. The Size is Fixed: Once you declare the size of a standard array, it cannot grow or shrink while the program is running. 
If you declare int numbers[10];, it holds exactly 10 integers. No more, no less.

4. You Cannot Copy Arrays with =: You cannot assign one array to another directly like array1 = array2;. To copy an array,
you have to use a for loop to copy each element one by one, or use memory functions like memcpy().

5. The Array Name is a Memory Address: When you use the name of the array without brackets (like scores), 
it acts as a pointer to the memory address of its very first element. This is why when you pass an array into a function,
you are actually passing its memory location, meaning the function can permanently change the original array.
*/

//* SYNTAX FOR AN ARRAY 
/*
1. int marks[3];

2. char name[10];

3. float price[2];

As,we can see in first int type the block integer will be formed and each contain 4 bytes. and the indexing will be 
starting from 0,1,2,3 and also know as 0 - based indexing.
*/

//* INPUT AND OUTPUT
/*
scanf("%d",&marks[0]);
printf("%d",marks[0]);
*/

//* AN ARRAY 
//EXAMPLE NO 1 
#include<stdio.h>
int main(){
    int marks1 = 97;
    int marks2 = 98;
    int marks3 = 89;

    int marks [] = {97,98,89};
    return 0;

}
//EXAMPLE 2 (Input in a array)

#include<stdio.h>
int main(){

    int marks [3];
    printf("enter  phy : ");
    scanf("%d", &marks[0]);

    printf("enter  chem : ");
    scanf("%d", &marks[1]);

    printf("enter  math : ");
    scanf("%d", &marks[2]);
    
    printf("phy = %d, chem = %d, math = %d", marks[0],marks[1],marks[2]);

    return 0;

}

//* INITITALIZATION OF ARRAY 
/*
int marks []={97,99,87}; // correct syntax
int marks [3]={97,99,87}; // correct syntax

memory reserved : 12 bytes (4byte + 4byte + 4byte)
*/
#include<stdio.h>
int main(){
    float price[]={100.0,200.0,300.0}; // inititalization of array 

    print("total price 1 : %f\n");
    print("total price 1 : %f\n");
    print("total price 1 : %f\n");
    return 0;
}

//* POINTER ARITHMETIC 

//^POINTER CAN BE INCREMENTED AND DECREMENTED
/*CASE 1 

int age = 22;
int *ptr = &age;
ptr++; // means 4 byte increment in memory location because int data type is 4 byte.
// ptr = ptr + (1 data type)*/

#include<stdio.h>
int main(){
    int age = 22;
    int *ptr = &age;
    printf("ptr = %u", ptr );
    ptr++;
    printf("ptr = %u", ptr );
    ptr--;
    printf("ptr");
    return 0;
}

/*CASE 2 
float price = 20.00;
float *ptr = &price ;
ptr++;// means 4 byte increment in memory location because float data type is 4 byte.
*/ 

#include<stdio.h>
int main(){
    float price  = 100.00;
    float *ptr = &price;
    printf("ptr = %u", ptr );
    ptr++;
    printf("ptr = %u", ptr );
    ptr--;
    printf("ptr");
    return 0;
}

/*CASE 3 
char star = '*';
char *ptr = &star;
ptr++; // means 1 byte increment in memory location because char data type is 1 byte.*/


#include<stdio.h>
int main(){
    char star = '*';
    char *ptr = &star;
    printf("ptr = %u", ptr );
    ptr++;
    printf("ptr = %u", ptr );
    ptr--;
    printf("ptr");
    return 0;
}

//^ WE CAN ALSO SUBTRACT ONE POINTER FROM ANOTHER.
/*
int age = 22;
int *ptr1 = &age;
int *ptr2 = &age;
int diff = ptr2 - ptr1; // difference in memory addresses
*/
#include<stdio.h>
int main(){
    int age = 22;
    int *ptr1 = &age;
    int *ptr2 = &age;
    int diff = ptr2 - ptr1; // difference in memory addresses
    printf("diff = %d", diff);
    return 0;
}

//^ WE CAN ALSO COMPARE TWO POINTERS.( Pointer should be of same data type)
/*
int age = 22;
int *ptr1 = &age;
int *ptr2 = &age;
if(ptr1 == ptr2){
    printf("pointers are equal");
}
*/
#include<stdio.h>
int main(){
    int age = 22;
    int *ptr1 = &age;
    int *ptr2 = &age;
    if(ptr1 == ptr2){
        printf("pointers are equal");
    }
    return 0;
}

//* ARRAY IS A POINTER
/*
int marks[3] = {97, 98, 89};
int *ptr = marks; // marks is the base address of the array
printf("ptr = %u", ptr);
*/
#include<stdio.h>
int main(){
    int marks[3] = {97, 98, 89};
    int *ptr = marks; // marks is the base address of the array
    printf("ptr = %u", ptr);
    return 0;
}

//* TRAVERSING AN ARRAY.
/*
int aadhar[10];
int *ptr = & aadhar[0];
*/
#include<stdio.h>
int main(){
    int aadhar[5];
    //input
    int *ptr = &aadhar[0];
    for(int i=0; i<5; i++){
        printf("%d index : ", i);
        scanf("%d", &aadhar[i]);
    }
//output
for(int i=0; i<5; i++){
    printf("%d index : %d\n", i,aadhar[i]);
}   
    return 0;
}

//* ARRAY AS FUNCTION ARGUMENTS.

//^ FUNCTION DECLARATION
/*
void printNumbers(int arr[],int n);// square brackets indicate that the function takes an array as an argument
            or 
void printNumbers(int *arr,int n);// pointer to an integer array
*/

//^ FUNCTION CALL
/*
printNumbers(arr,n); // &arr[0] is passed to the function
*/

#include<stdio.h>
void printNumbers(int arr[],int n);
    int main(){
        int arr[] = {1,2,3,4,5};
        printNumbers(arr,6); // &arr[0] is passed to the function

        return 0;
    }

void printNumbers(int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d index : %d\t", i,arr[i]); // \t is used to print a tab space.
    }
    printf("\n");
}

//* MULTI-DIMENSIONAL ARRAYS
//^ 2-D ARRAY
/*
int arr[][]={{1,2,},{3,4}};// declaration and initialization of 2-D array.

> ACCESS
arr[0][0] = 1;
arr[0][1] = 2;
arr[1][0] = 3;
arr[1][1] = 4;
*/
#include<stdio.h>
int main(){
    // 2 student x 3 subjects
    int marks[2][3]; // _ _ _ | _ _ _
    marks[0][0]=90;
    marks[0][1]=87;
    marks[0][2]=91;

    marks[1][0]=88;
    marks[1][1]=92;
    marks[1][2]=85;

    printf("%d",marks[0][0]); // this will tell the marks of student 1 in subject 1
    printf("%d",marks[1][2]); // this will tell the marks of student

    return 0;
}


