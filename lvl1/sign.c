// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.01.2023     |
// _______________________

#include <stdio.h>

int main() {
    int height;                               // Height of the flag

    printf("Enter the height of the sign: "); // Prompt user for height
    scanf("%d", &height);                     // Read in value for height

    // Check if input is invalid and print error message
    if(height < 3 || height > 12) {
        printf("Height must be between 3 and 12.");
        return 0;
    }

    // Print flag header:
    printf("|---------------+\n");
    printf("| Neil Dandekar |\n");
    printf("|---------------+\n");

    // Print flag pole:
    for(int i = 0; i < height-3; i++) printf("|\n");
}