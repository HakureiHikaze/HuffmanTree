#include <stdio.h>
#include "HuffmanTree.h"

int main() {
    long a[5][2];
    for(int i = 0; i<5; i++){
        a[i][0] = i;
        a[i][1] = 'A'+i;
    }
    HuffmanTree test = ConstructHT(a,5);
    return 0;
}
