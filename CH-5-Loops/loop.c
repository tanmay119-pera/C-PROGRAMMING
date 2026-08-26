//!                                           LOOP CONTROL INSTRUCTION 

//? TO REPEAT SOME PARTS OF THE PROGRAM. 

/* A loop is a control flow structure that repeatedly executes a specific block of code as long as a given condition remains true

Instead of writing the same lines of code multiple times, a loop automates repetitive tasks, 
reducing redundancy and making your program much more efficient. Once the condition evaluates to false, the loop terminates, 
and the program moves on to the next set of instructions.

THE ANATOMY OF LOOP 

Regardless of the type, every loop generally relies on three core components to function without running forever 
(an infinite loop):

1. Initialization: Setting a starting value for a counter variable (e.g., int i = 0;).

2. Condition: The test evaluated before each iteration (e.g., i < 5;). If true, the loop runs. If false, it stops.

3. Update: Modifying the counter variable after each cycle (e.g., i++ or i--) so the condition eventually becomes false.

TYPES OF LOOP 

A) FOR LOOP 

FOR loop is an entry-controlled control flow statement that allows you to execute a block of code repeatedly for a specific,
 known number of times.

It is highly efficient because it condenses the three essential parts of a loop—initialization, condition,
and update—into a single, readable line of code.

B) WHILE LOOP 

WHILE loop is an entry-controlled loop that repeatedly executes a block of code as long as a specified condition remains true.

Unlike a for loop, which is used when you know the exact number of iterations, a while loop is best used when you do not know
how many times the loop needs to run in advance. It simply keeps running until its condition is no longer met.

C) DO WHILE 

DO-WHILE loop is an exit-controlled loop that executes a block of code first, and then checks the condition.

Because the condition is evaluated at the very end of the loop, the code inside a do-while loop is guaranteed
to run at least once, even if the condition is false right from the beginning. This makes it perfect for scenarios 
where you need to prompt a user for input or display a menu before checking if they want to continue.
.*/


//* FOR LOOP 
/*
for(initialisation; condition; updation){
# do something 
}
*/
//syntax "for loop"
#include<stdio.h>
int main(){
    for(int i=1; i<=5; i=i+1){
        printf("hello world \n ");
    }
    return 0;

}

// program to print number 1 to 100 using "for loop"

#include<stdio.h> 
int main(){
    for(int i=1; i<=100; i=i+1){ // i=i+1 == i++
        printf("%d \n ",i);
    }
    return 0;

}

// program to print number 10 to 1 using "for loop"

#include<stdio.h>
int main(){
    for(int i=10; i<=1; i=i-1 ){
        printf("%d \n",i);
    }
    return 0;
}

//& INCREMENT OPERATORS ("++i(pre increment)" / "i++( post increment)"")

#include<stdio.h>
int main(){
    int i=1;
    printf("%d \n",i++); // use, then increase (pre increment)
    printf("%d \n",i);

    printf("%d \n",++i); // increase, then use (post increment)
    printf("%d \n",i);
    
    return 0;
}

//& DECREMENT OPERATORS ("--i(pre decrement)" / "i--(post decrement)")

#include<stdio.h>
int main(){
    int i=1;
    printf("%d \n",--i); // use, then decrease (pre decrement)
    printf("%d \n",i); 

    printf("%d \n",i--); // decrease, then use (post decrement)
    printf("%d \n",i);
    
    return 0;

}

//^ LOOP COUNTER CAN BE FLOAT OR EVEN CHARACTER
#include<stdio.h>
int main(){

    for(float i=1.0; i<=5.0; i++){
        printf("%f \n",i);
    }
    for(char ch='a'; ch<='z'; ch++){
        print("%c \n",ch);
    }
    return 0;
}

//? INFINITE LOOP
#include<stdio.h>
int main(){
    for(int i=1; ;i++){
        printf("hello world \n");
    }
    
    return 0;
}

//* WHILE LOOP
/*
while(condition){
#do something
}
*/
// syntax("while loop")
#include<stdio.h>
int main(){
    int i=1;
    while(i<=5){
        printf("hello world \n");
        i++;
    }
    return 0;
}


//* DO-WHILE LOOP
/*
do{
# do something 
}while(condition);
*/

#include<stdio.h>
int main(){
    int i = 1;
    do {
        printf("%d\n",i);
        i++; // "or we can also use post increment/decrement and pre increment/decrement" 
    }while(i<=5);
    return 0;
}

//* BREAK STATEMENT ("EXIT LOOP")

#include<stdio.h>

int main(){
    for(int i=1; i<=5; i++){
        if(i == 3 ){
            break;
        }
        printf("%d\n",i);
    }

    printf("END");

    return 0;
    
}

//* CONTINUE STATEMENT ("SKIP TO NEXT ITERATION")
#include<stdio.h>
int main(){
    for(int i=1; i<=5; i++){
        if(i == 3){ // SKIP
            continue; 
        }
        printf("%d\n",i);
    }
    return 0;

}