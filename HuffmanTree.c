//
// Created by Hikaze on 2021/9/25 20:48.
// 
//

#include "HuffmanTree.h"
char compareHTNodeWeight(void* a, void* b){
    //比较回调函数，用于LList查找最小值
    if(((HTNode*)a)->weight > ((HTNode*)b)->weight){
        return 1;
    }else{
        return 0;
    }
}

HuffmanTree ConstructHT(CodeTable * table, size_t size){                          //创建哈夫曼树
    LList HTNodeList = ListInit();
    size_t remain = size;//剩余哈夫曼树数量
    for(size_t i = 0; i<size; i++){
        //初始化森林
        ListAppend(&HTNodeList, (void*) HTNodeInit(
                table->pArray[i].weight,
                table->pArray[i].value
        ));
    }
    HTNode* buffer[2];//最小2子树缓冲，buffer[0]的权重小于buffer[1]的
    while(remain > 1){//森林有多于1棵树时选择weight最小的2个子树根结点创建新树
        buffer[0] = ListRemove(&HTNodeList, ListFindMin(HTNodeList, compareHTNodeWeight)); //todo: ListFindMin返回指针效果更佳
        buffer[1] = ListRemove(&HTNodeList, ListFindMin(HTNodeList, compareHTNodeWeight));
        HTNode * pNode = HTNodeInit(buffer[0]->weight + buffer[1]->weight, -1);
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