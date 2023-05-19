// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    // Print error message if not enough command line arguments
    if (argc < 2) {
        printf("Please supply the correct number of arguments.");
        exit(1);
    }

    char *str = argv[1];                    // String to search for
    FILE *readf = fopen(argv[2], "r");      // File to read

    // Print error message if file(s) are null
    if (!readf) {
        printf("File could not be opened. Please try again.");
        exit(1);
    }

    char line[255]; // Line of text read from file

    // Loop through read file
    while(!feof(readf)) {
        fgets(line, 255, readf); // Get line

        // Check if string is in line and print it
        if (strstr(line, str)) printf("%s", line);
    }
    
    // Close file
    fclose(readf);
}

// TEST CASES:
// ./a.out alphabet.txt short.txt long.txt