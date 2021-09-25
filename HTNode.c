//
// Created by Hikaze on 2021/9/25 20:28.
// 
//

#include "HTNode.h"
#include <stdlib.h>

HTNode* ConstructNode(long _weight, long _data){
    HTNode* pRtn = malloc(sizeof(HTNode));
    pRtn->weight = _weight;
    pRtn->data = _data;
    pRtn->pLeft = 0;
    pRtn->pRight = 0;
    pRtn->pParent = 0;
    return pRtn;
}

void DeConstructNode(HTNode* pNode){
    free(pNode);
}