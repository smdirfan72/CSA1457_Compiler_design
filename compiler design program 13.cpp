#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0; // Flag to indicate if currently in a word

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("File does not exist or cannot be opened.\n");
        exit(EXIT_FAILURE);
    }

    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Increment character count
        charCount++;

        // Check for newline character
        if (ch == '\n') {
            lineCount++;
        }

        // Check for word boundaries
        if (isspace(ch)) {
            inWord = 0; // Not in a word
        } else if (!inWord) {
            inWord = 1; // Start of a new word
            wordCount++;
        }
    }

    // Close file
    fclose(file);

    // Output counts
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

