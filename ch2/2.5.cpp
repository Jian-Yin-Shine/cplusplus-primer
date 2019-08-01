#include <iostream>

typedef long long ll;
typedef char *pstring; // pstring 为指向char的指针

int main() {
    
    ll a = 0;
    std::cout << a << std::endl;
    char str = 'a';
    pstring ps = &str;
    std::cout << *ps << std::endl;
   
   
    const pstring cstr = &str;  // const修饰这个指针，即这个指针是const指针
                                // 而非替代 const char *cstr(指向const对象的指针)
                                // char * const cstr
    std::cout << *cstr << std::endl;

    const pstring *pss = &cstr; // ps指针，指向const修饰的一个指针（即指针的指针）
    std::cout << **pss << std::endl;

    return 0;    
}
