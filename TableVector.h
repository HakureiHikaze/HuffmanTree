//
// Created by Hikaze on 2021/9/29 1:04.
// 
//

#pragma once
#include <stdlib.h>
typedef struct FTItem_{
    long weight;
    unsigned char value;
}FTItem;

typedef struct FrequencyTable_{
    FTItem* pArray;
    unsigned int capacity;
    unsigned int size;
}FrequencyTable;

extern FrequencyTable* CTInit();
extern void CTFree(FrequencyTable*);
extern void CTAppend(FrequencyTable* table, unsigned char value, long weight);
extern void CTSwap(FrequencyTable* table, unsigned char indexA, unsigned char indexB);
extern void CTQSort(FrequencyTable* table);