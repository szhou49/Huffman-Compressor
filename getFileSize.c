#include <stdio.h>
#include <stdlib.h>

long int getFileSize(char* filename) {
    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    long int size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    fclose(file);
    return size;
}

