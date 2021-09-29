//
// Created by Hikaze on 2021/9/29 11:43.
// 
//

#include "HuffmanCode.h"

void Recursion(CodeTable* table, HTNode * p, unsigned int code, unsigned int depth);//内部实现
BitStream * HCEncode_(CodeTable* table, const char* str);//内部实现

CodeTable* Census(const char* str){
    CodeTable * p = CTInit();
    for(size_t i = 0; str[i] != '\0'; i++){
        //有则加权，无则追加
        CTAddValue(p, str[i]);
    }
    return p;
}

void HCGenCodeTable(CodeTable* table, HuffmanTree* tree){
    Recursion(table, tree->pRoot, 0b0, 0b1);//内部递归，根节点编码为0，初始深度（编码宽度）为1
}

void Recursion(CodeTable* table, HTNode * p, unsigned int code, unsigned int depth){
    //内部递归
    if(p->data == -1){//中间结点
        Recursion(table,p->pLeft,code<<1,depth+1);//递归左子树传入编码左移1位，深度+1
        Recursion(table,p->pRight,(code+1)<<1,depth+1);//递归右子树传入编码+1后左移1位，深度+1
    }else{//数据结点
        CTSetSize(table, depth);//设置最大宽度（如超过原有最大宽度）
        unsigned int i = CTSearchByValue(table, (char) p->data);
        if (i == 256) exit(-2);//未搜索到则终止运行
        table->pArray[i].code = code >> 1;//传入的编码右移1位（调用时方便递归多移了1位）
        table->pArray[i].width = depth;//设置编码宽度=结点所在深度
    }
}

BitStream * HCEncode_(CodeTable* table, const char* str){
    //内部实现
    BitStream * p = BSInit(512);//随便写的整数
    size_t j = 0;//BitStream用的游标
    for(size_t i = 0; str[i] != '\0'; i++){//字符串结束之前
        unsigned int index = CTSearchByValue(table,str[i]);
        if(index == 256)exit(-2);//未搜索到则终止运行
        CTItem * pItem = &table->pArray[index];
        BSSetByte(p,pItem->code, j,pItem->width);//设置连续bit
        j+=pItem->width;//游标增加一个哈夫曼码宽度
    }
    return p;
}

BitStream * HCEncode(const char* str){
    CodeTable * pTable = Census(str);//todo:此处要么把字符编码表返回给用户，要么由用户代码传入CT指针，编码完了丢掉码表很愚蠢
    HuffmanTree tree = ConstructHT(pTable, pTable->size);//创建对应哈夫曼树
    HCGenCodeTable(pTable, &tree);//创建码表
    //以下为debug功能，输出码表信息
#ifdef DEBUG_HIKAZE
    for(unsigned int i = 0; i<pTable->size;i++){
        printf("\nValue:\t%c",pTable->pArray[i].value);
        printf("\nWidth:\t%d",pTable->pArray[i].width);
        printf("\nCode :\t%x",pTable->pArray[i].code);
        printf("\nWeight:\t%ld\n",pTable->pArray[i].weight);
    }
#endif
    //编码
    BitStream * rtn = HCEncode_(pTable, str);
    CTFree(pTable);
    //todo:越看越蠢
    HTNodeFree(tree.pRoot);
    return rtn;
}