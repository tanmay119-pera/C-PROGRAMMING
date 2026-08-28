/*                              PROJECT 3: Event RSVP Validator (Google Developer Events)
 
 *  A beginner-friendly C program that lets attendees RSVP to
 *  Google Developer style events (DevFest, I/O Extended, Study
 *  Jams) and validates their details before confirming a seat.
 *
 *  Validations performed:
 *    - Name    : letters and spaces only, not empty
 *    - Email   : has exactly one '@' and a '.' after it, no spaces
 *    - Phone   : exactly 10 digits
 *    - Seats   : event must have seats remaining
 *    - Duplicate: same email can't RSVP twice for the same event
 *
 *  Concepts used: structures, arrays, string.h functions,
 *                 ctype.h (isalpha/isdigit), functions, switch,
 *                 fgets for safe string input
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EVENTS 4
#define MAX_RSVPS 50

// ---------- One RSVP record ----------
typedef struct {
    int rsvpID;
    char name[50];
    char email[50];
    char phone[15];
    int eventIndex;   // which event from eventNames[] this belongs to
} RSVP;

// ---------- Predefined Google Developer events & seats left ----------
char eventNames[MAX_EVENTS][50] = {
    "DevFest 2026",
    "Google I/O Extended",
    "Android Study Jam",
    "Cloud Study Jam"
};
int seatsLeft[MAX_EVENTS] = {50, 30, 40, 25};

// ---------- Function prototypes ----------
void displayEvents();
int isValidName(char *name);
int isValidEmail(char *email);
int isValidPhone(char *phone);
int isDuplicate(RSVP list[], int count, char *email, int eventIndex);
void registerRSVP(RSVP list[], int *count);
void viewAllRSVPs(RSVP list[], int count);
void clearInputBuffer();

int main() {
    RSVP rsvpList[MAX_RSVPS];
    int rsvpCount = 0;
    int choice;

    do {
        printf("\n===== Google Developer Event RSVP Validator =====\n");
        printf("1. View Events\n");
        printf("2. RSVP for an Event\n");
        printf("3. View All RSVPs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // remove leftover newline so fgets() works next

        switch (choice) {
            case 1:
                displayEvents();
                break;
            case 2:
                registerRSVP(rsvpList, &rsvpCount);
                break;
            case 3:
                viewAllRSVPs(rsvpList, rsvpCount);
                break;
            case 4:
                printf("Thank you for using the RSVP Validator!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// ------------------------------------------------------------
// scanf("%d", ...) leaves a newline character behind in the
// input buffer. If we don't clear it, the next fgets() will
// read that leftover newline instead of waiting for real input.
// This function throws away everything up to and including it.
// ------------------------------------------------------------
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ------------------------------------------------------------
// Prints every event along with how many seats are still free.
// ------------------------------------------------------------
void displayEvents() {
    printf("\n----- Available Events -----\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        printf("%d. %s (Seats left: %d)\n", i + 1, eventNames[i], seatsLeft[i]);
    }
}

// ------------------------------------------------------------
// A valid name has at least one character and contains only
// letters and spaces - no digits, no symbols.
// ------------------------------------------------------------
int isValidName(char *name) {
    if (strlen(name) == 0) return 0;

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ') {
            return 0; // found a character that isn't a letter/space
        }
    }
    return 1;
}

// ------------------------------------------------------------
// Simple (not fully RFC-compliant, but solid for beginner
// practice) email validation:
//   - exactly one '@'
//   - a '.' appearing somewhere after the '@'
//   - no spaces anywhere in the string
// ------------------------------------------------------------
int isValidEmail(char *email) {
    char *atSign = strchr(email, '@');
    if (atSign == NULL) return 0; // no '@' found at all

    if (strchr(atSign + 1, '@') != NULL) return 0; // more than one '@'

    char *dot = strchr(atSign, '.');
    if (dot == NULL) return 0; // no '.' after the '@'

    if (strchr(email, ' ') != NULL) return 0; // spaces aren't allowed

    return 1;
}

// ------------------------------------------------------------
// A valid phone number here is exactly 10 digits, nothing else.
// ------------------------------------------------------------
int isValidPhone(char *phone) {
    if (strlen(phone) != 10) return 0;

    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit((unsigned char)phone[i])) return 0;
    }
    return 1;
}

// ------------------------------------------------------------
// Stops the same email from RSVPing twice for the same event
// by scanning through all previously stored RSVPs.
// ------------------------------------------------------------
int isDuplicate(RSVP list[], int count, char *email, int eventIndex) {
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].email, email) == 0 && list[i].eventIndex == eventIndex) {
            return 1; // already registered for this event
        }
    }
    return 0;
}

// ------------------------------------------------------------
// Walks through one full RSVP attempt: pick event, enter
// details, validate everything, then store it if all checks
// pass and a seat is still available.
// ------------------------------------------------------------
void registerRSVP(RSVP list[], int *count) {
    if (*count >= MAX_RSVPS) {
        printf("RSVP list is full. Cannot register more attendees.\n");
        return;
    }

    char nameInput[50], emailInput[50], phoneInput[15];
    int eventChoice;

    displayEvents();
    printf("Select event number: ");
    scanf("%d", &eventChoice);
    clearInputBuffer();

    // Validate the event number is actually on the menu
    if (eventChoice < 1 || eventChoice > MAX_EVENTS) {
        printf("Invalid event number.\n");
        return;
    }
    int eventIndex = eventChoice - 1;

    // Check seat availability before bothering to collect details
    if (seatsLeft[eventIndex] <= 0) {
        printf("Sorry, %s is fully booked.\n", eventNames[eventIndex]);
        return;
    }

    // fgets() is used (not scanf("%s")) so full names with spaces
    // are read correctly, and the input can't overflow the buffer.
    printf("Enter full name: ");
    fgets(nameInput, sizeof(nameInput), stdin);
    nameInput[strcspn(nameInput, "\n")] = '\0'; // strip trailing newline

    printf("Enter email: ");
    fgets(emailInput, sizeof(emailInput), stdin);
    emailInput[strcspn(emailInput, "\n")] = '\0';

    printf("Enter 10-digit phone number: ");
    fgets(phoneInput, sizeof(phoneInput), stdin);
    phoneInput[strcspn(phoneInput, "\n")] = '\0';

    // -------- Run every validation before saving anything --------
    if (!isValidName(nameInput)) {
        printf("Registration failed: name must contain only letters and spaces.\n");
        return;
    }
    if (!isValidEmail(emailInput)) {
        printf("Registration failed: invalid email format.\n");
        return;
    }
    if (!isValidPhone(phoneInput)) {
        printf("Registration failed: phone number must be exactly 10 digits.\n");
        return;
    }
    if (isDuplicate(list, *count, emailInput, eventIndex)) {
        printf("Registration failed: this email has already RSVP'd for this event.\n");
        return;
    }

    // -------- All checks passed: save the RSVP --------
    RSVP newRsvp;
    newRsvp.rsvpID = *count + 1;
    strcpy(newRsvp.name, nameInput);
    strcpy(newRsvp.email, emailInput);
    strcpy(newRsvp.phone, phoneInput);
    newRsvp.eventIndex = eventIndex;

    list[*count] = newRsvp;
    (*count)++;
    seatsLeft[eventIndex]--; // one less seat available now

    printf("\nRSVP confirmed! Your RSVP ID is %d for %s.\n",
           newRsvp.rsvpID, eventNames[eventIndex]);
}

// ------------------------------------------------------------
// Lists every confirmed RSVP collected so far.
// ------------------------------------------------------------
void viewAllRSVPs(RSVP list[], int count) {
    if (count == 0) {
        printf("\nNo RSVPs yet.\n");
        return;
    }

    printf("\n----- All Confirmed RSVPs -----\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s | Event: %s\n",
               list[i].rsvpID, list[i].name, list[i].email,
               list[i].phone, eventNames[list[i].eventIndex]);
    }
}