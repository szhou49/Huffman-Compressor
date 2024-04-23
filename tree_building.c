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

// Helper function to print the huffman tree
void printHuffmanTree(TreeNode* root) {
    if (root != NULL) {
        printf("Node frequency: %d\n", root->freq);
        printHuffmanTree(root->left);
        printHuffmanTree(root->right);
    }
}

// Recursive function to assign 0 and 1 to left and right nodes
void dfs(TreeNode* node, char* code, int depth, char** result) {

    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL && depth == 0) {
        code[depth] = '0';
        code[depth+1] = '\0';
        result[node->val] = malloc((depth+1)*sizeof(char));
        strcpy(result[node->val], code);
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        code[depth] = '\0';
        result[node->val] = malloc((depth+1)*sizeof(char));
        if (result[node->val] == NULL) return;
        strcpy(result[node->val], code);
    }

    // assign 0 to the left node
    code[depth] = '0';
    dfs(node->left, code, depth+1, result);

    // assign 1 to the right node
    code[depth] = '1';
    dfs(node->right, code, depth+1, result);

}

// Get the height of the huffman tree
int treeHieght(TreeNode* node) {

    if (node == NULL) return 0;
    
    int leftHeight = treeHieght(node->left);
    int rightHeight = treeHieght(node->right);


    return (leftHeight >  rightHeight ? leftHeight : rightHeight) + 1;
}

// Assign Huffman codes to each tree node
char** encode(TreeNode* root) {
    int height = treeHieght(root);
    char code[height]; 
    char** result = malloc(256*sizeof(char*));
    if (result == NULL) return NULL;
    dfs(root, code, 0, result);

    return result;

}
