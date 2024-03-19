#include <stdio.h>
#include <string.h>

#define MAX_PROD 10
#define MAX_LEN 10

int main() {
    char productions[MAX_PROD][MAX_LEN];
    int num_prod, i;

    printf("Enter the number of productions: ");
    scanf("%d", &num_prod);

    printf("Enter the productions:\n");
    for (i = 0; i < num_prod; ++i) {
        scanf("%s", productions[i]);
    }

    // Eliminate left recursion
    for (i = 0; i < num_prod; ++i) {
        char non_terminal = productions[i][0];
        int j;
        for (j = 0; j < i; ++j) {
            if (productions[j][0] == non_terminal) {
                int k;
                for (k = 0; productions[i][k] == productions[j][k]; ++k) {}
                if (productions[i][k] == '\0') {
                    char new_non_terminal = non_terminal + 1;
                    printf("%c -> %s%c'\n", new_non_terminal, &productions[i][k], new_non_terminal);
                    printf("%c' -> %s%c' | epsilon\n", non_terminal, &productions[j][k], new_non_terminal);
                    productions[i][0] = new_non_terminal;
                }
            }
        }
    }

    // Output the modified productions
    printf("Productions after left recursion elimination:\n");
    for (i = 0; i < num_prod; ++i) {
        printf("%s\n", productions[i]);
    }

    return 0;
}

