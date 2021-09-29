//
// Created by Hikaze on 2021/9/29 1:04.
// 
//

#pragma once
#include <stdlib.h>
/**
 * @brief 全码表元素
 * @param weight 权重值，用于生成树
 * @param value 值，存储字符或其他
 * @param code 哈夫曼码，低位存储
 * @param width 哈夫曼码宽度
 */
typedef struct CTItem_{
    long weight;
    char value;
    unsigned int code;
    unsigned int width;
}CTItem;
/**
 * @brief 码表结构，容量最大为256（只编码ascii字符） ※其实是vector
 * @param pArray 元素数组指针
 * @param capacity 最大存储量（已分配的内存
 * @param size 已存储的元素数量
 * @param maxCodeWidth 哈夫曼码的最大宽度，用于最长匹配
 */
typedef struct CodeTable_{
    CTItem* pArray;
    unsigned int capacity;
    unsigned int size;
    unsigned int maxCodeWidth;
}CodeTable;
/**
 * @brief 初始化码表，初始capacity为8
 * @return CT指针
 */
extern CodeTable* CTInit();
/**
 * @brief 释放CT空间
 * @param table CT指针
 */
extern void CTFree(CodeTable* table);
/**
 * @brief 在末尾添加一个元素，不检查value是否重复
 * @param table CT指针
 * @param value 值
 * @param weight 权重
 */
extern void CTAppend(CodeTable* table, char value, long weight);
/**
 * @brief 按值添加，如果存在对应值的元素，则该元素的权重+1，无对应值的元素则添加新元素至末尾，权重为1
 * @param table CT指针
 * @param value 值
 */
extern void CTAddValue(CodeTable* table, char value);
/**
 * @brief 按索引交换两个元素
 * @param table CT指针
 * @param indexA 第一个元素的索引
 * @param indexB 第二个元素的索引
 */
extern void CTSwap(CodeTable* table, unsigned char indexA, unsigned char indexB);
/**
 * @brief 按权重从大到小快速排序 ※方便测试顺便写了，但是实际上没有用
 * @param table CT指针
 */
extern void CTQSort(CodeTable* table);
/**
 * @brief 按值查找索引，找不到返回256
 * @param table CT指针
 * @param value 值
 * @return 索引
 */
extern unsigned int CTSearchByValue(CodeTable* table, char value);
/**
 * @brief 按哈夫曼码（低位表示）查找索引，找不到返回256
 * @param table CT指针
 * @param code 哈夫曼码（低位表示）
 * @return 索引
 */
extern unsigned int CTSearchByCode(CodeTable* table, unsigned int code);
/**
 * @brief 按值设置哈夫曼码（低位表示）
 * @param table CT指针
 * @param value 值
 * @param code 哈夫曼码（低位表示）
 */
extern void CTSetCode(CodeTable* table, char value, unsigned int code);
/**
 * @brief 更新最长哈夫曼单字码，若小于等于原最大宽度则无作用
 * @param table CT指针
 * @param size 哈夫曼码宽度
 */
extern void CTSetSize(CodeTable* table, unsigned char size);