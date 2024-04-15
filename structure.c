#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

TreeNode *newTreeNode(char val, int freq) {
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root -> val = val;
    root -> freq = freq;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

MinHeap *newMinHeap() {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap -> array = (TreeNode**)malloc(sizeof(TreeNode*));
    minHeap -> size = 0;
    return minHeap;
}

void swap(TreeNode **a, TreeNode **b) {
    TreeNode *temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int val) {
    return (val - 1) / 2;
}

int leftChild(int val) {
    return 2 * val + 1;
}

int rightChild(int val) {
    return 2 * val + 2;
}

void push(MinHeap* minHeap, TreeNode* newNode) {
    minHeap->array[minHeap->size] = newNode;
    minHeap->size++;
    // heapify(minHeap, minHeap->size);
}