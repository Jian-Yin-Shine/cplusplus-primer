/**
vector其他操作：
push_back
empty()
size()
==
!=
<, <=, >, >=
vector<int>::size_type
string::size_type
vector<int>::iterator
vector<int>::const_iterator


迭代器运算
iter + n
iter - n
iter1 - iter2
<, <=, >, >=

**/


#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    
    vector<int> v1, v2;
    for(int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i);
    }
    
    // c++11 引用访问
    for(auto &i : v2) 
        i+=1;

    // 迭代器访问
    // *it返回迭代器所指元素的引用
    for(auto it = v2.begin(); it != v2.end(); ++it) 
        *it +=1;

    for(vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it) 
        cout << *it << " ";
    cout << endl;

    cout << (v1 > v2) << endl;

    // const修饰的vector必须用const的迭代器
    const vector<string> vs = {10, "a"};
    for(vector<string>::const_iterator it = vs.begin(); it != vs.end(); ++it) 
        cout << *it;
    cout << endl;

    return 0;    
}

