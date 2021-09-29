//
// Created by Hikaze on 2021/9/28 11:39.
// 
//

#pragma once
#include <stdlib.h>
/**
 * @brief 比特流结构，用BSSetBit BSSetByte时按需扩增空间
 * todo:byte作为单元太小了，不足以存放码表，分割麻烦，将改动
 */
typedef struct BitStream_{
    unsigned char* pBinary;
    size_t size;
}BitStream;
/**
 * @brief 初始化比特流BitStream
 * @param size 比特流BitStream位数，实际占用空间为size/8
 * @return 返回BitStream的指针
 */
extern BitStream* BSInit(size_t size);
/**
 * @brief 设置目标索引单个bit，
 * @param bitStream BitStream指针
 * @param bool 位值
 * @param index 索引，粒度为1bit
 */
extern void BSSetBit(BitStream* bitStream,unsigned char bool, size_t index);
/**
 * @brief 获取目标索引单个bit，此函数存在缺陷，目标位必须为0
 * @param bitStream BitStream指针
 * @param index 索引，粒度为1bit
 * @return 目标索引处的bit值
 */
extern unsigned char BSGetBit(BitStream* bitStream, size_t index);
/**
 * @brief 释放指针
 * @param bitStream BitStream指针
 */
extern void BSFree(BitStream* bitStream);
/**
 * @brief 设置连续的，长度<=9的bit串，此函数存在缺陷，目标位段必须为0
 * @param bitStream BitStream指针
 * @param data bit串，低位表示
 * @param index 首位索引，粒度为1bit
 * @param size bit串长度
 */
extern void BSSetByte(BitStream* bitStream,unsigned char data, size_t index, unsigned char size);
/**
 * @brief 读取连续的bit串
 * @param bitStream BitStream指针
 * @param index 首位索引，粒度为1bit
 * @param size 欲读取的bit串长度
 * @return 读取的bit串
 */
extern unsigned long BSReadByte(BitStream* bitStream,size_t index, unsigned char size);