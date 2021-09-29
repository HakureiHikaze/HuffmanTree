//
// Created by Hikaze on 2021/9/25 20:28.
// 
//

#pragma once

typedef struct HTNode_{
    long weight;
    long data;
    struct HTNode_* pParent,* pLeft,* pRight;
}HTNode;

extern HTNode* ConstructNode(long _weight, long _data);
extern void DeConstructNode(HTNode*);