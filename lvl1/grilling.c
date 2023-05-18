// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.01.2023     |
// _______________________

#include <stdio.h>

int main() {
    int width, height; // Width and height of grill

    printf("Enter a grill width: ");  // Prompt user for width
    scanf("%d", &width);              // Read value for width

    printf("Enter a grill height: "); // Prompt user for height
    scanf("%d", &height);             // Read value for height

    // Check if input is invalid and print error message:
    if(width < 2 || width > 30 || height < 2 || height > 12) {
        printf("The width must be 2-30 and the height must be 2-12\n\n");
        return 0;
    }

    printf("\n"); // Newline to separate grill from I/O
    // Loop for every row:
    for(int i = 0; i < height; i++) {
        // Loop for every column
        for(int j = 0; j < width; j++) {
            // If the current grill index is a side or corner:
            if(j == 0 || j == width - 1) {
                // Print "+" if current index is a corner
                if(i == 0 || i == height - 1) printf("+"); 
                // Print "|" if current index is a side
                else printf("|");
            }
            // Print "-" if current index is neither a cornder nor side:
            else printf("-");
        }
        printf("\n"); // Newline for next row
    }
}