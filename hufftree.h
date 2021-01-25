#ifndef __HUFFTREE_H__
#define __HUFFTREE_H__

#include<iostream>
#include"node.h"
#include"queue.h"
using namespace std;
class HuffTree
{
public:
    HuffTree();
    ~HuffTree();
public:
    //构建树,i成功返回true，否则返回false
   bool create(int codedTreeNum);
   void dataTable();
   bool getCode(char c);
private:
    Queue queue;
    Tree* tree;
    Queue* leafQueue;
    //遍历树
    Node* search(Node* root,char c);
    //获取所有的叶子
    Queue* getLeaf(Node* node);
};

#endif