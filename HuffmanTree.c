//
// Created by Hikaze on 2021/9/25 20:48.
// 
//

#include "HuffmanTree.h"

HuffmanTree ConstructHT(long** data, size_t size){
    HuffmanTree rtn;
    HuffmanTree** pArrayHT = (HuffmanTree**)calloc(size, sizeof(void*));
    for(size_t i = 0; i<size; i++){
        pArrayHT[i] = (HuffmanTree*)malloc(sizeof(HuffmanTree));
        pArrayHT[i]->pRoot = ConstructNode(data[i][1], data[i][2]);
    }
    size_t remain = size;
    while(remain > 1){
        size_t index[2];
        index[0] = 0;index[1] = 0;
        for(size_t i = 2; i<size; i++){
            if(index[0] == 0 && index[1] == 0) {
                if(pArrayHT[0]->pRoot->weight < pArrayHT[1]->pRoot->weight)
                {
                    index[0] = 0;
                    index[1] = 1;
                }else{
                    index[0] = 1;
                    index[1] = 0;
                }
            }
            if(pArrayHT[i]){
                if(pArrayHT[i]->pRoot->weight < pArrayHT[index[0]]->pRoot->weight){
                    index[1] = index[0];
                    index[0] = i;
                }else if(pArrayHT[i]->pRoot->weight < pArrayHT[index[1]]->pRoot->weight){
                    index[1] = i;
                }
            }
        }
        HTNode* p = ConstructNode(pArrayHT[index[0]]->pRoot->weight + pArrayHT[index[1]]->pRoot->weight, -1);
        p->pLeft = pArrayHT[index[0]]->pRoot;
        p->pRight = pArrayHT[index[1]]->pRoot;
        pArrayHT[index[0]]->pRoot->pParent = p;
        pArrayHT[index[1]]->pRoot->pParent = p;
        free(pArrayHT[index[1]]);
        pArrayHT[index[1]] = 0;
        pArrayHT[index[0]]->pRoot = p;
        remain--;
    }
    for(size_t i = 0; i<size; i++){
        if(pArrayHT[i]){
            for(size_t j = i+1; j<size; j++){
                if(pArrayHT[j]){
                    HTNode* p = ConstructNode(pArrayHT[i]->pRoot->weight + pArrayHT[j]->pRoot->weight, -1);
                    if(pArrayHT[i]->pRoot->weight < pArrayHT[j]->pRoot->weight){
                        p->pLeft = pArrayHT[i]->pRoot;
                        p->pRight = pArrayHT[j]->pRoot;
                        pArrayHT[i]->pRoot->pParent = p;
                        pArrayHT[j]->pRoot->pParent = p;
                        free(pArrayHT[j]);
                        pArrayHT[j] = 0;
                        pArrayHT[i]->pRoot = p;
                        rtn = *pArrayHT[i];
                        free(pArrayHT[i]);
                        free(pArrayHT);
                        return rtn;
                    }
                }
            }
        }
    }
    exit(-1);
}