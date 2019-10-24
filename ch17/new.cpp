/*
 1. new的流程：
        - 调用operator new 或者 operator new []的标准库函数(分配一个足够大，原始的，未命名的内存空间) (可以接管，返回void指针)
        - 编译器运行构造函数 （编译器进行void* 指针强转，然后用指针调用构造(只有编译器可以用指针调用构造函数，析构函数可以用户自己用指针调用)）
        - 此时已经完成内存分配，并且构造，返回一个指向该对象的指针
 2. delete流程：
        - 执行析构
        - 调用operator delete 或者 operator delete []的标准库函数释放内存
 
 
 3. new string : 默认初始化
    new string() ： 值初始化
 对于定义了默认构造函数 string() { // } 没有区别，都是用默认构造函数
    new int;
    new int();
 如果没有定义默认构造函数, 则会使用合成的默认构造函数，如果数据没有在类内初始化，则是为定义的
 内置对象使用值初始化，则会有较好的定义值
 
 
 4. C++ 11 operator delete 或者 operator delete[] 都要制定不抛出异常
 
 5. operator new 可以有多个版本，但是要使用定点new表达式
    除了 operator new(size_t, void*)外 ?
 
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Foo {
public:
    int i;
    Foo() : i(0) {}
    Foo(int i) : i(i) {}
    ~Foo() {}
    
    static void* operator new(size_t);
    static void operator delete(void*) noexcept;
    
    static void* operator new(size_t, void*);
    static void* operator new(size_t size, void*, int x);
    
};

void* Foo::operator new(size_t size) {
    cout << "接管内存分配工作";
    if (void* mem = malloc(size)) {
        return mem;
    }
    else {
        throw bad_alloc();
    }
}

void Foo::operator delete(void* mem) noexcept {
    cout << "接管内存释放工作" << endl;
    free(mem);
}

void* Foo::operator new(size_t size, void* ptr) {
    return ptr;
}


void* Foo::operator new(size_t size, void* ptr2, int x) {
    cout << "operator new v3 ";
    return ptr2;
}

int main()
{
    Foo* ptr = new Foo;
    cout << ptr->i << endl;
    delete ptr;
    
    
    void* buf = malloc(sizeof(Foo) * 3);
    Foo* ptx = new(buf)Foo(1);
    cout << ptx->i << endl;

    Foo* ptx2 = new(ptx+1, 4)Foo(2);
    cout << ptx2->i << endl;
    
    return 0;
}
