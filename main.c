#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

int main() {
    MinHeap* frequencyTable = countFrequency("Original_text.txt");
    print(frequencyTable);
    getchar();
    return 0;
}