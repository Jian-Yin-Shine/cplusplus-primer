/*
函数重载
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;


// 函数名相同，返回类型不同 or 参数类型，个数不同
// 注意：一定要参数不同，如果参数完全相同，而返回类型不同，则不可

// 1. 形残忽略顶层const, const int 和 int 是一样的
// 2. 底层const不同，可以属于重载
// 例子：
// 属于相同:
// const int a = const int , const int a = int
//       int a = const int ,       int a = int
// lookup(const int)
// lookup(int)

//       int *p = &(const int a) ,       int *p = &(int a)
//       int * const p = &(const int a), int * const p = &(int a)
// 注意：
// const double pi = 3.14;
// const double * const pip = &pi; // 指向常对象的，常指针.
// lookup(int *p)
// lookup(int * const p)


// 底层const不同可以算重载
// int &a = int b;  int &a = const int b(不可)
// const int &a = b; const int &a = const int b;
// lookup(int &)
// lookup(const int &)

// int *p = &(int b); int *p = &(const int b) (不可)
// const int *p = &(int b); const int *p = &(const int b)
// lookup(int *)
// lookup(const int *)

int main() {
    return 0;    
}
