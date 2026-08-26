//!                                          STRING IN C PROGRAMMING 

//&  A CHARACTER ARRAY TERMINATED BY A '\O' (null character) IS CALLED A STRING TERMINATION.
/*
In C, there is no built-in string data type like you might find in Python or Java. Instead, a string in C is 
simply an array of characters that is terminated by a special null character (\0).


Because a string is just an array under the hood, it follows the same memory rules: 

the characters are stored side-by-side in contiguous memory locations. The compiler uses the \0 at the end to know
exactly where the string stops.

Here is what declaring and initializing a string looks like in C:

Method 1: Character by character (you must include the '\0')
char greeting1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

Method 2: String literal (the compiler automatically adds the '\0' at the end)
char greeting2[] = "Hello"; 

printf("%s", greeting2); // Output: Hello

POINTS TO REMEMBER:

Always Count the Null Terminator: When sizing your arrays, you must always leave one extra space for the \0. 
If you want to store the word "Apple" (5 letters), your array must be at least size 6 (char fruit[6] = "Apple";). 

If you don't leave room for the null terminator, standard string functions will keep reading memory until they 
crash or print garbage data.

Single Quotes vs. Double Quotes: In C, they mean very different things.

'A' (single quotes) is a single char.

"A" (double quotes) is a string (a character array containing 'A' and '\0').

You Cannot Use = or ==:

Just like standard arrays, you cannot assign a string a new value directly after declaring it
(e.g., greeting2 = "Hi"; will cause an error). 

You also cannot compare strings using if (str1 == str2).To copy or compare strings, you must #include <string.h> and 
use built-in functions like strcpy() (string copy) and strcmp()(string compare).

Modifiable vs. Read-Only Strings: How you declare a string changes how it behaves:

char str[] = "Hello"; creates an array where you can change individual letters later (str[0] = 'J'; makes it "Jello").

char *str = "Hello"; creates a pointer to a read-only string literal. If you try to change a letter (str[0] = 'J';), 
your program will crash with a Segmentation Fault.

Be Careful with Input (scanf): If you use scanf("%s", myString); to get user input, it will stop reading as soon as 
the user hits a space (so "John Doe" just becomes "John"). It also won't stop the user from typing 50 characters into 
a 10-character array, causing a buffer overflow. For safer string input with spaces, use fgets().*/

//^ EXAPMLE 
/*
char name [] = {'S', 'a', 'M', 'p', 'l', 'e', '\0'};

char class [] = {'s', 't', 'R', 'I', 'n', 'G', '\0'};
*/
#include <stdio.h>
int main(){
    char name [] = {'S', 'a', 'M', 'p', 'l', 'e', '\0'};// Character array (the compiler automatically adds the '\0' at the end)
    char class [] = "HELLO";// String literal (the compiler automatically adds the '\0' at the end)
    char str[] = "Hello world "; // Modifiable string

    printf("Name: %s\n", name);
    printf("Class: %s\n", class);
    return 0;
}

//* WHAT HAPPEN IN THE MEMORY?
/*
When you declare a string in C, the compiler allocates memory for the character array and initializes 
it with the

char name[]={'S', 'a', 'M', 'p', 'l', 'e', '\0'}; and char class[] = "HELLO"; statements.
have the same effect, but the second one is more concise and easier to read.

after formation of string block, the memory will look like this:
+---+---+---+---+---+---+---+
| S | a | M | p | l | e | \0 |
+---+---+---+---+---+---+---+
2000 2004 2008 2012 2016 2020 2024
+---+---+---+---+---+---+
| H | E | L | L | O | \0 |  
+---+---+---+---+---+---+
2028 2032 2036 2040 2044 2048

*/

//* STRING FORMAT SPECIFIERS
/*
%s - for strings
%c - for single characters

char name [] = "tanmay";
printf("%s", name); // Output: tanmay
*/
//! IMPORTANT 

//! scanf() CANNOT INPUT MULTI-WORLD STRINGS WITH SPACES.
//! HERE, gets() & puts() COME INTO PICTURE.

//* STRING FUNCTIONS
/*
C provides a set of built-in functions for manipulating strings, which are declared in the <string.h> header file.
 Some commonly used string functions include:

- strcpy() - Copies a string to another string
- strcat() - Concatenates two strings
- strlen() - Returns the length of a string
- strcmp() - Compares two strings
_ gets() - Reads a line of text from the standard input (stdin) and stores it in a string
- puts() - Writes a string to the standard output (stdout) followed by a newline character

gets(str) = DANGEROUS FUNCTION(OUTDATED), IT CAN CAUSE BUFFER OVERFLOW. IT IS RECOMMENDED TO USE fgets() INSTEAD.

fgets(str, sizeof(str), stdin) = SAFER FUNCTION, IT READS A LINE OF TEXT FROM THE STANDARD INPUT (stdin) AND STORES IT IN A STRING,
INCLUDING SPACES. IT ALSO LIMITS THE NUMBER OF CHARACTERS READ TO AVOID BUFFER OVERFLOW.

Puts(str) = (OUTPUT A STRING)WRITES A STRING TO THE STANDARD OUTPUT (stdout) FOLLOWED BY A NEWLINE CHARACTER. IT IS SAFER THAN printf()
BECAUSE IT AUTOMATICALLY HANDLES THE NULL TERMINATOR AND DOES NOT REQUIRE A FORMAT SPECIFIER.
*/

// fgets()
#include <stdio.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of text including spaces,storing it in str
    printf("You entered: %s", str); // Output the string entered by the user
    return 0;
}   

//puts()
#include <stdio.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of text including spaces, storing it in str
    printf("You entered: ");
    puts(str); // Output the string entered by the user followed by a newline character
    return 0;
}

//* STRING USING POINTERS 
/*
char *str = "hello world"; 

store string in a memory and the assigned address is stored in the char pointer 'str'.

The string literal "hello world" is stored in a read-only section of memory, and the pointer str points to the first character
of that string. This means that you can access the characters of the string using pointer arithmetic,
but you cannot modify the string itself. If you try to modify the string, you will get a segmentation fault error.

char *str = "HELLO WORLD"; // CAN BE REINITIALIZED
*/

#include <stdio.h>
int main() {
    char *canChange = "HELLO WORLD"; // CAN BE REINITIALIZED.
    puts(canChange);
    canChange = "HELLO WORLD AGAIN"; // Reassigning the pointer to a new string literal
    puts(canChange);
    return 0;
}

//* STANDARD LIBRARY FUNCTION
/* <string.h>

1. strlen(str)
  count number of character excluding '\o'

2. strcpy(newStr,oldStr)
   copies value of old string to new string.

3. strcat(firstStr, secStr)
   concatenates first string with second string.

4. strcmp(firstStr,secStr)
   compare 2 strings & return a value 

   0 -> string equal
   positive -> first>second(ASCII)
   negative -> first<second(ASCII) 

           
*/

// strlen(str)
#include <stdio.h>
#include <string.h>
int main() {
    void printString(char arr[]);
    int countLength(char arr[]);
    char name[]="tanmay";
    int length = strlen(name);
    printf("length is : %d", length);

    return 0;
}
int countLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i]!='\0'; i++){
        count++;
    }

    return count -1;

}

void printString(char arr[]){
    for(int i=0; arr[i] != '\0' ;i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

//strcpy(newStr,oldStr)

#include<stdio.h>
#include<string.h>

void printString(char arr[]);
int countLength(char arr[]);

int main(){
    char oldStr[]= "oldStr";
    char newStr[]= "newStr";
    strcpy(newStr,oldStr);
    puts(newStr);
}

// strcat

#include<stdio.h>
#include<string.h>
int main(){
    char firstStr[100] = "Hello";
    char secString[] = "World";
    strcat(firstStr, secString);
    puts(firstStr);
}

// strcmp

#include<stdio.h>
#include<string.h>
int main(){
    char firstStr = "Apple";
    char secStr = "banana";
    printf("%d\n", strcmp(firstStr, secStr));
}

