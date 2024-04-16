#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#define ASCII_MAX 256
#define BUFFER_SIZE 4096

MinHeap* countFrequency(char* fileName) {
    printf("----");
    
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
        
    }
    fclose(result);

    MinHeap* minheap = newMinHeap();

    int index = 0;
    // Add the char-freq pair into the list
    for (int i = 0; i < ASCII_MAX; i++) {
        if (occurrences[i] > 0) {
            TreeNode* newNode = newTreeNode(i, occurrences[i]);
            push(minheap, newNode);
        }
    }

    return minheap;
}
