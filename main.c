#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"
#include "compress.c"

#define FILENAME "sample-2mb-text-file.txt"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
char** encode(TreeNode* root);
// void printCodes(char** encoded);
void compress(char** encoded, char* fileName);


int main() {

    MinHeap* frequencyTable = countFrequency(FILENAME);


    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);

    char** encoded = encode(huffmanTree);
    compress(encoded, FILENAME);

    // printCodes(encoded);



    return 0;
}