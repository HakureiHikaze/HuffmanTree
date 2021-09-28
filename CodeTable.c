//
// Created by Hikaze on 2021/9/29 1:04.
// 
//
#include "CodeTable.h"

extern void QSort(CodeTable* table, unsigned char low, unsigned high);

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
    pBuffer->size = table->pArray[indexA].size;
    pBuffer->weight = table->pArray[indexA].weight;
    pBuffer->value = table->pArray[indexA].value;
    table->pArray[indexA].size = table->pArray[indexB].size;
    table->pArray[indexA].weight = table->pArray[indexB].weight;
    table->pArray[indexA].value = table->pArray[indexB].value;
    table->pArray[indexB].size = pBuffer->size;
    table->pArray[indexB].weight = pBuffer->weight;
    table->pArray[indexB].value = pBuffer->value;
}


void CTAppend(CodeTable* table, unsigned char value, long weight, unsigned char size){
    if(table->size>=table->capacity){
        if(table->capacity>= 512) exit(-2);
        CTItem * pNew = (CTItem*)realloc(table->pArray,table->capacity*2* sizeof(CTItem));
        table->capacity*=2;
        table->pArray = pNew;
    }
    table->pArray[table->size].value = value;
    table->pArray[table->size].weight = weight;
    table->pArray[table->size].size = size;
    table->size++;
}

void QSort(CodeTable* table, unsigned char low, unsigned high){

}

void CTQSort(CodeTable* table){
    QSort(table,0,table->size-1);
}