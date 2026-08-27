// PROBLEM 1. //
/* WAP TO FIND SUM OF TWO NUMBERS */

// SOLUTION 1 //
#include <stdio.h>
int main(){
    int a,b;
    printf("enter a");
    scanf("%d",&a);
    printf("enter b");
    scanf("%d",&b);
    int sum = a+b;
    printf("sum of %d and %d is %d",a,b,sum);  
    return 0;
}

// SOLUTION 2 //
#include <stdio.h>

int main() {
    int a, b, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("Sum of %d and %d is %d", a, b, sum);
    return 0;
}

// PROBLEM 2. //
/* WAP TO FIND AREA OF SQUARE (SIDE IS GIVEN)*/

#include <stdio.h>
int main() {
    float side;
    printf("Enter the side of the square: ");
    scanf("%f", &side);
    printf("Area of the square is: %f", side * side);
    return 0;
}

// PROBLEM 3. //
/* WAP TO FIND AREA OF CIRCLE (RADIUS IS GIVEN) */

#include <stdio.h>
int main() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area = 3.14 * radius * radius;
    printf("Area of the circle is: %f", area);
    return 0;
}

// SOLUTION 2 //
#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area = PI * radius * radius;
    printf("Area of the circle is: %f", area);
    return 0;
}