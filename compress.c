#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILENAME ".compressed"
int byteCnt = 0;

char *byteToBinaryString(unsigned char byte) {
    static char binaryString[9]; 
    for (int i = 7; i >= 0; --i) {
        binaryString[7 - i] = ((byte >> i) & 1) ? '1' : '0';
    }
    
    binaryString[8] = '\0';
    
    return binaryString;
}

int compress(char** encoded, char* fileName) {
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
    

   while(fread(&temporaryChar, sizeof(unsigned char), 1, originalFile) == 1) {
        // Write the encoded bitstring into buffer
        strcat(codeBuffer, encoded[temporaryChar]);

        // If the buffer size exceed 8,write the 8 bits as a byte into the file
        while (strlen(codeBuffer) >= 8) {
            unsigned char byte = 0;
            for (int i = 0; i < 8; i++) {
                byte <<= 1;
                if (codeBuffer[i] == '1') byte |= 1;
            }
            fwrite((char*)&byte, sizeof(unsigned char), 1, compressedFile);
            byteCnt++;
            strcpy(codeBuffer, codeBuffer+8);
        }
    }
    fclose(originalFile);

    // If there are left bits that are not enough to be converted to a byte
    int validBits = strlen(codeBuffer); 
    if (validBits > 0) {
        unsigned char byte = 0;
        for (int i = 0; i < validBits; i++) {
            byte <<= 1;
            if (codeBuffer[i] == '1') {
                byte |= 1;
            }
        }

        byte <<= (8 - validBits);
        char* str = byteToBinaryString(byte);
        // printf("Compress last byte: %s\n", str);
        fwrite((char *)&byte, sizeof(unsigned char), 1, compressedFile);
        byteCnt++;
    }

    fclose(compressedFile);
    printf("Compression finished\n");
    // printf("Compress bytes: %d\n", byteCnt);
    return validBits;
}



