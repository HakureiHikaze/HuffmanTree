//
// Created by Hikaze on 2021/9/29 11:43.
// 
//

#include "HuffmanCode.h"

CodeTable* Census(const unsigned char* str){
    CodeTable * p = CTInit();
    for(size_t i = 0; str[i] != '\0'; i++){
        CTAddValue(p, str[i]);
    }
    return p;
}
