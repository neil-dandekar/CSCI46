// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.18.2023     |
// _______________________

#include <stdio.h>

// Max string length
#define STR_MAX 100

// Function prototypes here:
int stringLength(char str[STR_MAX]);

void trim(char str[STR_MAX]);

void reverse(char str[STR_MAX]);

// Main function
int main() {
    char input[STR_MAX];
	
    // Loop until we break out
    while (1) {
        printf("Enter a string: ");
        fgets(input, STR_MAX, stdin);
        if (input[0] == '.') {
            break;
        }
		
        // Trim the newline
        trim(input);

        // Print the trimmed string
        printf("After trim: %s\n", input);
		
        // Reverse the string
        reverse(input);
		
        // Print the reversed string
        printf("Reversed: %s\n", input);
    }
}

int stringLength(char str[STR_MAX]) {
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}

void trim(char str[STR_MAX]) {
    int length = stringLength(str);
    
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

void reverse(char str[STR_MAX]) {
    char temp;
    int len = stringLength(str);
    
    for (int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
