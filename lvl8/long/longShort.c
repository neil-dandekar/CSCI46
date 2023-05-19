// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *readf = fopen(argv[1], "r");
    // printf("read file name: %s", argv[1]);

    // FILE *shortf = fopen(argv[2], "w");
    // FILE *longf = fopen(argv[3], "w");

    // if (!readf || !shortf || !longf) {
    //     printf("File(s) could not be opened. Please try again.");
    //     exit(1);
    // }

    char line[1000];
    while(!feof(readf)) {
        fgets(line, 1000, readf);
        printf("%s", line);

        // fgets(line, 100, readf);
        // if (strlen(*line) > 20) {
        //     fputs(toupper(line), longf);
        // }
        // else fputs(tolower(line), shortf);
        
    }
    
    fclose(readf);
    // fclose(shortf);
    // fclose(longf);
    
}