/**
string的一些函数
empty
size
size_type
==
< 
<=
>
>=
!=
+
**/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    
    string str1("Hello");
    string str2("World");

    // + 
    cout << str1 + str2 << endl;
    // >
    cout << (str1 > str2) << endl;
    
    // + 一个字面值
    cout << str1 + "abc" << endl;
    
    //索引
    for(decltype(str1.size()) i = 0; i != str1.size(); ++i) 
        cout << str1[i];
    cout << endl;

    for(auto c : str1)
        cout << c;
    cout << endl;

    for(auto &c : str1) 
        c += 1;
    cout << str1 << endl;
    return 0;    
}
