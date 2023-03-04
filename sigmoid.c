// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.08.2023     |
// _______________________

#include <stdio.h>
#include <math.h>

// Calculates the sigmoid of the input float and returns a float
float sigmoid(float x) {
    return 1 / (1 + exp(-x)); // Calculation
}

int main() {
    // Loop through input values and print out the result:
    for(float i = -5; i < 6; i++) {
        printf("%.3f %.3f\n", i, sigmoid(i));
    }
}