#include"hufftree.h"
#include<iostream>
using namespace std;
bool HuffTree::create(int codedNum)
{
    //1.创建队列

    for(int i=1 ; i <= codedNum ; ++i)
    {   

        Node *node = new Node; //由pop函数释放
        cout<<"请输入第"<<i<<"个字符和出现频率: "<<endl;
        cin >> node->data >> node->priority;
        cout << node->data << node->priority<<endl;
        cout << "finish"<<endl;
        //压入队列
        if(queue.push(node))
        cout << "finish"<<endl;
    }
    
    //2.构建树
    if(queue.length ==1) 
        return queue.pop();
    while(queue.length > 1)
    {
        cout<<queue.length<<endl;
        Node* lNode = queue.pop();
        lNode->code = '0';
        Node* rNode = queue.pop();
        rNode->code = '1';
        Node* parent = new Node;
        lNode->parent = parent;
        parent->leftChild = lNode;
        rNode->parent = parent;
        parent->rightChild = rNode;
        parent->priority = lNode->priority + rNode->priority;
        queue.push(parent);
    }
    //树构建完毕
    cout<<"finish"<<endl;
    tree = queue.pop();
    tree->data = '0';
    return true;
}


void HuffTree::dataTable()
{
    if(leafQueue->length == 0)
        leafQueue = getLeaf(tree); //叶子的顺序是从左到右
    leafQueue->rear = leafQueue->front;
    for(int i=0;i<leafQueue->length;i++)
    {
        cout<< leafQueue->rear->node->data;
        if(!getCode(leafQueue->rear->node->data))
            cout<<"There is no such char"<<endl;
        if(i != leafQueue->length-1)
            leafQueue->rear = leafQueue->rear->next;
    }
}

bool HuffTree::getCode(char c)
{
    //遍历树，得到结点
    if(leafQueue->length==0)
        leafQueue = getLeaf(tree);
    leafQueue->rear = leafQueue->front;
    for(int i=0;i<leafQueue->length;i++)
    {
        if(leafQueue->rear->node->data == c)
        {
            Node *node = leafQueue->rear->node;
            while(node->parent)
            {
                cout << node->code;
                node = node->parent;
            }
            cout << endl;
            return true;
        }
        if(i != leafQueue->length-1)
            leafQueue->rear = leafQueue->rear->next;
    }
   return false;
}

Node* HuffTree::search(Node* root,char c)
{

    if(!(root->rightChild==nullptr && root->leftChild==nullptr))
    {
        if(search(root->leftChild,c))
            return root->leftChild;
        if(search(root->rightChild,c))
            return root->rightChild;
    }
    else
    {
        if(root->data == c) return root;
    }
    return nullptr;
}

Queue* HuffTree::getLeaf(Node* node)
{
    if(node->leftChild==nullptr && node->rightChild==nullptr)
    {
        queue.push(node);
    }
    else
    {
        getLeaf(node->leftChild);
        getLeaf(node->rightChild);
    }
    return &queue;
}

HuffTree::HuffTree() {
    queue.init();
    tree = new Tree;
    leafQueue = new Queue;
    leafQueue->init();
}
    