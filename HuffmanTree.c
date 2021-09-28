//
// Created by Hikaze on 2021/9/25 20:48.
// 
//

#include "HuffmanTree.h"

char compareHTNodeWeight(void* a, void* b){
    if(((HTNode*)a)->weight > ((HTNode*)b)->weight){
        return 1;
    }else{
        return 0;
    }
}

HuffmanTree ConstructHT(long data[][2], size_t size){                          //创建哈夫曼树
    LList HTNodeList = ListInit();
    size_t remain = size;
    for(size_t i = 0; i<size; i++){
        ListAppend(&HTNodeList, (void*)ConstructNode(data[i][0], data[i][1]));
    }
    HTNode* buffer[2];
    while(remain > 1){
        buffer[0] = ListRemove(&HTNodeList, ListFindMin(HTNodeList, compareHTNodeWeight)); //todo: ListFindMin返回指针效果更佳
        buffer[1] = ListRemove(&HTNodeList, ListFindMin(HTNodeList, compareHTNodeWeight));
        HTNode * pNode = ConstructNode(buffer[0]->weight+buffer[1]->weight, -1);
        pNode->pLeft = buffer[0];
        pNode->pRight = buffer[1];
        buffer[0]->pParent = pNode;
        buffer[1]->pParent = pNode;
        ListAppend(&HTNodeList, pNode);
        remain--;
    }
    HuffmanTree rtn;
    rtn.pRoot = ListRemove(&HTNodeList, 0);
    return rtn;
}