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
    teststruct a;
    a.b1 = 0b1;
    a.b2 = 0b11;
    a.b3 = 0b111;
    a.b4 = 0b1111;
    a.b5 = 0b11111;
    a.b6 = 0b111111;
    a.b7 = 0b1111111;
    a.b8 = 0b11111111;
    a.b8 = a.b8<<3;
    return 0;
}

