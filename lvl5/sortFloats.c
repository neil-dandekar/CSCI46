// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>

// Swap the value of integers a and b
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Get three prices and "return" in ascending order
void getPrices(float *a, float *b, float *c) {
    // Get values
    printf("Enter the price of item 1: ");
    scanf("%f", a);

    printf("Enter the price of item 2: ");
    scanf("%f", b);

    printf("Enter the price of item 3: ");
    scanf("%f", c);

    // Sort values
    if (*a > *b) swap(a, b); // Ensures a < b
    if (*a > *c) swap(a, c); // Ensures a < c
    if (*b > *c) swap(c, b); // Ensures b < c
}

int main() {
    float price1;
    float price2;
    float price3;
    getPrices(&price1, &price2, &price3);
    printf("The three price are: %.2f, %.2f, %.2f", price1, price2, price3); 
}