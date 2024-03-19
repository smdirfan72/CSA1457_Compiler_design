#include <stdio.h>

int main() {
    char text[] = "This is an example text.\nIt has multiple lines.\nWith different whitespace characters like spaces\t and tabs.\n";
    int whitespace_count = 0;
    int newline_count = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\t') {
            whitespace_count++;
        } else if (text[i] == '\n') {
            whitespace_count++; // Newline is also considered a whitespace
            newline_count++;
        }
    }

    printf("Number of whitespaces: %d\n", whitespace_count);
    printf("Number of newlines: %d\n", newline_count);

    return 0;
}

