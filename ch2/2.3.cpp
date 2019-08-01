/**
复合类型：基于其他类型定义的类型

引用: 
1. 只能绑定在对象上，不能绑定在字面上，或者某个表达式的的计算结果上。
2. 引用不是对象，因此不能有引用的引用。
3. 引用不是对象，一旦绑定就不能绑定其他对象。
4. 一个对象可以有多个引用
5. 引用和对象之间要类型匹配。
6. 定义时必须初始化

指针:
1. 与引用类似的地方是：也实现了对其他对象的间接访问（仅此而已）
2. 指针是对象，因此有指针的指针（而没有引用的引用）
3. 指针是对象，因此可以改变存放对象的地址。
3. 可以定义时不必初始化。
4. 使用&取得地址，使用*解引用来访问对象

const:
1. const限定符，其值不能改变
2. const限定的对象，其引用也不能修改
3. 引用、指针必须保持类型相同，但是const例外
    可以用const int 对象绑定 int 对象（而不一定要求const int），反过来不可以。
    甚至是常量上面（常量引用）
    可以用const int *p 指向 int 对象(而不一定要求const int)

**/

#include <iostream>
#include <cstdlib>

int main() {
    
    //引用
    int ival = 1024;
    int &refVal = ival;
    int &refVal2 = refVal; // 这不是引用的引用，而是refVal2 和 refVal 都绑定在ival上
    refVal = 0;
    std::cout << ival << refVal << refVal2 << std::endl;
   
    /**
    类型不匹配
    float a = 3.0;
    int & tmp = a;
    **/

    //指针
    ival = 42;
    int *p = &ival;
    std::cout << p  << " " << *p << std::endl;
    
    //空指针：不指定任何对象
    /**
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;
    std::cout << p1 <<" "<< p2 <<" "<< p3 << " " << std::endl;
    **/
    
    int i = 42;
    int *pi = 0;
    int *pi2 = &i;
    int *pi3;

    pi3 = pi2;
    pi2 = 0;
    std::cout << *pi3 << std::endl;

    //void指针, 可以存放任意类型对象的地址, 但不能*解引用
    double obj = 3.14;
    void *pv = &obj;
    //std::cout << *pv << std::endl;

    
    //指针的指针
    //指针也是对象，于是指针就可以存放指针的地址，形成指针的指针
    ival = 1024;
    pi = &ival;
    int **pipi = &pi;
    std::cout << ival << " " << *pi << " " << **pipi << std::endl;


    //指针的引用
    //指针是对象，存在指针的引用
    i = 42;
    int *&r = p;
    p = &i;
    std::cout << *r << std::endl;


    //const
    const int bufSize = 512;
    // bufSize = 512;不能对他进行复制操作
    
    //const对象的引用
    const int &r1 = bufSize;
    std::cout << r1 << std::endl;
    //r1 = 512;

    // const 引用可以绑定到普通变量，常量上面
    i = 42;
    const int &constr1 = i;
    const int &constr2 = 42;
    const int &constr3 = constr1*2;
    // int &tmp = bufSize;

    std::cout << constr1 << " " << constr2 << " " << constr3 << std::endl;


    //指针和const
    //const对象的指针
    const double mathpi = 3.14;
    const double *contptrs = &mathpi;
    std::cout << *contptrs << std::endl;

    //const指针：指针的地址是常量
    int errNumb = 0;
    int *const curErr = &errNumb; //一直指向errNumb
    std::cout << *curErr << std::endl;
    
    const double constpi = 3.1415926;
    const double *const pip = &constpi;
    std::cout << *pip << std::endl;
    
    return 0;    
}
