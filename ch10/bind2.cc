/*
1. bind, 将函数包装为算法能够接受的谓词
2. bind函数可以看作一个通用的函数适配器,返回一个新的可调用对象来“适应”算法
3. 一般形式：
    auto newCallable = bind(callable, arg_list);
    arg_list是原来可调用对象callable的参数
4. 需要给新的可调用的对象的参数，用_n表示
5. _n 在 placeholders中
6. 默认情况下：不是_n(占位符)的参数，通过值传递，要使用引用传递，使用ref,
    如果那个参数是const，还需要引用传递，使用cref, 都在 functional中
*/
// This file illustrates the use of bind and ref, which are
// functions in the C++ 11 library

#include <algorithm>
using std::for_each;

#include <functional>
using std::bind; using namespace std::placeholders;
using std::ref;

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream; 

#include <fstream>
using std::ifstream; using std::ofstream; 

ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

int main()
{
	string s;
	vector<string> words;
	while (cin >> s)
		words.push_back(s);

	for_each(words.begin(), words.end(), 
	         bind(print, ref(cout), _1, ' '));
	cout << endl;
    
    /*
	ofstream os("data/outFile1");
	for_each(words.begin(), words.end(), 
	         bind(print, ref(os), _1, ' '));
	os << endl;

	ifstream is("data/outFile1");
	istream_iterator<string> in(is), eof;
	for_each(in, eof, bind(print, ref(cout), _1, '\n'));
	cout << endl;
    */
	return 0;
}
