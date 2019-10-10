/*
阻止拷贝
 2. 放在private区域
 */



#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    // 无访问说明符，private
    Sales_data(const Sales_data&);
    Sales_data& operator=(const Sales_data&);
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
    
//    Sales_data c(a);
//    Sales_data c = b;
    
    return 0;
}
