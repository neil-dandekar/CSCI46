// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.08.2023     |
// _______________________

#include <stdio.h>

int bills(int n) {
    int bills = 0; // Number of bills

    // Test $100 bills:
    bills += n / 100;
    n = n % 100;

    // Test $20 bills:
    bills += n / 20;
    n = n % 20;

    // Test $10 bills:
    bills += n / 10;
    n = n % 10;

    // Test $5 bills:
    bills += n / 5;
    n = n % 5;

    // Test $1 bills:
    bills += n;

    // Return result:
    return bills;
}

int getAmount() {
    int x; // Amount
    // Prompt user for number and store it:
    printf("Enter the amount: ");
    scanf("%d", &x);

    // Check if number is valid. Prints error message and 
    // restarts process if invalid.
    if(x < 1) {
        printf("The amount should be a positive integer.\n");
        return getAmount();
    }

    // Return valid starting number
    return x;
}

int main() {
    // Get amount using getAmount(), call bills(), and print result:
    int amount = getAmount();
    printf("A minimum of %d bill(s) needed for $%d.", bills(amount), amount);
}