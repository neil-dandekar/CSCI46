// Name:  Neil Dandekar  |
// Class: CSCI 46        |
// Date:  05.16.2023     |
// _______________________

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);

void fillBoard(int arr[], int len);

void shuffleBoard(int arr[], int len);

void printBoard(int arr[], int len);

void reverse(int arr[], int len, int num);

int isSorted(int arr[], int len);

int main() {
    // Seed the random number generator
    srandom(time(NULL));
        
    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board: ", 3, 20);
    
    // Create board. Shuffle numbers.
    int board[boardLength];
    
    // Fill board in order with numbers 1..boardLength.
    fillBoard(board, boardLength);
    
    // Shuffle board.
    while (isSorted(board, boardLength)) {
       shuffleBoard(board, boardLength);
    }
    
    // Print board
    printBoard(board, boardLength);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers
        reverse(board, boardLength, amt);
        
        // Print the board
        printBoard(board, boardLength);
        
        // Check to see if the game is over
        gameOver = isSorted(board, boardLength);
        
        moves++;
    }
    printf("You won in %d moves!\n", moves);
}

// Get integer between min and max with prompt
int getInt(char prompt[], int min, int max) {
    // Number to return
    int num;

    // Get input
    printf("%s", prompt);
    scanf("%d", &num);

    // Input validation
    if (num < min || num > max) {
        printf("Number must be between %d and %d. Please try again.\n", min, max);
        return getInt(prompt, min, max); // Recursive call to get int if error exists
    }

    // Return valid number
    else return num;
}

// Fill a board (array) with ascending values from 1.
void fillBoard(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = i + 1;
    } 
}

// Shuffle a board (array) randomly
void shuffleBoard(int arr[], int len) {
    // Fisher-Yates Shuffle (https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)
    int j;
    int temp;
    for (int i = len-1; i >= 0; i--) {
        j = random() % (i+1);

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Print a board (array)
void printBoard(int arr[], int len) {

    printf("Board: ");
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

// Reverse the first num elements of a board (array)
void reverse(int arr[], int len, int num) {

    int temp; // Temp element in swap

    // Each iteration swaps two elements --> only num/2 iterations needed
    // Swaps the first and last elements and works inwards

    // For example, consider this array: {1, 2, 3, 4, 5, 6, 7, 8, 9} 
    // and swap the first 7 elements:
    //      Iteration 1: {7, 2, 3, 4, 5, 6, 1, 8, 9} 
    //      Iteration 2: {7, 6, 3, 4, 5, 2, 1, 8, 9} 
    //      Iteration 3: {7, 6, 5, 4, 3, 2, 1, 8, 9} 

    // Loop
    for (int i = 0; i < num/2; i++) {
        temp = arr[i];             // Temp
        arr[i] = arr[num - i - 1]; // Swap
        arr[num - i - 1] = temp;   // Replace Temp
    }
}

// Return true/false (1/0) if a board (array) is sorted
int isSorted(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        if(arr[i] > arr[i+1]) return 0;
    }
    return 1;
    
}