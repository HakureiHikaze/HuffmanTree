#include <stdio.h>
#include "BitStream.h"



int main() {
    BitStream * a = BSInit(34359738368);
    for(size_t i = 0; i<34359738368;i++){
        if(i/8%2 == 0){
            BSSetBit(a,1,i);
        }else{
            BSSetBit(a,0,i);
        }
    }
    for(int i = 0; i<512;i++){
        printf("%d", BSGetBit(a,i));
    }
    return 0;
}

