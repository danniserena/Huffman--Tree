#include"queue.h"
bool Queue::init()
{
    length = 0;
    front = rear = nullptr;
    return true;
}

bool Queue::push(Node *node)
{
    auto *queueNode = new QueueNode;
    queueNode->node = node;
    if(length == 0)
    {
        front = rear = queueNode;
    }
    else
    {
         rear->next = queueNode;
        rear = queueNode;
    } 
    ++length;
    return true;
}

//删除并返回priority最小的结点
Node* Queue::pop()
{
    Node* node = nullptr;
    if(length==1)
    {
        node = rear->node;
        delete rear;
        rear = front = nullptr;
        --length;
        return node;
    }
    if(length)
    {
        QueueNode * delNode = nullptr;
        QueueNode * lastNode = nullptr;
        delNode = front;
        rear = front;
        for(int i=0;i<length;i++)
        {
            if(delNode->node->priority > rear->node->priority)
            {
                lastNode = delNode;
                delNode = rear;
            }
            //最后一次不需要移动rear指针
            if(i!= length-1)
            rear = rear->next;
        }
        if(delNode == rear)
        {
            rear = lastNode;
            node = delNode->node;
            delete delNode;
            delNode = nullptr;
            rear->next = nullptr;
        }
        else if(delNode == front)
        {
            front = front->next;
            node = delNode->node;
            delete delNode;
            delNode = nullptr;
        }
        else
        {
            QueueNode *tmpNode;
            tmpNode = delNode;
            lastNode->next = delNode->next;
            node = tmpNode->node;
            delete tmpNode;
            tmpNode = nullptr;
        }
    }
    --length;
    return node;
}