/*
阻止拷贝
 1. delete
 2. 原则：当不可能拷贝、赋值和析构的成员时，类的合成拷贝控制成员就被定义为删除的
 
 若成员不能访问析构：类的析构就是删除的，而且默认初始化，拷贝构造都是delete
 成员有引用& 有无法默认构造const成员：合成的拷贝赋值是delete
 
 */



#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    friend ostream& operator << (ostream &, const Sales_data &);
public:
    Sales_data() = default;
    Sales_data(const string& str) : bookn(str) {}

    Sales_data(const Sales_data&) = delete;
    Sales_data& operator=(const Sales_data&) = delete;

    
private:
    string bookn;
    int num = 1;
};

ostream& operator << (ostream & os, const Sales_data & rhs) {
    os << rhs.bookn << ' ' << rhs.num;
    return os;
}


int main()
{
    Sales_data a("Number1");
    cout << a << endl;
    
    Sales_data b;
    cout << b << endl;
    
//    Sales_data c(a);
//    Sales_data c = b;
    
    return 0;
}
