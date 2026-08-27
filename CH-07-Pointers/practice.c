//&                                       PROBLEM AND SOLUTION FOR POINTERS IN C                                                //
/*PROBLEM NO 1  
FIND THE OUTPUT OF THE GIVEN CODE.
*/
#include<stdio.h>
int main(){
    int *ptr;
    int x;

    ptr  =&x;
    *ptr =0; // x=0

    printf("x = %d\n" ,x); // 0
    printf(" *ptr = %d\n",*ptr); // 0

    *ptr += 5; // x = 5
    printf("x = %d\n" , *ptr); // 5
    printf(" *ptr = %d\n", *ptr); // 5

(*ptr)++;
printf(" x = %d\n",x); // 6
printf(" *ptr = %d\n",*ptr); // 6

    return 0;

}

//^ solution output will be.
/*

x = 0
 *ptr = 0
x = 5
 *ptr = 5
 x = 6
 *ptr = 6

*/

/*PROBLEM NO 2 
PRINT THE VALUE OF "I" FROM ITS POINTER TO POINTER.
*/
#include<stdio.h>
int main(){
    int i = 5;
    int *ptr = &i;
    int **pptr = &ptr;

    printf("%d\n", **pptr);
    return 0;
}

/*PROBLEM NO 3
SWAP 2 NUMBERS , A AND B.
*/
#include<stdio.h>


int main(){
    void swap(int a,int b);
    void _swap(int *a, int *);
    int x = 3, y = 5;
    __swap(&x,&y);
    printf("x = %d & y= %d\n", x, y);
    return 0;

}
// call by reference
void _swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// call by value 
void swap(int a,int b) {
    int t = a;
    a = b;
    b = a;
    printf("a = %d & b = %d\n", a, b);
}

/* PROBLEM NO 4
WILL THE ADDRESS OUTPUT BE SAME ?
*/
#include<stdio.h>
int main(){
    void printAddress(int n);
    int n = 4;

    printf("%p\n",&n);
    printAddress(n);

    return 0;

}

void printAddress(int n){
    printf("%p\n", n);
}

/*PROBLEM NO 5
WAF TO CALCULATE THE SUM, PRODUCT AND THE AVERAGE OF 2 NUMBERS. PRINT THAT AVERAGE IN THE MAIN FUNCTION.
*/
#include<stdio.h>
int main(){
    void doWork(int a, int b, int *sum, int *prod, int *avg);
    int a = 3, b= 5;
    int sum, prod, avg;
    doWork(a, b, &sum, &prod, &avg);

    printf("sum =%d, prod = %d, avg = %d\n", sum, prod, avg);

    return 0;

}

void doWork(int a, int b, int *sum, int *prod, int *avg){
    *sum = a+b;
    *prod = a*b;
    *avg = (a+b)/2;
    
}

/*PROBLEM NO 6
WAP IN C TO FIND THE MAXIMUM NUMBER BETWEEN TWO NUMBERS USING A POINTER.
*/
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int max;
    
    // Create pointers
    int *ptr1 = &a;
    int *ptr2 = &b;
    
    // Compare using pointers
    if (*ptr1 > *ptr2) {
        max = *ptr1;
    } else {
        max = *ptr2;
    }
    
    printf("Maximum number is: %d\n", max);
    
    return 0;
}

/*PROBLEM NO 7
WAP IN C TO PRIINT THE ELEMENT OF AN ARRAY IN  REVERSE ORDER.
*/
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int i;
    
    printf("Array in reverse order: ");
    
    // Loop from last element to first
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}
/*PROBLEM NO 8
WAP A PROGRAM IN C TO PRINT ALL THE LETTERS IN ENGLISH ALPHABET USING A POINTER.
*/
#include <stdio.h>

int main() {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char *ptr = letters;  // Pointer to array
    
    printf("All letters: ");
    
    // Loop through all 26 letters
    for (int i = 0; i < 26; i++) {
        printf("%c ", *ptr);  // Print character
        ptr++;                // Move to next character
    }
    
    printf("\n");
    
    return 0;
}