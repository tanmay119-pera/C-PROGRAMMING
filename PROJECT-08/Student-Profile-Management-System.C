/*!                ADVANCE PROJECT - 08 : STUDENT PROFILE MANAGEMENT SYSTEM                          */
/*
 *    Author        : Adesh Srivastava (TANMAY)/tanmay119-pera
 *    Target Course : BCA / B.Tech / B.Sc (Computer Science) - C Programming
 *    Description   : A comprehensive student profile management system with dynamic data structures and file I/O.
 *    Language      : C (C17 Standard)
 *    File          : Student-Profile-Management-System.C
 
 *    Key Concepts  : 
 *    1. Structures (struct)     -> Grouping heterogeneous student attributes.
 *    2. Enumerations (enum)     -> Type-safe representation of degree programs.
 *    3. Dynamic Memory          -> Heap allocation (malloc, realloc, free).
 *    4. Function Pointers       -> qsort() comparator functions.
 *    5. Binary File I/O         -> Persistent storage via fwrite() and fread().
 *    6. Robust Input Validation -> Clean buffer handling to prevent crashes.
 *    7. Modular Architecture    -> Single-responsibility principle per function.
 */

#include <stdio.h>   /* Standard Input/Output: printf, scanf, fgets, fread, fwrite */
#include <stdlib.h>  /* Standard Library: malloc, realloc, free, exit, qsort       */
#include <string.h>  /* String handling: strlen, strcmp, strcspn, snprintf         */
#include <ctype.h>   /* Character classification & conversion: tolower             */

/* ----------------------------------------------------------------------------
 *  Constants and Configurations
 * ---------------------------------------------------------------------------- */
#define MAX_NAME_LEN     50          /* Maximum characters allowed for student names */
#define MAX_SUBJECTS     6           /* Number of subjects tracked for CGPA calculation */
#define INITIAL_CAPACITY 4           /* Initial capacity of dynamic array on startup */
#define DATA_FILE        "students.dat" /* Binary storage file name */

/* Subject labels used for input prompts and formatted card display */
const char *SUBJECT_NAMES[MAX_SUBJECTS] = {
    "C Programming",
    "Mathematics",
    "Computer Fundamentals",
    "Technical Communication",
    "Web Programming",
    "Environmental Science"
};

/* ----------------------------------------------------------------------------
 *  ENUMERATION: Degree Types
 *  Enums assign meaningful names to integral constants, improving code clarity.
 * ---------------------------------------------------------------------------- */
typedef enum {
    BCA,          /* 0 */
    BTECH,        /* 1 */
    MCA,          /* 2 */
    BBA,          /* 3 */
    BSC,          /* 4 */
    DEGREE_OTHER  /* 5 */
} DegreeType;

/* Lookup table for string representation of DegreeType */
const char *DEGREE_NAMES[] = { "BCA", "B.Tech", "MCA", "BBA", "B.Sc", "Other" };

/* ----------------------------------------------------------------------------
 *  STRUCTURE: Student Profile
 *  Encapsulates all relevant data for an individual student record.
 * ---------------------------------------------------------------------------- */
typedef struct {
    int id;                      /* Unique auto-incremented identifier (e.g., 1001) */
    char name[MAX_NAME_LEN];     /* Full name of the student */
    int enrollmentYear;          /* Year of admission (e.g., 2026) */
    DegreeType degree;           /* Degree course enrolled */
    int semester;                /* Current semester (1 - 8) */
    float marks[MAX_SUBJECTS];   /* Subject scores (0 - 100) */
    float cgpa;                  /* Computed Grade Point Average (0.00 - 10.00) */
} Student;

/* ----------------------------------------------------------------------------
 *  STRUCTURE: Dynamic Database Container
 *  Implements a dynamically-resizing array (similar to std::vector or ArrayList).
 * ---------------------------------------------------------------------------- */
typedef struct {
    Student *students;  /* Pointer to heap memory holding array of Student structs */
    int count;          /* Actual number of valid student records currently stored */
    int capacity;       /* Total allocated capacity of the array */
    int nextId;         /* Counter used to generate unique IDs automatically */
} StudentDB;

/* ----------------------------------------------------------------------------
 *  Function Prototypes (Declarations)
 * ---------------------------------------------------------------------------- */
/* Memory Lifecycle */
void  initDB(StudentDB *db);
void  freeDB(StudentDB *db);
void  ensureCapacity(StudentDB *db);

/* Input Handling & Validation */
void  clearInputBuffer(void);
int   getValidatedInt(const char *prompt, int minVal, int maxVal);
float getValidatedFloat(const char *prompt, float minVal, float maxVal);
void  getValidatedName(char *buffer, int size, const char *prompt);

/* Utilities & Converters */
float       calculateCGPA(const float marks[]);
const char *degreeToString(DegreeType d);
DegreeType  chooseDegree(void);

/* CRUD Operations */
void addStudent(StudentDB *db);
void displayAllStudents(const StudentDB *db);
void printProfileCard(const Student *s);
int  findIndexById(const StudentDB *db, int id);
void viewProfileById(const StudentDB *db);
void updateStudent(StudentDB *db);
void deleteStudent(StudentDB *db);

/* Search & Sorting */
int  containsIgnoreCase(const char *haystack, const char *needle);
void searchByName(const StudentDB *db);
int  compareByCGPADesc(const void *a, const void *b);
int  compareByNameAsc(const void *a, const void *b);
void sortStudents(StudentDB *db);

/* File Persistence */
void saveToFile(const StudentDB *db);
void loadFromFile(StudentDB *db);

/* User Interface */
void printMenu(void);

/* ============================================================================
 *  MAIN ENTRY POINT
 * ============================================================================ */
int main(void) {
    StudentDB db;

    /* Initialize database structure in memory */
    initDB(&db);

    /* Load existing data from file if available */
    loadFromFile(&db);

    int choice;
    do {
        printMenu();
        choice = getValidatedInt("Enter your choice: ", 0, 9);

        /* Dispatch user selection to corresponding handler */
        switch (choice) {
            case 1: addStudent(&db);         break;
            case 2: displayAllStudents(&db); break;
            case 3: viewProfileById(&db);    break;
            case 4: searchByName(&db);       break;
            case 5: updateStudent(&db);      break;
            case 6: deleteStudent(&db);      break;
            case 7: sortStudents(&db);       break;
            case 8: saveToFile(&db);         break;
            case 9: loadFromFile(&db);       break;
            case 0:
                printf("\nSaving student data before exiting...\n");
                saveToFile(&db);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    /* Clean up allocated heap memory before program terminates */
    freeDB(&db);
    printf("Goodbye! Program exited cleanly.\n");
    return 0;
}

/* ============================================================================
 *  DATABASE LIFECYCLE MANAGEMENT (Dynamic Memory)
 * ============================================================================ */

/**
 * Allocates initial heap memory for the dynamic array and resets counters.
 */
void initDB(StudentDB *db) {
    db->students = malloc(INITIAL_CAPACITY * sizeof(Student));
    if (db->students == NULL) {
        perror("Fatal Error: Initial memory allocation failed");
        exit(EXIT_FAILURE);
    }
    db->count    = 0;
    db->capacity = INITIAL_CAPACITY;
    db->nextId   = 1001; /* Initial roll/ID number */
}

/**
 * Deallocates all dynamically allocated memory to avoid memory leaks.
 */
void freeDB(StudentDB *db) {
    if (db->students != NULL) {
        free(db->students);
        db->students = NULL;
    }
    db->count = 0;
    db->capacity = 0;
}

/**
 * Automatically expands the dynamic array capacity using geometric doubling.
 * Geometric resizing provides O(1) amortized insertion time complexity.
 */
void ensureCapacity(StudentDB *db) {
    if (db->count >= db->capacity) {
        int newCapacity = db->capacity * 2;
        
        /* Reallocate memory safely using temporary pointer */
        Student *temp = realloc(db->students, (size_t)newCapacity * sizeof(Student));
        if (temp == NULL) {
            printf("Error: Could not expand database capacity. Memory exhausted.\n");
            return;
        }
        db->students = temp;
        db->capacity = newCapacity;
    }
}

/* ============================================================================
 *  INPUT VALIDATION & BUFFER SANITIZATION
 * ============================================================================ */

/**
 * Clears trailing characters (including newline '\n') from the standard input stream.
 * Essential to prevent leftover input from corrupting subsequent fgets()/scanf() calls.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* Discard input until newline or end-of-file */
    }
}

/**
 * Reads and validates an integer within [minVal, maxVal], re-prompting on bad input.
 */
int getValidatedInt(const char *prompt, int minVal, int maxVal) {
    int value, result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        /* Handle unexpected EOF / Stream termination (e.g., Ctrl+D or Ctrl+Z) */
        if (result == EOF) {
            printf("\nInput stream ended. Exiting program.\n");
            exit(EXIT_SUCCESS);
        }

        clearInputBuffer(); /* Clear leftover input / newline */

        if (result != 1) {
            printf("Invalid input: Please enter a valid whole number.\n");
            continue;
        }
        if (value < minVal || value > maxVal) {
            printf("Out of range: Please enter a value between %d and %d.\n", minVal, maxVal);
            continue;
        }
        return value;
    }
}

/**
 * Reads and validates a float within [minVal, maxVal].
 */
float getValidatedFloat(const char *prompt, float minVal, float maxVal) {
    float value;
    int result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%f", &value);

        if (result == EOF) {
            printf("\nInput stream ended. Exiting program.\n");
            exit(EXIT_SUCCESS);
        }

        clearInputBuffer();

        if (result != 1) {
            printf("Invalid input: Please enter a valid number.\n");
            continue;
        }
        if (value < minVal || value > maxVal) {
            printf("Out of range: Please enter a value between %.1f and %.1f.\n", 
                   (double)minVal, (double)maxVal);
            continue;
        }
        return value;
    }
}

/**
 * Reads a non-empty string using fgets() to support spaces (e.g. "John Doe")
 * and strips the trailing newline character.
 */
void getValidatedName(char *buffer, int size, const char *prompt) {
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) == NULL) {
            if (feof(stdin)) {
                printf("\nInput stream ended. Exiting program.\n");
                exit(EXIT_SUCCESS);
            }
            clearerr(stdin);
            continue;
        }

        /* Replace newline '\n' character with null terminator '\0' */
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0) {
            printf("Error: This field cannot be left blank.\n");
            continue;
        }
        return;
    }
}

/* ============================================================================
 *  DOMAIN LOGIC & HELPERS
 * ============================================================================ */

/**
 * Calculates CGPA from an array of subject marks (0-100).
 * Uses standard Indian percentage-to-CGPA scale: CGPA = percentage / 9.5
 */
float calculateCGPA(const float marks[]) {
    float sum = 0.0f;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += marks[i];
    }
    float averagePercentage = sum / MAX_SUBJECTS;
    float cgpa = averagePercentage / 9.5f;

    /* Cap at maximum achievable 10.0 scale */
    if (cgpa > 10.0f) cgpa = 10.0f;
    return cgpa;
}

/**
 * Converts a DegreeType enum value to its corresponding display string.
 */
const char *degreeToString(DegreeType d) {
    if (d < 0 || d > DEGREE_OTHER) return "Unknown";
    return DEGREE_NAMES[d];
}

/**
 * Displays degree options menu and returns the selected DegreeType enum value.
 */
DegreeType chooseDegree(void) {
    printf("\nSelect Degree Program:\n");
    for (int i = 0; i <= DEGREE_OTHER; i++) {
        printf("  %d. %s\n", i + 1, DEGREE_NAMES[i]);
    }
    int choice = getValidatedInt("Choice: ", 1, DEGREE_OTHER + 1);
    return (DegreeType)(choice - 1);
}

/* ============================================================================
 *  CRUD OPERATIONS (Create, Read, Update, Delete)
 * ============================================================================ */

/**
 * Prompts user for all student fields and appends the new record.
 */
void addStudent(StudentDB *db) {
    ensureCapacity(db); /* Expand memory if dynamic array is full */

    Student *s = &db->students[db->count]; /* Pointer to new record slot */

    s->id = db->nextId++; /* Auto-generate unique ID */

    printf("\n--- Add New Student Record ---\n");
    getValidatedName(s->name, MAX_NAME_LEN, "Enter Student Name: ");
    s->enrollmentYear = getValidatedInt("Enrollment Year (e.g., 2026): ", 2000, 2100);
    s->degree         = chooseDegree();
    s->semester       = getValidatedInt("Current Semester (1-8): ", 1, 8);

    printf("\nEnter marks (0-100) for each subject:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        char prompt[80];
        snprintf(prompt, sizeof(prompt), "  %-25s: ", SUBJECT_NAMES[i]);
        s->marks[i] = getValidatedFloat(prompt, 0.0f, 100.0f);
    }

    /* Compute and store CGPA immediately */
    s->cgpa = calculateCGPA(s->marks);

    db->count++; /* Increment stored count */
    printf("\n[Success] Student added! ID: %d | CGPA: %.2f\n", s->id, s->cgpa);
}

/**
 * Tabulates all students currently stored in memory.
 */
void displayAllStudents(const StudentDB *db) {
    if (db->count == 0) {
        printf("\nNo student records found in database.\n");
        return;
    }

    printf("\n%-6s %-25s %-6s %-10s %-5s %-6s\n",
           "ID", "Name", "Year", "Degree", "Sem", "CGPA");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        const Student *s = &db->students[i];
        printf("%-6d %-25s %-6d %-10s %-5d %-6.2f\n",
               s->id, s->name, s->enrollmentYear,
               degreeToString(s->degree), s->semester, s->cgpa);
    }
    printf("-----------------------------------------------------------------\n");
    printf("Total Students: %d\n", db->count);
}

/* Card formatting constants */
#define CARD_WIDTH         48
#define CARD_CONTENT_WIDTH (CARD_WIDTH - 4)
#define CARD_BORDER_DASHES (CARD_WIDTH - 2)

static void printCardBorder(void) {
    putchar('+');
    for (int i = 0; i < CARD_BORDER_DASHES; i++) putchar('-');
    putchar('+');
    putchar('\n');
}

static void printCardRow(const char *text) {
    printf("| %-*s |\n", CARD_CONTENT_WIDTH, text);
}

/**
 * Displays a formatted ASCII profile card for a single student.
 */
void printProfileCard(const Student *s) {
    char line[100];

    printf("\n");
    printCardBorder();
    printCardRow("            STUDENT PROFILE CARD");
    printCardBorder();

    snprintf(line, sizeof(line), "ID           : %d", s->id);
    printCardRow(line);
    snprintf(line, sizeof(line), "Name         : %s", s->name);
    printCardRow(line);
    snprintf(line, sizeof(line), "Degree       : %s", degreeToString(s->degree));
    printCardRow(line);
    snprintf(line, sizeof(line), "Enroll. Year : %d", s->enrollmentYear);
    printCardRow(line);
    snprintf(line, sizeof(line), "Semester     : %d", s->semester);
    printCardRow(line);
    snprintf(line, sizeof(line), "CGPA         : %.2f", s->cgpa);
    printCardRow(line);

    printCardBorder();
    printCardRow("Subject-wise Marks:");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        snprintf(line, sizeof(line), "  %-24s: %6.2f", SUBJECT_NAMES[i], s->marks[i]);
        printCardRow(line);
    }
    printCardBorder();
}

/**
 * Performs a linear search by Student ID.
 * Returns array index if found, or -1 if not found. Time Complexity: O(n).
 */
int findIndexById(const StudentDB *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == id) {
            return i;
        }
    }
    return -1;
}

/**
 * Searches for a student by their ID and displays their profile card.
 */
void viewProfileById(const StudentDB *db) {
    if (db->count == 0) {
        printf("\nDatabase is empty. No records to search.\n");
        return;
    }
    int id = getValidatedInt("Enter Student ID: ", 1, 999999);
    int idx = findIndexById(db, id);

    if (idx == -1) {
        printf("Record not found: No student with ID %d.\n", id);
        return;
    }
    printProfileCard(&db->students[idx]);
}

/**
 * Checks if 'haystack' contains 'needle' as a substring (case-insensitive).
 * Custom portable implementation avoiding non-standard POSIX strcasestr().
 */
int containsIgnoreCase(const char *haystack, const char *needle) {
    int hLen = (int)strlen(haystack);
    int nLen = (int)strlen(needle);
    if (nLen == 0) return 1;

    for (int i = 0; i <= hLen - nLen; i++) {
        int j;
        for (j = 0; j < nLen; j++) {
            if (tolower((unsigned char)haystack[i + j]) != tolower((unsigned char)needle[j])) {
                break;
            }
        }
        if (j == nLen) return 1; /* Match found */
    }
    return 0;
}

/**
 * Searches and displays profile cards for all students matching a name query.
 */
void searchByName(const StudentDB *db) {
    if (db->count == 0) {
        printf("\nDatabase is empty. No records to search.\n");
        return;
    }

    char query[MAX_NAME_LEN];
    getValidatedName(query, MAX_NAME_LEN, "Enter name (or part of name) to search: ");

    int matchCount = 0;
    for (int i = 0; i < db->count; i++) {
        if (containsIgnoreCase(db->students[i].name, query)) {
            printProfileCard(&db->students[i]);
            matchCount++;
        }
    }

    if (matchCount == 0) {
        printf("No records matching \"%s\".\n", query);
    } else {
        printf("\nFound %d matching record(s).\n", matchCount);
    }
}

/**
 * Modifies an existing student's attributes in-place.
 */
void updateStudent(StudentDB *db) {
    if (db->count == 0) {
        printf("\nDatabase is empty. No records to update.\n");
        return;
    }

    int id = getValidatedInt("Enter Student ID to update: ", 1, 999999);
    int idx = findIndexById(db, id);

    if (idx == -1) {
        printf("Record not found: No student with ID %d.\n", id);
        return;
    }

    Student *s = &db->students[idx];
    printf("\nUpdating details for: %s (ID: %d)\n", s->name, s->id);
    printf("  1. Update Name\n");
    printf("  2. Update Semester\n");
    printf("  3. Update Marks (Recalculates CGPA)\n");
    printf("  4. Update Degree Program\n");
    printf("  0. Cancel\n");

    int choice = getValidatedInt("Choose field to update: ", 0, 4);

    switch (choice) {
        case 1:
            getValidatedName(s->name, MAX_NAME_LEN, "Enter new name: ");
            break;
        case 2:
            s->semester = getValidatedInt("Enter new semester (1-8): ", 1, 8);
            break;
        case 3:
            printf("\nEnter updated marks (0-100):\n");
            for (int i = 0; i < MAX_SUBJECTS; i++) {
                char prompt[80];
                snprintf(prompt, sizeof(prompt), "  %-25s: ", SUBJECT_NAMES[i]);
                s->marks[i] = getValidatedFloat(prompt, 0.0f, 100.0f);
            }
            s->cgpa = calculateCGPA(s->marks);
            break;
        case 4:
            s->degree = chooseDegree();
            break;
        case 0:
            printf("Update operation cancelled.\n");
            return;
    }
    printf("[Success] Student profile updated!\n");
}

/**
 * Removes a student by ID and left-shifts subsequent elements to maintain continuity.
 */
void deleteStudent(StudentDB *db) {
    if (db->count == 0) {
        printf("\nDatabase is empty. No records to delete.\n");
        return;
    }

    int id = getValidatedInt("Enter Student ID to delete: ", 1, 999999);
    int idx = findIndexById(db, id);

    if (idx == -1) {
        printf("Record not found: No student with ID %d.\n", id);
        return;
    }

    printf("Deleting record for: %s (ID: %d)...\n", db->students[idx].name, db->students[idx].id);

    /* Shift all elements to the left to overwrite the deleted item */
    for (int i = idx; i < db->count - 1; i++) {
        db->students[i] = db->students[i + 1];
    }
    db->count--; /* Decrease record count */

    printf("[Success] Student deleted successfully.\n");
}

/* ============================================================================
 *  SORTING (Using qsort and Function Pointers)
 * ============================================================================ */

/**
 * Comparator function for sorting students by CGPA in descending order.
 */
int compareByCGPADesc(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;

    if (s2->cgpa > s1->cgpa) return 1;
    if (s2->cgpa < s1->cgpa) return -1;
    return 0;
}

/**
 * Comparator function for sorting students alphabetically by name (A-Z).
 */
int compareByNameAsc(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    return strcmp(s1->name, s2->name);
}

/**
 * Sorts student records based on user-chosen criteria using standard qsort().
 */
void sortStudents(StudentDB *db) {
    if (db->count < 2) {
        printf("\nAt least 2 student records are required for sorting.\n");
        return;
    }

    printf("\nSelect Sorting Criteria:\n");
    printf("  1. Sort by CGPA (Highest to Lowest)\n");
    printf("  2. Sort by Name (Alphabetical A - Z)\n");
    int choice = getValidatedInt("Choice: ", 1, 2);

    if (choice == 1) {
        qsort(db->students, (size_t)db->count, sizeof(Student), compareByCGPADesc);
        printf("\n[Success] Records sorted by CGPA (Descending).\n");
    } else {
        qsort(db->students, (size_t)db->count, sizeof(Student), compareByNameAsc);
        printf("\n[Success] Records sorted by Name (Ascending).\n");
    }

    displayAllStudents(db);
}

/* ============================================================================
 *  FILE I/O: PERSISTENCE (Binary File Mode)
 * ============================================================================ */

/**
 * Serializes database state to a binary file:
 * Format: [int count] [int nextId] [Student structs array]
 */
void saveToFile(const StudentDB *db) {
    FILE *fp = fopen(DATA_FILE, "wb"); /* Open in binary write mode */
    if (fp == NULL) {
        perror("Error opening file for saving");
        return;
    }

    /* Write metadata headers */
    fwrite(&db->count, sizeof(int), 1, fp);
    fwrite(&db->nextId, sizeof(int), 1, fp);

    /* Write student array block */
    if (db->count > 0) {
        fwrite(db->students, sizeof(Student), (size_t)db->count, fp);
    }

    fclose(fp);
    printf("[Success] Saved %d record(s) to \"%s\".\n", db->count, DATA_FILE);
}

/**
 * Deserializes database state from the binary file.
 */
void loadFromFile(StudentDB *db) {
    FILE *fp = fopen(DATA_FILE, "rb"); /* Open in binary read mode */
    if (fp == NULL) {
        return; /* Normal scenario on first run when no file exists yet */
    }

    int savedCount = 0;
    int savedNextId = 1001;

    /* Read metadata headers */
    if (fread(&savedCount, sizeof(int), 1, fp) != 1 ||
        fread(&savedNextId, sizeof(int), 1, fp) != 1) {
        printf("Warning: \"%s\" appears corrupted or unreadable. Starting clean.\n", DATA_FILE);
        fclose(fp);
        return;
    }

    /* Resize database capacity if loaded count exceeds current memory buffer */
    if (savedCount > db->capacity) {
        Student *temp = realloc(db->students, (size_t)savedCount * sizeof(Student));
        if (temp == NULL) {
            printf("Error: Insufficient memory to load stored records.\n");
            fclose(fp);
            return;
        }
        db->students = temp;
        db->capacity = savedCount;
    }

    /* Read stored student records directly into the array */
    size_t readCount = fread(db->students, sizeof(Student), (size_t)savedCount, fp);
    db->count  = (int)readCount;
    db->nextId = savedNextId;

    fclose(fp);
    printf("Loaded %d record(s) from \"%s\".\n", db->count, DATA_FILE);
}

/* ============================================================================
 *  MENU INTERFACE
 * ============================================================================ */
void printMenu(void) {
    printf("\n===========================================================\n");
    printf("            STUDENT PROFILE MANAGEMENT SYSTEM              \n");
    printf("===========================================================\n");
    printf("  1. Add New Student Record\n");
    printf("  2. Display All Students\n");
    printf("  3. View Profile Card (Search by ID)\n");
    printf("  4. Search by Name\n");
    printf("  5. Update Student Record\n");
    printf("  6. Delete Student Record\n");
    printf("  7. Sort Student Records\n");
    printf("  8. Save Data to File\n");
    printf("  9. Load Data from File\n");
    printf("  0. Exit (Auto-saves)\n");
    printf("===========================================================\n");
}