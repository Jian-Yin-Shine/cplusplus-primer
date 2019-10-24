/*
 移动控制：只能绑定到一个将要销毁的对象上，包括使用了move操作的对象，右值引用完全接管那段内存。
 移后对象必须可析构
 
 合成的移动：1.如果有拷贝控制或者析构函数，就一定不会合成。
            2. 若没有自己定义拷贝控制，析构函数，并且成员可以移动才会合成。
 
 删除的移动：除非 我们显式将移动=default，但是又不能移动所有的非static的成员，就会隐式delete
 
 */

#include <iostream>
#include <string>

using namespace std;

// 有拷贝构造，则无合成的移动函数
class Foo {
public:
    Foo() = default;
    Foo(const Foo&);
private:
    string str;
};

int main()
{
    Foo x;
    Foo y(x);
    Foo z(std::move(x));  // 及时使用移动也是拷贝
    return 0;
}
