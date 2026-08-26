//!                                             CONDITIONAL STATEMENT                                                          //

/*A conditional statement is a programming construct that allows your code to make decisions and execute
 different blocks of code based on whether a condition is true or false.
 
 TYPES:

(A) if-else 
(B) switch 

IF-ELSE SYNTAX

if (condition) {
// do something if TRUE
}
else {
// do something if FALSE
}
 */

//==========================================================================================================================================================

//? if-else statement 

#include<stdio.h>

int main(){
    int age;
    printf("entr age : ");
    scanf("%d",&age);


    if(age>18){
        printf("adult\n");
        printf(" you can vote \n");
        printf(" you can drive \n");
    }
    else {
        printf("minor\n");
        printf(" you can not vote\n");
        printf("you can not drive\n");
    }

    printf("thank you");

    return 0;
}

//===============================================================================================================================================

//~ Else If (syntax)
/*
if(condition 1){
# do something if true 
}
else if (condition 2){
# do something if 1st is false nd 2nd is true 
}
*/

#include<stdio.h>

int main(){
    int age;
    printf("entr age : ");
    scanf("%d",&age);


    if(age>18){
        printf("adult\n");
        printf(" you can vote \n");
        printf(" you can drive \n");
    }
    else if (age >13 && age <18){
        print("teenager\n");
    }
    else {
        printf("child");
    }

    printf("thank you");

    return 0;
}

//==============================================================================================================================================

//* TERNARY OPERATORS //
// Condition? doSomething if TRUE : doSomething if False;//


#include<stdio.h>

int main(){
    int age;
    printf("entr age : ");
    scanf("%d",&age);

    age >= 18? printf("adult \n"): printf("not adult \n"); // Ternary operator 

    return 0;

}

//=====================================================================================================================================

//? SWITCH OPERATOR //

/*   (syntax)

switch(number){
case C1: // do something 
       break;
case C2: // do something 
       break;
default : // do something   

SWITCH PROPERTIES

A. CASES CAN BE IN ANY ORDER

B. NESTED SWITCH (SWITCH INSIDE SWITCH) ARE ALLOWED

}
*/
#include<stdio.h>

int main(){ 
        int day; //1-mon;2-tue;3-wed;4-thu;5-fri;6-sat;7-sun;
        printf("enter day(1-7) : ");
        scanf("%d", &day);

        switch (day){
        case 1 : printf("monday \n");
            break;
        case 2 : printf("tuesday \n");
            break;
        case 3 : printf("wednesday \n");
            break;
        case 4 : printf("thursday \n");
            break;
        case 5 : printf("friday \n");
            break;  
        case 6 : printf("saturday \n");
            break; 
        case 7 : printf("sunday \n");
            break;     
        default : printf("not a valid day! \n");
        }

        return 0;
    }

// NESTED SWITCH 
#include<stdio.h>
int main() {
    int number;
    printf("enter number : ");
    scanf("%d", &number);

    if (number >= 0) {
        printf("positive \n");
        if (number % 2 ==0 ){
             printf("even \n");
        } else {
            printf("odd \n");
        }     
            
    } else{
        printf("negative \n");
    }

    return 0;

}


    









