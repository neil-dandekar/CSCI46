// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.01.2023     |
// _______________________

#include <stdio.h>

int main() {
    int n1, d1; // Numerator and denominator of fraction 1
    int n2, d2; // Numerator and denominator of fraction 2
    int n3, d3; // Numerator and denominator of fraction 1 + 2

    printf("This program will sum two fractions.\n"); // Info of program
    printf("Input the first fraction: ");             // Prompt user for fraction 1
    scanf("%d/%d", &n1, &d1);                         // Read input for n1 and d1
    printf("Input the second fraction: ");            // Prompt user for fraction 2
    scanf("%d/%d", &n2, &d2);                         // Read input for n2 and d2

    n3 = n1*d2 + n2*d1;                               // Calculate n3
    d3 = d1*d2;                                       // Calculate d3

    printf("The sum is: %d/%d", n3, d3);              // Display sum
}