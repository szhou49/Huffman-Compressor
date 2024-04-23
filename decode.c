#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

char *byteToString(unsigned char byte) {
    static char binaryString[9]; 
    for (int i = 7; i >= 0; --i) {
        binaryString[7 - i] = ((byte >> i) & 1) ? '1' : '0';
    }
    
    binaryString[8] = '\0';
    
    return binaryString;
}


void decode(char *filename, TreeNode* huffmanTree, int validBits) {
    FILE* compressedFile;
    FILE* decoded_text;

    compressedFile = fopen(filename, "rb");

    if (compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    decoded_text = fopen("decoded.txt","w");

    fseek(compressedFile, 0, SEEK_END);
    long filelen = ftell(compressedFile); // how many bytes
    rewind(compressedFile);
    unsigned char bytes[filelen];
    fread(bytes, sizeof(bytes), 1, compressedFile);

    char *bits = (char*)malloc(8*filelen*sizeof(char));
    // Convert Bytes to Bits

    int i;

    if (validBits == 0) {
        for (i = 0; i < 8*filelen; ++i) {
            bits[i] = (bytes[i / 8] >> (7 - (i % 8))) & 1;
        }
    } else {
        
        for (i = 0; i < 8*(filelen-1); ++i) {
            bits[i] = (bytes[i / 8] >> (7 - (i % 8))) & 1;
        }
        // Handle the last byte
        for (int k = 0; k < validBits; k++) {
            bits[i] = bytes[filelen-1] >> (7 - (k % 8)) & 1;
            i++;
        }
    }
    if (huffmanTree->val != '\0') {
        fputc(huffmanTree->val, decoded_text);
    } else {
        TreeNode *curr = huffmanTree;
    
        for (int j = 0; j < i; ++j) {
            if (bits[j] == 0) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
            if (curr->left == NULL && curr->right == NULL) {
                fputc(curr->val, decoded_text);
                curr = huffmanTree;
            }
        }
    }
    fclose(decoded_text);
    fclose(compressedFile);
    free(bits); 
}