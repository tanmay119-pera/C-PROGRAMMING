//! Practice code for instructions and operators //

/*problem no 1: 
solve int a = 1.9999999;
*/

#include <stdio.h>

int main() {
    int a = (int)(1.9999999); // This will truncate the decimal part and store 1 in 'a'
    printf("The value of a is: %d\n", a); // Output will be: The value of a is: 1
    return 0;
}

/*
problem no 2:
solve these 
5*2-2*3
5*2/2*3
5*(2/2)*3
5+2/2*3
*/

#include <stdio.h>
int main() {
    int result1 = 5 * 2 - 2 * 3; // Result: 4
    int result2 = 5 * 2 / 2 * 3; // Result: 15
    int result3 = 5 * (2 / 2) * 3; // Result: 15
    int result4 = 5 + 2 / 2 * 3; // Result: 8

    printf("Result of 5*2-2*3: %d\n", result1);
    printf("Result of 5*2/2*3: %d\n", result2);
    printf("Result of 5*(2/2)*3: %d\n", result3);
    printf("Result of 5+2/2*3: %d\n", result4);



/* problem no 3: 
check divisibility by 2 */

    int x;
    printf("enter a number :");
    scanf("d%",&x);
    print("%d",x% 2==0);
    return 0;
}

/*problem no 4:
Are the following valid or not ?
a. int a = 8^8//valid
b. int x; int y = x;//valid
c. int x,y = x; // invalid
d. char stars = '**'; // invalid

*/

# include <stdio.h>

int main(){
    print("d%",8^8); // valid
    int x;int y = x; // valid

    return 0;

}

/*problem 5:
print 1(true) or (false) for following statement:
a. if it's sunday & it's showing -> true
b. if it's monday or it's raining -> true
c. if a number is a greater than 9 & less than 100 -> true
(2 digit number)
*/

# include <stdio.h> // (a.)

int main(){
    int isSunday = 0;
    int isSnowing = 1;
    printf("%d \n", isSunday && isSnowing);
        return 0;


}

# include <stdio.h> // (b.)

int main(){
    int x;
    printf("enter number :");
    scanf("%d", &x);
    printf("%d \n" , x>9 && x<100);
        return 0;


}

# include <stdio.h>

int main(){
    int isSunday = 0;
    int isSnowing = 1;
    printf("%d \n", isSunday && isSnowing);
        return 0;


}
