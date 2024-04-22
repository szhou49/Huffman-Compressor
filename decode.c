#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void decode(char *filename, TreeNode* huffmanTree) {
    FILE* compressedFile;
    FILE* decoded_text;

    compressedFile = fopen(filename, "rb");

    if (compressedFile == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    decoded_text = fopen("decoded_text.txt" ,"a");

    fseek(compressedFile, 0, SEEK_END);
    long filelen = ftell(compressedFile);
    rewind(compressedFile);

    unsigned char bytes[filelen];
    char *bits = (char*)malloc(8*filelen*sizeof(char));
    fread(bytes, sizeof(bytes), 1, compressedFile);

    //Convert Bytes to Bits/
    for (int i = 0; i < 8*filelen; ++i) {
        bits[i] = ((1 << (i % 8)) & (bytes[i/8]));
    }
    TreeNode *curr = huffmanTree;
    for (int j = 0; j < 8*filelen; ++j) {
        if (bits[j] == 0) {
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
        if (curr -> left == NULL && curr -> right == NULL) {
            fputc(curr -> val, decoded_text);
            curr = huffmanTree;
        }
    }
    fclose(decoded_text);
    fclose(compressedFile);
}