#include <stdio.h>
#include "HuffmanTree.h"

int main() {
    long data[5][2];
    for(int i = 1; i<6; i++){
        data[i-1][0] = i;
        data[i-1][1] = 'a'+i;
    }
    HuffmanTree test = ConstructHT(data, 5);
    return 0;
}

