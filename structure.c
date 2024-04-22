#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

TreeNode *newTreeNode(char val, int freq) {
    TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
    root -> val = val;
    root -> freq = freq;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

MinHeap *newMinHeap(int arraySize) {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap -> array = (TreeNode**)malloc(arraySize*sizeof(TreeNode*));
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

void proclateDown(MinHeap *minHeap, int val) {
    
    int left = leftChild(val);
    int right = rightChild(val);
    int index = val;
    
    if (left < minHeap -> size && (minHeap -> array[left] -> freq) < (minHeap -> array[val] -> freq)) {
        index = left;
    }
    if (right < minHeap -> size && (minHeap -> array[right] -> freq) < (minHeap -> array[index] -> freq)) {
        index = right;
    }
    
    if (index != val) {
        swap(&(minHeap -> array[val]), &(minHeap -> array[index]));
        proclateDown(minHeap, index);
    }
}

void push(MinHeap *minHeap, TreeNode *newNode) {
    int index = minHeap -> size;
    minHeap -> array[index] = newNode;
    minHeap -> size++;
    while (index > 0 && (minHeap -> array[parent(index)] -> freq) > (minHeap -> array[index] -> freq)) {
        swap(&(minHeap -> array[index]), &(minHeap -> array[parent(index)]));
        index = parent(index);
    }
}

TreeNode *pop(MinHeap *minHeap) {
    if (minHeap -> size == 0) {
        printf("The MinHeap is empty.");
        return NULL;
    }
    
    TreeNode *res = minHeap -> array[0];
    minHeap -> array[0] = minHeap -> array[minHeap -> size - 1];
    // minHeap->array[minHeap -> size - 1] = NULL;
    minHeap -> size--;
    
    proclateDown(minHeap, 0);

    return res;
}

TreeNode *top(MinHeap *minHeap) {
    if (minHeap -> size == 0) {
        printf("The MinHeap is empty.");
        return NULL;
    }
    return minHeap -> array[0];
}
