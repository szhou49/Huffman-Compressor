#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

extern TreeNode *newTreeNode(char val, int freq) {
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

void proclateDown(MinHeap *minHeap, int val) {
    int left = leftChild(val);
    int right = rightChild(val);
    int index = val;
    if (left < minHeap -> size & (minHeap -> array[left] -> freq) < (minHeap -> array[val] -> freq)) {
        index = left;
    }
    if (right < minHeap -> size & (minHeap -> array[right] -> freq) < (minHeap -> array[index] -> freq)) {
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
    while (index > 0 & (minHeap -> array[parent(index)] -> freq) > (minHeap -> array[index] -> freq)) {
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

void print(MinHeap *minHeap) {
    for (int i = 0; i < minHeap -> size; ++i) {
        printf("%c: %d\n", minHeap -> array[i] -> val, minHeap -> array[i] -> freq);
    }
}

#define ASCII_MAX 256
#define BUFFER_SIZE 4096

MinHeap* countFrequency(char* fileName) {
    FILE* file;
    char ch;

    // Opening file in reading mode
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File cannot be opened \n");
        exit(EXIT_FAILURE);
    }

    // Count the occurrence of each character
    int occurrences[ASCII_MAX] = {0};
    do {
        ch = fgetc(file);
        occurrences[ch]++;
    } while (ch != EOF); 


    // Close the file
    fclose(file);


    // Create a new file
    FILE* result;
    result = fopen("Character_frequency.txt", "w");

    char buffer[BUFFER_SIZE] = {0};

    // Write the result to the file
    for (int i = 0; i < ASCII_MAX; i++) {
        if (occurrences[i] > 0) {
            snprintf(buffer, sizeof(buffer), "\n%c : %d", i, occurrences[i]);
        }
        int status = fputs(buffer, result);
        if (status == EOF) {
            printf("Reaching the end of the file");
            exit(EXIT_FAILURE);
        }
        memset(buffer, '\0', sizeof(buffer));
    }
    fclose(result);

    MinHeap* minheap = newMinHeap();

    int index = 0;
    // Add the char-freq pair into the list
    for (int i = 0; i < ASCII_MAX; i++) {
        if (occurrences[i] > 0) {
            char c = i;
            TreeNode* newNode = newTreeNode(c, occurrences[i]);
            push(minheap, newNode);
        }
    }
    return minheap;
}