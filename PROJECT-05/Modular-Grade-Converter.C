/*                                              PROJECT 5: Grade Converter 

 *  Converts percentage marks into letter grades, grade points,
 *  and pass/fail status, using a common Indian university
 *  10-point grading scale:
 *
 *    90-100 -> O   (Outstanding)   -> 10 points
 *    80-89  -> A+  (Excellent)     -> 9  points
 *    70-79  -> A   (Very Good)     -> 8  points
 *    60-69  -> B+  (Good)          -> 7  points
 *    50-59  -> B   (Above Average) -> 6  points
 *    45-49  -> C   (Average)       -> 5  points
 *    40-44  -> P   (Pass)          -> 4  points
 *    below 40 -> F (Fail)          -> 0  points
 *
 *  (Adjust the cutoffs below if your university uses different
 *  ones - everything else stays the same.)
 *
 *  Modes:
 *    1. Single Conversion - one percentage -> grade + grade point
 *    2. Batch Conversion   - multiple subjects -> GPA
 *                            (credit-weighted average grade point)
 *
 *  Concepts used: functions, if-else chains, arrays, loops,
 *                 basic input validation
 */

#include <stdio.h>

#define MAX_SUBJECTS 20

// ---------- Function prototypes ----------
// Declaring these up top lets main() call them even though
// their full code appears later in the file.
const char* getLetterGrade(float percentage);
int getGradePoint(float percentage);
int isPassing(float percentage);
int isValidPercentage(float percentage);
void convertSingle();
void convertBatch();

int main() {
    int choice;

    do {
        printf("\n===== Grade Converter =====\n");
        printf("1. Convert a Single Percentage\n");
        printf("2. Convert Multiple Subjects (Batch + SGPA)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: convertSingle(); break;
            case 2: convertBatch();  break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}

// ------------------------------------------------------------
// Maps a percentage to its letter grade using the scale above.
// The checks go from highest to lowest so each percentage
// falls through until it matches the right bracket.
// ------------------------------------------------------------
const char* getLetterGrade(float percentage) {
    if (percentage >= 90) return "O";
    else if (percentage >= 80) return "A+";
    else if (percentage >= 70) return "A";
    else if (percentage >= 60) return "B+";
    else if (percentage >= 50) return "B";
    else if (percentage >= 45) return "C";
    else if (percentage >= 40) return "P";
    else return "F";
}

// ------------------------------------------------------------
// Same brackets as getLetterGrade(), but returns the numeric
// grade point instead - used later for SGPA calculation.
// ------------------------------------------------------------
int getGradePoint(float percentage) {
    if (percentage >= 90) return 10;
    else if (percentage >= 80) return 9;
    else if (percentage >= 70) return 8;
    else if (percentage >= 60) return 7;
    else if (percentage >= 50) return 6;
    else if (percentage >= 45) return 5;
    else if (percentage >= 40) return 4;
    else return 0;
}

// ------------------------------------------------------------
// Anything 40% or above counts as passing on this scale.
// ------------------------------------------------------------
int isPassing(float percentage) {
    return percentage >= 40;
}

// ------------------------------------------------------------
// A percentage only makes sense between 0 and 100.
// ------------------------------------------------------------
int isValidPercentage(float percentage) {
    return percentage >= 0 && percentage <= 100;
}

// ------------------------------------------------------------
// Converts one percentage into its letter grade, grade point,
// and pass/fail status.
// ------------------------------------------------------------
void convertSingle() {
    float percentage;

    printf("Enter percentage (0-100): ");
    scanf("%f", &percentage);

    if (!isValidPercentage(percentage)) {
        printf("Invalid percentage! Must be between 0 and 100.\n");
        return;
    }

    printf("\nLetter Grade : %s\n", getLetterGrade(percentage));
    printf("Grade Point  : %d/10\n", getGradePoint(percentage));
    printf("Status       : %s\n", isPassing(percentage) ? "PASS" : "FAIL");
}

// ------------------------------------------------------------
// Converts several subjects at once and computes SGPA - the
// credit-weighted average of all grade points, which is how
// most Indian universities calculate a semester's GPA:
//
//   SGPA = (sum of gradePoint x credits for each subject)
//          -------------------------------------------------
//                    (sum of credits for each subject)
// ------------------------------------------------------------
void convertBatch() {
    int numSubjects;

    printf("How many subjects? (max %d): ", MAX_SUBJECTS);
    scanf("%d", &numSubjects);

    if (numSubjects <= 0 || numSubjects > MAX_SUBJECTS) {
        printf("Please enter a number between 1 and %d.\n", MAX_SUBJECTS);
        return;
    }

    float percentages[MAX_SUBJECTS];
    int credits[MAX_SUBJECTS];
    float totalCreditPoints = 0; // running sum of (gradePoint x credits)
    int totalCredits = 0;        // running sum of credits

    for (int i = 0; i < numSubjects; i++) {
        printf("\nSubject %d\n", i + 1);

        printf("  Percentage: ");
        scanf("%f", &percentages[i]);

        printf("  Credits: ");
        scanf("%d", &credits[i]);

        // Skip this subject instead of crashing if the entry is bad
        if (!isValidPercentage(percentages[i]) || credits[i] <= 0) {
            printf("  Invalid entry - skipping this subject.\n");
            continue;
        }

        int gradePoint = getGradePoint(percentages[i]);
        printf("  -> Grade: %s | Grade Point: %d\n",
               getLetterGrade(percentages[i]), gradePoint);

        totalCreditPoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    printf("\n----- Summary -----\n");
    if (totalCredits > 0) {
        float sgpa = totalCreditPoints / totalCredits;
        printf("SGPA (credit-weighted average): %.2f\n", sgpa);
    } else {
        printf("No valid subjects to calculate SGPA.\n");
    }
}