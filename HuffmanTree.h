//
// Created by Hikaze on 2021/9/25 20:48.
// 
//

#pragma once

#include "HTNode.h"
#include <stdlib.h>

typedef struct HuffmanTree_{
    HTNode* pRoot;
}HuffmanTree;

extern HuffmanTree ConstructHT(long**, size_t);