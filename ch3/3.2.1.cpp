/**
String
**/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    
    //初始化
    string s1;      // 空字符串
    string s2(s1);  // s1的一个副本, 两个不同的对象
    // string s2 = s1    
    string s3("abc"); // 字面值的一个副本
    string s4 = "abcd"; // 等价于 string s4 = string("abcd")
    
    string s5(5, 'c');  //重复c5遍
    
    cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << endl;

    //读写, string对象自动忽略开头的空白，从第一个真正的字符开始读起，直到下一个空白
    cin >> s1 >> s2;
    cout << s1 << s2 <<  endl;
    
    //未知数量的string对象
    // 直到文件结束，或者非法输入
    /*
    while(cin >> s1) 
        cout << s1 << endl;
    */

    //getline读取一行，包括空白符
    // 注意：getline读入换行，但是存入string时，丢弃了换行
    while(getline(cin, s1)) {
        cout << s1 << endl;
    }

    return 0;    
}
