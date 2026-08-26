//!      PRACTICE DMA PROBLEM IN C PROGRAMMING

/*PROBLEM NO 1 
WAP TO ALLOCATE MEMORY  TO STORE 5 PRICES.*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    float *prices;
    prices = (float*)malloc(5 * sizeof(float)); // ALLOCATES MEMORY FOR 5 FLOATS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
    if(prices == NULL){
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }  
    for(int i = 0; i < 5; i++){
            printf("Enter price %d: ", i + 1);
            scanf("%f", &prices[i]);
        }
    // DO NOT FORGET TO FREE THE ALLOCATED MEMORY
    free(prices);
    return 0;
}

/*PROBLEM NO 2
WAP TO ALLOCATE MEMORY OF SIZE N, WHERE N IS ENTERED BY THE USER*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float *prices = (float*)malloc(n * sizeof(float));
    if(prices == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Enter price %d: ", i + 1);
        scanf("%f", &prices[i]);
    }
    free(prices);
    return 0;
}

/*PROBLEM NO 3
IN PROBLEM 1, FREE THE MEMORY ALLOCATED WITH CALLOC()*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    float *prices;
    prices = (float*)calloc(5, sizeof(float)); // ALLOCATES MEMORY FOR 5 FLOATS AND INITIALIZES THEM TO ZERO.
    if(prices == NULL){
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }
    for(int i = 0; i < 5; i++){
        printf("Enter price %d: ", i + 1);
        scanf("%f", &prices[i]);
    }
    // DO NOT FORGET TO FREE THE ALLOCATED MEMORY
    free(prices);
    return 0;
}

/*PROBLEM NO 4
CREATE AN ARRAY OF SIZE 5(USING CALLOC()) AND ENTER ITS VALUES FROM THE USER.*/

#include <stdio.h>
#include <stdlib.h>
int main() {    
    int *arr;
    arr = (int*)calloc(5, sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND INITIALIZES THEM TO ZERO.
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }
    for(int i = 0; i < 5; i++){
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // DO NOT FORGET TO FREE THE ALLOCATED MEMORY
    free(arr);
    return 0;
}

/*PROBLEM NO 5
ALLOCATE MEMO TO STORE FIRST 5 ODD NUMBERS, THEN REALLOCATE IT TO STORE FIRST 6 EVEN NUMBERS.*/

//METHOD 1 (array of odd numbers is stored first, then reallocated to store even numbers)

#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    arr = (int*)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR 5 INTEGERS AND RETURNS A POINTER TO THE FIRST ELEMENT OF THE ARRAY.
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1; // Exit the program if memory allocation fails
    }
    // Store first 5 odd numbers
    for(int i = 0; i < 5; i++){
        arr[i] = 2 * i + 1; // 1, 3, 5, 7, 9
    }
    // Reallocate memory to store first 6 even numbers
    arr = (int*)realloc(arr, 6 * sizeof(int)); // RESIZES THE MEMORY BLOCK TO HOLD 6 INTEGERS.
    if(arr == NULL){
        printf("Memory reallocation failed\n");
        return 1; // Exit the program if memory reallocation fails
    }
    // Store first 6 even numbers
    for(int i = 0; i < 6; i++){
        arr[i] = 2 * i; // 0, 2, 4, 6, 8, 10
    }
    // Print the even numbers
    printf("First 6 even numbers:\n");
    for(int i = 0; i < 6; i++){
        printf("%d\n", arr[i]);
    }
    // DO NOT FORGET TO FREE THE ALLOCATED MEMORY
    free(arr);
    return 0;
}

//METHOD 2 (pointer is used to store first 5 odd numbers, then reallocated to store first 6 even numbers)

#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr;
    ptr = (int*)malloc(5 * sizeof(int)); // ALLOCATES MEMORY FOR
    ptr[0] = 1;
    ptr[1] = 3;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 9;

    for(int i = 0; i < 5; i++){
        printf("%d\n", ptr[i]);
    }

    ptr = realloc(ptr,6);
    ptr[0] = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 8;
    ptr[4] = 10;
    ptr[5] = 12;
    for(int i = 0; i < 6; i++){
        printf("%d\n", ptr[i]);
    }
    free(ptr);
    return 0;
}
