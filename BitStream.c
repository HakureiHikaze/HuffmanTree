//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#include "BitStream.h"

BitStream* BSInit(size_t size){
    BitStream * rtn = (BitStream*) calloc(1, sizeof (BitStream));
    rtn->pBinary = calloc(size/8, 1);//不需要类型转换为(unsigned char*)，直接内存hack
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
        //如果index超出该bit流长度，则重分配2倍的空间
        //realloc函数返回值不能赋给原指针，会引发内存泄漏
        //需要定义一个新的指针
        //※糟糕的设计
        unsigned char* pNew = (unsigned char*) realloc(bitStream->pBinary, 2*bitStream->size*sizeof (unsigned char));
        bitStream->pBinary = pNew;
        bitStream->size*=2;//最大大小x2
    }
    //设置第index/8个byte的第index%8位
    //我不知道用什么逻辑运算能让0b00001101 运算出0b00000101 ，只能按位or掩码
    *(unsigned char*)(bitStream->pBinary+index/8) |= bool<<index%8;
}

unsigned char BSGetBit(BitStream* bitStream, size_t index){
    if(!bitStream) exit(-1);
    if(!bitStream->pBinary)exit(-1);
    if(index>=bitStream->size) exit(-2);
    //位操作得到目标位bit
    return ((*(unsigned char*)(bitStream->pBinary+index/8)) >> index%8) & 1;
}

void BSSetByte(BitStream* bitStream,unsigned char data, size_t index, unsigned char size){
    if(index+size>bitStream->size){//同上
        unsigned char* pNew = (unsigned char*) realloc(bitStream->pBinary, 2*bitStream->size*sizeof (unsigned char));
        bitStream->pBinary = pNew;
        bitStream->size*=2;
    }
    //逐个设置位
    //todo:直接赋值效率更高，但是要切割比特串，以后再说
    for(unsigned char i = 0; i<size; i++){
        BSSetBit(bitStream,data>>(size-i-1)&1,index+i);
    }
}

unsigned long BSReadByte(BitStream* bitStream,size_t index, unsigned char size){
    unsigned long buffer = 0;
    //逐个读取bit
    for(unsigned char i=0;i<size;i++){
        buffer |= BSGetBit(bitStream,index+i)<<(size-i-1);
    }
    return buffer;
}