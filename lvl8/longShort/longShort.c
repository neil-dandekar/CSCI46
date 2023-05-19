// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    FILE *readf = fopen(argv[1], "r");      // File to read
    FILE *shortf = fopen(argv[2], "w");     // File to write (short strings - lower)
    FILE *longf = fopen(argv[3], "w");      // File to write (long  strings - UPPER)

    // Print error message if file(s) are null
    if (!readf || !shortf || !longf) {
        printf("File(s) could not be opened. Please try again.");
        exit(1);
    }

    char line[1000]; // Line of text read from file
    int numShort = 0;
    int numLong = 0;
    // Loop through read file
    while(!feof(readf)) {
        fgets(line, 1000, readf); // Get line

        int i = 0; // Counter for toupper() and tolower() loops
        if (strlen(line) < 20) { // Check length of line
            // Convert line to lowercase
            while(line[i]) {
                line[i] = tolower(line[i]);
                i++;
            }
            
            // Write line to file
            fputs(line, shortf);
            numShort++;
        }
        else {
            // Convert line to uppercase
            while(line[i]) {
                line[i] = toupper(line[i]);
                i++;
            }

            // Write line to file
            fputs(line, longf);
            numLong++;
        }
    }
    
    // Close files
    fclose(readf);
    fclose(shortf);
    fclose(longf);

    // Print number of lines written to each file
    printf("%d lines written to short.txt\n", numShort);
    printf("%d lines written to long.txt\n", numLong);
}

// TEST CASES:
// ./a.out alphabet.txt short.txt long.txt
// ./a.out greeneggs.txt short.txt long.txt