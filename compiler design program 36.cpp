#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluateExpression(char *expression) {
    int result = 0,power;
    int num1, num2;
    char op;

    sscanf(expression, "%d %c %d", &num1, &op, &num2);
    switch (op) {
        case '^':
            result = power(num1, num2); 
            break;
        case '*':
            result = num1 * num2; 
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2; 
            else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            break;
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2; 
            break;
        default:
            printf("Error: Invalid operator\n");
            exit(EXIT_FAILURE);
    }
    return result;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    char expression[100];

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}

