#include <stdio.h>
#include <stdlib.h>
#include "structure.c"


TreeNode *newTreeNode(char val, int freq); 

void push(MinHeap* minHeap, TreeNode* newNode);
TreeNode* pop(MinHeap* minHeap);



// Build a binary huffman tree
TreeNode* buildHuffmanTree(MinHeap* minHeap) {
    while (minHeap->size > 1) {
        TreeNode* leftNode = minHeap.pop();
        TreeNode* rightNode = minHeap.pop();
        int sum = leftNode->freq + rightNode->freq;
        TreeNode* newNode = newTreeNode(NULL, sum);
        newNode->left = leftNode;
        newNode->right= rightNode;
        push(minHeap, newNode);
    }

    return minHeap.pop();
}

void printHuffmanTree(TreeNode* root) {
    if (root != NULL) {
        printf("%c : %d\n", root->val, root->freq);
        printHuffmanTree(root->left);
        printHuffmanTree(root->right);
    }
}

// Assign Huffman codes to each tree node
void assignBinaryCode(TreeNode* root) {
    TreeNode* current = root;
    while (current != NULL) {
        
    }
}


