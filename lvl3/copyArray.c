// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  02.08.2023     |
// _______________________

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this constant to 1 to fill source array
// with random values.
#define RAND_ARR 0

#define SRC_SIZE 10

int main()
{
    // Declare source array
    int source[SRC_SIZE];
    
    // Fill array with random values or constant values
    if (RAND_ARR == 1)
    {
        // Seed random number generator
        srandom(time(NULL));
        
        // Fill array with random values
        for (int i = 0; i < SRC_SIZE; i++)
            source[i] = random() % 20 - 10;
    }
    else
    {
        // Fill array with constant values
        source[0] = 9;
        source[1] = 2;
        source[2] = 0;
        source[3] = -4;
        source[4] = 0;
        source[5] = 21;
        source[6] = -92;
        source[7] = 1;
        source[8] = 10;
        source[9] = 2;
    }
    
    // ADD YOUR CODE BELOW HERE
    
    // What to do:
    //   Determine the number of positive and number of negative
    //     values.
    //   Declare the pos and neg arrays, sized correctly.
    //   Copy the values out of the source array into the pos or neg
    //      array, as appropriate.
    
    // You'll need to replace these two lines with some code to
    //    determine the correct values.

    // pos and neg lengths
    int posLength = 0;
    int negLength = 0;

    // Count pos and neg numbers in source
    for (int i = 0; i < 10; i++) {
        if (source[i] > 0) posLength++;
        if (source[i] < 0) negLength++;
    }

    // Initialize arrays
    int pos[posLength];
    int neg[negLength];

    // Counters to place values in arrays
    int pCount = 0;
    int nCount = 0;

    // Loop and copy values accordingly
    for (int i = 0; i < 10; i++) {
        if (source[i] > 0) {
            pos[pCount] = source[i];
            pCount++;
        }
        if (source[i] < 0) {
            neg[nCount] = source[i];
            nCount++;
        }
    }
    
    // YOUR CODE ABOVE HERE
    
    // Display the contents of the pos array
    printf("pos: ");
    for (int i = 0; i < posLength; i++) {
        printf("%d ", pos[i]);
    }
    printf("\n");
    
    // TODO: Display contents of the neg array
    printf("neg: ");
    for (int i = 0; i < negLength; i++) {
        printf("%d ", neg[i]);
    }
    printf("\n");

}