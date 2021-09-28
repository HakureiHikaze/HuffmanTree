//
// Created by Hikaze on 2021/9/29 1:04.
// 
//
#include "CodeTable.h"

void QSort(CodeTable* table, unsigned char low, unsigned high);
unsigned char QSPartition(CodeTable* table, unsigned char low, unsigned high);
void CTItemCpy(CTItem* to, CTItem* from){
    to->value = from->value;
    to->weight = from->weight;
}

void CTItemSet(CTItem* to, long weight, unsigned char value){
    to->weight = weight;
    to->value = value;
}

CodeTable* CTInit(){
    CodeTable * p = (CodeTable*) malloc(sizeof(CodeTable));
    p->pArray = (CTItem*) calloc(8, sizeof(CTItem));
    p->capacity = 8;
    p->size = 0;
    return p;
}

void CTFree(CodeTable* table){
    if(!table)return;
    if(!table->pArray)return;
    free(table->pArray);
    free(table);
}

void CTSwap(CodeTable* table, unsigned char indexA, unsigned char indexB){
    if(indexA>=table->size || indexB>= table->size) exit(-2);
    CTItem * pBuffer = (CTItem*) calloc(1, sizeof(CTItem));
    CTItemCpy(pBuffer, &table->pArray[indexA]);
    CTItemCpy(&table->pArray[indexA], &table->pArray[indexB]);
    CTItemCpy(&table->pArray[indexB], pBuffer);
}


void CTAppend(CodeTable* table, unsigned char value, long weight){
    if(table->size>=table->capacity){
        if(table->capacity>= 256) exit(-2);
        CTItem * pNew = (CTItem*)realloc(table->pArray,table->capacity*2* sizeof(CTItem));
        table->capacity*=2;
        table->pArray = pNew;
    }
    CTItemSet(&table->pArray[table->size],weight, value);
    table->size++;
}

unsigned char QSPartition(CodeTable* table, unsigned char low, unsigned high){
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

void QSort(CodeTable* table, unsigned char low, unsigned high){
    if(low < high){
        unsigned char pivotIndex = QSPartition(table, low, high);
        if(pivotIndex)QSort(table, low, pivotIndex-1);
        if(pivotIndex < high)QSort(table, pivotIndex+1, high);
    }
}

void CTQSort(CodeTable* table){
    QSort(table,0,table->size-1);
}