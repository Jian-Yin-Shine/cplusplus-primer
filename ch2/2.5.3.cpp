/**
decltype
**/

#include <iostream>

int main() {
    
    int a=100;
    const int ci = 0, &cj = ci;
    decltype(ci) x = a; //ci 是const int, 不同于auto忽略顶层const，x也是const int
    decltype(cj) y = x; 
    // decltype(cj) z; cj是引用类型，必须定义时初始化
    std::cout << x << " " << y << std::endl;

    // decltype里面可以有表达式推出类型
    int i = 42, *p = &i, &r = i;
    std::cout << *p << " " << p << std::endl;
    
    decltype(r+0) b; // int
    //decltype(*p) c; //括号中是解引用，则得到引用类型
    
    //decltype(()) 双层括号结果永远返回引用
    // decltype((i)) d; 返回int & 
    decltype(i) e;
    
    

    return 0;    
}
