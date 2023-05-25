#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    char **hashes = loadFile(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    qsort(hashes, size, sizeof(char *), alphabetic);
    
    // Open the password file for reading.
    FILE *passwords = fopen(argv[2], "r");

    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.

    // Get line and set counter
    char target[30];
    int count = 0;

    while(!feof(passwords)) {

        // Get line
        fgets(target, 30, passwords);

        // Trim newline character
        char *nl = strchr(target, '\n');
        if (nl) *nl = '\0';

        // CHALLENGE1: Use binary search instead of linear search.
        // Make hash and binary search in hashes array
        char* hash = md5(target, strlen(target));
        char* found = bsearch(hash, hashes, size, sizeof(char *), strsearch);

        // If we got a match, display the hash and the word.
        if (found) {
            printf("Found: %s\n", target);
            count++;
        }
    }

    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
    fclose(passwords);
    printf("Found %d hash(es).\n", count);
    freeAA(hashes, size);
}