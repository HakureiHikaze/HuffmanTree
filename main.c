#include <stdio.h>
#include "HuffmanCode.h"


int main() {
    BitStream * test = HCEncode("Lorem ipsum dolor sit amet, consectetur adipisicing elit,");
    for(int i = 0; i<512;i++){
        printf("%d", BSGetBit(test,i));
    }
    BSFree(test);
    return 0;
}

