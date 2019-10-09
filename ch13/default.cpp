/*
 默认构造函数：一定是不接受任何实参的构造函数，反之也是。
 合成的默认构造函数：当且仅当没有任何其他形的构造函数，包括自己定义的默认构造函数时，编译器才会创建
 默认构造函数可以与带参数的构造函数并存
 若没有默认构造函数：Sales_data a; 这样不带实参的对象创建报错。
 */



#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    
    friend ostream& operator << (ostream &, const Sales_data &);
public:
    Sales_data() = default;
    Sales_data(const string& str) : bookn(str) {}
    
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
    
    return 0;
}
