/*
C 风格字符串:
C的字符串都是char 数组
strlen
strcpy
strcat
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() {
    char cstr[] = {'a', 'b', 'c', '\0'};
    cout << strlen(cstr) << endl;
    
    string str = cstr;
    cout << str << endl;
    
    // string转char *
    const char *p = str.c_str();
    while(*p != '\0') {
        cout << *p << endl;
        ++p;
    }

    // 用数组出事话vector
    int int_arr[]= {0, 1, 2, 3, 4, 5};
    
    vector<int> ivec(begin(int_arr), end(int_arr));
    cout << ivec.size() << endl;
    for(auto i : ivec) 
        cout << i << endl;

    return 0;
}
