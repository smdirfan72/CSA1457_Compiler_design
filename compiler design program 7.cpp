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

    // Perform left factoring
    for (i = 0; i < num_prod; ++i) {
        int j, k, len = strlen(productions[i]);
        for (j = 0; j < num_prod; ++j) {
            if (i != j && productions[i][0] == productions[j][0]) {
                for (k = 0; k < len; ++k) {
                    if (productions[i][k] != productions[j][k]) {
                        break;
                    }
                }
                if (k > 0) {
                    char new_non_terminal = productions[i][0] + 1;
                    printf("%c' -> %s\n", new_non_terminal, &productions[i][k]);
                    printf("%s -> %c%c'\n", productions[i], productions[i][0], new_non_terminal);
                    printf("%s -> %c%c'\n", productions[j], productions[j][0], new_non_terminal);
                    return 0;
                }
            }
        }
    }

    printf("No left factoring required.\n");

    return 0;
}

