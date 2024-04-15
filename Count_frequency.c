#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_MAX 256
#define BUFFER_SIZE 4096

int readInput(char* fileName) {
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

    // Used to count the total number of character kinds
    int charSize = 0;

    // Write the result to the file
    for (int i = 0; i < ASCII_MAX; i++) {
        if (occurrences[i] > 0) {
            printf("\n%c : %d", i, occurrences[i]);
            snprintf(buffer, sizeof(buffer), "\n%c : %d", i, occurrences[i]);
            charSize++;
        }
        int status = fputs(buffer, result);
        if (status == EOF) {
            printf("Reaching the end of the file");
            return charSize;
        }
        memset(buffer, '\0', sizeof(buffer));
    }

    fclose(result);

    return charSize;

}

int main(void) {
    
    int nodeNumber = readInput("Original_text.txt");
    return 0;
}