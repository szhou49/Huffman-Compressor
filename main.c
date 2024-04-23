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
int compress(char** encoded, char* fileName, char* compressed);
long int getFileSize(char* filename);
void decode(char *filename, TreeNode* huffmanTree, int validBits);
void TreeToFile(TreeNode *root);
TreeNode *FileToTree(char *fileName);

int main() {
    char *filename = (char*)malloc(sizeof(char));
    char *compressed = (char*)malloc(sizeof(char));
    char *decoded = (char*)malloc(sizeof(char));

    printf("Please enter the path of text file to compress.\n");
    scanf("%s", filename);
    printf("Please enter the name of compressed file.\n");
    scanf("%s", compressed);
    MinHeap* frequencyTable = countFrequency(filename); 
    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);
    char** encoded = encode(huffmanTree);
    int validBits = compress(encoded, filename, compressed);
    printf("Compression ratio: %.2f%%\n", ((float)getFileSize(compressed)/getFileSize(filename))*100);
    decode(compressed, huffmanTree, 1);
    return 0;
}