#include<stdio.h>
int printOdd(int n);

int main(){
    int num;
    printf("enter a num: ");
    scanf("%d", &num);
    printf("sum of odd digits: %d\n", printOdd(num));
    return 0;
}

int printOdd(int n){
    if(n == 0){
        return 0;
    }
    int digit = n % 10;
    int sum = printOdd(n / 10);
    if(digit < 0) digit = -digit;
    if(digit % 2 != 0){
        sum += digit;
    }
    return sum;
}
