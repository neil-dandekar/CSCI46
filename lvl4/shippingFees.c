// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>

// Get length of a string
int length(char str[100]) {
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}

// Get weight of largest compartment of a container
float getWeight(char str[], int len) {
    float left = 0;
    float right = 0;
    int x; // ASCII value offset for weight conversion

    
    for (int i = 0; i < len-1; i++) {
        x = 38;                     // Offset value for A-Z
        if (str[i] >= 97) x = 96;   // Offset value for a-z

        // Add to left total if first half of string
        if (i < len/2) left += (str[i]-x) * 0.1; 

        // Add to right total if second half of string
        else right += (str[i]-x) * 0.1;          
    }

    // Return larger weight
    if (left > right) return left;
    return right;
}

int main() {
    char container[100];
    float weight = 0;
    int numContainers = 0;

    // Loop for container values
    while(1) {
        // Get Container
        printf("Container: ");
        fgets(container, 100, stdin);

        // Break if '.' is entered
        if (container[0] == '.') break;

        // Get weight and add to sum
        weight += getWeight(container, length(container));
        numContainers++; // Increment count
    }

    // Calculate total price
    float total = weight * 2.75;

    // Print result
    printf("%d containers, total shipping fee $%.2f", numContainers, total);
}