#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"
#include "compress.c"
#include "getFileSize.c"


#define TOCOMPRESS_FILENAME "Original_text.txt"
#define COMPRESSED_FILENAME ".compressed"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
char** encode(TreeNode* root);
void compress(char** encoded, char* fileName);
long int getFileSize(char* filename);


int main() {

    MinHeap* frequencyTable = countFrequency(TOCOMPRESS_FILENAME);


    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);

    char** encoded = encode(huffmanTree);
    compress(encoded, TOCOMPRESS_FILENAME);

    int originalSize = getFileSize(TOCOMPRESS_FILENAME);
    int compressedSize = getFileSize(COMPRESSED_FILENAME);

    printf("Compression ratio: %.2f%%\n", ((float)compressedSize/originalSize)*100);


    

    return 0;
}