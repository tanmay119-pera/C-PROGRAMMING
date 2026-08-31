/*                             Project: Meetup & Workshop Log System

 * Concept: Chapter 11 - File Input / Output (File I/O)
 * Author : Adesh Srivastava (TANMAY)/tanmay119-pera
 * 
 * Description:
 * Demonstrates persistent disk storage in C by logging, displaying, searching,
 * and managing technical workshops and community meetups using file streams.
 *
 * Core File-IO Operations Demonstrated:
 * 1. fopen() with "a" (Append Mode) - Appending records without overwriting.
 * 2. fopen() with "r" (Read Mode)   - Sequential parsing from disk until EOF.
 * 3. fopen() with "w" (Write Mode)  - File truncation & reset capability.
 * 4. fseek() and ftell()            - Querying file cursor & disk size.
 * 5. fclose()                       - Flushing stream buffers & releasing descriptors.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100
#define LOG_FILENAME "meetups.txt"

// ---------- Data Model: Meetup / Workshop Event ----------
struct MeetupEvent {
    char title[MAX_STR];       // Event Name / Topic
    char category[MAX_STR];    // e.g., Workshop, Meetup, Bootcamp, Hackathon
    char date[MAX_STR];        // Date (YYYY-MM-DD)
    char speaker[MAX_STR];     // Speaker or Organizer Name
    char venue[MAX_STR];       // Physical Venue or Platform (e.g. Zoom/Discord)
};

// ---------- Function Prototypes ----------
void displayMainMenu();
void appendEvent(const char *filename);
void displayAllEvents(const char *filename);
void searchEvents(const char *filename);
void displayEventStatistics(const char *filename);
void resetLogFile(const char *filename);

// Helper Utilities
void clearInputBuffer();
void trimSpaces(char *str);
void trimNewline(char *str);
int parseEventLine(const char *line, struct MeetupEvent *event);
void toLowerCase(char *dest, const char *src);

// ============================================================================
// Main Application Entry Point
// ============================================================================
int main() {
    int choice;

    printf("\n=========================================================\n");
    printf("        🚀 MEETUP & TECH WORKSHOP LOG SYSTEM            \n");
    printf("         [Powered by C Chapter 11: File I/O]             \n");
    printf("=========================================================\n");

    while (1) {
        displayMainMenu();
        printf("👉 Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\n❌ [ERROR] Invalid selection! Please enter a valid number (1-6).\n");
            continue;
        }
        clearInputBuffer(); // Consume newline leftover from numeric input

        switch (choice) {
            case 1:
                // Append Mode ("a")
                appendEvent(LOG_FILENAME);
                break;

            case 2:
                // Read Mode ("r")
                displayAllEvents(LOG_FILENAME);
                break;

            case 3:
                // Search in File ("r")
                searchEvents(LOG_FILENAME);
                break;

            case 4:
                // Stats & File Cursor ("r" + fseek/ftell)
                displayEventStatistics(LOG_FILENAME);
                break;

            case 5:
                // Reset / Truncate File ("w")
                resetLogFile(LOG_FILENAME);
                break;

            case 6:
                // Exit
                printf("\n=========================================================\n");
                printf("  ✨ Thank you for using Meetup Log System! Happy Coding! 👋\n");
                printf("=========================================================\n\n");
                return 0;

            default:
                printf("\n⚠️ [WARNING] Invalid option! Please select between 1 and 6.\n");
                break;
        }
    }

    return 0;
}

// ============================================================================
// Displays Application Menu
// ============================================================================
void displayMainMenu() {
    printf("\n---------------------------------------------------------\n");
    printf("                     📋 MAIN MENU                        \n");
    printf("---------------------------------------------------------\n");
    printf(" 1. ➕ Log / Append New Meetup or Workshop (Mode: \"a\")\n");
    printf(" 2. 📜 View All Logged Events (Mode: \"r\")\n");
    printf(" 3. 🔍 Search Events by Keyword / Speaker\n");
    printf(" 4. 📊 View Event Analytics & File Disk Size\n");
    printf(" 5. 🗑️  Reset / Clear Log File (Mode: \"w\")\n");
    printf(" 6. 🚪 Exit Program\n");
    printf("---------------------------------------------------------\n");
}

// ============================================================================
// 1. Append Event to File (File I/O: Append Mode "a")
// ============================================================================
void appendEvent(const char *filename) {
    struct MeetupEvent event;

    printf("\n=========================================================\n");
    printf("            ➕ LOG NEW MEETUP / WORKSHOP                 \n");
    printf("=========================================================\n");

    // 1. Collect Event Title
    printf("Enter Event Title / Topic : ");
    fgets(event.title, MAX_STR, stdin);
    trimNewline(event.title);
    trimSpaces(event.title);

    if (strlen(event.title) == 0) {
        printf("\n❌ [ERROR] Event title cannot be blank!\n");
        return;
    }

    // 2. Collect Event Category
    printf("Enter Category (e.g. Workshop, Meetup, Bootcamp, Webinar): ");
    fgets(event.category, MAX_STR, stdin);
    trimNewline(event.category);
    trimSpaces(event.category);
    if (strlen(event.category) == 0) {
        strcpy(event.category, "General Meetup");
    }

    // 3. Collect Event Date
    printf("Enter Date (YYYY-MM-DD)   : ");
    fgets(event.date, MAX_STR, stdin);
    trimNewline(event.date);
    trimSpaces(event.date);
    if (strlen(event.date) == 0) {
        strcpy(event.date, "TBD");
    }

    // 4. Collect Speaker / Organizer
    printf("Enter Speaker / Organizer : ");
    fgets(event.speaker, MAX_STR, stdin);
    trimNewline(event.speaker);
    trimSpaces(event.speaker);
    if (strlen(event.speaker) == 0) {
        strcpy(event.speaker, "Community");
    }

    // 5. Collect Venue / Platform
    printf("Enter Venue / Platform    : ");
    fgets(event.venue, MAX_STR, stdin);
    trimNewline(event.venue);
    trimSpaces(event.venue);
    if (strlen(event.venue) == 0) {
        strcpy(event.venue, "Online");
    }

    // --- File-IO Operation: Open in Append Mode ("a") ---
    // If the file does not exist, "a" creates it. If it exists, writes at the end.
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("\n❌ [ERROR] Failed to open file for appending");
        return;
    }

    // Write formatted record to disk
    fprintf(fp, "%s | %s | %s | %s | %s\n",
            event.title, event.category, event.date, event.speaker, event.venue);

    // Close the file stream to flush buffer immediately
    fclose(fp);

    printf("\n=========================================================\n");
    printf("      🎉 SUCCESS! EVENT RECORD APPENDED TO DISK          \n");
    printf("=========================================================\n");
    printf(" File   : %s\n", filename);
    printf(" Title  : %s\n", event.title);
    printf(" Type   : %s\n", event.category);
    printf(" Date   : %s\n", event.date);
    printf(" Speaker: %s\n", event.speaker);
    printf(" Venue  : %s\n", event.venue);
    printf("=========================================================\n");
}

// ============================================================================
// 2. View All Events (File I/O: Read Mode "r")
// ============================================================================
void displayAllEvents(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n⚠️ [NOTICE] Log file '%s' does not exist yet. Please log an event first!\n", filename);
        return;
    }

    char line[512];
    struct MeetupEvent event;
    int count = 0;

    printf("\n========================================================================================================\n");
    printf("                                      📜 ALL LOGGED TECH EVENTS & MEETUPS                               \n");
    printf("========================================================================================================\n");
    printf(" %-4s | %-32s | %-14s | %-12s | %-18s | %-20s\n",
           "#", "Event / Workshop Title", "Category", "Date", "Speaker/Host", "Venue/Platform");
    printf("--------------------------------------------------------------------------------------------------------\n");

    // Read stream line-by-line until EOF
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parseEventLine(line, &event)) {
            count++;
            printf(" %-4d | %-32.32s | %-14.14s | %-12.12s | %-18.18s | %-20.20s\n",
                   count, event.title, event.category, event.date, event.speaker, event.venue);
        }
    }

    fclose(fp);

    if (count == 0) {
        printf("                           (No events recorded in file yet)\n");
    }

    printf("========================================================================================================\n");
    printf(" 📊 Total Events Logged on Disk: %d\n", count);
    printf("========================================================================================================\n");
}

// ============================================================================
// 3. Search Events by Keyword (File I/O: Sequential File Scan)
// ============================================================================
void searchEvents(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n⚠️ [NOTICE] Log file '%s' not found. Please add events first.\n", filename);
        return;
    }

    char query[MAX_STR];
    printf("\n🔎 Enter search keyword (title, category, speaker, or venue): ");
    fgets(query, MAX_STR, stdin);
    trimNewline(query);
    trimSpaces(query);

    if (strlen(query) == 0) {
        printf("\n❌ [ERROR] Search query cannot be empty!\n");
        fclose(fp);
        return;
    }

    char lowerQuery[MAX_STR];
    toLowerCase(lowerQuery, query);

    char line[512];
    struct MeetupEvent event;
    int matches = 0;
    int totalScanned = 0;

    printf("\n========================================================================================================\n");
    printf("                                  🔎 SEARCH RESULTS FOR: \"%s\"                                           \n", query);
    printf("========================================================================================================\n");
    printf(" %-4s | %-32s | %-14s | %-12s | %-18s | %-20s\n",
           "#", "Event / Workshop Title", "Category", "Date", "Speaker/Host", "Venue/Platform");
    printf("--------------------------------------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parseEventLine(line, &event)) {
            totalScanned++;

            char lowerTitle[MAX_STR], lowerCat[MAX_STR], lowerSpeaker[MAX_STR], lowerVenue[MAX_STR];
            toLowerCase(lowerTitle, event.title);
            toLowerCase(lowerCat, event.category);
            toLowerCase(lowerSpeaker, event.speaker);
            toLowerCase(lowerVenue, event.venue);

            // Substring search using strstr()
            if (strstr(lowerTitle, lowerQuery) != NULL ||
                strstr(lowerCat, lowerQuery) != NULL ||
                strstr(lowerSpeaker, lowerQuery) != NULL ||
                strstr(lowerVenue, lowerQuery) != NULL) {
                
                matches++;
                printf(" %-4d | %-32.32s | %-14.14s | %-12.12s | %-18.18s | %-20.20s\n",
                       matches, event.title, event.category, event.date, event.speaker, event.venue);
            }
        }
    }

    fclose(fp);

    if (matches == 0) {
        printf("                 ❌ No events matching \"%s\" were found in %d records.\n", query, totalScanned);
    }

    printf("========================================================================================================\n");
    printf(" ✨ Found %d matching event(s) out of %d total records.\n", matches, totalScanned);
    printf("========================================================================================================\n");
}

// ============================================================================
// 4. View Statistics & File Size (File I/O: fseek() & ftell())
// ============================================================================
void displayEventStatistics(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\n⚠️ [NOTICE] Log file '%s' does not exist yet.\n", filename);
        return;
    }

    // Seek to end of file to determine file size in bytes
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);

    // Rewind back to the beginning of the file for line processing
    fseek(fp, 0, SEEK_SET);

    char line[512];
    struct MeetupEvent event;
    int totalEvents = 0;
    int workshops = 0;
    int meetups = 0;
    int bootcamps = 0;
    int hackathons = 0;
    int others = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parseEventLine(line, &event)) {
            totalEvents++;

            char lowerCat[MAX_STR];
            toLowerCase(lowerCat, event.category);

            if (strstr(lowerCat, "workshop") != NULL) {
                workshops++;
            } else if (strstr(lowerCat, "meetup") != NULL) {
                meetups++;
            } else if (strstr(lowerCat, "bootcamp") != NULL) {
                bootcamps++;
            } else if (strstr(lowerCat, "hackathon") != NULL) {
                hackathons++;
            } else {
                others++;
            }
        }
    }

    fclose(fp);

    printf("\n=========================================================\n");
    printf("             📊 MEETUP LOG SYSTEM ANALYTICS              \n");
    printf("=========================================================\n");
    printf(" Persistent File Name    : %s\n", filename);
    printf(" Physical File Size      : %ld bytes (%.2f KB)\n", fileSize, (float)fileSize / 1024.0);
    printf(" Total Logged Records    : %d Events\n", totalEvents);
    printf("---------------------------------------------------------\n");
    printf(" 🛠️  Workshops Recorded   : %d\n", workshops);
    printf(" 👥 Tech Meetups         : %d\n", meetups);
    printf(" 💻 Bootcamps            : %d\n", bootcamps);
    printf(" 🏆 Hackathons           : %d\n", hackathons);
    printf(" 🌐 Other / Webinars     : %d\n", others);
    printf("=========================================================\n");
}

// ============================================================================
// 5. Reset / Clear File (File I/O: Truncate Mode "w")
// ============================================================================
void resetLogFile(const char *filename) {
    char confirm;

    printf("\n⚠️  [CAUTION] You are about to clear all records in '%s'.\n", filename);
    printf("Are you sure you want to delete all entries? (y/n): ");
    scanf(" %c", &confirm);
    clearInputBuffer();

    if (confirm == 'y' || confirm == 'Y') {
        // Opening with "w" truncates existing file to 0 bytes
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            perror("❌ [ERROR] Could not reset log file");
            return;
        }
        fclose(fp);

        printf("\n✅ [SUCCESS] File '%s' has been reset to 0 bytes. All logs cleared.\n", filename);
    } else {
        printf("\n🛡️  [CANCELLED] Operation aborted. Your log file was not modified.\n");
    }
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

    // Leading spaces
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    // Trailing spaces
    char *end = start + strlen(start) - 1;
    while (end >= start && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

// Parses a pipe-delimited line into a MeetupEvent struct
int parseEventLine(const char *line, struct MeetupEvent *event) {
    char temp[512];
    strncpy(temp, line, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';
    trimNewline(temp);

    if (strlen(temp) == 0) return 0;

    // 1. Title
    char *token = strtok(temp, "|");
    if (!token) return 0;
    trimSpaces(token);
    strncpy(event->title, token, sizeof(event->title) - 1);
    event->title[sizeof(event->title) - 1] = '\0';

    // 2. Category
    token = strtok(NULL, "|");
    if (!token) return 0;
    trimSpaces(token);
    strncpy(event->category, token, sizeof(event->category) - 1);
    event->category[sizeof(event->category) - 1] = '\0';

    // 3. Date
    token = strtok(NULL, "|");
    if (!token) return 0;
    trimSpaces(token);
    strncpy(event->date, token, sizeof(event->date) - 1);
    event->date[sizeof(event->date) - 1] = '\0';

    // 4. Speaker
    token = strtok(NULL, "|");
    if (!token) return 0;
    trimSpaces(token);
    strncpy(event->speaker, token, sizeof(event->speaker) - 1);
    event->speaker[sizeof(event->speaker) - 1] = '\0';

    // 5. Venue
    token = strtok(NULL, "|");
    if (!token) return 0;
    trimSpaces(token);
    strncpy(event->venue, token, sizeof(event->venue) - 1);
    event->venue[sizeof(event->venue) - 1] = '\0';

    return 1;
}

// Converts string to lowercase for case-insensitive search
void toLowerCase(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = (char)tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}
