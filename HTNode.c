//
// Created by Hikaze on 2021/9/25 20:28.
// 
//

#include "HTNode.h"
#include <stdlib.h>

HTNode* HTNodeInit(long _weight, long _data){
    HTNode* pRtn = (HTNode*)calloc(1,sizeof(HTNode));
    pRtn->weight = _weight;
    pRtn->data = _data;
    return pRtn;
}

void HTNodeFree(HTNode* pNode){
    free(pNode);
}