#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

/*
一些说明：
1.  成员函数的this
    1) 调用成员函数时，实际是某个对象调用成员函数
    2) 成员函数自带一个this参数，来访问调用成员函数的那个对象
    3) 相当于this = &obj
    4) this 是隐式定义的，不能自己定义
    5) this 是常量指针，已经指向到调用者的地址上，不能再修改。
    6) 在成员函数里面，可以使用this访问对象的数据，但是没有必要
2.  const成员函数
    const 其实不是修饰这个函数，而是修饰这个成员函数的this指针。
    这个this指针，默认情况下类型是：Sales_data * const this; 
    说明这个指针不能指向一个常量对象（顶层const没有）上；也使得不能在const 对象上调用普通的成员函数
    如果 this是 const Sales_data * const this, 函数是普通函数，那么在函数中，this指向的对象由于被const修饰，或者没有被const修饰
    这个指针已经不能用来修改对象, 则在函数中不能修改该对象。从而解决来上面的两个问题：1. this指针不能指向const对象 2. 不能在const对象不能调用普通成员函数

    由于this指针不能自己定义，其顶层const写在函数形参列表后面 isbn() const {}
    相当于 string isbn(const Sales_data * const this) {
                return this->isbn;
            } 

3.  返回this对象的函数
    类似与操作符重载+=，a+=b；则表示返回将b加到a上，返回a对象
    返回原来的对象，实参就是 *this
    接受方（返回类型）就是调用者的类型 Sales_data，并且是&

4.  和类相关的非成员函数
    如果要直接使用对象的数据，声明友元

5.  拷贝对象，a = b(sum = lhs)，代表把数据成员拷贝给sum
    total = trans
    等价于：
    total.bookNo = trans.bookNo;
    total.unit_sold = trans.unit_sold;
    total.revenue = trans.revenue;
    第13章继续讨论，如果类里有指针，要自定义这个过程。


6.  构造函数
    1) 不写构造函数，编译器创建一个合成的默认构造函数
    2) 定义自己的构造函数，首先要明确的是，不接受实参的，就是默认构造函数
        定义他的目的，仅仅是因为既需要其他形式的构造函数，也需要默认的构造函数。
        Sales_data() = default，要求编译器生成构造函数。
    3) 参数列表
    4) 如果构造函数需要一些其他的操作，可以定义在类的外部


*/

class Sales_data {

friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
    // Sales_data() = default;
    Sales_data(): units_sold(0), revenue(0.0) { }
    Sales_data(const string &s): bookNo(s), units_sold(0), revenue(0.0) { }
    Sales_data(const string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &);

    string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold;
    double revenue;
    
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);



#endif
