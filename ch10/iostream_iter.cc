/*
输入流迭代器：
插入迭代器绑定在容器上，输入流迭代器不是绑定在容器上。
                        而是绑定在到一个流(cin等)上，并且指定将要读写的对象类型
                                                    (int或者自定义类型，重载了>>)
不同于插入迭代器，*, ++, 有含义
                *in 返回从流中读取的值
                ++in, in++, 使用元素类型所定义的>>运算符从输入流中读取下一个值

输出流迭代器：
    同插入迭代器，*, ++没有操作
                *out, ++out, ou++, 不对out做任何操作
    只要out = val, 用<< 运算法将val写入到out所绑定的输出流对象上ostream上，并且val的
                    类型必须与out可以写的类型兼容
    但是，为了保证与输入流对象相同，则还是使用
*/
#include <algorithm>
using std::copy; using std::sort; using std::unique_copy;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

int main() 
{
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;
    
    vector<int> v;
    while(int_it != int_eof) {
        v.push_back(*int_it);
        int_it ++;
    }
    
    ostream_iterator<int> out(cout, " ");
    for (auto elem : v) 
        out = elem;
    cout << endl;
    
    return 0;    
}
