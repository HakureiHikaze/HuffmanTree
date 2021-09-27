//
// Created by Hikaze on 2021/9/27 15:43.
// 
//

#include "LList.h"

LList ListInit(){
    LList rtn;
    rtn.pHead = 0;
    return rtn;
}

void ListAppend(LList* pList, void* pData){
    if(!pList->pHead){
        pList->pHead = (LNode*) calloc(1, sizeof (LNode));
        pList->pHead->pData = pData;
        return;
    }
    LNode * p = pList->pHead;
    while(p->pNext){
        p = p->pNext;
    }
    p->pNext = (LNode*) calloc(1, sizeof (LNode));
    p->pNext->pData = pData;
}

void* ListRemove(LList* pList, size_t index){
    void * pRtn = 0;
    if(!pList->pHead){
        return pRtn;
    }
    LNode * p = pList->pHead;
    LNode * q = p;
    for(size_t i = 0; i < index;i++){
        if(p->pNext){
            q = p;
            p = p->pNext;
        }else{
            exit(-1);
        }
    }
    if(q == p){
        pList->pHead = p->pNext;
        pRtn = p->pData;
        free(p);
    }else{
        q->pNext = p->pNext?p->pNext:0;
        pRtn = p->pData;
        free(p);
    }
    return pRtn;
}

size_t ListFindMin(LList list, char(*compareCallback)(void*, void*)){
    if(!list.pHead) {
        return 0;
    }
    LNode* p = list.pHead;
    LNode* q = p;
    size_t index = 0;
    for(size_t i = 1;p->pNext;i++){
        p = p->pNext;
        if(compareCallback(q->pData, p->pData)){
            q = p;
            index = i;
        }
    }
    return index;
}