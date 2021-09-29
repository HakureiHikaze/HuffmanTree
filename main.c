#include <stdio.h>
#include "HuffmanCode.h"


int main() {
    CodeTable * p = Census("Lorem ipsum dolor sit amet, consectetur adipisicing elit,");
    CTQSort(p);
    return 0;
}

