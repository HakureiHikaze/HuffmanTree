cmake_minimum_required(VERSION 3.20)
project(HuffmanTree C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanTree main.c HTNode.c HTNode.h HuffmanTree.c HuffmanTree.h LList.c LList.h BitStream.c BitStream.h CodeTable.c CodeTable.h)
