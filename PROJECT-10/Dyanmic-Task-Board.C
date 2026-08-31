//!NOTE - PROJECT-08,PROJECT-09,PROJECT-10 are advanced projects that require a solid understanding of C programming concepts. They are designed for learners who have completed the foundational projects (PROJECT-01 to PROJECT-07) and are ready to tackle more complex applications involving dynamic memory management, file I/O, and data structures.

//                     ADVANCE PROJECT - 10 : DYNAMIC TASK BOARD (DMA ENGINE)

/*
 * Concept: Chapter 12 - Dynamic Memory Allocation (malloc, realloc, free)
 * Author : Adesh Srivastava (Tanmay)
 * License: MIT License

 * Beginner Quick Guide (DMA Basics):
 * - malloc(size)     : Allocates exact bytes on Heap (e.g. for dynamic strings).
 * - realloc(ptr, sz) : Grows or shrinks an existing heap array.
 * - free(ptr)        : Returns memory to Operating System (prevents memory leaks).
 * - ptr = NULL       : Eliminates dangling pointers after free().
 * Description:
 * This project demonstrates a dynamic task board implemented in C using dynamic memory allocation.
 * It allows users to add, view, toggle, and delete tasks, while managing memory efficiently
 * using malloc, realloc, and free. The program also provides a live memory footprint inspector to monitor heap usage.
 * Key Concepts:
 * 1. Dynamic Memory Allocation (malloc, realloc, free)
 * 2. Structs for Task Representation
 * 3. Pointer Management and Memory Safety
 * 4. User Input Validation and String Handling
 * 5. Modular Function Design for Maintainability
 * 6. Live Memory Footprint Inspection
 * 7. Safe Exit with Memory Deallocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// ---------- Data Model: Individual Dynamic Task ----------
struct Task {
    int id;              // Unique Task ID (1, 2, 3...)
    char *title;         // Pointer to dynamic string on Heap (exact length + 1 for '\0')
    char *category;      // Pointer to dynamic category on Heap
    int priority;        // 1: Low, 2: Medium, 3: High, 4: Urgent
    int isCompleted;     // 0 = [TODO], 1 = [DONE]
};

// ---------- Data Model: Dynamic Task Board ----------
struct TaskBoard {
    struct Task *tasks;  // Pointer to dynamic array on Heap (starts at NULL = 0 bytes)
    int count;           // Current number of active tasks
    int nextId;          // Auto-incrementing ID counter
};

// ---------- Function Prototypes ----------
void displayMainMenu();
void addTask(struct TaskBoard *board);
void displayAllTasks(const struct TaskBoard *board);
void toggleTaskStatus(struct TaskBoard *board);
void deleteTask(struct TaskBoard *board);
void displayMemoryProfile(const struct TaskBoard *board);
void clearEntireBoard(struct TaskBoard *board);
void freeTaskBoard(struct TaskBoard *board);

// Helper Utilities
void clearInputBuffer();
void trimNewline(char *str);
void trimSpaces(char *str);
const char* getPriorityBadge(int priority);

// ============================================================================
// Main Application Entry Point
// ============================================================================
int main() {
    // 1. Initialize empty board (0 bytes allocated on Heap)
    struct TaskBoard board;
    board.tasks = NULL;   // Best practice: initialize pointers to NULL
    board.count = 0;
    board.nextId = 1;

    int choice;

    printf("\n=========================================================\n");
    printf("           📋 DYNAMIC TASK BOARD (DMA ENGINE)            \n");
    printf("        [Powered by C Chapter 12: malloc & free]         \n");
    printf("=========================================================\n");

    while (1) {
        displayMainMenu();
        printf("👉 Enter your choice (1-7): ");

        // Validate numeric user input
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\n❌ [ERROR] Invalid selection! Please enter a valid number (1-7).\n");
            continue;
        }
        clearInputBuffer(); // Flush newline from stdin

        switch (choice) {
            case 1:
                // Expand heap array with realloc() and allocate strings with malloc()
                addTask(&board);
                break;

            case 2:
                // View all tasks currently stored in dynamic memory
                displayAllTasks(&board);
                break;

            case 3:
                // Toggle task completion flag
                toggleTaskStatus(&board);
                break;

            case 4:
                // Delete task, free() its strings, and shrink array with realloc()
                deleteTask(&board);
                break;

            case 5:
                // Inspect live heap memory footprint in bytes
                displayMemoryProfile(&board);
                break;

            case 6:
                // free() all tasks and reset pointer back to NULL
                clearEntireBoard(&board);
                break;

            case 7:
                // Clean exit: free all memory so 0 bytes leak
                freeTaskBoard(&board);
                printf("\n=========================================================\n");
                printf("  ✨ All dynamic heap memory freed safely. (0 leaks)      \n");
                printf("  👋 Thank you for using Dynamic Task Board! Goodbye!    \n");
                printf("=========================================================\n\n");
                return 0;

            default:
                printf("\n⚠️ [WARNING] Invalid option! Please select between 1 and 7.\n");
                break;
        }
    }

    return 0;
}

// ============================================================================
// Displays Main Menu
// ============================================================================
void displayMainMenu() {
    printf("\n---------------------------------------------------------\n");
    printf("                     📋 MAIN MENU                        \n");
    printf("---------------------------------------------------------\n");
    printf(" 1. ➕ Add New Dynamic Task (realloc + malloc)\n");
    printf(" 2. 📜 View All Active Tasks\n");
    printf(" 3. ✅ Toggle Task Status (Pending / Done)\n");
    printf(" 4. 🗑️  Delete Task & Shrink RAM (free + realloc)\n");
    printf(" 5. 📊 Live RAM Footprint & Heap Memory Inspector\n");
    printf(" 6. 🧹 Clear Entire Board (free all -> NULL)\n");
    printf(" 7. 🚪 Exit Program (Safe Heap Deallocation)\n");
    printf("---------------------------------------------------------\n");
}

// ============================================================================
// 1. Add Task (DMA: realloc array + malloc exact string lengths)
// ============================================================================
void addTask(struct TaskBoard *board) {
    char titleBuf[BUFFER_SIZE];
    char catBuf[BUFFER_SIZE];
    int priority;

    printf("\n=========================================================\n");
    printf("                ➕ ADD NEW DYNAMIC TASK                  \n");
    printf("=========================================================\n");

    // Read title safely
    printf("Enter Task Title       : ");
    fgets(titleBuf, sizeof(titleBuf), stdin);
    trimNewline(titleBuf);
    trimSpaces(titleBuf);

    if (strlen(titleBuf) == 0) {
        printf("\n❌ [ERROR] Task title cannot be blank!\n");
        return;
    }

    // Read category safely
    printf("Enter Category / Tag   : ");
    fgets(catBuf, sizeof(catBuf), stdin);
    trimNewline(catBuf);
    trimSpaces(catBuf);
    if (strlen(catBuf) == 0) {
        strcpy(catBuf, "General");
    }

    // Read priority
    printf("Enter Priority (1: Low, 2: Med, 3: High, 4: Urgent): ");
    if (scanf("%d", &priority) != 1 || priority < 1 || priority > 4) {
        clearInputBuffer();
        priority = 2; // Default to Medium
        printf("⚠️ Invalid priority entered. Defaulting to [2: Medium].\n");
    } else {
        clearInputBuffer();
    }

    // --- DMA Step 1: Expand Tasks Array on Heap using realloc() ---
    // realloc() resizes the block without destroying existing tasks
    int newCount = board->count + 1;
    struct Task *expandedTasks = (struct Task *)realloc(board->tasks, newCount * sizeof(struct Task));
    if (expandedTasks == NULL) {
        printf("\n❌ [FATAL] Heap memory allocation failed for tasks array!\n");
        return;
    }
    board->tasks = expandedTasks; // Update pointer to new heap memory location

    // --- DMA Step 2: Allocate Exact String Bytes using malloc() ---
    // +1 byte is required for the string null-terminator character ('\0')
    size_t titleLen = strlen(titleBuf) + 1;
    size_t catLen = strlen(catBuf) + 1;

    char *dynamicTitle = (char *)malloc(titleLen * sizeof(char));
    char *dynamicCat = (char *)malloc(catLen * sizeof(char));

    // Always check if malloc succeeded (ptr != NULL)
    if (dynamicTitle == NULL || dynamicCat == NULL) {
        printf("\n❌ [FATAL] Heap string allocation failed!\n");
        free(dynamicTitle);
        free(dynamicCat);
        return;
    }

    // Copy string from temporary stack buffer into dynamic heap memory
    strcpy(dynamicTitle, titleBuf);
    strcpy(dynamicCat, catBuf);

    // --- DMA Step 3: Populate Task at new index ---
    int idx = board->count;
    board->tasks[idx].id = board->nextId++;
    board->tasks[idx].title = dynamicTitle;     // Store heap pointer
    board->tasks[idx].category = dynamicCat;   // Store heap pointer
    board->tasks[idx].priority = priority;
    board->tasks[idx].isCompleted = 0;

    board->count = newCount; // Increment active task count

    size_t taskRam = sizeof(struct Task) + titleLen + catLen;

    printf("\n=========================================================\n");
    printf("        🎉 SUCCESS! TASK CREATED ON THE HEAP             \n");
    printf("=========================================================\n");
    printf(" ID       : #%d\n", board->tasks[idx].id);
    printf(" Title    : %s (%zu bytes on heap)\n", board->tasks[idx].title, titleLen);
    printf(" Category : %s (%zu bytes on heap)\n", board->tasks[idx].category, catLen);
    printf(" Priority : %s\n", getPriorityBadge(board->tasks[idx].priority));
    printf(" RAM Used : %zu bytes dynamically allocated\n", taskRam);
    printf(" Total Active Tasks: %d\n", board->count);
    printf("=========================================================\n");
}

// ============================================================================
// 2. View All Active Tasks
// ============================================================================
void displayAllTasks(const struct TaskBoard *board) {
    printf("\n========================================================================================================\n");
    printf("                                         📋 ACTIVE TASK BOARD                                            \n");
    printf("========================================================================================================\n");

    // Check if board is empty (pointer is NULL)
    if (board->count == 0 || board->tasks == NULL) {
        printf("                       (Your task board is completely empty. 0 bytes on Heap)\n");
        printf("========================================================================================================\n");
        return;
    }

    printf(" %-5s | %-10s | %-8s | %-16s | %-40s\n",
           "ID", "Status", "Priority", "Category", "Task Title");
    printf("--------------------------------------------------------------------------------------------------------\n");

    // Loop through dynamic array on heap
    for (int i = 0; i < board->count; i++) {
        const char *statusBadge = board->tasks[i].isCompleted ? "✅ [DONE]" : "⏳ [TODO]";
        printf(" #%-4d | %-10s | %-8s | %-16.16s | %-40s\n",
               board->tasks[i].id,
               statusBadge,
               getPriorityBadge(board->tasks[i].priority),
               board->tasks[i].category,
               board->tasks[i].title);
    }

    printf("========================================================================================================\n");
    printf(" 📊 Total Active Tasks: %d | Dynamic Memory Scaled to Current Workload\n", board->count);
    printf("========================================================================================================\n");
}

// ============================================================================
// 3. Toggle Task Status (Pending / Done)
// ============================================================================
void toggleTaskStatus(struct TaskBoard *board) {
    if (board->count == 0 || board->tasks == NULL) {
        printf("\n⚠️ [NOTICE] Task board is empty. Nothing to update.\n");
        return;
    }

    int id;
    printf("\n👉 Enter Task ID to toggle status: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("❌ [ERROR] Invalid Task ID entered!\n");
        return;
    }
    clearInputBuffer();

    // Linear search for task by ID
    int foundIdx = -1;
    for (int i = 0; i < board->count; i++) {
        if (board->tasks[i].id == id) {
            foundIdx = i;
            break;
        }
    }

    if (foundIdx == -1) {
        printf("\n❌ [ERROR] Task #%d was not found!\n", id);
        return;
    }

    // Toggle 0 <-> 1
    board->tasks[foundIdx].isCompleted = !board->tasks[foundIdx].isCompleted;

    printf("\n=========================================================\n");
    printf("            ✨ TASK STATUS UPDATED!                      \n");
    printf("=========================================================\n");
    printf(" Task ID : #%d\n", board->tasks[foundIdx].id);
    printf(" Title   : %s\n", board->tasks[foundIdx].title);
    printf(" Status  : %s\n", board->tasks[foundIdx].isCompleted ? "✅ COMPLETED" : "⏳ PENDING");
    printf("=========================================================\n");
}

// ============================================================================
// 4. Delete Task & Shrink RAM (DMA: free strings + shrink array with realloc)
// ============================================================================
void deleteTask(struct TaskBoard *board) {
    if (board->count == 0 || board->tasks == NULL) {
        printf("\n⚠️ [NOTICE] Task board is empty. Nothing to delete.\n");
        return;
    }

    int id;
    printf("\n👉 Enter Task ID to delete: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        printf("❌ [ERROR] Invalid Task ID entered!\n");
        return;
    }
    clearInputBuffer();

    // Find task index
    int foundIdx = -1;
    for (int i = 0; i < board->count; i++) {
        if (board->tasks[i].id == id) {
            foundIdx = i;
            break;
        }
    }

    if (foundIdx == -1) {
        printf("\n❌ [ERROR] Task #%d not found!\n", id);
        return;
    }

    // Calculate memory freed for beginner display
    size_t freedBytes = sizeof(struct Task) + 
                        strlen(board->tasks[foundIdx].title) + 1 + 
                        strlen(board->tasks[foundIdx].category) + 1;

    // --- DMA Step 1: Free dynamic string heap memory ---
    free(board->tasks[foundIdx].title);
    board->tasks[foundIdx].title = NULL; // Best Practice: eliminate dangling pointer

    free(board->tasks[foundIdx].category);
    board->tasks[foundIdx].category = NULL; // Best Practice: eliminate dangling pointer

    // --- DMA Step 2: Shift remaining tasks left to fill gap ---
    for (int i = foundIdx; i < board->count - 1; i++) {
        board->tasks[i] = board->tasks[i + 1];
    }

    board->count--;

    // --- DMA Step 3: Shrink array capacity on the Heap ---
    if (board->count == 0) {
        // If 0 tasks left, free the array block completely and reset to NULL
        free(board->tasks);
        board->tasks = NULL;
    } else {
        // Shrink heap memory block using realloc()
        struct Task *shrunkTasks = (struct Task *)realloc(board->tasks, board->count * sizeof(struct Task));
        if (shrunkTasks != NULL) {
            board->tasks = shrunkTasks;
        }
    }

    printf("\n=========================================================\n");
    printf("         🗑️  TASK DELETED & HEAP MEMORY FREED!            \n");
    printf("=========================================================\n");
    printf(" Deleted Task ID : #%d\n", id);
    printf(" Memory Released : %zu bytes returned to Operating System\n", freedBytes);
    printf(" Remaining Tasks : %d active\n", board->count);
    printf("=========================================================\n");
}

// ============================================================================
// 5. Live RAM Footprint & Heap Memory Inspector
// ============================================================================
void displayMemoryProfile(const struct TaskBoard *board) {
    // 1. Calculate struct array bytes (count * sizeof(Task))
    size_t structArrayBytes = board->count * sizeof(struct Task);
    size_t stringHeapBytes = 0;

    // 2. Calculate dynamic string bytes (strlen + 1 for each string)
    for (int i = 0; i < board->count; i++) {
        if (board->tasks[i].title) {
            stringHeapBytes += strlen(board->tasks[i].title) + 1;
        }
        if (board->tasks[i].category) {
            stringHeapBytes += strlen(board->tasks[i].category) + 1;
        }
    }

    size_t totalDynamicRam = structArrayBytes + stringHeapBytes;

    // Comparison: A static implementation typically pre-allocates 100 fixed structs
    // e.g. struct StaticTask { int id, char title[100], char cat[50], int priority, int done; } = ~164 bytes each
    size_t staticWastedRam = 100 * 164; // ~16,400 bytes

    printf("\n=========================================================\n");
    printf("          📊 LIVE HEAP MEMORY PROFILER (DMA)             \n");
    printf("=========================================================\n");
    printf(" Active Task Count       : %d Tasks\n", board->count);
    printf(" Pointer Address (Heap)  : %p\n", (void *)board->tasks);
    printf("---------------------------------------------------------\n");
    printf(" 📦 Struct Array Block   : %zu bytes (%d x %zu bytes)\n",
           structArrayBytes, board->count, sizeof(struct Task));
    printf(" 🔤 Dynamic String Heap  : %zu bytes (Exact character allocation)\n", stringHeapBytes);
    printf("---------------------------------------------------------\n");
    printf(" ⚡ Total Active RAM Used : %zu bytes\n", totalDynamicRam);
    printf(" 🛡️  Static Array Baseline: %zu bytes (Pre-allocated 100 slots)\n", staticWastedRam);
    
    if (totalDynamicRam < staticWastedRam) {
        size_t saved = staticWastedRam - totalDynamicRam;
        float percent = ((float)saved / (float)staticWastedRam) * 100.0f;
        printf(" 💡 DMA RAM Savings      : %zu bytes saved (%.1f%% more efficient!)\n", saved, percent);
    }
    printf("=========================================================\n");
}

// ============================================================================
// 6. Clear Entire Board (free all tasks -> reset to NULL)
// ============================================================================
void clearEntireBoard(struct TaskBoard *board) {
    if (board->count == 0 || board->tasks == NULL) {
        printf("\n⚠️ [NOTICE] Task board is already empty.\n");
        return;
    }

    char confirm;
    printf("\n⚠️ [CAUTION] Are you sure you want to delete ALL %d tasks? (y/n): ", board->count);
    scanf(" %c", &confirm);
    clearInputBuffer();

    if (confirm == 'y' || confirm == 'Y') {
        int clearedCount = board->count;
        freeTaskBoard(board); // Release all heap allocations
        printf("\n✅ [SUCCESS] Cleared %d tasks. All heap memory freed and pointer set to NULL.\n", clearedCount);
    } else {
        printf("\n🛡️  [CANCELLED] Operation aborted. Task board unchanged.\n");
    }
}

// ============================================================================
// 7. Full Heap Deallocation (Prevents Memory Leaks & Dangling Pointers)
// ============================================================================
void freeTaskBoard(struct TaskBoard *board) {
    if (board->tasks != NULL) {
        // Step 1: Free each task's dynamic strings first
        for (int i = 0; i < board->count; i++) {
            if (board->tasks[i].title != NULL) {
                free(board->tasks[i].title);
                board->tasks[i].title = NULL; // Prevent dangling pointer
            }
            if (board->tasks[i].category != NULL) {
                free(board->tasks[i].category);
                board->tasks[i].category = NULL; // Prevent dangling pointer
            }
        }
        // Step 2: Free the task array itself
        free(board->tasks);
        board->tasks = NULL; // Reset to NULL (0 bytes on Heap)
    }
    board->count = 0;
}

// ============================================================================
// Helper Utilities Implementation
// ============================================================================

// Flushes extra characters from standard input stream
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Strips newline and carriage returns
void trimNewline(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}

// Trims leading and trailing whitespace
void trimSpaces(char *str) {
    if (!str) return;

    // Remove leading spaces
    char *start = str;
    while (*start && isspace((unsigned char)*start)) start++;

    // Remove trailing spaces
    char *end = start + strlen(start) - 1;
    while (end >= start && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

// Returns human-readable priority string badge
const char* getPriorityBadge(int priority) {
    switch (priority) {
        case 1: return "Low";
        case 2: return "Medium";
        case 3: return "High";
        case 4: return "🔥 Urgent";
        default: return "Normal";
    }
}
