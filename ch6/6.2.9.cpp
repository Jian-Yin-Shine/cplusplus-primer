/*
函数指针:指向函数的指针
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool lengthCompare(const string& str1, const string& str2) {
    return str1.size() == str2.size();    
}

// 函数指针做形参
void useBigger(const string& str1, const string& str2, bool (*pf)(const string& str1, const string& str2)) {
    if (pf(str1, str2)) {
        cout << "Yes" << endl;    
    }
    else {
        cout << "No" << endl;
    }
}
// 函数指针做形参太长, 用 typedef 和类型推断decltype



int main() {
    string str1 = "abc";
    string str2 = "ABC";
    
    bool (*pf)(const string&, const string&);
    
    pf = &lengthCompare; // 类型同样要进行匹配检查
                        // 或者直接用函数名(函数名做值使用时候，自动转为函数的地址
                        //                  不同于数组，数组名字是第一个元素的地址)

    cout << (*pf)(str1, str2) << endl; // 或者不解引用
    cout << pf(str1, str2) << endl;
    
    // 重载函数的指针也同样要做类型检查，匹配之类的。

    useBigger(str1, str2, lengthCompare); 
    
    // typedef decltype(lengthCompare) Func2;
    // typedef decltype(lengthCompare) *FuncP2
    // 推断出函数的类型后，定义这个类型的别名，Func2 和FuncP2(指针)
    // useBigger的声明可以用
    // void useBigger(const string&, const string &b, FuncP2) or Func2，函数名自动转为指针

    // 函数指针做返回值
    // 返回函数的指针，必须是指针形式，不会自动转成函数指针
    // 类型别名：typedef int INT, using INT = int
    // using F  = int(int *, int) // F是函数类型，不是函数指针
    // using PF = int(*)(int *, int); // PF是函数指针
    // PF f1(int); // 函数f1接受一个int类型参数，返回一个函数指针
                // 这个函数指针指向一个函数（参数是int *p, int,  返回一个int)
    // 或者不用类型别名，用auto
    // auto f1(int) -> int (*)(int *, init)
    return 0;    
}
