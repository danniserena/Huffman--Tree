#ifndef __QUEUE_H__
#define __QUEUE_H__
#include"node.h"
typedef struct _QueueNode
{
    Node* node;
    _QueueNode* next;
}QueueNode;

typedef QueueNode* QueuePtr;

class Queue
{
public:
    bool init();
    bool push(Node *node);
    Node* pop();

public:
    int length;
    QueuePtr rear;
    QueuePtr front;
};

#endif