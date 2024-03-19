#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given string is a single-line comment (//)
bool isSingleLineComment(char *str) {
    return (strlen(str) >= 2 && str[0] == '/' && str[1] == '/');
}

// Function to check if a given string is the start of a multi-line comment (/*)
bool isMultiLineCommentStart(char *str) {
    return (strlen(str) >= 2 && str[0] == '/' && str[1] == '*');
}

// Function to check if a given string is the end of a multi-line comment (*/)
bool isMultiLineCommentEnd(char *str) {
    return (strlen(str) >= 2 && str[0] == '*' && str[1] == '/');
}

int main() {
    char line[100];
    
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    if (isSingleLineComment(line)) {
        printf("This is a single-line comment.\n");
    } else if (isMultiLineCommentStart(line)) {
        printf("This is the start of a multi-line comment.\n");
    } else if (isMultiLineCommentEnd(line)) {
        printf("This is the end of a multi-line comment.\n");
    } else {
        printf("This is not a comment.\n");
    }

    return 0;
}

