/*
const_cast
对两个非常量操作，但是函数中不能修改，并且返回他的引用；这是返回值必须用const修饰；
但是这里变脸又是非常量，存在冲突，修改方案是const_cast
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// const_cast 和重载
const string &shorterString(const string &str1, const string &str2) {
    cout << "return const string &" << endl;
    return str1.size() <= str2.size() ? str1 : str2;    
}

// 上述返回的引用是const，如果需要一个普通的引用
string &shorterString(string &str1, string &str2) {
    cout << "const_cast" << endl;
    auto &r = shorterString(const_cast<const string&>(str1),
                  const_cast<const string&>(str2));    
    // auto &r 得到一个引用，绑定在const string 的对象上
    return const_cast<string&>(r);
}

int main() {
    
    const string str1 = "abcd";
    const string str2 = "ABC";
    string str3 = "abcd";
    string str4 = "ABC";
    cout << shorterString(str1, str2) << endl;
    cout << shorterString(str3, str4) << endl;
    shorterString(str3, str4)[0] = 'a';
    cout << str4 << endl;
    return 0;    
}
