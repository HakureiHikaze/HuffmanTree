//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#include "BitStream.h"

BitStream* BSInit(size_t size){
    BitStream * rtn = (BitStream*) calloc(1, sizeof (BitStream));
    rtn->pBinary = calloc(size, 1);
    return rtn;
}
void BSFree(BitStream* bitStream){
    free(bitStream->pBinary);
    free(bitStream);
}

void BSSetBit(BitStream* bitStream, unsigned char bool, size_t index){
    if(!bitStream) exit(-1);
    if(!bitStream->pBinary)exit(-1);
    if(index>=bitStream->size) exit(-2);
    *(unsigned char*)(bitStream->pBinary+index/8) |= bool<<index%8;
}

unsigned char BSGetBit(BitStream* bitStream, size_t index){
    if(!bitStream) exit(-1);
    if(!bitStream->pBinary)exit(-1);
    if(index>=bitStream->size) exit(-2);
    return ((*(unsigned char*)(bitStream->pBinary+index/8)) >> index%8) & 1;
}