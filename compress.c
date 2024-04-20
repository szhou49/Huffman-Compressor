#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILENAME ".compressed"

void compress(char** encoded, char* fileName) {
    FILE* originalFile;
    FILE* compressedFile;
    char ch;

    originalFile = fopen(fileName, "r");
    
    compressedFile = fopen(OUTPUT_FILENAME, "wb");

    if (originalFile == NULL || compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    unsigned char temporaryChar;
    char codeBuffer[256] = "";
    

    while (!feof(originalFile)) {
        fread((char*)&temporaryChar, sizeof(unsigned char), 1, originalFile);
        if (temporaryChar == '\n') continue;
        // printf("Read character: %c\n", temporaryChar);
        // Write the encoded bitstring into buffer
        strcat(codeBuffer, encoded[temporaryChar]);

        // If the buffer size exceed 8,write the 8 bits as a byte into the file
        while (strlen(codeBuffer) >= 8) {
            unsigned char byte = '\0';
            for (int i = 0; i < 8; i++) {
                byte <<= 1;
                if (codeBuffer[i] == '1') byte |= 1;
            }
            fwrite((char*)&byte, sizeof(unsigned char), 1, compressedFile);
            strcpy(codeBuffer, codeBuffer+8);
        }
    }
    

    fclose(originalFile);

    // If there are left bits that are not enough to be converted to a byte
    if (strlen(codeBuffer) > 0) {
        unsigned char byte = 0;
        for (int i = 0; i < strlen(codeBuffer); i++) {
            byte <<= 1;
            if (codeBuffer[i] == '1') {
                byte |= 1;
            }
        }

        byte <<= (8 - strlen(codeBuffer));
        fwrite((char *)&byte, sizeof(unsigned char), 1, compressedFile);
    }

    

    fclose(compressedFile);
    printf("Compression finished");
}



