#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate target code from intermediate representation (IR)
void generateTargetCode(char *ir_filename, char *target_filename) {
    FILE *ir_file = fopen(ir_filename, "r");
    if (ir_file == NULL) {
        printf("Error: Failed to open intermediate representation file.\n");
        return;
    }

    FILE *target_file = fopen(target_filename, "w");
    if (target_file == NULL) {
        printf("Error: Failed to create target code file.\n");
        fclose(ir_file);
        return;
    }

    // Read each line of the IR and generate corresponding target code
    char line[100];
    while (fgets(line, sizeof(line), ir_file)) {
        // Example: Assume IR is in the format "ADD R1, R2, R3"
        // Generate corresponding target code (e.g., machine code or assembly)
        fprintf(target_file, "Machine code/Assembly: %s", line);
    }

    printf("Target code generated successfully.\n");

    // Close files
    fclose(ir_file);
    fclose(target_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IR_file> <target_file>\n", argv[0]);
        return 1;
    }

    char *ir_filename = argv[1];
    char *target_filename = argv[2];

    // Generate target code from intermediate representation
    generateTargetCode(ir_filename, target_filename);

    return 0;
}

