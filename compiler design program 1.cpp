#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 10

typedef enum {
    IDENTIFIER,
    CONSTANT,
    OPERATOR
} TokenType;

void analyze(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        // Ignore whitespace characters
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Ignore comments
        if (input[i] == '/' && input[i+1] == '/') {
            while (input[i] != '\n')
                i++;
            continue;
        }

        // Check for identifiers
        if (isalpha(input[i])) {
            char identifier[MAX_IDENTIFIER_LENGTH + 1];
            int j = 0;
            while (isalnum(input[i]) && j < MAX_IDENTIFIER_LENGTH) {
                identifier[j++] = input[i++];
            }
            identifier[j] = '\0';
            printf("Identifier: %s\n", identifier);
            continue;
        }

        // Check for constants
        if (isdigit(input[i])) {
            char constant[MAX_CONSTANT_LENGTH + 1];
            int j = 0;
            while (isdigit(input[i]) && j < MAX_CONSTANT_LENGTH) {
                constant[j++] = input[i++];
            }
            constant[j] = '\0';
            printf("Constant: %s\n", constant);
            continue;
        }

        // Check for operators
        if (ispunct(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        // If not any of the above, move to the next character
        i++;
    }
}

int main() {
    char input[] = "int main() {\n    // This is a comment\n    int x = 10;\n    float y = 3.14;\n    return 0;\n}";
    analyze(input);
    return 0;
}

