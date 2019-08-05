/*
参数传递
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 传值（包括指针形参）int *ip = &i;
// 拷贝了指针，ip 指向了那个对象，但是是两根指针；
void reset(int *ip) {
    *ip = 10;
    ip = 0;     // 实参没有改变
}


// 引用传递 int &i=j;
void reset(int &i) {
    i = 20;    
}

// const形参和实参

/*
const 形参
void fun(const int i) {}
void fun(int) {} 
是同一个函数（重名）

const int i = int ; const int i = 34;
      int i = int ;       int i = 34;
*/


int main() {
    int i = 0;
    reset(&i);
    cout << i << endl;
    
    reset(i);
    cout << i << endl;

    // 指针和引用的const
    const int ci = i;
    string::size_type ctr = 0;

    reset(&i); // int *ip = &i;
    // reset(&ci); // int *ip = (const int) 对象的地址 // const int *ip;
    reset(i);  // int &i = i;
    // reset(ci);  // int &i = (const int) 对象的引用 // const int &i;
    // reset(42);  // int &i = 42 ; 引用必须绑定到对象，而不是字面值
    // reset(ctr); // int &i = size_type 类型不匹配
    
    // 因为 int &i 不能绑定const对象，并且 int *ip 不能指向 const int 对象的地址；
    // 如果不需要修改实参时，最好使用const int & i (常量引用)

    return 0;    
}
