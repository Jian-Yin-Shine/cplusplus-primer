/*
默认实参:
1. 一旦某个实参被赋予默认值，后面的都要
2. 调用时，想要赋予某个有默认值的参数，前面的都要赋予
*/



#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef string::size_type sz;
string screan(sz ht, sz wid = 80, char backgrand = ' ') {
    return "2333333333";    
}



// 内联函数
inline const string &
shorterString(const string& str1, const string& str2) {
    return str1.size() <= str2.size() ? str1 : str2;    
}

// constexpr函数
// 用于常量表达式的函数
constexpr int new_sz() {return 42;}

// 函数匹配(寻找最佳匹配)
void f() { cout<< "no can shu"<<endl;}
void f(int) {cout << "one int"<<endl;}
void f(int, int) {cout << "two int"<<endl;}
void f(double, double = 3.14) {cout << "two double"<<endl;}



int main() {
    // 默认实参
    cout << screan(12) << endl;
    cout << screan(12, 75, 'a') << endl;
    
    // 内联函数
    string str1 = "abcd";
    string str2 = "ABC";
    cout << shorterString(str1, str2) << endl;
    
    // constexpr函数
    constexpr int foo = new_sz();

    // 重载函数的匹配
    f(5.6); //f(int), f(double, double=3.14)可选，但是后者精准匹配
    // f(42, 2.56); 二义型，f(int, int)，f(double, double = 3.14)同样需要转换
    return 0;    
}
