#include <iostream>
#include "StrVec.h"

using std::cin; using std::cout; using std::endl;

int main() {

    StrVec a;
    cout << a.capacity() << endl;
    cout << a.size() << endl;

    a.push_back(string("abc"));
    cout << a.capacity() << endl;
    cout << a.size() << endl;

    a.push_back(string("def"));
    cout << a.capacity() << endl;
    cout << a.size() << endl;

    a.push_back(string("hij"));
    cout << a.capacity() << endl;
    cout << a.size() << endl;

    StrVec b(a);
    cout << b.capacity() << endl;
    cout << b.size() << endl;

    a.push_back(string("klm"));
    b = a;
    cout << b.capacity() << endl;
    cout << b.size() << endl;

    string str[] = {"a", "bc", "def", "ghij", "klmno"};
    StrVec e(str, str + sizeof(str) / sizeof(*str));
    cout << e.capacity() << endl;
    cout << e.size() << endl;


    // 移动构造与赋值
    StrVec f(std::move(e));
    e = f;

    e = std::move(f);

    return 0;
}