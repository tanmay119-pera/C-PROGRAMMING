//!                                             PRACTICE QUESTIONS FOR ARRAY 
/*PROBLEM 1
WAP TO ENTER PRICE OF 3 ITEMS AND PRINT THEIR FINAL COST WITH GST.
*/
// SOLUTION TYPE 1 

#include<stdio.h>
int main(){

    float price[3];
    printf("enter ITEM 1 : ");
    scanf("%f", &price[0]);

    printf("enter  ITEM 2 : ");
    scanf("%f", &price[1]);

    printf("enter ITEM 3 : ");
    scanf("%f", &price[2]);
    
    printf("FINAL COST IS : ");
    printf("ITEM 1 = %f, ITEM 2 = %f, ITEM 3  = %f", price[0]+(0.18*price[0]),price[1]+(0.18*price[1]),price[2]+(0.18*price[2]));

    return 0;

}
// SOLUTION TYPE 2

#include<stdio.h>
int main(){

    float price[3];
    printf("enter 3 ITEMS : ");
    scanf("%f", &price[0]);
    scanf("%f", &price[1]);
    scanf("%f", &price[2]);

    print("total price 1 : %f\n", price[0]+(0.18*price[0]));
    print("total price 1 : %f\n", price[1]+(0.18*price[1]));
    print("total price 1 : %f\n", price[2]+(0.18*price[2]));

    return 0;

}

/*PROBLEM 2
WAF TO COUNT THE NUMBER OF ODD NUMBERS IN A ARRAY.*/

//SOLUTION TYPE 1 
#include<stdio.h>
int countOdd(int arr[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]%2!=0){    
            count++;
        }
    }
    return count;
}
int main(){
    int arr[5];
    printf("enter 5 numbers : ");
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }   
    printf("number of odd numbers : %d", countOdd(arr,5));
    return 0;
}   

//SOLUTION TYPE 2 
#include<stdio.h>
int main(){
    int countOdd(int arr[], int n);
    int arr[]={1,2,3,4,5,6,7,8};
    printf("%d", countOdd(arr,6));
   return 0;
}

int countOdd(int arr[],int n){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] % 2  != 0){ //odd
            count++;

        }
    }

    return count;
}

/*PROBLEM NO 3
int arr[]={1,2,3,4,5}
for the given array, what will the following give?
a.) *(arr+2)
b.) *(arr=5)
*/
#include<stdio.h>
int main(){
    int countOdd(int arr[], int n);
    int arr[]={1,2,3,4,5,6,7,8};
    printf("%d \n", *(arr+2));
    printf("%d \n", *(arr+5));

   return 0;
}

int countOdd(int arr[],int n){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] % 2  != 0){ //odd
            count++;

          }
      }

  return count;

}
/*PROBLEM NO 4
WRITE A FUNCTION TO REVERSE AN ARRAY*/
//! N-I-1 FOR REVERSING AN ARRAY.
//classical type 
#include<stdio.h>
int main(){
    void reverse(int arr[],int n);
    void printArr(int arr[], int n);

    int arr[]={1,2,3,4,5};
    reverse(arr, 5);
    printArr(arr,5);
    
   return 0;
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i ++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int n){
    for(int i = 0; i<n/2; i++){
        int firstVal = arr[i];
        int secondVal = arr[n-i-1];
        arr[i] = secondVal;
        arr[n-i-1]= firstVal;
    }
}

// another way to reverse an array
#include<stdio.h>
int main(){
    void reverse(int arr[],int n);
    void printArr(int arr[], int n);
    int arr[]={1,2,3,4,5};
    reverse(arr, 5);
    printArr(arr,5);
   return 0;
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i ++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* PROBLEM NO 5
WAP TO STORE THE FIRST N FIBONACCI NUMBERS.
*/
#include<stdio.h>
int main(){
    int n;
    printf("enter n (n>2) : ");
    scanf("%d", &n);
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i=0; i<n; i++){
        printf("%d\t", fib[i]);
    }
    return 0;
}   

/*PROBLEM NO 6
CREATE A 2D ARRAY, STORING THE TABLES OF 2 AND 3.
*/
//SOLUTION TYPE 1

#include<stdio.h>
int main(){
    int table[2][10];
    for(int i=0; i<2; i++){
        for(int j=0; j<10; j++){
            table[i][j] = (i+2)*(j+1);
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<10; j++){
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//SOLUTION TYPE 2

#include <stdio.h>

int main() {
    int table[2][10];  // 2 rows (for tables 2,3), 10 columns (1-10)
    
    // Store table of 2 in first row
    for (int j = 0; j < 10; j++) {
        table[0][j] = 2 * (j + 1);
    }
    
    // Store table of 3 in second row
    for (int j = 0; j < 10; j++) {
        table[1][j] = 3 * (j + 1);
    }
    
    // Display the tables
    printf("Table of 2:\n");
    for (int j = 0; j < 10; j++) {
        printf("2 x %d = %d\n", j + 1, table[0][j]);
    }
    
    printf("\nTable of 3:\n");
    for (int j = 0; j < 10; j++) {
        printf("3 x %d = %d\n", j + 1, table[1][j]);
    }
    
    return 0;
}

//SOLUTION TYPE 3

#include <stdio.h>
int main() {
    int table[2][10]; // 2 rows for tables of 2 and 3, 10 columns for numbers 1 to 10
    storeTables(table, 0, 10, 2);
    storeTables(table, 1, 10, 3);

    for(int i = 0; i<10; i++){
        printf("%d\t", table[0][i]);
    }

    for (int i = 0; i<10; i++){
        printf("%d\t", table[1][i]);
    }
    printf("\n");
    return 0;
}

void storeTables(int arr[][10], int n, int m, int number){
    for(int i=0; i<m; i++){
        arr[n][i] = number * (i+1);
    
    }
}

/*PROBLEM NO 7
IN AN ARRAY OF NUMBERS, FIND HOW MANY TIMES DOES A NUMBER 'X' OCCUR.
*/

//sOLUTION TYPE 1
#include<stdio.h>
int main(){
    int countOccurrences(int arr[], int n, int x);
    int arr[]={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int x;
    printf("enter the number to find occurrences : ");
    scanf("%d", &x);
    int occurrences = countOccurrences(arr, 15, x);
    printf("The number %d occurs %d times in the array.\n", x, occurrences);
    return 0;
}
int countOccurrences(int arr[], int n, int x){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            count++;
        }
    }
    return count;
}

//SOLUTION TYPE 2
#include <stdio.h>

int main() {
    int arr[10] = {2, 5, 3, 5, 8, 5, 1, 5, 9, 5};
    int x, count = 0;
    
    printf("Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nEnter the number to find: ");
    scanf("%d", &x);
    
    // Count occurrences of x
    for (int i = 0; i < 10; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    
    printf("\nThe number %d occurs %d times\n", x, count);
    
    return 0;
}

/*PROBLEM NO 8
WAP TO PRINT THE LARGEST NUMBER IN AN ARRAY.
*/

//SOLUTION TYPE 1
#include<stdio.h>
int main(){
    int findLargest(int arr[], int n);
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int largest = findLargest(arr, 10);
    printf("The largest number in the array is: %d\n", largest);
    return 0;
}
int findLargest(int arr[], int n){
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

//SOLUTION TYPE 2
#include <stdio.h>

int main() {
    int arr[10] = {15, 42, 8, 95, 23, 67, 34, 88, 12, 50};
    int largest = arr[0];
    
    printf("Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    // Find largest number
    for (int i = 1; i < 10; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    printf("\n\nLargest number: %d\n", largest);
    
    return 0;
}


/*PROBLEM NO 9
WAP TO INSERT AN ELEMENT AT THE END OF AN ARRAY.
*/

//SOLUTION TYPE 1
#include<stdio.h>
int main(){
    void insertAtEnd(int arr[], int *n, int element);
    int arr[100] = {1, 2, 3, 4, 5}; // initial array with 5 elements
    int n = 5; // current number of elements in the array
    int element;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &element);
    insertAtEnd(arr, &n, element);
    printf("Array after insertion: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
void insertAtEnd(int arr[], int *n, int element){
    arr[*n] = element; // insert the new element at the end
    (*n)++; // increment the size of the array
}

//SOLUTION TYPE 2
#include <stdio.h>

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int size = 5;  // Current number of elements
    int element;
    
    printf("Current array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nEnter element to insert: ");
    scanf("%d", &element);
    
    // Insert at the end
    arr[size] = element;
    size++;
    
    printf("\nArray after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
