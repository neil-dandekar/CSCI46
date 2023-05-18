// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>
#include <string.h>

// Prepends string b to string a with a space in between
void prepend(char *a, char *b) {
    char copy[1000] = ""; // Temp copy string
    strcat(b, " ");       // Append a space to b
    strcpy(copy, b);      // Copy b to copy
    strcat(copy, a);      // Append a to copy (a to b)
    strcpy(a, copy);      // Copy copy to a
}

// Appends string b to string a with a space in between
void append(char *a, char *b) {
    strcat(b, " ");
    strcat(a, b);
}

// Trims newline character from a string
void trim(char *str) {
    char* n = strchr(str, '\n');
    *n = '\0';
}

int main() {
    char input[20] = "";
    char str[1000] = "";

    while (1) {
        // Get Input
        printf("Enter a string: ");
        fgets(input, 20, stdin);

        trim(input); // Trim input

        if (!strcmp(input, "DONE")) break; // Break if DONE
        else if(!strstr(str, input)) {     // If string does not contain input
            // Prepend if string is greater
            if (strcmp(str, input) > 0) prepend(str, input);
            // Append if input is greater
            else append(str, input); // Print result
        }
        printf("%s\n", str); // Print result
    }
    printf("%s\n", str);
}