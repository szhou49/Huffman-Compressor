#include <stdio.h>
#include <stdlib.h>

void decode(char *filename) {

    FILE* compressedFile;
    FILE* decoded_text;
    unsigned char buffer = '\0';

    compressedFile = fopen(filename, "rb");

    if (compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    decoded_text = fopen("decoded_text.txt" ,"a");

    while (!feof(compressedFile)) {
        fread((char*)&buffer, sizeof(unsigned char), 1, compressedFile);
        fputc(buffer, decoded_text);
    }
    fclose(decoded_text);
    fclose(compressedFile);
}