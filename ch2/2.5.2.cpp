/**
auto；
忽略顶层const


**/
#include <iostream>

int main() {
    
    // auto a = 0, sz = 3.14; 必须同类型
    int i = 0, &r = i;
    // 推断是引用，类型为引用的对象的类型
    auto a = r;
    std::cout << a << std::endl; 
    
    //忽略顶层const
    const int ci = i, &cr = ci;
    auto b = ci; // b 是一个 int，忽略了顶层const
    auto c = cr; // c 是一个 int, cr是引用，c获取引用的对象，忽略顶层const
    auto d = &i; // &i 是地址，推断出d是指针
    auto e = &ci; // e是指针，忽略顶层const, 指针可以再次赋值，但是指向对象必须是const

    //想要顶层const
    const auto f = ci; //f 是一个const int

    //推断后，想要一个引用
    auto &g = ci;  //g绑定到了ci, ci是const int
    //auto &h = 42; 必须绑定到一个对象上，否则用const修饰
    const auto &j = 42;

    //一条声明中，类型必须相同,推断后的类型必须都相同
    auto k = ci, &l = i; // ci 是const int , 推断后忽略顶层 k int 
    auto &m = ci,*p = &ci; // ci 是const int, 推断后由于是&不忽略顶层const, const int
                            // &ci 是const int的地址，指针指向对象的类型是const int
    
    // auto &n = i, *p2 = &ci;  //p2指向的类型为const int, n 是int的引用

    return 0;    
}
