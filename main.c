#include <stdio.h>


typedef union teststruct_{
    unsigned char b1:1;
    unsigned char b2:2;
    unsigned char b3:3;
    unsigned char b4:4;
    unsigned char b5:5;
    unsigned char b6:6;
    unsigned char b7:7;
    unsigned char b8:8;
}teststruct;

int main() {
    printf_s("%llu", sizeof(teststruct));
    unsigned long test = 1ul;
    teststruct a[4];
    a[0].b8 = 0xff;
    a[1].b8 = 0;
    a[2].b8 = 0xff;
    a[3].b8 = 0;
    for(int i = 0;i<32;i++){
        printf("\ni:%d\tbit:%d\n", i, (*((unsigned char *) (&a) + i / 8)) << (i & 8) != 0);
    }
    return 0;
}

