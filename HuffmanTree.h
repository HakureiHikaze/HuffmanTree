//
// Created by Hikaze on 2021/9/25 20:48.
// 
//

#pragma once

#include "HTNode.h"
#include "LList.h"
#include "CodeTable.h"
#include <stdlib.h>
/**
 * @brief 哈夫曼树结构
 * @param pRoot 根结点
 */
typedef struct HuffmanTree_{
    HTNode* pRoot;
}HuffmanTree;
/**
 * @brief 从初始码表创建哈夫曼树
 * @param table CT指针
 * @param size CT大小//todo:可以省掉size，此处为数组传值时期的遗留问题
 * @return 哈夫曼树
 */
extern HuffmanTree ConstructHT(CodeTable * table, size_t size);