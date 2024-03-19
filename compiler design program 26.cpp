#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_CONSTANT_LENGTH 20

// Function to check if a character is a valid operator (+, -, *, /)
bool isValidOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if a character is a valid identifier character (alphabet or underscore)
bool isValidIdentifierChar(char c) {
    return (isalpha(c) || c == '_');
}

// Function to check if a character is a valid digit
bool isValidDigit(char c) {
    return isdigit(c);
}

// Function to check if a string is a valid constant
bool isValidConstant(char *str) {
    int len = strlen(str);
    if (len == 0)
        return false;

    for (int i = 0; i < len; i++) {
        if (!isValidDigit(str[i]))
            return false;
    }
    return true;
}

// Function to analyze the input text and identify identifiers, constants, and operators
void analyze(char *text) {
    char identifier[MAX_IDENTIFIER_LENGTH + 1]; // +1 for null terminator
    char constant[MAX_CONSTANT_LENGTH + 1]; // +1 for null terminator
    int identifier_index = 0;
    int constant_index = 0;

    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '/' && text[i+1] == '/') { // Single-line comment
            while (text[i] != '\n' && text[i] != '\0') {
                i++;
            }
        }
        else if (text[i] == '/' && text[i+1] == '*') { // Multi-line comment
            i += 2; // Skip /*
            while (!(text[i] == '*' && text[i+1] == '/')) {
                i++;
            }
            i += 2; // Skip */
        }
        else if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') { // Skip whitespace
            i++;
        }
        else if (isValidOperator(text[i])) { // Operator
            printf("Operator: %c\n", text[i]);
            i++;
        }
        else if (isValidIdentifierChar(text[i])) { // Identifier
            identifier_index = 0;
            while (isValidIdentifierChar(text[i]) && identifier_index < MAX_IDENTIFIER_LENGTH) {
                identifier[identifier_index++] = text[i++];
            }
            identifier[identifier_index] = '\0';
            printf("Identifier: %s\n", identifier);
        }
        else if (isValidDigit(text[i])) { // Constant
            constant_index = 0;
            while (isValidDigit(text[i]) && constant_index < MAX_CONSTANT_LENGTH) {
                constant[constant_index++] = text[i++];
            }
            constant[constant_index] = '\0';
            printf("Constant: %s\n", constant);
        }
        else { // Invalid character
            printf("Invalid character: %c\n", text[i]);
            i++;
        }
    }
}

int main() {
    char text[] = "int main() {\n    int a = 5;\n    int b = 7;\n    int sum = a + b;\n    // This is a comment\n    /* This is a multi-line\n       comment */\n    return 0;\n}";

    analyze(text);

    return 0;
}

