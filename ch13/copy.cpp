
/*
 拷贝构造
 */


#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    
    friend ostream& operator << (ostream &, const Sales_data &);
public:
    Sales_data() = default;
    Sales_data(const string& str) : bookn(str) {}
    
    Sales_data(const Sales_data&);
    
    
private:
    string bookn;
    int num = 1;
};

Sales_data::Sales_data(const Sales_data& org) : bookn(org.bookn), num(org.num) {
    
    cout << "拷贝构造 ";
}

ostream& operator << (ostream & os, const Sales_data & rhs) {
    os << rhs.bookn << ' ' << rhs.num;
    return os;
}


int main()
{
    Sales_data a("Number1"); // 直接构造
    cout << a << endl;
    
    Sales_data b;           // 默认构造
    cout << b << endl;
    
    Sales_data c(a);  // 拷贝构造，注意《C++ Primer》第五版P441页有错误，并且网络上绝大部份的博客都是错的
    cout << c << endl;
    
    Sales_data d = a; // 拷贝构造
    cout << d << endl;
    
    return 0;
}
