//
// Created by Hikaze on 2021/9/29 1:04.
// 
//
#include "TableVector.h"

void QSort(FrequencyTable* table, unsigned char low, unsigned high);
unsigned char QSPartition(FrequencyTable* table, unsigned char low, unsigned high);
void CTItemCpy(FTItem* to, FTItem* from){
    to->value = from->value;
    to->weight = from->weight;
}

void CTItemSet(FTItem* to, long weight, unsigned char value){
    to->weight = weight;
    to->value = value;
}

FrequencyTable* CTInit(){
    FrequencyTable * p = (FrequencyTable*) malloc(sizeof(FrequencyTable));
    p->pArray = (FTItem*) calloc(8, sizeof(FTItem));
    p->capacity = 8;
    p->size = 0;
    return p;
}

void CTFree(FrequencyTable* table){
    if(!table)return;
    if(!table->pArray)return;
    free(table->pArray);
    free(table);
}

void CTSwap(FrequencyTable* table, unsigned char indexA, unsigned char indexB){
    if(indexA>=table->size || indexB>= table->size) exit(-2);
    FTItem * pBuffer = (FTItem*) calloc(1, sizeof(FTItem));
    CTItemCpy(pBuffer, &table->pArray[indexA]);
    CTItemCpy(&table->pArray[indexA], &table->pArray[indexB]);
    CTItemCpy(&table->pArray[indexB], pBuffer);
}


void CTAppend(FrequencyTable* table, unsigned char value, long weight){
    if(table->size>=table->capacity){
        if(table->capacity>= 256) exit(-2);
        FTItem * pNew = (FTItem*)realloc(table->pArray, table->capacity * 2 * sizeof(FTItem));
        table->capacity*=2;
        table->pArray = pNew;
    }
    CTItemSet(&table->pArray[table->size],weight, value);
    table->size++;
}

unsigned char QSPartition(FrequencyTable* table, unsigned char low, unsigned high){
    long pivot = table->pArray[low].weight;
    while(low<high){
        while(low<high && table->pArray[high].weight <= pivot){
            high--;
        }
        CTSwap(table, low, high);
        while(low<high && table->pArray[low].weight >= pivot){
            low++;
        }
        CTSwap(table, low, high);
    }
    return low;
}

void QSort(FrequencyTable* table, unsigned char low, unsigned high){
    if(low < high){
        unsigned char pivotIndex = QSPartition(table, low, high);
        if(pivotIndex)QSort(table, low, pivotIndex-1);
        if(pivotIndex < high)QSort(table, pivotIndex+1, high);
    }
}

void CTQSort(FrequencyTable* table){
    QSort(table,0,table->size-1);
}