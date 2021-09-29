//
// Created by Hikaze on 2021/9/29 11:43.
// 
//

#pragma once
#include "HuffmanTree.h"
#include "BitStream.h"
#include <stdio.h>

extern CodeTable* Census(const char* str);
extern void HCGenCodeTable(CodeTable* table, HuffmanTree* tree);
extern BitStream * HCEncode(const char* str);