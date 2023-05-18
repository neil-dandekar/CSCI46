// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.08.2023     |
// _______________________

#include <stdio.h>

int getStart() {
    int x; // Starting number
    // Prompt user for number and store it:
    printf("Enter the starting numnber: ");
    scanf("%d", &x);

    // Check if number is valid. Prints error message and 
    // restarts process if invalid.
    if(x < 1) {
        printf("The number should be a positive integer.\n");
        return getStart();
    }

    // Return valid starting number
    return x;
}

// Generate the next Collatz number based on the current number
int nextCollatz(int n) {
    n = (n % 2) ? 3*n+1 : n/2; // Calculation
    return n;
}

int main() {
    int len = 1;            // Current sequence length
    int num = getStart();   // Current Collatz number; intitialize with getStart()
    printf("Colletz sequence: "); // Print sequence

    // Loop/print all of the next Collatz numbers until the end (num is 1):
    while(num != 1) {
        printf("%d, ", num);
        num = nextCollatz(num);
        len++;
    }

    // Finish sequence and print length:
    printf("%d \nLength: %d\n", num, len);

    int maxLen = 0; // Temp max length
    int maxInt = 0; // Temp max Collatz number
    
    // Loop through all numbers 2-1000 (1 is unnecessary to test)
    for(int i = 2; i <= 1000; i++) {
        len = 0; // Reset length
        num = i; // Current Collatz number

        // Generate Collatz sequence for num:
        while(num != 1) {
            num = nextCollatz(num);
            len++;
        }

        // Set new max values if possible:
        if(len > maxLen) {
            maxLen = len;
            maxInt = i;
        }
    }

    // Print results:
    printf("%d is the starting number, n, between 1 and 1000 that", maxInt);
    printf("results in the longest sequence, which is %d.", maxLen);
}