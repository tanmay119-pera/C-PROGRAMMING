//!      PRACTICE QUESTIONS FOR STRINGS IN C

/*PROBLEM NO 1
CREATE A STRING firstName AND lastName TO STORE DETAILS OF USER AND PRINT ALL THE CHARACTER USING LOOP.*/

#include <stdio.h>
int main() {
    char firstName[20], lastName[20];
    printf("Enter your first name: ");
    scanf("%19s", firstName); // Limit input to avoid buffer overflow
    printf("Enter your last name: ");
    scanf("%19s", lastName); // Limit input to avoid buffer overflow

    printf("First Name: ");
    for (int i = 0; firstName[i] != '\0'; i++) {
        printf("%c ", firstName[i]);
    }
    printf("\n");

    printf("Last Name: ");
    for (int i = 0; lastName[i] != '\0'; i++) {
        printf("%c ", lastName[i]);
    }
    printf("\n");

    return 0;
}

//SOLUTION TYPE 2 
#include <stdio.h>
int main() {
    void printString(char arr[]);
    char firstName[]= "tanmay";
    char lastName[]= "srivastava";

    printString(firstName);
    printString(lastName);

    return 0;
}

void printString(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

/*PROBLEM NO 2
ASK THE USER TO ENTER THEIR FIRSTNAME AND PRINT IT BACK TO THEM.
&
ALSO TRY THIS WITH THEIR FULLNAME. */

// with firstname
#include <stdio.h>
int main() {
    void printString(char arr[]);
    char firstName[50];
    scanf("%s", firstName);
    printf("your first name is: %s\n", firstName);
   
    return 0;
}

void printString(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// with fullname
#include <stdio.h>
int main() {
    char fullName[50];
    scanf("%s\n", fullName); // Read full line including spaces
    printf("your full name is: %s\n", fullName);

   
    return 0;
}
//! IMPORTANT 

//! scanf() CANNOT INPUT MULTI-WORLD STRINGS WITH SPACES.
//! HERE, gets() & puts() COME INTO PICTURE.

void printString(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}


//correct way 
#include <stdio.h>
int main() {
    char fullName[50];
    printf("Enter your full name: ");
    fgets(fullName, sizeof(fullName), stdin); // Read full line including spaces
    printf("Your full name is: %s\n", fullName);
    return 0;
}

/*PROBLEM NO 3
CREATE A PROGRAM THAT INPUTS USER'S NAME AND PRINT ITS LENGTH.*/

//SOLUTION TYPE 1

#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Length of your name is: %lu\n", strlen(name) - 1); // Subtract 1 to exclude the newline character
    return 0;
}
//SOLUTION TYPE 2

#include <stdio.h>
int main() {
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    int length = 0;
    while (name[length] != '\0') {
        length++;
    }
    printf("Length of your name is: %d\n", length - 1); // Subtract 1 to exclude the newline character
    return 0;
}

//SOLUTION TYPE 3

#include <stdio.h>
int main() {
    void printString(char arr[]);
    int countLength(char arr[]);
    char name[100];
    fgets(name, 100, stdin);

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

/*PROBLEM NO 4
TAKE A STRING INPUT FROM THE USER USING %C.*/

#include <stdio.h>
#include <string.h>
int main() {
    void printString(char arr[]);
    int countLength(char arr[]);
    char str[100];
    char ch;
    int i = 0;

    while(ch != '\n'){
        scanf("%c",&ch);
        str[i] = ch;
        i++;
    }
    str[i]='\0';
    puts(str);
    return 0;
}
int countLength(char arr[]){
    int count = 0;
    for(int i = 0; arr[i]!='\0'; i++){
        count++;
    }

    return count -1;
}

/*PROBLEM 5
SALTING : Salting is the security practice of adding a unique, random string of characters (called a "salt") to a user's password before it is put through a hashing algorithm and stored in a database.
FIND THE SALTED FORM OF A PASSWORD ENTERED BY USER IF THE SALT IS "123" & ADDED AT THE END.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    char salt[] = "123";
    
    // Get password from the user
    printf("Enter your password: ");
    scanf("%s", password);
    
    // Append the salt to the end of the password
    strcat(password, salt);
    
    printf("Salted Password: %s\n", password);
    
    return 0;
}
/*PROBLEM NO 6
WAF NAMED SLICE, WHICH TAKES A STRING AND RETURN A SLICED STRING FROM INDEX N TO M.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimal slice function
char* slice(char* str, int n, int m) {
    int len = m - n + 1;               // Calculate slice length
    char* result = malloc(len + 1);    // Allocate memory (+1 for '\0')
    
    strncpy(result, str + n, len);     // Copy characters starting from index n
    result[len] = '\0';                // Add null terminator
    
    return result;
}

int main() {
    char* my_slice = slice("Programming", 3, 6);
    
    printf("%s\n", my_slice); // Outputs: gram
    
    free(my_slice); // Free memory
    return 0;
}
/*PROBLEM NO 7
WAF TO COUNT THE OCCURRENCE OF VOWELS IN A STRING.
*/
#include <stdio.h>

// Function to count vowels
int count_vowels(const char* str) {
    int count = 0;
    
    // Loop through the string until the null terminator '\0' is reached
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        // Check for both lowercase and uppercase vowels
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    
    return count;
}

int main() {
    char text[] = "Hello World";
    
    printf("Total vowels: %d\n", count_vowels(text)); // Outputs: 3
    
    return 0;
}

/*PROBLEM NO 8
CHECK IF A GIVEN CHARACTER IS PRESENT IN A STRING OR NOT.*/

#include <stdio.h>

// Function to check if a character is present
int is_present(const char* str, char target) {
    // Loop through the string until the null terminator '\0'
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            return 1; // Character found
        }
    }
    
    return 0; // Character not found
}

int main() {
    char text[] = "Programming";
    
    if (is_present(text, 'm')) {
        printf("The character is present.\n");
    } else {
        printf("The character is NOT present.\n");
    }

    return 0;
}
/*PROBLEM 9
WAP TO CONVERT ALL LOWERCASE VOWELS TO UPPERCASE IN A STRING.*/

#include <stdio.h>

// Function to convert lowercase vowels to uppercase
void uppercase_vowels(char* str) {
    // Loop through the string until the null terminator '\0'
    for (int i = 0; str[i] != '\0'; i++) {
        
        // Check if the character is a lowercase vowel
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || 
            str[i] == 'o' || str[i] == 'u') {
            
            // Convert to uppercase by subtracting 32 (ASCII logic)
            str[i] = str[i] - 32; 
        }
    }
}

int main() {
    // Note: We use a character array because string literals (char* text = "...") 
    // are read-only and cannot be modified in C.
    char text[] = "education is important";
    
    printf("Original: %s\n", text);
    
    uppercase_vowels(text);
    
    printf("Modified: %s\n", text);
    
    return 0;
}

/*PROBLEM 10
WAP TO PRINT THE HIGHEST FREQUENCY CHARACTER IN  STRING.*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0}; // Array to store frequencies for all 256 ASCII characters
    int i, max_freq = 0;
    char max_char;

    // 1. Get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // 2. Count the frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        // Ignore the newline character added by fgets
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
    }

    // 3. Find the character with the highest frequency
    for (i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = i; // Store the character (ASCII value)
        }
    }

    // 4. Print the result
    printf("Highest frequency character: '%c'\n", max_char);
    printf("It appears %d times.\n", max_freq);

    return 0;
}

/*PROBLEM 11
WAP TO REMOVE BLANK SPACES IN A STRING*/

#include <stdio.h>

int main() {
    char str[100];
    int i, j = 0;

    // 1. Get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // 2. Loop through each character of the string
    for (i = 0; str[i] != '\0'; i++) {
        
        // 3. If the character is NOT a space, keep it
        if (str[i] != ' ') {
            str[j] = str[i]; // Copy the character to the 'j' position
            j++;             // Move the 'j' counter forward
        }
    }

    // 4. Add the null terminator to mark the end of the new string
    str[j] = '\0';

    // 5. Print the modified string
    printf("String without spaces: %s\n", str);

    return 0;
}

/*PROBLEM 12
wAP TO REPLACE LOWERCASE LETTERS WITH UPPERCASE AND VICE VERSA IN A STRING*/

#include <stdio.h>

int main() {
    char str[100];
    int i;

    // 1. Get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // 2. Loop through each character of the string
    for (i = 0; str[i] != '\0'; i++) {
        
        // 3. If it's a lowercase letter, convert to uppercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; 
        }
        // 4. If it's an uppercase letter, convert to lowercase
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
        // Numbers, spaces, and special characters will be ignored
    }

    // 5. Print the modified string
    printf("Toggled string: %s", str);

    return 0;
}


