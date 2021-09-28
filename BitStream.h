//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#pragma once
#include <stdlib.h>

typedef struct BitStream_{
    unsigned char* p;
    size_t size;
}BitStream;

extern BitStream* BSInit(size_t size);
extern void BSFree(BitStream*);
extern void BSAdd(BitStream*, BitStream*);
extern void BSAddBits(BitStream*, unsigned char, unsigned char);
extern void BSLeftShift(BitStream*, size_t);
extern void BSRightShift(BitStream*, size_t);