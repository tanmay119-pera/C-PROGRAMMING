/*                                        PROJECT 1: Credit (Loan) Calculator
 
 *  A beginner-friendly C program that calculates:

 *    1. Monthly EMI (Equated Monthly Installment)
 *    2. Total amount payable over the loan tenure
 *    3. Total interest paid
\
 *  The program uses the standard EMI formula:
 *  EMI = [P x R x (1+R)^N] / [(1+R)^N - 1]
 *  The program takes user input for:
 *    - Principal loan amount
 *    - Annual interest rate
 *    - Loan tenure
 *  Concepts used: functions, math.h, if-else, do-while loop,
 *                 printf/scanf, basic input validation
 */

#include <stdio.h>
#include <math.h>   // needed for pow() function used in EMI formula


/*Function: calculateEMI
 *  Calculates the Equated Monthly Installment (EMI) for a loan.
 *  Formula : EMI = [P x R x (1+R)^N] / [(1+R)^N - 1]
 *  P = Principal loan amount
 *  R = Monthly interest rate (as a decimal, not percentage)
 *  N = Loan tenure in months*/

float calculateEMI(float principal, float monthlyRate, int months) {
    float rateFactor = pow((1 + monthlyRate), months); // (1+R)^N
    float emi = (principal * monthlyRate * rateFactor) / (rateFactor - 1);
    return emi;
}

int main() {
    float principal;    // Loan amount requested by user
    float annualRate;   // Annual interest rate (in %)
    int years;           // Loan tenure in years
    char choice;         // To ask "calculate another loan?"

    do {
        // -------- Step 1: Take input from user --------
        printf("\n===== Credit / Loan Calculator =====\n");

        printf("Enter loan amount (Principal): Rs. ");
        scanf("%f", &principal);

        printf("Enter annual interest rate (in %%): ");
        scanf("%f", &annualRate);

        printf("Enter loan tenure (in years): ");
        scanf("%d", &years);

        // -------- Step 2: Validate input --------
        // A real loan can't have zero or negative values,
        // so we check before doing any math.
        if (principal <= 0 || annualRate <= 0 || years <= 0) {
            printf("Invalid input! Please enter positive values.\n");
        } else {
            // -------- Step 3: Convert to monthly units --------
            // EMI formula works in months, not years,
            // and needs the rate as a decimal, not a percentage.
            float monthlyRate = annualRate / 12 / 100;
            int months = years * 12;

            // -------- Step 4: Calculate EMI --------
            float emi = calculateEMI(principal, monthlyRate, months);

            // -------- Step 5: Calculate totals --------
            float totalPayment = emi * months;
            float totalInterest = totalPayment - principal;

            // -------- Step 6: Display results --------
            printf("\n----- Loan Summary -----\n");
            printf("Monthly EMI      : Rs. %.2f\n", emi);
            printf("Total Payment    : Rs. %.2f\n", totalPayment);
            printf("Total Interest   : Rs. %.2f\n", totalInterest);
        }

        // -------- Step 7: Repeat or exit --------
        printf("\nCalculate another loan? (y/n): ");
        scanf(" %c", &choice); // space before %c skips leftover newline in buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Credit Calculator!\n");
    return 0;
}