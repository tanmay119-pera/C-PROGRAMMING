//!                                              FILE INPUT/OUTPUT

//& FILE - CONTAINER IN A STORAGE DEVICE TO STORE DATA.
//& RAM(RANDOM ACCESS MEMORY) IS VOLATILE IN NATURE.CONTENTS ARE LOST WHEN PROGRAM TERMINATES.
//& FILES ARE USED TO PERSIST THE DATA.

/*
general summary:

File I/O (Input/Output) in C allows your programs to do something crucial: save and retrieve data permanently. Without it, 
any data your program processes is lost the moment theprogram closes because it only lives temporarily in the computer's RAM.

File I/O in C is the process of reading data from and writing data to external files on a storage device using standard 
library functions.

In C, a file is simply treated as a continuous stream of bytes. To interact with this stream, C uses a special structure 
pointer called a FILE * (file pointer) defined in the <stdio.h> library.This pointer acts as the connection bridge between 
your program and the physical file on your disk.

The Core Lifecycle :
1. No matter what you are trying to do with a file, the lifecycle in C always follows three mandatory steps:
2. Open the file: Use fopen() to create a connection and specify your intent (read, write, or append).  
3. Precess the data: Read from the file (using fscanf, fgets, fread) or write to it (using fprintf, fputs, fwrite).  
4. Close the file: Use fclose() to sever the connection and save the changes.

Crucial Points to Remember:

1. Always check for NULL: When you use fopen(), the operation might fail—perhaps the file doesn't exist,
or you lack read/write permissions. If it fails, fopen() returns NULL. Attempting to read or write to a NULL pointer will 
crash your program.  

2. Never forget to close (fclose): If you don't close your files, you risk memory leaks or data loss. Often, C buffers the data
you write in memory; calling fclose() forces the system to actually write that data to the disk.

3. Modes can be destructive: Be very careful with file access modes. Opening an existing file in "w" (write) mode will instantly 
wipe all its existing content. If you want to keep the old data and just add to the bottom, use "a" (append) mode.

4. Text vs. Binary: C distinguishes between text files (like .txt or .csv) and binary files (like raw bytes, images, or saved C structs). 
If you are working with binary data, you must append a b to your mode (e.g., "rb" for read-binary, "wb" for write-binary). 

5. The internal cursor moves automatically: As you read or write data, an internal "file position indicator" automatically moves 
forward. You don't have to manually tell it to move to the next line. (Though you can manually move this cursor if needed using 
a function called fseek()).
*/

//* MODES OF FILES
/*
1. "r" : OPEN A FILE FOR READING. IF THE FILE DOES NOT EXIST, IT RETURNS NULL.
2. "w" : OPEN A FILE FOR WRITING. IF THE FILE EXISTS, IT TRUNCATES THE FILE TO ZERO LENGTH. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
3. "a" : OPEN A FILE FOR APPENDING. IF THE FILE EXISTS, IT WRITES DATA AT THE END OF THE FILE. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
4. "r+" : OPEN A FILE FOR READING AND WRITING. IF THE FILE DOES NOT EXIST, IT RETURNS NULL.
5. "w+" : OPEN A FILE FOR READING AND WRITING. IF THE FILE EXISTS, IT TRUNCATES THE FILE TO ZERO LENGTH. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
6. "a+" : OPEN A FILE FOR READING AND APPENDING. IF THE FILE EXISTS, IT WRITES DATA AT THE END OF THE FILE. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
7. "rb" : OPEN A BINARY FILE FOR READING. IF THE FILE DOES NOT EXIST, IT RETURNS NULL.
8. "wb" : OPEN A BINARY FILE FOR WRITING. IF THE FILE EXISTS, IT TRUNCATES THE FILE TO ZERO LENGTH. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
9. "ab" : OPEN A BINARY FILE FOR APPENDING. IF THE FILE EXISTS, IT WRITES DATA AT THE END OF THE FILE. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
10. "r+b" : OPEN A BINARY FILE FOR READING AND WRITING. IF THE FILE DOES NOT EXIST, IT RETURNS NULL.
11. "w+b" : OPEN A BINARY FILE FOR READING AND WRITING. IF THE FILE EXISTS, IT TRUNCATES THE FILE TO ZERO LENGTH. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.
12. "a+b" : OPEN A BINARY FILE FOR READING AND APPENDING. IF THE FILE EXISTS, IT WRITES DATA AT THE END OF THE FILE. IF THE FILE DOES NOT EXIST, IT CREATES A NEW FILE.*/  

//* OPERATIONS ON FILES
/*
1. CREATE A FILE : TO CREATE A FILE, WE USE fopen() FUNCTION WITH "w" OR "a" MODE.
2. OPEN A FILE : TO OPEN A FILE, WE USE fopen() FUNCTION WITH "r" OR "r+" MODE.
3. READ A FILE : TO READ A FILE, WE USE fscanf(), fgets() OR fread() FUNCTION.
4. WRITE A FILE : TO WRITE A FILE, WE USE fprintf(), fputs() OR fwrite() FUNCTION.
5. CLOSE A FILE : TO CLOSE A FILE, WE USE fclose() FUNCTION.*/

//* TYPES OF FILES 
/*
1. TEXT FILES : TEXT FILES ARE THE FILES THAT CONTAIN DATA IN HUMAN READABLE FORMAT. THEY CAN BE OPENED AND READ USING TEXT EDITORS LIKE NOTEPAD,
   WORDPAD, ETC. EXAMPLES OF TEXT FILES ARE .txt, .csv, .html, .xml, ETC.

2. BINARY FILES : BINARY FILES ARE THE FILES THAT CONTAIN DATA IN MACHINE READABLE FORMAT. THEY CANNOT BE OPENED AND READ USING TEXT EDITORS. EXAMPLES OF BINARY FILES ARE 
.exe, .bin, .jpg, .png, .mp3, ETC.
*/     

//* FILE POINTER
/*  FILE IS A(HIDDEN) STRUCTURE THAT NEEDS TO BE CREATED FOR OPENING A FILE .

A FILE ptr THAT POINTS TO THIS STRUCTURE AND IS USED TO ACCESS THE FILE. IT IS DEFINED IN <stdio.h> HEADER FILE.
The FILE structure is defined in the <stdio.h> header file and contains information about the file, such as its current position, error status, and buffering mode. When you open a file using
fopen(), it returns a pointer to this structure, which you can then use to perform various file operations.

FILE *fptr; // Declare a file pointer*/

#include <stdio.h>
int main(){
    FILE *fptr; // Declare a file pointer
    return 0;
}

//* OPENING A FILE / CLOSING A FILE

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r");
    fclose(fptr); // Close the file
    return 0;
}

//* FILE OPENING MODES
#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r"); // Open a file for reading

    fptr = fopen("example.txt", "w"); // Open a file for writing

    fptr = fopen("example.txt", "a"); // Open a file for appending

    fptr = fopen("example.txt", "r+"); // Open a file for reading and writing

    fptr = fopen("example.txt", "w+"); // Open a file for reading and writing (truncate)

    fptr = fopen("example.txt", "a+"); // Open a file for reading and appending

    fptr = fopen("example.txt", "rb"); // Open a binary file for reading

    fptr = fopen("example.txt", "wb"); // Open a binary file for writing

    fptr = fopen("example.txt", "ab"); // Open a binary file for appending

    fptr = fopen("example.txt", "r+b"); // Open a binary file for reading and writing

    fptr = fopen("example.txt", "w+b"); // Open a binary file for reading and writing (truncate)

    fptr = fopen("example.txt", "a+b"); // Open a binary file for reading and appending

    fclose(fptr); // Close the file
    return 0;
}

//*  BEST PRACTICES FOR FILE I/O IN C
/*
1. Always check the return value of fopen() to ensure the file was opened successfully.
2. Always close files with fclose() to free resources.
3. Use appropriate file modes to avoid data loss.
4. Handle errors gracefully, providing feedback to the user if a file operation fails.  
5. Use binary modes for non-text data to prevent data corruption.
6. Check if a file exists before reading from it.*/

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r"); // Open a file for reading
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit the program with an error code
    }
    // Perform file operations here
    fclose(fptr); // Close the file
    return 0;
}

//* READING FROM A FILE
//& fscanf(fptr, "%c", &ch); // Read a character from the file
//& fscanf(fptr, "%s", str); // Read a string from the file

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r"); // Open a file for reading
    
    char ch;
    fscanf(fptr, "%c", &ch); // Read a character from the file
    printf("Character read: %c\n", ch);
    fscanf(fptr, "%c", &ch); // this will read the next character from the file
    printf("Character read: %c\n", ch);
    fscanf(fptr, "%c", &ch); // this will read the next character from the file
    printf("Character read: %c\n", ch);
    fclose(fptr); // Close the file
    return 0;
}

//* WRITING TO A FILE
//& fprintf(fptr, "%c", ch); // Write a character to the file
//& fprintf(fptr, "%s", str); // Write a string to the file.

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "w"); // Open a file for writing
    fprintf(fptr, "%c", 'P'); // Write a character to the file
    fprintf(fptr, "%s", "Hello, World!"); // Write a string to the file
    fclose(fptr); // Close the file
    return 0;
}

//* READ AND WRITE A CHAR
//& fscanf(fptr) // Read a character from the file
//& fputc(A,fptr) // Write a character to the file

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r+"); // Open a file for reading
    fputc('A', fptr); // Write a character to the file
    fputc('D', fptr); // Write another character to the file
    fclose(fptr); // Close the file
    return 0;
}

//* EOF (END OF FILE) IN C
//^ fgetc returns EOF to show that the file has ended.!!

//& EOF IS A MACRO DEFINED IN <stdio.h> HEADER FILE. IT IS USED TO INDICATE THE END OF A FILE.WHEN READING FROM A FILE,
//& IF THE END OF THE FILE IS REACHED, THE FUNCTION WILL RETURN EOF. IT IS USUALLY DEFINED AS -1. EOF IS USED TO DETECT 
//& THE END OF A FILE WHEN READING DATA

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("example.txt", "r"); // Open a file for reading
    char ch;
    while ((ch = fgetc(fptr)) != EOF) { // Read characters until EOF
        printf("%c", ch); // Print the character
    }
    fclose(fptr); // Close the file
    return 0;

