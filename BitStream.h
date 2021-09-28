//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#pragma once
#include <stdlib.h>

typedef struct BitStream_{
    unsigned char* pBinary;
    size_t size;
}BitStream;

extern BitStream* BSInit(size_t size);
extern void BSSetBit(BitStream*,unsigned char, size_t);
extern unsigned char BSGetBit(BitStream*, size_t);
extern void BSFree(BitStream*);

extern void BSSetByte(BitStream*,unsigned char data, size_t index, unsigned char size);
extern unsigned long BSReadByte(BitStream*,size_t index, unsigned char size);