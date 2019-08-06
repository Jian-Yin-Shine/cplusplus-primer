/*
实参个数不一定，同类型
*/

#include <iostream>
#include <string>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::initializer_list;

// 里面必须是常数
void error_meg(initializer_list<string> il) {
    for(auto it = il.begin(); it!=il.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {
    error_meg({"abc", "abcd", "abcde"});
    error_meg({"a", "b", "c"});
    return 0;    
}

