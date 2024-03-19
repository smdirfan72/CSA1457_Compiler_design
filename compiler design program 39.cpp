#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

// Structure to store expression and its result
typedef struct {
    char expr[MAX_EXPR_LENGTH];
    char result;
} Expression;

// Function to perform common subexpression elimination
void eliminateCommonSubexpression(Expression expressions[], int numExpressions) {
    int i, j;
    for (i = 0; i < numExpressions; i++) {
        for (j = i + 1; j < numExpressions; j++) {
            // Check if expressions are identical
            if (strcmp(expressions[i].expr, expressions[j].expr) == 0) {
                // Replace expression in later occurrences with result of earlier occurrence
                expressions[j].result = expressions[i].result;
            }
        }
    }
}

int main() {
    // Example expressions
    Expression expressions[] = {
        {"a + b", 'x'},
        {"c * d", 'y'},
        {"a + b", 'x'},  // Duplicate of first expression
        {"c * d", 'y'},  // Duplicate of second expression
        {"a + b", 'x'},  // Duplicate of first expression
        {"e - f", 'z'},
    };

    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    // Perform common subexpression elimination
    eliminateCommonSubexpression(expressions, numExpressions);

    // Print optimized expressions
    printf("Optimized expressions:\n");
    for (int i = 0; i < numExpressions; i++) {
        printf("%s = %c\n", expressions[i].expr, expressions[i].result);
    }

    return 0;
}

