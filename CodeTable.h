//
// Created by Hikaze on 2021/9/29 1:04.
// 
//

#pragma once
#include <stdlib.h>
typedef struct CTItem_{
    long weight;
    unsigned char value;
    unsigned char code;
}CTItem;

typedef struct CodeTable_{
    CTItem* pArray;
    unsigned int capacity;
    unsigned int size;
    unsigned int maxCodeWidth;
}CodeTable;

extern CodeTable* CTInit();
extern void CTFree(CodeTable*);
extern void CTAppend(CodeTable* table, unsigned char value, long weight);
extern void CTAddValue(CodeTable* table, unsigned char value);
extern void CTSwap(CodeTable* table, unsigned char indexA, unsigned char indexB);
extern void CTQSort(CodeTable* table);
extern unsigned int CTSearchByValue(CodeTable* table, unsigned char value);
extern unsigned int CTSearchByCode(CodeTable* table, unsigned char code);
extern void CTSetCode(CodeTable* table, unsigned char value, unsigned char code);