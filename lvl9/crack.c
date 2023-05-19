#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings


// Given a target plaintext word, use it to try to find
// a matching hash in the hashFile.
// Get this function working first!
char * tryWord(char * plaintext, char * hashFilename)
{
    // Hash the plaintext
    char *hash = md5(plaintext, strlen(plaintext));

    // Open the hash file
    FILE *hashf = fopen(hashFilename, "r");

    // Loop through the hash file, one line at a time.
    char line[1000];    // Line from file
    int match = 0;
    while(!feof(hashf)) {

        // Get line
        fgets(line, 1000, hashf);

        // Trim newline character
        char *nl = strchr(line, '\n');
        if (nl) *nl = '\0';

        // Attempt to match the hash from the file to the
        // hash of the plaintext.
        if (!strcmp(hash, line)) {
            match = 1;
            break;
        }
    }

    // Before returning, do any needed cleanup:
    //   Close files?
    //   Free memory?
    fclose(hashf);

    // If there is a match, you'll return the hash.
    // If not, return NULL.
    if (match) return hash;
    else return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the dictionary file for reading.
    FILE *d = fopen(argv[2], "r");

    // For each dictionary word, pass it to tryWord, which
    // will attempt to match it against the hashes in the hash_file.
    char word[30];    // Line from file
    int count = 0;

    while(!feof(d)) {

        // Get line
        fgets(word, 30, d);

        // Trim newline character
        char *nl = strchr(word, '\n');
        if (nl) *nl = '\0';

        char* hash = tryWord(word, argv[1]);

        // If we got a match, display the hash and the word. For example:
        //   5d41402abc4b2a76b9719d911017c592 hello
        if (hash) {
            printf("%s %s\n", hash, word);
            count++;
        }
    }

    // Close the dictionary file.
    fclose(d);

    // Display the number of hashes that were cracked.
    printf("%d hashes were cracked.\n", count);
}