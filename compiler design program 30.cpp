#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidIdentifier(char *identifier) {
    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_')
        return false;

    // Check the rest of the characters
    for (int i = 1; identifier[i] != '\0'; ++i) {
        if (!isalnum(identifier[i]) && identifier[i] != '_')
            return false;
    }

    return true;
}

int yylex() {
    char identifier[100];
    scanf("%s", identifier);

    if (isValidIdentifier(identifier))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}

