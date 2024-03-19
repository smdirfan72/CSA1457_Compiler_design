#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isLineComment(char *line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '/' && line[i+1] == '/') {
            return true;
        }
        i++;
    }
    return false;
}

bool isBlockComment(char *line) {
    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '/' && line[i+1] == '*') {
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    char line1[] = "// This is a line comment";
    char line2[] = "/* This is a block comment */";
    char line3[] = "int main() {";
    
    printf("Line 1 is a comment: %s\n", isLineComment(line1) ? "true" : "false");
    printf("Line 2 is a comment: %s\n", isLineComment(line2) ? "true" : "false");
    printf("Line 3 is a comment: %s\n", isLineComment(line3) ? "true" : "false");
    
    printf("Line 1 is a block comment: %s\n", isBlockComment(line1) ? "true" : "false");
    printf("Line 2 is a block comment: %s\n", isBlockComment(line2) ? "true" : "false");
    printf("Line 3 is a block comment: %s\n", isBlockComment(line3) ? "true" : "false");
    
    return 0;
}

