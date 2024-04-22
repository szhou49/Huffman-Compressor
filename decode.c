#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void decode(char *filename, TreeNode* huffmanTree, int validBits) {
    printf("Last byte valid bits: %d\n", validBits);
    FILE* compressedFile;
    FILE* decoded_text;

    compressedFile = fopen(filename, "rb");

    if (compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    decoded_text = fopen("decoded_text.txt" ,"w");

    fseek(compressedFile, 0, SEEK_END);
    long filelen = ftell(compressedFile); // how many bytes
    // printf("%d", filelen);
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
        for (int k = 0; k < validBits; ++k) {
            bits[i++] = bytes[filelen-1] >> (7 - (k % 8)) & 1;
        }
    }
    
    bits[i] = '\0'; // Add null terminator
    // printf("%d\n", i);
    // printf("%d\n", 8*(filelen-1)+validBits);

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

    fclose(decoded_text);
    fclose(compressedFile);
    printf("Uncompression finished");
}
