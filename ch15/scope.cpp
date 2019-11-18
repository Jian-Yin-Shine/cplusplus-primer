
#include <iostream>

using namespace std;

struct Base {
    Base() : mem(21) { }
    int get_mem() { return mem; }
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i) : mem(i) { } // 编译器自动填上 Base()
    
    int get_mem(int) { return mem; }
    int get_base_mem() { return Base::mem; }
protected:
    int mem;
};

int main()
{
    Derived d(42);
//    cout << d.get_mem() << endl;  名字查找优先与类型检查
    cout << d.get_mem(1) << endl;
    cout << d.get_base_mem() << endl;
    return 0;
}
