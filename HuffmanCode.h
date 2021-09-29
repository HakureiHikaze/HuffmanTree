//
// Created by Hikaze on 2021/9/29 11:43.
// 
//

#pragma once
#include "HuffmanTree.h"
#include "BitStream.h"
#include <stdio.h>
/**
 * @brief 统计字符串字符，生成初始码表
 * @param str 字符串
 * @return CT指针
 */
extern CodeTable* Census(const char* str);
/**
 * @brief 在初始码表里创建每个元素的哈夫曼码
 * @param table CT指针
 * @param tree 哈夫曼树指针
 */
extern void HCGenCodeTable(CodeTable* table, HuffmanTree* tree);
/**
 * @brief 哈夫曼编码
 * @param str 目的字符串
 * @return 二进制哈夫曼编码流
 */
extern BitStream * HCEncode(const char* str);