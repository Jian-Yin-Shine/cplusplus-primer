/*
1. 泛型算法:算法永远只执行于迭代器上，不执行容器的操作
2. 由于算法只操作迭代器，可以读取，写入，移动元素，但是不改变容器的大小，
    即不能直接添加、删除元素。
    除：back_instert迭代器外。
具体
find, accumulate, equal
fill, fill_n, back_inserter, copy, replace, replace_copy

*/

// 只读算法
// 写入算法
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <list>
using std::list;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::back_inserter;
using std::begin;
using std::end;

#include <algorithm>
using std::equal;
using std::fill; using std::fill_n;
using std::copy;
using std::replace;
using std::replace_copy;

#include <iostream>
using std::cin; using std::cout; using std::endl;

// 找, 算算法
// accumulate 
// find

// 写入
// fill(开始位置，结束位置，val)
// fill_n(开始位置，n , val)

// 插入迭代器
// back_inserter;

int main() 
{
    vector<int> vec(10);    
    fill(vec.begin(), vec.end(), 1);
    
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << sum << endl;
    vector<string> v;
    v.push_back("abc");
    v.push_back("def");
    cout << accumulate(v.begin(), v.end(), string("begin")) << endl;

    fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
    for(auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;

    fill_n(vec.begin() + vec.size() / 2, 5, 2);
    for(auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;
    
    // back_inserter() 接受容器的一个引用，返回一个与该容器绑定的迭代器
    // 解引用此迭代器，调用push_back
    auto it = back_inserter(vec);
    *it = 42;
    for(auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;

    fill_n(back_inserter(vec), 4, 42);
    for(auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;
    
    // equal(第一个容器的开始地址，第一个容器的结束地址，第二个容器的开始地址)
    // 两个容器的元素类型不一样也没关系，只要能用==进行元素比较即可
    // 假设第二个容器至少和第一个容器至少一样长
    const char* temp1[] = {"hello", "so long"};
    const char* temp2[] = {"hello", "so long", "tata"};
    list<const char*> roster1(temp1, temp1+sizeof(temp1)/sizeof(*temp1));
    list<string> roster2(temp2, temp2+sizeof(temp2)/sizeof(*temp2));

    cout << equal(roster1.begin(), roster1.end(), roster2.begin()) << endl;
    

    // copy(第一个容器的开始地址，第二个元素的结束地址，目的地)
    // ret指向拷贝到a2的尾元素之后的位置
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1)/sizeof(*a1)];
    
    auto ret = copy(begin(a1), end(a1), a2);
    for (auto it = a2; it != ret; ++it) cout << *it << " ";
    cout << endl;

    // replace(开始地址，结束地址，原来值，修改值) 
    // 一般算法会提供一个拷贝版本
    // replace_copy(开始地址，结束地址，目的地址，原来值，修改值)
    replace(a2, ret, 0, 42);
    for (auto it = a2; it != ret; ++it) cout << *it << " ";
    cout << endl;
    vector<int> vtemp1 = {0, 2, 3, 4};    
    vector<int> vtemp2;
    replace_copy(vtemp1.begin(), vtemp1.begin() + 3, back_inserter(vtemp2),0, 5);
    for(auto it = vtemp2.begin(); it != vtemp2.end(); it++) cout << *it << " ";
    cout << endl;
    
    // 重排
    return 0;    
}
