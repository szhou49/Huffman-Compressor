#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILENAME "Compressed_text.txt"

void compress(char** encoded, char* fileName) {
    FILE* originalFile;
    FILE* compressedFile;
    char ch;

    originalFile = fopen(fileName, "rb");
    
    compressedFile = fopen(OUTPUT_FILENAME, "wb");

    if (originalFile == NULL || compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    while (ch = fgetc(originalFile)) {
        if (ch == EOF) break;
        fputs(encoded[(unsigned char)ch], compressedFile);
    }

    

    fclose(originalFile);
    fclose(compressedFile);


}

