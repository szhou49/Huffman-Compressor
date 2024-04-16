#include <stdio.h>
#include <stdlib.h>
#include "structure.c"
#include "frequency.c"

MinHeap* countFrequency(char* filename);

TreeNode *newTreeNode(char val, int freq); 

MinHeap *newMinHeap();

void push(MinHeap* minHeap, TreeNode* newNode);

int main() {

    MinHeap* frequencyTable = countFrequency("Original_text.txt");

    for (int i = 0; i < frequencyTable->size; i++) {
        printf("%c : %d\n", frequencyTable->array[i]->val, frequencyTable->array[i]->freq);
    }

    return 0;
}