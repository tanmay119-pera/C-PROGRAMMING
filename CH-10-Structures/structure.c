//!                                        STRUCTURE IN C PROGRAMMING      

//^ A COLLECTION OF VALUES OF DIFFERENT DATA TYPES

/*A structure is a user-defined data type that allows you to group different types of variables together under a single name.

Think of it this way: An array can only hold variables of the same data type (like 10 integers). But a structure can hold variables
of different data types (like an integer, a float, and a string).

Structures are perfect for representing real-world entities. For example, a "Student" might have a name (string),
a roll number (integer), and a grade percentage (float).

POINTS TO REMEMBER!!

Strings Need a Stop Sign (\0)

1. A string in C is just an array of characters. The compiler doesn't know how long it is, so you must ensure there is a
null terminator ('\0') at the end of your valid characters. Without it, C will just keep reading random garbage 
memory until the program crashes.

2. Arrays Always Start at Zero
If you declare char str[100];, the very first character is at str[0] and the absolute last character you can safely use
is str[99]. Trying to access str[100] will overwrite memory that doesn't belong to the array.

3. Beware the Single Equals Sign (=)
This is the most common logic bug for beginners:
if (x = 5) assigns 5 to x, and evaluates as TRUE. The code inside the if block will always run.
if (x == 5) actually checks if x is equal to 5.

4. Variables Start as "Garbage"
C is built for speed, so it does not clean up memory for you. If you declare int max_freq;

and don't set it to 0, it will start with whatever random number was left in that memory slot from a previous program.
Always initialize your counters!

5. Integer Division is Ruthless
In C, if you divide two integers, the decimal is chopped off entirely (not rounded).
5 / 2 equals 2.
If you need the decimal fraction, at least one number must be a float: 5.0 / 2 equals 2.5.

6. Structures Are Just Blueprints
When you define a struct { ... };, you are just telling the compiler what a concept looks like. 
It takes up zero memory and you can't put data into it until you actually create a variable of that type
(e.g., struct Student s1;).*/

//& EXAMPLE 
/*FOR A STUDENT STORE THE FOLLOWING :
1. name(string)
2. roll no(integer)
3. cgpa(float)*/

//^ SYNTAX
/*
struct student {             struct student s1;
  char name [100];           s1.cgpa = 7.5;
  int roll;
  float cgpa;
}
*/

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
    s1.roll = 18979;
    s1.cgpa = 9.2;
    strcpy(s1.name, "tanmay");

printf("student name = %s\n", s1.name);
printf("student roll no = %d\n", s1.roll);
printf("student cgpa = %f\n", s1.cgpa);

return 0;
}

//* STRUCTURE IN A MEMORY 
/*
struct student {
char name [100];
int roll;
float cgpa;
}
STRUCTURES ARE STORED IN CONTIGUOUS MEMORY LOCATION
*/

//* ARRAY OF STRUCTURE
/*
First type normal datatype then variable then the size of array.
struct student ECE[100];
struct student COE[100];
struct student IT[100];

ACCESS
IT[0].roll = 200;
IT[0].cgpa = 7.6; 
*/
#include <stdio.h>
#include <string.h>

struct student{
    int roll;
    float cgpa;
    char name[100];
};

int main(){
    struct student ece[100];
    ece[0].roll = 1164;
    ece[0].cgpa = 9.2;
    strcpy(ece[0].name,"tanmay");

    printf("name = %s\n", ece[0].name);
    printf("name = %s\n", ece[0].roll);
    printf("name = %s\n", ece[0].cgpa);

}

//* INITIALIZING STRUCTURES 

/*struct student s1 = {"tanmay",1664,7.9};
struct student s1 = {"anushka",1665,8.7};
struct student s1 = {0};*/

#include <stdio.h>
#include <string.h>

struct student{
    
    char name[100];
    int roll;
    float cgpa;
    
};

int main(){
    struct student s1 = {"tanmay",1664,9.2};
    struct student s2 = {"anushka",1665,8.2};
    struct student s3 = {0};
    printf("student roll = %d\n",s1.roll);

    return 0;

}

//* POINTER TO STRUCTURES
/*
struct student s1;
struct student *ptr;
ptr =&s1;
*/ 

#include <stdio.h>
#include <string.h>

struct student{
    
    char name[100];
    int roll;
    float cgpa;
    
};

int main(){
    struct student s1 = {"tanmay",1664,9.2};
    printf("student roll = %d\n",s1.roll);

    struct student *ptr = &s1;
    printf("student roll = %d\n", (*ptr).roll); //pointer to structure 

    return 0;

}
    
//* ARROW OPERATOR 
/*
(*ptr).code <-----> ptr->code
*/

#include <stdio.h>
#include <string.h>

struct student{
    
    char name[100];
    int roll;
    float cgpa;
    
};

int main(){
    struct student s1 = {"tanmay",1664,9.2};
    printf("student roll = %d\n",s1.roll);

    struct student *ptr = &s1;
    printf("student roll = %d\n", (*ptr).roll);
    printf("student roll = %d\n", ptr->roll);//arrow to structure 
    printf("student name = %s\n", ptr->roll);

    return 0;

}

//* PASSING STRUCTURE TO FUNCTION 
// FUNCTION PROTOTYPE
// void printInfo(struct student s1);

#include <stdio.h>
#include <string.h>

struct student{
    
    char name[100];
    int roll;
    float cgpa;
    
};
void printInfo(struct student s1);

int main(){
    struct student s1 = {"tanmay",1664,9.2};
    printf("student roll = %d\n",s1.roll);

    struct student *ptr = &s1;
    printf("student roll = %d\n", (*ptr).roll);
    printf("student roll = %d\n", ptr->roll);
    printf("student name = %s\n", ptr->roll);
    return 0;
}

void printInfo(struct student s1){
    print("student information : \n");
    printf("student roll = %d\n", s1.name);
    printf("student roll = %d\n", s1.roll);
    printf("student name = %s\n", s1.cgpa);

    s1.roll = 1660;

}
//* TYPEDEF KEYWORD
/*USED  TO CREATE ALIAS FOR DATA TYPES 
alias means alternative name.

typedef struct ComputerEngineeringStudent{
        int roll;
        float cgpa;
        char name[100];
} coe;

coe student1;
*/
#include<stdio.h>
#include<string.h>
typedef struct student{
    int roll;
    float cgpa;
    char name[100];
} stu;

typedef struct computerEngineeringStudent{
    int roll;
    float cgpa;
    char name[100];
} coe;

int main(){
    coe s1;
    s1.roll = 1664;
    s1.cgpa = 9.2;
    strcpy(s1.name, "tanmay");

    printf("student name is %s\n", s1.name);

    return 0;
}
