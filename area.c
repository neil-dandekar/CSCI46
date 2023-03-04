// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.01.2023     |
// _______________________

#include <stdio.h>

int main() {
    int width, height;                                      // Width and height of rectangle
    printf("Enter the height and width of a rectangle: ");  // Prompt user for width and height
    scanf("%d %d", &width, &height);                        // Read values for width and height
    printf("The area is %d sq in.", width*height);          // Display the area
}