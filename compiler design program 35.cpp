#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *input;
int pos;

int expression();
int term();
int factor();
void error();

void consume(char expected) {
    if (*input == expected)
        input++, pos++;
    else
        error();
}
void error() {
    fprintf(stderr, "Syntax error at position %d\n", pos);
    exit(EXIT_FAILURE);
}

int expression() {
    int result = term();
    while (*input == '+' || *input == '-') {
        char op = *input;
        consume(op);
        int value = term();
        if (op == '+')
            result += value;
        else
            result -= value;
    }
    return result;
}

int term() {
    int result = factor();
    while (*input == '*' || *input == '/') {
        char op = *input;
        consume(op);
        int value = factor();
        if (op == '*')
            result *= value;
        else
            result /= value;
    }
    return result;
}

int factor() {
    int result;
    if (isdigit(*input)) {
        result = *input - '0';
        consume(*input);
    } else if (*input == '(') {
        consume('(');
        result = expression();
        consume(')');
    } else
        error();
    return result;
}

int main() {
    input = "(2+3)*4-6/2";
    pos = 0;

    int result = expression();
    printf("Result: %d\n", result);

    return 0;
}

