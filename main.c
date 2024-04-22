#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"
#include "compress.c"
#include "decode.c"

#define TOCOMPRESS_FILENAME "Original_text.txt"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
char** encode(TreeNode* root);
void compress(char** encoded, char* fileName);
void decode(char *filename);

int main() {

    MinHeap* frequencyTable = countFrequency(TOCOMPRESS_FILENAME);


    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);

    char** encoded = encode(huffmanTree);
    compress(encoded, TOCOMPRESS_FILENAME);
    decode(".compressed");
    return 0;
}