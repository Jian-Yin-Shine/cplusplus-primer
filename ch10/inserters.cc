/*
插入迭代器：插入迭代器接受一个容器，生成一个迭代器，能实现向给定容器添加元素
当使用一个插入迭代器进行赋值时，该迭代器调用容器操作向给定容器指定位置插入元素。

it = val, 迭代器赋值，直接调用容器的操作
注意：*it, ++it, it++ ：虽然存在，但是不对迭代器做任何事情。每次操作直接返回一个迭代器

*/

#include <algorithm>
using std::copy;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iterator>
using std::back_inserter;
using std::front_inserter;
using std::inserter;

void print(const string &label, const list<int> &lst) {
    cout << label << endl;
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";    
    }
    cout << endl;
}

int main()
{
    const int digits[] = {1,2,3,4,5,6,7,8,9};
    list<int> lst(digits, digits+4);
    print("lst", lst);
    
    list<int> lst2, lst3;
    copy(lst.begin(), lst.end(), front_inserter(lst2));
    print("lst2", lst2);

    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
    print("lst3", lst3);

    vector<int> v(digits, digits+5);
    list<int> new_lst(digits+5, digits+9);
    for(auto elem : v) cout << elem << " ";
    cout << endl;
    print("new_lst", new_lst);
    list<int>::iterator it = new_lst.begin();
    copy(v.begin(), v.end(), inserter(new_lst, it));
    print("new_lst", new_lst);
    
    vector<int> tmp;
    auto iter = back_inserter(tmp);
    iter = 1;
    iter = 2; // *iter = 2;
    for (auto elem : tmp) cout << elem << "****";
    cout << endl;
    return 0;    
}
