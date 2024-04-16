#include <stdio.h>
#include <stdlib.h>
#include "frequency.c"
#include "tree_building.c"

MinHeap* countFrequency(char* filename);
TreeNode* buildHuffmanTree(MinHeap* minHeap);
void printHuffmanTree(TreeNode* root);

int main() {

    MinHeap* frequencyTable = countFrequency("Original_text.txt");

    TreeNode* huffmanTree = buildHuffmanTree(frequencyTable);

    printHuffmanTree(huffmanTree);


    return 0;
}