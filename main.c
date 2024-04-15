#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main() {
    TreeNode *root = newTreeNode('A', 1);
    printf("%d", root -> freq);
    getchar();
    return 0;
}