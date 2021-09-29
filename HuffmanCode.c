//
// Created by Hikaze on 2021/9/29 11:43.
// 
//

#include "HuffmanCode.h"

void Recursion(CodeTable* table, HTNode * p, unsigned int code, unsigned int depth);
BitStream * HCEncode_(CodeTable* table, const char* str);

CodeTable* Census(const char* str){
    CodeTable * p = CTInit();
    for(size_t i = 0; str[i] != '\0'; i++){
        CTAddValue(p, str[i]);
    }
    return p;
}

void HCGenCodeTable(CodeTable* table, HuffmanTree* tree){
    Recursion(table, tree->pRoot, 0b0, 0b1);
}

void Recursion(CodeTable* table, HTNode * p, unsigned int code, unsigned int depth){
    if(p->data == -1){
        Recursion(table,p->pLeft,code<<1,depth+1);
        Recursion(table,p->pRight,(code+1)<<1,depth+1);
    }else{
        CTSetSize(table, depth);
        unsigned int i = CTSearchByValue(table, (char) p->data);
        if (i == 256) exit(-2);
        table->pArray[i].code = code >> 1;
        table->pArray[i].width = depth;
    }
}

BitStream * HCEncode_(CodeTable* table, const char* str){
    BitStream * p = BSInit(512);
    size_t j = 0;
    for(size_t i = 0; str[i] != '\0'; i++){
        unsigned int index = CTSearchByValue(table,str[i]);
        if(index == 256)exit(-2);
        CTItem * pItem = &table->pArray[index];
        BSSetByte(p,pItem->code, j,pItem->width);
        j+=pItem->width;
    }
    return p;
}

BitStream * HCEncode(const char* str){
    CodeTable * pTable = Census(str);
    HuffmanTree tree = ConstructHT(pTable, pTable->size);
    HCGenCodeTable(pTable, &tree);
    for(unsigned int i = 0; i<pTable->size;i++){
        printf("\nValue:\t%c",pTable->pArray[i].value);
        printf("\nWidth:\t%d",pTable->pArray[i].width);
        printf("\nCode :\t%x",pTable->pArray[i].code);
        printf("\nWeight:\t%ld\n",pTable->pArray[i].weight);
    }
    BitStream * rtn = HCEncode_(pTable, str);
    CTFree(pTable);
    DeConstructNode(tree.pRoot);
    return rtn;
}