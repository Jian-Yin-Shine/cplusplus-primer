/*
 行为像值的类(string)的交换操作
 */


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class hasptr {
    friend ostream& operator << (ostream&, const hasptr&);
    friend void swap(hasptr &, hasptr &);
public:
    hasptr(const string& str) : ptr (new string(str)), i(0) {}
    ~hasptr() { delete ptr; }
    
    hasptr(const hasptr& org) : ptr (new string(*org.ptr)), i(org.i) {cout << "拷贝构造" << endl;}
//    hasptr& operator=(const hasptr& rhs);
    hasptr& operator=(hasptr);

private:
    string* ptr;
    int i;
};


// 防卫式赋值
//hasptr&
//hasptr::operator=(const hasptr& rhs) {
//    if (this==&rhs)
//        return *this;
//    delete ptr;
//    ptr = new string(*rhs.ptr);
//    i = rhs.i;
//    return *this;
//}




ostream&
operator << (ostream& os, const hasptr& a) {
    os << a.ptr << "->" << *a.ptr;
    return os;
}

inline
void swap(hasptr &lhs, hasptr &rhs) {
    cout << "my swap ";
    std::swap(lhs.ptr, rhs.ptr);
    std::swap(lhs.i, rhs.i);
}

// 防卫式赋值2
// 注意：此时的传递是拷贝构造
hasptr&
hasptr::operator=(hasptr rhs) {
    cout << "****************" << endl;
    cout << rhs << endl;
    swap(*this, rhs);
    return *this;
}

int main()
{
    hasptr a(string("abc"));
    hasptr b(string("cde"));
    cout << a << endl;
    cout << b << endl;
    
    swap(a, b);         // 标准库中的swap，是利用了第三方变量来实现，hasptr tmp = v1; v1 = v2; v2 = tmp;
    cout << a << endl;  // 由于我们类是类似值，重载了拷贝赋值，会重新创建一个临时的对象，消耗空间。
    cout << b << endl;
    
    a = b;              // 防卫式赋值2，值传递给rhs; rhs是b的一个副本
    cout << a << endl;
    
    a = a;
    cout << a << endl;
    
    
    
    return 0;
}
