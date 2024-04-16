#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

// Build a binary huffman tree
TreeNode* buildHuffmanTree(MinHeap* minHeap) {
    while (minHeap->size > 1) {
        TreeNode* leftNode = pop(minHeap);
        TreeNode* rightNode = pop(minHeap);
        int sum = leftNode->freq + rightNode->freq;
        TreeNode* newNode = newTreeNode('\0', sum);
        newNode->left = leftNode;
        newNode->right= rightNode;
        push(minHeap, newNode);
    }

    return pop(minHeap);
}

void printHuffmanTree(TreeNode* root) {
    if (root != NULL) {
        printf("%c : %d\n", root->val, root->freq);
        printHuffmanTree(root->left);
        printHuffmanTree(root->right);
    }
}

// Assign Huffman codes to each tree node
// void assignBinaryCode(TreeNode* root) {
//     if (root == '\0')

// }


