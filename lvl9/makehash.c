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
    FILE *writef = fopen(argv[2], "w");     // File to write (short strings - lower)

    // Print error message if file(s) are null
    if (!readf || !writef) {
        printf("File(s) could not be opened. Please try again.");
        exit(1);
    }

    char line[1000];
    while(!feof(readf)) {
        fgets(line, 1000, readf);

        
    }
}