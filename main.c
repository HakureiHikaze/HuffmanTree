#include <stdio.h>
#include "BitStream.h"



int main() {
    BitStream * a = BSInit(1024);
    BSSetByte(a,0b00000101,0,3);
    BSSetByte(a,0b10110111,3,8);
    printf("%lu\n", BSReadByte(a,0,4));
    for(int i = 0; i<16;i++){
        printf("%d", BSGetBit(a,i));
    }
    BSFree(a);
    return 0;
}

