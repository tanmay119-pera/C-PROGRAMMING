//!                                            PROJECT - 7 COMMUNITY ROSTER

// This program stores a list of community chapters and 
// lets you search for them using loops and arrays.
//
// CONCEPTS COVERED:
// - Arrays (storing multiple values)
// - Strings (text data)
// - Loops (repeating code)
// - Functions (organizing code into blocks)

#include <stdio.h>      // For input/output (printf, scanf)
#include <string.h>     // For string functions (strcpy, strlen, strstr)
#include <ctype.h>      // For isspace() function

// ============================================================
// STEP 1: DEFINE CONSTANTS (Values that don't change)
// ============================================================

#define MAX_CHAPTERS 10      // Maximum number of chapters we can store
#define MAX_NAME_LENGTH 50   // Maximum characters in a chapter name

// ============================================================
// STEP 2: CREATE A STRUCTURE (Template for storing chapter data)
// ============================================================
// Think of a struct like a form with multiple fields
// Each chapter will have: name, city, and number of members

struct Chapter {
    char name[MAX_NAME_LENGTH];  // Name of the chapter (e.g., "Delhi Club")
    char city[MAX_NAME_LENGTH];  // City where chapter is located
    int members;                 // Number of people in the chapter
};

// ============================================================
// STEP 3: FUNCTION DECLARATIONS (Telling C what functions exist)
// ============================================================
// We declare these first so the main function knows about them

void addSampleData(struct Chapter chapters[], int *totalChapters);
// This function fills the array with example chapter data

void displayAllChapters(struct Chapter chapters[], int totalChapters);
// This function shows all chapters in the array

int searchChapter(struct Chapter chapters[], int totalChapters, char searchName[]);
// This function searches for a chapter and returns its position
// Returns -1 if chapter not found, or the index (0-9) if found

void addNewChapter(struct Chapter chapters[], int *totalChapters);
// This function handles adding a new chapter with proper input validation

void displayMenu();
// This function shows the menu options to user

void clearInputBuffer();
// This function clears the input buffer to prevent issues with scanf/fgets mixing

// ============================================================
// STEP 4: MAIN PROGRAM
// ============================================================

int main() {
    // Create an array of Chapter structures
    // This is like creating 10 empty forms to fill later
    struct Chapter chapters[MAX_CHAPTERS];
    
    // Variable to store how many chapters we actually have
    int totalChapters = 0;
    
    // Variable to store user's choice from menu
    int choice;
    
    // Variable to store what user wants to search for
    char searchName[MAX_NAME_LENGTH];
    
    // Variable to store the result of search (position in array)
    int foundPosition;
    
    // Fill array with sample chapters
    addSampleData(chapters, &totalChapters);
    
    // Print welcome message
    printf("\n========================================\n");
    printf("   WELCOME TO COMMUNITY ROSTER\n");
    printf("========================================\n");
    printf("\nA simple program to store and search\n");
    printf("community chapters using arrays!\n\n");
    
    // ========== MAIN MENU LOOP ==========
    // This loop keeps running until user chooses to exit
    while (1) {
        // Show menu to user
        displayMenu();
        
        // Get user's choice
        printf("Enter your choice (1-4): ");
        
        // ! IMPORTANT: Check if scanf works properly
        if (scanf("%d", &choice) != 1) {
            // scanf failed - clear the input buffer and try again
            clearInputBuffer();
            printf("Invalid input! Please enter a number.\n");
            continue;  // Skip rest of loop and go back to menu
        }
        
        // Skip the newline character left by scanf
        clearInputBuffer();
        
        // DO THIS ACTION based on user's choice
        if (choice == 1) {
            // USER CHOICE 1: Show all chapters
            printf("\n");
            displayAllChapters(chapters, totalChapters);
            
        } else if (choice == 2) {
            // USER CHOICE 2: Search for a chapter
            printf("\nEnter chapter name to search: ");
            
            // Read the search input (up to MAX_NAME_LENGTH characters)
            // fgets() is better than scanf for strings because it reads whole line
            fgets(searchName, MAX_NAME_LENGTH, stdin);
            
            // Remove the newline character from the input
            // (fgets includes the newline at the end)
            searchName[strcspn(searchName, "\n")] = '\0';
            
            // Check if user entered empty search
            if (strlen(searchName) == 0) {
                printf("Please enter a chapter name to search.\n");
                continue;
            }
            
            // Call search function
            foundPosition = searchChapter(chapters, totalChapters, searchName);
            
            // Check if chapter was found
            if (foundPosition == -1) {
                // Not found
                printf("Sorry! Chapter '%s' not found.\n", searchName);
            } else {
                // Found! Display the chapter details
                printf("\n=== CHAPTER FOUND! ===\n");
                printf("Name: %s\n", chapters[foundPosition].name);
                printf("City: %s\n", chapters[foundPosition].city);
                printf("Members: %d\n", chapters[foundPosition].members);
            }
            
        } else if (choice == 3) {
            // USER CHOICE 3: Add a new chapter
            addNewChapter(chapters, &totalChapters);
            
        } else if (choice == 4) {
            // USER CHOICE 4: Exit program
            printf("\nThank you for using Community Roster!\n");
            printf("Goodbye!\n\n");
            break;  // Exit the while loop
            
        } else {
            // Invalid choice
            printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }
    
    return 0;  // Program ended successfully
}

// ============================================================
// STEP 5: FUNCTION DEFINITIONS (Actual code for each function)
// ============================================================

// HELPER FUNCTION: Clear the input buffer
// ! This is important to prevent scanf/fgets issues
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Keep reading characters until newline or end of file
    }
}

// FUNCTION 1: Add sample chapters to the array
// Parameters:
//   - chapters[] : the array of Chapter structures
//   - *totalChapters : pointer to the count variable
void addSampleData(struct Chapter chapters[], int *totalChapters) {
    // Chapter 1
    strcpy(chapters[0].name, "Delhi Chapter");     // Copy text into name
    strcpy(chapters[0].city, "Delhi");             // Copy text into city
    chapters[0].members = 45;                      // Set number of members
    
    // Chapter 2
    strcpy(chapters[1].name, "Mumbai Chapter");
    strcpy(chapters[1].city, "Mumbai");
    chapters[1].members = 38;
    
    // Chapter 3
    strcpy(chapters[2].name, "Bangalore Chapter");
    strcpy(chapters[2].city, "Bangalore");
    chapters[2].members = 52;
    
    // Chapter 4
    strcpy(chapters[3].name, "Jaipur Chapter");
    strcpy(chapters[3].city, "Jaipur");
    chapters[3].members = 28;
    
    // Chapter 5
    strcpy(chapters[4].name, "Kolkata Chapter");
    strcpy(chapters[4].city, "Kolkata");
    chapters[4].members = 35;
    
    // Set total chapters to 5
    *totalChapters = 5;
}

// FUNCTION 2: Display all chapters in the array
// Parameters:
//   - chapters[] : the array of Chapter structures
//   - totalChapters : how many chapters are in the array
void displayAllChapters(struct Chapter chapters[], int totalChapters) {
    printf("========================================\n");
    printf("      LIST OF ALL CHAPTERS\n");
    printf("========================================\n\n");
    
    // Check if there are any chapters
    if (totalChapters == 0) {
        printf("No chapters in the roster.\n");
        return;  // Exit function early
    }
    
    // LOOP THROUGH ARRAY: Visit each chapter one by one
    // 'i' starts at 0 and increases by 1 each time
    // Loop stops when i reaches totalChapters
    for (int i = 0; i < totalChapters; i++) {
        printf("Chapter %d:\n", i + 1);           // Show chapter number
        printf("  Name: %s\n", chapters[i].name);  // Show chapter name
        printf("  City: %s\n", chapters[i].city);  // Show city
        printf("  Members: %d\n\n", chapters[i].members);  // Show member count
    }
}

// FUNCTION 3: Search for a chapter by name
// Parameters:
//   - chapters[] : the array of Chapter structures
//   - totalChapters : how many chapters are in the array
//   - searchName[] : the chapter name we're looking for
// Returns:
//   - Index (position) of chapter if found (0-9)
//   - -1 if chapter not found
int searchChapter(struct Chapter chapters[], int totalChapters, char searchName[]) {
    
    printf("Searching for '%s'...\n", searchName);
    
    // MAIN SEARCH LOOP: Go through each chapter in the array
    // This loop demonstrates how to search using arrays and strings
    for (int i = 0; i < totalChapters; i++) {
        
        // Compare the search name with current chapter name
        // strstr() checks if searchName is part of chapters[i].name
        // If found, it returns a pointer (not NULL)
        // If not found, it returns NULL
        if (strstr(chapters[i].name, searchName) != NULL) {
            // Match found! Return the position (index)
            return i;
        }
    }
    
    // If loop finishes without finding anything, return -1
    return -1;
}

// FUNCTION 4: Add a new chapter with proper input handling
// ! This function has been IMPROVED with better input validation
// Parameters:
//   - chapters[] : the array of Chapter structures
//   - *totalChapters : pointer to the count variable
void addNewChapter(struct Chapter chapters[], int *totalChapters) {
    // First, check if array is full
    if (*totalChapters >= MAX_CHAPTERS) {
        printf("\n");
        printf("========================================\n");
        printf("      ADD NEW CHAPTER\n");
        printf("========================================\n");
        printf("ERROR: The roster is full! (Max: %d chapters)\n", MAX_CHAPTERS);
        printf("Cannot add more chapters.\n");
        return;  // Exit function early
    }
    
    // Show menu for adding chapter
    printf("\n");
    printf("========================================\n");
    printf("      ADD NEW CHAPTER\n");
    printf("========================================\n");
    printf("Current total: %d chapters\n\n", *totalChapters);
    
    // Get the index where new chapter will be added
    int newIndex = *totalChapters;
    
    // ! INPUT 1: Get chapter name
    printf("Enter chapter name: ");
    fgets(chapters[newIndex].name, MAX_NAME_LENGTH, stdin);
    
    // Remove newline from name
    chapters[newIndex].name[strcspn(chapters[newIndex].name, "\n")] = '\0';
    
    // Check if name is empty
    if (strlen(chapters[newIndex].name) == 0) {
        printf("ERROR: Chapter name cannot be empty!\n");
        return;  // Don't add chapter
    }
    
    // ! INPUT 2: Get city name
    printf("Enter city: ");
    fgets(chapters[newIndex].city, MAX_NAME_LENGTH, stdin);
    
    // Remove newline from city
    chapters[newIndex].city[strcspn(chapters[newIndex].city, "\n")] = '\0';
    
    // Check if city is empty
    if (strlen(chapters[newIndex].city) == 0) {
        printf("ERROR: City cannot be empty!\n");
        return;  // Don't add chapter
    }
    
    // ! INPUT 3: Get number of members
    printf("Enter number of members: ");
    
    // Check if scanf worked properly
    if (scanf("%d", &chapters[newIndex].members) != 1) {
        // scanf failed - invalid input
        clearInputBuffer();  // Clear the bad input
        printf("ERROR: Please enter a valid number!\n");
        return;  // Don't add chapter
    }
    
    // Clear input buffer after scanf
    clearInputBuffer();
    
    // Validate members count (must be positive)
    if (chapters[newIndex].members < 0) {
        printf("ERROR: Members count cannot be negative!\n");
        return;  // Don't add chapter
    }
    
    // ! ALL VALIDATION PASSED - ADD THE CHAPTER
    (*totalChapters)++;  // Increase chapter count
    
    printf("\n========================================\n");
    printf("SUCCESS! Chapter added successfully!\n");
    printf("========================================\n");
    printf("Name: %s\n", chapters[newIndex].name);
    printf("City: %s\n", chapters[newIndex].city);
    printf("Members: %d\n", chapters[newIndex].members);
    printf("Total chapters now: %d\n\n", *totalChapters);
}

// FUNCTION 5: Display menu options
void displayMenu() {
    printf("\n========================================\n");
    printf("           MAIN MENU\n");
    printf("========================================\n");
    printf("1. Display all chapters\n");
    printf("2. Search for a chapter\n");
    printf("3. Add a new chapter\n");
    printf("4. Exit\n");
    printf("========================================\n");
}

// ============================================================
// END OF PROGRAM
// ============================================================
// 
// KEY IMPROVEMENTS IN THIS VERSION:
//
// 1. BETTER INPUT HANDLING:
//    - clearInputBuffer() to prevent scanf/fgets mixing issues
//    - Check return value of scanf()
//    - Proper newline removal from fgets()
//
// 2. VALIDATION:
//    - Check if chapter name is empty
//    - Check if city is empty
//    - Check if members is a valid number
//    - Check if members count is non-negative
//    - Check if array is full before adding
//
// 3. CLEAR FEEDBACK:
//    - Show error messages if input fails
//    - Show success message when chapter is added
//    - Display the added chapter details
//    - Show current chapter count
//
// 4. ROBUST CODE:
//    - Won't crash with invalid input
//    - Handles edge cases
//    - Provides helpful error messages