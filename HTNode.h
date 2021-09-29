//
// Created by Hikaze on 2021/9/25 20:28.
// 
//

#pragma once
/**
 * @brief 哈夫曼树结构
 * @param weight 结点权重
 * @param data 结点数据值
 * @param pParent 母结点指针
 * @param pLeft 左子结点指针
 * @param pRight 右子结点指针
 */
typedef struct HTNode_{
    long weight;
    long data;
    struct HTNode_* pParent,* pLeft,* pRight;
}HTNode;
/**
 * @brief 初始化哈夫曼结点
 * @param _weight 权重
 * @param _data 值
 * @return 哈夫曼根结点指针
 */
extern HTNode* HTNodeInit(long _weight, long _data);
/**
 * @brief 释放空间
 * @param pNode 哈夫曼结点指针
 */
extern void HTNodeFree(HTNode *pNode);