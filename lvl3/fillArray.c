// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.08.2023     |
// _______________________

#include <stdio.h>

// Generate the next Collatz number based on the current number
int Collatz(int n) {
    n = (n % 2) ? 3 * n + 1 : n / 2; // Calculation
    return n;
}

int main() {
    // Array
    int arr[40];

    // Index 0-9: Numbers 0-9 using for loop
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Index 10-19: Numbers 100, 110, 120, ..., 190 using for loop
    for (int i = 10; i < 20; i++) {
        arr[i] = 10*i;
    }
    
    // Index 20-25: The values 4, 8, 15, 16, 23, 42 (explicitly assigned)
    arr[20] = 4;
    arr[21] = 8;
    arr[22] = 15;
    arr[23] = 16;
    arr[24] = 23;
    arr[25] = 42;

    // Index 26-39: Collatz Sequence starting at 7
    arr[26] = 7; // Assign first value
    // Assign rest of sequence using for loop
    for (int i = 27; i < 40; i++) {
        arr[i] = Collatz(i - 19);
    }
    
    // Print array
    for (int i = 0; i < 40; i++) {
        printf("%d, ", arr[i]);
    }
}