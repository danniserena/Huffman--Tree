#include<iostream>
using namespace std;

#include"hufftree.h"


int main()
{
    //需要编码的字符个数
    int coded_num;
    cout<<"请输入要编码的字符个数: "<<endl;
    cin >> coded_num;

    auto *tree = new HuffTree;
    if (tree->create(coded_num))
    {
        cout<<"构建完成"<<endl;
    }else{
        cout<<"构建失败"<<endl;
    }
    //输出每个字符的编码
    tree->dataTable();
    //查询字符编码
    if(!tree->getCode('f'))
        cout<<"There is no such char"<< endl;
    return 0;
}
