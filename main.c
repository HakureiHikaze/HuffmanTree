#include <stdio.h>
#include "BitStream.h"
#include "CodeTable.h"


int main() {
    CodeTable * test = CTInit();
    for(int i = 0; i<512; i++){
        CTAppend(test,'a',16+i,3);
    }
    return 0;
}

