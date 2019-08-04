/**
vector : 对象的集合，容器，类模版

形式：
vector<int> ivec;
vector<Sales_item> Sales_vec;
vector<vector<string> > file;

初始化方式：

vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;

vector<T> v3(n, val);
vector<T> v4(n);

vector<T> v5{a,b,c};
vector<T> v5 = {a,b,c};
**/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    // 列表初始化
    vector<string> vs1 = {"a", "b"};
    vector<string> vs2{"a", "b"};

    // 元素个数
    vector<int> vs3(10,-1);
    vector<string> vs4(10, "a");
    
    // 元素个数，忽略初始值
    vector<int> vs5(10);
    vector<string> vs6(10);

    // 列表初始化不能表示元素时，用元素个数
    vector<string> vs7 = {10, "a"};
    vector<string> vs8{10, "a"};
    // 列表初始化不能表示元素，并不带初始化
    vector<string> vs9{10};  //但是不能 = {10}; 也不能(10)



    return 0;    
}
