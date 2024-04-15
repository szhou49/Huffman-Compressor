#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct TreeNode_Struct {
    char val;                         // The unqiue character of the tree node.
    int freq;                         // The frequency of appearence of the character.
    struct TreeNode_Struct *left;     // Left child of the tree node.
    struct TreeNode_Struct *right;    // Right child of the tree node.
} TreeNode;

typedef struct MinHeap_Struct {
    TreeNode **array;
    int size;
} MinHeap;

//Initialize a new TreeNode.
TreeNode *newTreeNode(char val, int freq); 

//Initialize a new MinHeap composed of TreeNode.
MinHeap *newMinHeap();

//Swap two TreeNodes in MinHeap/
void swap(TreeNode **a, TreeNode **b);

//Locate the index of the parent of an index in array.
int parent(int val);

//Locate the index of the left child of an index in array.
int leftChild(int val);

//Locate the index of the right child of an index in array.
int rightChild(int val);

// Proclate element at index n down.
void proclateDown(MinHeap *minHeap, int val);

//Push new TreeNode into the MinHeap.
void push(MinHeap *minHeap, TreeNode *newNode);

//Pop the top TreeNode of the MinHeap out.
TreeNode *pop(MinHeap *minHeap);

//Return the top TreeNode of the MinHeap.
TreeNode *top(MinHeap *minHeap);

//Print each TreeNode of the MinHeap.
void print(MinHeap *minHeap);

//Create a frequency table of characters from a text.
MinHeap* countFrequency(char* fileName);
#endif
