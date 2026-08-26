//!       PRACTICE PROBLEM FOR FILE I/O IN C

/*PROBLEM NO 1
MAKE A PROGARM TO READ 5 INTEGERS FROM A FILE.*/

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("numbers.txt", "r"); // Open a file for reading
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit the program with an error code
    }
    int num;
    for (int i = 0; i < 5; i++) {
        fscanf(fptr, "%d", &num);
        printf("Integer %d: %d\n", i + 1, num);
    }
    fclose(fptr); // Close the file
    return 0;
}

/*PROBLEM NO 2
MAKE A PROGRAM TO INPUT STUDENT INFORMATION FROM A USER AND ENTER IT TO A FILE.*/

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("students.txt", "w"); // Open a file for writing
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit the program with an error code
    }
    char name[100];
    int age;
    float gpa;
    printf("Enter student information:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("GPA: ");
    scanf("%f", &gpa);
    fprintf(fptr, "Name: %s\n", name);
    fprintf(fptr, "Age: %d\n", age);
    fprintf(fptr, "GPA: %.2f\n", gpa);
    fclose(fptr); // Close the file
    return 0;
}

/*PROBLEM NO 3
WAP TO WRITE ALL THE ODD NUMBERS FROM 1 TO N IN A FILE.*/
#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("odd_numbers.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            fprintf(fptr, "%d\n", i);
        }
    }
    fclose(fptr);
    return 0;
}

/*PROBLEM NO 4
2 NUMBERS - a & b, ARE WRITTEN IN A FILE. WAP TO REPLACE THEM WITH THEIR SUM IN THE SAME FILE.*/
#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("numbers.txt", "r+");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int a, b;
    fscanf(fptr, "%d %d", &a, &b);
    int sum = a + b;
    fseek(fptr, 0, SEEK_SET); // Move the file pointer to the beginning of the file
    fprintf(fptr, "%d", sum); // Write the sum to the file
    fclose(fptr);
    return 0;
}

/*PROBLEM NO 5
WAP TO READ A STRING FROM A FILE AND OUTPUT TO THE USER.*/

#include <stdio.h>
int main() {
    FILE *fptr; // Declare a file pointer
    fptr = fopen("string.txt", "r"); // Open a file for reading
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1; // Exit the program with an error code
    }
    char str[100];
    fscanf(fptr, "%s", str); // Read a string from the file
    printf("String read from file: %s\n", str);
    fclose(fptr); // Close the file
    return 0;
}   

/*PROBLEM NO 6
REPLACE THE DATA IN FILE OF Q(a) WITH THE NUMBER OF VOWELS IN THE STRING.*/

#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("string.txt", "r+");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char str[100];
    fscanf(fptr, "%s", str); // Read a string from the file
    int vowel_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowel_count++;
        }
    }
    fseek(fptr, 0, SEEK_SET); // Move the file pointer to the beginning of the file
    fprintf(fptr, "%d", vowel_count); // Write the vowel count to the file
    fclose(fptr);
    return 0;
}

/*PROBLEM NO 7
FORMAT THE INFORMATION OF 5 STUDENTS (NAME,MARKS,CGPA,COURSE) IN A TABLE LIKE STRUCTURE IN A FILE.*/

#include <stdio.h>
int main() {
    FILE *fptr;
    fptr = fopen("students_info.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fptr, "%-20s %-10s %-10s %-20s\n", "Name", "Marks", "CGPA", "Course");
    for (int i = 0; i < 5; i++) {
        char name[100];
        int marks;
        float cgpa;
        char course[100];
        printf("Enter information for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Marks: ");
        scanf("%d", &marks);
        printf("CGPA: ");
        scanf("%f", &cgpa);
        printf("Course: ");
        scanf("%s", course);
        fprintf(fptr, "%-20s %-10d %-10.2f %-20s\n", name, marks, cgpa, course);
    }
    fclose(fptr);
    return 0;
}
