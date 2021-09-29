//
// Created by Hikaze on 2021/9/29 1:04.
// 
//
#include "CodeTable.h"

void QSort(CodeTable* table, unsigned char high, unsigned low);//内部实现
unsigned char QSPartition(CodeTable* table, unsigned char high, unsigned low);//内部实现
void CTItemCpy(CTItem* to, CTItem* from){
    //复制CT元素，内部实现
    to->value = from->value;
    to->weight = from->weight;
    to->code = from->code;
    to->width = from->width;
}

void CTItemSet(CTItem* to, long weight, char value,unsigned int code, unsigned int width){
    //设置CT元素，内部实现
    to->weight = weight;
    to->value = value;
    to->code = code;
    to->width = width;
}

CodeTable* CTInit(){
    CodeTable * p = (CodeTable*) calloc(1, sizeof(CodeTable));
    //初始分配8个元素的空间
    p->pArray = (CTItem*) calloc(8, sizeof(CTItem));
    p->capacity = 8;
    return p;
}

void CTFree(CodeTable* table){
    //释放空间
    if(!table)return;
    if(!table->pArray)return;
    free(table->pArray);
    free(table);
}

void CTSwap(CodeTable* table, unsigned char indexA, unsigned char indexB){
    //交换元素
    if(indexA>=table->size || indexB>= table->size) exit(-2);
    CTItem * pBuffer = (CTItem*) calloc(1, sizeof(CTItem));
    CTItemCpy(pBuffer, &table->pArray[indexA]);
    CTItemCpy(&table->pArray[indexA], &table->pArray[indexB]);
    CTItemCpy(&table->pArray[indexB], pBuffer);
    free(pBuffer);
}


void CTAppend(CodeTable* table, char value, long weight){
    if(table->size>=table->capacity){
        if(table->capacity>= 256) exit(-2);//超过256溢出
        CTItem * pNew = (CTItem*)realloc(table->pArray, table->capacity * 2 * sizeof(CTItem));
        table->capacity*=2;
        table->pArray = pNew;
    }
    CTItemSet(&table->pArray[table->size],weight, value,0, 0);
    table->size++;
}

void CTAddValue(CodeTable* table, char value){
    unsigned int i = CTSearchByValue(table,value);
    if(i == 256){//超过256溢出
        CTAppend(table,value,1);
        return;
    }
    table->pArray[i].weight++;
}

unsigned char QSPartition(CodeTable* table, unsigned char high, unsigned low){
    //快排分区
    long pivot = table->pArray[high].weight;
    while(high < low){//指针相遇时退出本轮分区，并返回相遇时索引
        //低指针遇到比支点大的值与高指针元素交换
        while(high < low && table->pArray[low].weight <= pivot){
            low--;
        }
        CTSwap(table, high, low);
        //高指针遇到比支点小的值与低指针元素交换
        while(high < low && table->pArray[high].weight >= pivot){
            high++;
        }
        CTSwap(table, high, low);
    }
    return high;
}

void QSort(CodeTable* table, unsigned char high, unsigned low){
    //递归排序分区
    if(high < low){
        unsigned char pivotIndex = QSPartition(table, high, low);
        //如果pivot不在首位或末尾则进行下一层递归
        if(pivotIndex)QSort(table, high, pivotIndex - 1);
        if(pivotIndex < low)QSort(table, pivotIndex + 1, low);
    }
}

void CTQSort(CodeTable* table){
    //接口
    QSort(table,0,table->size-1);
}

unsigned int CTSearchByValue(CodeTable* table, char value){
    //顺序查找
    for(unsigned int i = 0; i<table->size; i++){
        if(table->pArray[i].value == value){
            return i;
        }
    }
    //找不到则返回256
    return 256;
}

unsigned int CTSearchByCode(CodeTable* table, unsigned int code){
    //顺序查找
    for(unsigned int i = 0; i<table->size; i++){
        if(table->pArray[i].code == code){
            return i;
        }
    }
    //找不到则返回256
    return 256;
}

void CTSetCode(CodeTable* table, char value, unsigned int code){
    unsigned char i = CTSearchByValue(table, value);
    if(i>255)exit(-2);//超过255溢出
    table->pArray[i].code = code;
}

void CTSetSize(CodeTable* table, unsigned char size){
    if(size > table->maxCodeWidth){
        table->maxCodeWidth = size;
    }
}