//
// Created by Hikaze on 2021/9/27 15:43.
// 
//

#pragma once
#include <stdlib.h>

typedef struct LNode_{
    void* pData;
    struct LNode_* pNext;
}LNode;

typedef struct LList_{
    LNode* pHead;
}LList;

LList ListInit();

/**
 * @brief 表尾追加结点
 * @param pList 链表list
 * @param pData 欲追加的结点数据项
 */
void ListAppend(LList* pList, void* pData);
/**
 * @brief 提取表中元素并释放结点空间
 * @param pList 链表list
 * @param index 欲删除的结点索引
 * @return 删除的元素数据项指针
 */
void* ListRemove(LList* pList, size_t index);
/**
 * @brief 搜索表中当前某数据项最小的元素
 * @param list 链表list
 * @param compareCallback 该回调函数判断参数1的某数据项是否大于参数2的某数据项，大于则返回1，否则返回0
 * @return 列表元素中，某数据项最小的元素的索引
 */
size_t ListFindMin(LList list, char(*compareCallback)(void*, void*));