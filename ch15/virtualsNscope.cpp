/*
 虚函数与名字查找
 */


#include <iostream>

using namespace std;

class Base {
public:
    virtual int fcn();
};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0; }

class D1 : public Base {
public:
    int fcn(int);
    virtual void f2();
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }
void D1::f2() { cout << "D1::f2()" << endl; }

class D2 : public D1 {
public:
    int fcn(int);
    int fcn();
    void f2();
};

int D2::fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }
int D2::fcn() { cout << "D2::fcn()" << endl; return 0; }
void D2::f2() { cout << "D2::f2()" << endl; }

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;
    
    Base* bj1 = &bobj;
    bj1->fcn();
    
    bj1 = &d1obj;
    bj1->fcn();
//    bj1->f2();
    
    bj1 = &d2obj;
    bj1->fcn();
    
    D1* d1p = &d1obj;
    d1p->f2();
    
    D1* d2p = &d2obj;
    d2p->f2();
    
    return 0;
}
