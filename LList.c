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

void ListAppend(LList* pList, void* pData){ //表尾添加元素
    //空表直接在表头指针分配新节点空间并返回
    if(!pList->pHead){
        pList->pHead = (LNode*) calloc(1, sizeof (LNode));
        pList->pHead->pData = pData;
        return;
    }
    LNode * p = pList->pHead;
    //移动游标到队尾
    while(p->pNext){
        p = p->pNext;
    }
    p->pNext = (LNode*) calloc(1, sizeof (LNode));
    p->pNext->pData = pData;
}

void* ListRemove(LList* pList, size_t index){   //删除索引指向的元素
    void * pRtn = 0;
    //若列表为空，返回空指针
    if(!pList->pHead){
        return pRtn;
    }
    LNode * p = pList->pHead;
    LNode * q = p;
    //定位至索引指向处
    for(size_t i = 0; i < index;i++){
        if(p->pNext){
            q = p;
            p = p->pNext;
        }else{
            exit(-1);
        }
    }
    //若删除表头元素
    if(q == p){
        pList->pHead = p->pNext;
        pRtn = p->pData;
        free(p);
        //若删除其他元素
    }else{
        //判断是否为删除表尾元素
        q->pNext = p->pNext?p->pNext:0;
        pRtn = p->pData;
        free(p);
    }
    return pRtn;
}

size_t ListFindMin(LList list, char(*compareCallback)(void*, void*)){   //传入比较数据项回调函数，将比较功能委托给用户代码
    if(!list.pHead) {
        return 0;
    }
    LNode* p = list.pHead;
    LNode* q = p;
    size_t index = 0;
    //一次遍历寻找数据项最小的元素
    //调用比较函数次数最多为表长
    //最差对比表长次，交换表长次节点
    for(size_t i = 1;p->pNext;i++){
        p = p->pNext;
        if(compareCallback(q->pData, p->pData)){
            q = p;
            index = i;
        }
    }
    return index;
}