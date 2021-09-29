//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#include "BitStream.h"

BitStream* BSInit(size_t size){
    BitStream * rtn = (BitStream*) calloc(1, sizeof (BitStream));
    rtn->pBinary = calloc(size/8, 1);
    rtn->size = size;
    return rtn;
}
void BSFree(BitStream* bitStream){
    free(bitStream->pBinary);
    free(bitStream);
}

void BSSetBit(BitStream* bitStream, unsigned char bool, size_t index){

    if(!bitStream) exit(-1);
    if(!bitStream->pBinary)exit(-1);
    if(index>= bitStream->size){
        unsigned char* pNew = (unsigned char*) realloc(bitStream->pBinary, 2*bitStream->size*sizeof (unsigned char));
        bitStream->pBinary = pNew;
        bitStream->size*=2;
    }
    *(unsigned char*)(bitStream->pBinary+index/8) |= bool<<index%8;
}

unsigned char BSGetBit(BitStream* bitStream, size_t index){
    if(!bitStream) exit(-1);
    if(!bitStream->pBinary)exit(-1);
    if(index>=bitStream->size) exit(-2);
    return ((*(unsigned char*)(bitStream->pBinary+index/8)) >> index%8) & 1;
}

void BSSetByte(BitStream* bitStream,unsigned char data, size_t index, unsigned char size){
    if(index+size>bitStream->size){
        unsigned char* pNew = (unsigned char*) realloc(bitStream->pBinary, 2*bitStream->size*sizeof (unsigned char));
        bitStream->pBinary = pNew;
        bitStream->size*=2;
    }
    for(unsigned char i = 0; i<size; i++){
        BSSetBit(bitStream,data>>(size-i-1)&1,index+i);
    }
}

unsigned long BSReadByte(BitStream* bitStream,size_t index, unsigned char size){
    unsigned long buffer = 0;
    for(unsigned char i=0;i<size;i++){
        buffer |= BSGetBit(bitStream,index+i)<<(size-i-1);
    }
    return buffer;
}