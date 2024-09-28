#include "parser.c"
#include <stdio.h>

void generateAssembly(const char* output_filename) {
    FILE* file = fopen(output_filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open output file.\n");
        return;
    }
    fprintf(file, "; Assembly code generated from SimpleLang\n");
    // Assembly generation logic
    fclose(file);
    printf("Assembly code written to %s\n", output_filename);
}
