#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"
#include "compress.c"
#include "getFileSize.c"
#include "decode.c"


#define TOCOMPRESS_FILENAME "Original_text.txt"
#define COMPRESSED_FILENAME ".compressed"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
char** encode(TreeNode* root);
int compress(char** encoded, char* fileName);
long int getFileSize(char* filename);
void decode(char *filename, TreeNode* huffmanTree, int validBits);


int main() {

    MinHeap* frequencyTable = countFrequency(TOCOMPRESS_FILENAME);


    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);

    char** encoded = encode(huffmanTree);
    int validBits = compress(encoded, TOCOMPRESS_FILENAME);

    int originalSize = getFileSize(TOCOMPRESS_FILENAME);
    int compressedSize = getFileSize(COMPRESSED_FILENAME);

    printf("Compression ratio: %.2f%%\n", ((float)compressedSize/originalSize)*100);

    decode(COMPRESSED_FILENAME, huffmanTree, validBits);

    return 0;
}