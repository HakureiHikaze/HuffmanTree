#include <stdio.h>
#include "BitStream.h"
#include "CodeTable.h"


int main() {
    CodeTable * test = CTInit();
    for(int i = 0; i<256; i++){
        CTAppend(test,'a',3+i,3);
    }
    CTQSort(test);
    for(int i = 0; i<256; i++){
        printf("%ld ", test->pArray[i].weight);
    }
    return 0;
}

