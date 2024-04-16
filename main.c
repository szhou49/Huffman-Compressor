#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);
void encode(TreeNode* root);

int main() {

    MinHeap* frequencyTable = countFrequency("Original_text.txt");


    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);


    encode(huffmanTree);


    return 0;
}