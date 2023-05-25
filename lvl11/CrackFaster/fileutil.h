// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFile(char *filename, int *size);

// Free the memory used by the array
void freeAA(char ** arr, int size);

// String comparison for qsort
int alphabetic(const void *a, const void *b);

// String comparison for bsearch
int strsearch(const void *key, const void *elem);