#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
bool expression(char **);
bool term(char **);
bool factor(char **);
bool consume(char **, char);
bool is_number(char);

// Function to check if a character is a number
bool is_number(char c) {
    return isdigit(c);
}

// Function to consume the next character in the input
bool consume(char **input, char expected) {
    if (**input == expected) {
        (*input)++;
        return true;
    }
    return false;
}

// Function to parse an expression
bool expression(char **input) {
    if (term(input)) {
        while (**input == '+' || **input == '-') {
            if (!consume(input, '+') && !consume(input, '-'))
                return false;
            if (!term(input))
                return false;
        }
        return true;
    }
    return false;
}

// Function to parse a term
bool term(char **input) {
    if (factor(input)) {
        while (**input == '*' || **input == '/') {
            if (!consume(input, '*') && !consume(input, '/'))
                return false;
            if (!factor(input))
                return false;
        }
        return true;
    }
    return false;
}

// Function to parse a factor
bool factor(char **input) {
    if (is_number(**input)) {
        (*input)++;
        return true;
    } else if (consume(input, '(')) {
        if (!expression(input))
            return false;
        if (!consume(input, ')'))
            return false;
        return true;
    }
    return false;
}

int main() {
    // Input string
    char input[] = "2+3*(4-5)";

    // Check if the input string conforms to the grammar
    if (expression(&input) && *input == '\0')
        printf("The input string satisfies the grammar.\n");
    else
        printf("The input string does not satisfy the grammar.\n");

    return 0;
}

