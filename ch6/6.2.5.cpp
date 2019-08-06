/*
返回类型
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// 有返回值的，也有没返回值的。

// 1. 如果返回值不是引用，则就会拷贝
//    同形参一样，拷贝代价大，最好返回引用
//    不要返回局部对象的引用和指针，他们本体被释放掉了。

// s1, s2是引用，const修饰，然后不能通过引用修改对象
// 返回值是引用，因此可以作为左值，也就是 = 的左边
// 返回值用const修饰，也就是 const string& ，也就是说如果作为右值，则类型要匹配。
const string& shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;   
}

// 要求返回引用
char &get_val(string &str, string::size_type idx) {
    return str[idx];    
}

// 返回列表，用{}, 无需像形参数一样用{} initializer_list
vector<string> process() {
    return {"abc", "edf"};    
}

// 返回指针
// 返回数组的指针
// int (*p)[10] = &arry // p是一个指针，指向的对象是数组
//                      返回这样的指针的函数，函数的形参写在函数名后面

// 函数fun(int i) 形参 int i, 返回指针，指向的对象是大小为10的数组，大小一定要指定
// int (*fun(int i)) [10] { }
// auto fun(int) -> int(*)[10];

// 如果知道指针指向的哪个数组，就可以用decltype(obj) 也是推断类型，不忽略顶层const
// odd数组名表示&odd[0],第一个对象的地址，指针接住后可以移动。
// &odd 表示数组这个对象的地址
// decltype返回odd的类型，表示数组，这里返回数组(这个对象)的指针
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) {
    return (i%2) ? &odd : &even;
}

int main() {
    string str1 = "abc";
    string str2 = "ABCD";
    
    const string &ans =  shorterString(str1, str2);
    cout << ans << endl;
    
    get_val(str1, 0) = 'A'; // 引用作为左值, 返回指针同理，可以 = 0;
    cout << str1 << endl;
    
    vector<string> mes = process();
    for(auto it = mes.begin(); it != mes.end(); ++it) 
        cout << *it << endl;
    
    int (*p)[5] = arrPtr(1);
    for(int i = 0; i < 5; i++) {
        cout << *((*p) + i) << " ";    
    }
    cout << endl;


    return 0;    
}


