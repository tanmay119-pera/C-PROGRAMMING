/*                                         PROJECT 4: Terminal Study Timer

 *  A beginner-friendly C program that runs a live countdown
 *  timer right in the terminal, logs every completed session
 *  (subject + duration + timestamp) to a file, and lets you
 *  review your full study history any time - even after
 *  closing and reopening the program.
 *
 *  Features:
 *    1. Custom Timer   - study any subject for N minutes
 *    2. Pomodoro Mode  - repeated 25-min work / 5-min break cycles
 *    3. View Log       - see every session ever recorded, with totals
 *
 *  Concepts used: structures-free file I/O (fopen/fprintf/fgets),
 *                 time.h for timestamps, cross-platform sleep,
 *                 '\r' for a live-updating countdown line, functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// sleep() works differently on Windows vs Linux/Mac. This picks
// the right version automatically depending on where it's compiled.
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_SECONDS(x) Sleep((x) * 1000)
#else
    #include <unistd.h>
    #define SLEEP_SECONDS(x) sleep(x)
#endif

#define LOG_FILE "study_log.txt"
#define WORK_MINUTES 25
#define BREAK_MINUTES 5

// ---------- Function prototypes ----------
void showMenu();
void countdown(int totalSeconds, const char *label);
void startCustomTimer();
void startPomodoro();
void logSession(const char *subject, int minutes);
void viewLog();
void clearInputBuffer();

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // flush leftover newline before any fgets()

        switch (choice) {
            case 1: startCustomTimer(); break;
            case 2: startPomodoro();    break;
            case 3: viewLog();          break;
            case 4: printf("Happy studying! Goodbye.\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// ------------------------------------------------------------
// Prints the main menu.
// ------------------------------------------------------------
void showMenu() {
    printf("\n===== Terminal Study Timer =====\n");
    printf("1. Custom Timer\n");
    printf("2. Pomodoro Session (25 min work / 5 min break)\n");
    printf("3. View Session Log\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// ------------------------------------------------------------
// scanf("%d", ...) leaves a newline character behind in the
// input buffer. If we don't clear it, the next fgets() call
// will read that leftover newline instead of waiting for real
// input. This throws away everything up to and including it.
// ------------------------------------------------------------
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ------------------------------------------------------------
// Counts down from totalSeconds to 0, updating the SAME
// terminal line every second using '\r' (carriage return)
// instead of printing a brand new line each time.
// ------------------------------------------------------------
void countdown(int totalSeconds, const char *label) {
    for (int remaining = totalSeconds; remaining >= 0; remaining--) {
        int mins = remaining / 60;
        int secs = remaining % 60;

        // '\r' moves the cursor back to the start of the line, so
        // this printf overwrites the previous one instead of
        // scrolling the terminal with a new line every second.
        printf("\r%s - Time left: %02d:%02d ", label, mins, secs);
        fflush(stdout); // push the output to screen immediately

        if (remaining > 0) {
            SLEEP_SECONDS(1);
        }
    }
    printf("\n");
    printf("\a"); // '\a' is the terminal bell - beeps when time's up
}

// ------------------------------------------------------------
// Appends one completed session to the log file along with the
// current date/time, so your history survives across runs.
// ------------------------------------------------------------
void logSession(const char *subject, int minutes) {
    FILE *file = fopen(LOG_FILE, "a"); // "a" = append, keeps old entries
    if (file == NULL) {
        printf("Warning: could not save session to log file.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *localTime = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M", localTime);

    fprintf(file, "%s | %s | %d min\n", timestamp, subject, minutes);
    fclose(file);
}

// ------------------------------------------------------------
// Runs one custom-length timer for a subject the user names,
// then logs it once the countdown finishes.
// ------------------------------------------------------------
void startCustomTimer() {
    char subject[50];
    int minutes;

    printf("What are you studying? ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0'; // strip the trailing newline

    printf("How many minutes? ");
    scanf("%d", &minutes);
    clearInputBuffer();

    if (minutes <= 0) {
        printf("Please enter a positive number of minutes.\n");
        return;
    }

    printf("\nStarting timer for '%s'. Stay focused!\n", subject);
    countdown(minutes * 60, subject);

    printf("Session complete! Great work on '%s'.\n", subject);
    logSession(subject, minutes);
}

// ------------------------------------------------------------
// Runs a classic Pomodoro sequence: work, then break, repeated
// for however many cycles the user asks for.
// ------------------------------------------------------------
void startPomodoro() {
    char subject[50];
    int cycles;

    printf("What are you studying? ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("How many Pomodoro cycles? ");
    scanf("%d", &cycles);
    clearInputBuffer();

    if (cycles <= 0) {
        printf("Please enter a positive number of cycles.\n");
        return;
    }

    for (int i = 1; i <= cycles; i++) {
        printf("\n--- Cycle %d of %d: Work ---\n", i, cycles);
        countdown(WORK_MINUTES * 60, "Work");
        logSession(subject, WORK_MINUTES);

        // Skip the break after the very last cycle
        if (i < cycles) {
            printf("\n--- Cycle %d of %d: Break ---\n", i, cycles);
            countdown(BREAK_MINUTES * 60, "Break");
        }
    }

    printf("\nPomodoro session finished. Well done!\n");
}

// ------------------------------------------------------------
// Reads and prints every session ever logged, plus a running
// total of minutes studied across all of them.
// ------------------------------------------------------------
void viewLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        printf("\nNo sessions logged yet.\n");
        return;
    }

    char line[100];
    int totalMinutes = 0;
    int sessionCount = 0;

    printf("\n----- Study Session Log -----\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        sessionCount++;

        // Each line looks like: "2026-08-29 10:00 | Maths | 25 min"
        // strrchr finds the LAST '|', right before the minutes value,
        // and atoi() reads the number that follows it.
        char *lastPipe = strrchr(line, '|');
        if (lastPipe != NULL) {
            totalMinutes += atoi(lastPipe + 1);
        }
    }
    fclose(file);

    printf("------------------------------\n");
    printf("Total sessions: %d | Total time studied: %d minutes\n",
           sessionCount, totalMinutes);
}