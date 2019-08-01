/**
基本内置数据类型：
bool, char, short, int, long, long long, float, double, long double

字符型： char, signed char, unsigned char，表现形式只有带符号和不带符号的。
        char类型具体表现为上述signed char，或者 unsigned char 看编译器
**/

#include <iostream>

int main() {
    
    unsigned u1 = 42, u2 = 10;

    std::cout << u1-u2 << std::endl;
    std::cout << u2-u1 << std::endl; // -1 = 2**32-1; -32 = 2**32-32
    
    unsigned u = 10;
    int i = -42;

    std::cout << i + i << std::endl;
    std::cout << u + i << std::endl; // unsigned + int, int进行一次强转,-42+2**32+10
    
    /**
    for (int i = 10; i >=0; i--) {
    }**/
    /** 死循环
    for (unsigned i = 10; i >=0; i--) {
        std::cout << i;
    }**/




    return 0;
}
