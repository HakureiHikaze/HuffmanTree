//
// Created by Hikaze on 2021/9/29 1:04.
// 
//

#pragma once
#include <stdlib.h>
typedef struct CTItem_{
    long weight;
    unsigned char value;
    unsigned char size;
}CTItem;

typedef struct CodeTable_{
    CTItem* pArray;
    unsigned int capacity;
    unsigned int size;
}CodeTable;

extern CodeTable* CTInit();
extern void CTFree(CodeTable*);
extern void CTAppend(CodeTable* table, unsigned char value, long weight, unsigned char size);
extern void CTSwap(CodeTable* table, unsigned char indexA, unsigned char indexB);
extern void CTQSort(CodeTable* table);