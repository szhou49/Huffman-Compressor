#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "structure.c"

int main() {
    MinHeap* frequencyTable = countFrequency("Original_text.txt");
    print(frequencyTable);
    return 0;
}