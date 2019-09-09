/*
1. 标准形式：[捕捉变量](参数列表) -> (返回类型){函数体}
2. 向lambda传递参数(参数列表)
    泛型算法需要的参数个数，sort(iter.begin(), iter.end(),[](const int& a, const int&b){a < b;});
3. 如果需要局部的变量，使用捕获变量
    find_if(words.begin(), words.end(), [sz](const string & a){ return a.size() >= sz;});
4. 一般来说函数体里面的返回类型可以通过推断，但是复杂的不行。简单的包括，只有return , return 一个条件表达式，如果写成了if就不可以了，要用 -> int, -> bool
5. lambda实际是生成一个无类型，无名字的对象，参数有几个就生成几个，捕获的变量就是对象的数据
部分。定义出这个对象时，数据部分就确定了，数据部分的初始化也分为值传递，引用传递
6. 隐式捕获，= , & 值捕获，引用捕获
7. 默认定义了lambda对象后，数据部分不会改变，如果在函数体中要修改，或者要调用()调用操作符，修改数据部分，使用关键字 mutable
*/

#include <vector>
#include <string>
#include <iostream>
using std::cout; using std::endl; using std::vector; using std::string;

// five functions illustrating different aspects of lambda expressions

void fcn1()
{
	size_t v1 = 42;  // local variable
	// copies v1 into the callable object named f
	auto f = [v1] { return v1; };
	v1 = 0;
	auto j = f(); // j is 42; f stored a copy of v1 when we created it
	cout << j << endl;
}

void fcn2()
{
	size_t v1 = 42;  // local variable
	// the object f2 contains a reference to v1 
	auto f2 = [&v1] { return v1; };
	v1 = 0;
	auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
	cout << j << endl;
}

void fcn3()
{
	size_t v1 = 42;  // local variable
	// f can change the value of the variables it captures
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	auto j = f(); // j is 43
	cout << j << endl;
}

void fcn4()
{
	size_t v1 = 42;  // local variable
	// v1 is a reference to a nonconst variable
	// we can change that variable through the reference inside f2
	auto f2 = [&v1] { return ++v1; };
	v1 = 0;
	auto j = f2(); // j is 1
	cout << j << endl;
}

void fcn5()
{
    size_t v1 = 42;
	// p is a const pointer to v1
    size_t* const p = &v1;
	// increments v1, the objet to which p points
    auto f = [p]() { return ++*p; };
    auto j = f();  // returns incremented value of *p
    cout << v1 << " " << j << endl; // prints 43 43
    v1 = 0;
    j = f();       // returns incremented value of *p
    cout << v1 << " " << j << endl; // prints 1 1
}


int main()
{
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	fcn5();
	return 0;
}
