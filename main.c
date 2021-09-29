#include <stdio.h>
#include "CodeTable.h"


int main() {
    CodeTable * test = CTInit();
    for(int i = 0; i<26; i++){
        CTAppend(test,'a'+i,3+i);
    }
    CTQSort(test);
    for(int i = 0; i<26; i++){
        printf("%ld\t", test->pArray[i].weight);
    }
    printf("\n");
    for(int i = 0; i<26; i++){
        printf("%c\t", test->pArray[i].value);
    }
    printf("\n");
    CTFree(test);
    return 0;
}

