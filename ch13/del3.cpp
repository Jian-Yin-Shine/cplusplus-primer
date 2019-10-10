/*
 析构函数如果是删除的，不能构造其对象。
 但是可以动态分配这种类型的对象。但是不能释放。
 */


#include <iostream>

using namespace std;

struct Node {
    Node() = default;
    ~Node() = delete;
    
};

int main()
{
//    Node nd;
    Node* ptr = new Node();
//    delete ptr;
    return 0;
}
