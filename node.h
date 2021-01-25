#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
typedef struct _Node{
    char data = ' ';
    std::string code ;
    int priority;   //
    _Node* parent = nullptr;
    _Node* leftChild = nullptr;
    _Node* rightChild = nullptr;
}Node,Tree;

#endif