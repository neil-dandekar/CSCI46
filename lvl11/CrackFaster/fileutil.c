#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFile(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	int CAPACITY = 100;
	char** arr = malloc(CAPACITY * sizeof(char *));
	
	*size = 0;

	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).

	char line[1000];    // Line from file
    // Loop through file

    while(!feof(in)) {

        // Get line
        fgets(line, 1000, in);

        // Trim newline character
        char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

		// Expand arr if needed
		if(*size == CAPACITY) {
			CAPACITY += 5;
			arr = realloc(arr, CAPACITY * sizeof(char *));
		}

        // Allocate space and add line to array
		// printf("size: %d\n", *size);
        arr[*size] = malloc(strlen(line) + 1);
        strcpy(arr[*size], line);

		// Increment size
		(*size)++;
    }

    // Close the file.
	fclose(in);

	// The size should be the number of entries in the array.
	
	// Return pointer to the array of strings.
	return arr;
}

// String comparison for Binary Search
int strsearch(const void *key, const void *elem) {	
	return strcmp((char *)key, *(char **)elem);
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

// Alphabetically compare two strings for QuickSort
int alphabetic(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}