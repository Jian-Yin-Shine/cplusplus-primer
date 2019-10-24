/*
 隐式类型转换：
 1. 数组： int a[10]; int *p = a;  // 数组a，转换为首元素的地址
 但是：在 sizeof(a), &a, decltype时，不会转换，还是代表数组对象
 ...
 
 指针转换:
 void* ,可以指向任意类型的对象，但是不能解引用，如果要解引用，用到强制类型转换
 static_cast : 只能做类型转换
 const_cast : 只能改变底层const属性，不能改变类型
 reinterpret_cast : 不能解引用, 同：int *p; char *pc = (char*) p;
 */


#include <iostream>

using namespace std;



int main()
{
    void* mem = new int(41);
    int* buf = static_cast<int*>(mem);
    cout << *buf << endl;

    const char ch = 'c';
    const char ch2 = 'b';
    
    const char * pc = &ch;
    cout << *pc << endl;
    pc = &ch2;
    cout << *pc << endl;
    const char * const pc2 = &ch;
    
    char *ptx = const_cast<char*>(pc);
    cout << *ptx << endl;
    char c = 'e';
    ptx = &c;
    cout << *ptx << endl;
    
    
    
    
    return 0;
}
