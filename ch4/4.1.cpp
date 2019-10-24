/*
 1. 左值、右值
    右值：一个对象被用作右值，用的是对象的值(内容)
    左值：一个对象被用作左值，用的是对象的身份(在内存中的位置)
 2. 取地址 & : 作用与一个左值对象，返回一个指向该对象的指针，这个指针是右值
 3. 内置解引用，下标运算符，迭代器递增递减，返回是左值
 4. decltype类型推断： 作用于左值，返回一个引用类型。（不忽略顶层const）
 5. 变量是左值
 6. decltype((i)) : 再添加一个() , 表示要使用表达式
    否则是该变量的类型
 7. 不能将右值引用&&绑定到左值上，除非使用move
 8. 如果没有移动构造，move也使用拷贝构造
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string i;
    decltype(i) x;
    cout << typeid(x).name() << endl;
    
    decltype((i)) y = i;
    
    return 0;
}
