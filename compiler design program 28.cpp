#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if a character is a valid operator (+, -, *, /)
bool isValidOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char expression[100];
    
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    int i = 0;
    while (expression[i] != '\0') {
        // Check if the current character is a valid operator
        if (isValidOperator(expression[i])) {
            printf("%c is a valid operator.\n", expression[i]);
        }
        i++;
    }

    return 0;
}

