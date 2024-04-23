#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"
#include "compress.c"
#include "getFileSize.c"
#include "decode.c"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
char** encode(TreeNode* root);
int compress(char** encoded, char* fileName);
long int getFileSize(char* filename);
void decode(char *filename, TreeNode* huffmanTree, int validBits);
void TreeToFile(TreeNode *root);
TreeNode *FileToTree(char *fileName);

int main() {
    char *filename = (char*)malloc(sizeof(char));
    printf("Please enter the name of text file (including file extension) to compress:\n");
    scanf("%s", filename);
    MinHeap* frequencyTable = countFrequency(filename);
    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);
    char** encoded = encode(huffmanTree);
    int validBits = compress(encoded, filename);
    int originalSize = getFileSize(filename);
    int compressedSize = getFileSize("compressed.bin");
    printf("Compression ratio: %.2f%%\n", ((float)compressedSize/originalSize)*100);
    decode("compressed.bin", huffmanTree, validBits);
    return 0;
}