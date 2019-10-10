/*
 行为像值的类(string)
 */


#include <iostream>
#include <string>

using namespace std;

class hasptr {
public:
    hasptr(const string& str) : ptr (new string(str)), i(0) {}
    ~hasptr() { delete ptr; }
    
    hasptr(const hasptr& org) : ptr (new string(*org.ptr)), i(org.i) {}
    hasptr& operator=(const hasptr& rhs);

private:
    string* ptr;
    int i;
};


// 防卫式赋值
hasptr&
hasptr::operator=(const hasptr& rhs) {
    if (this==&rhs)
        return *this;
    delete ptr;
    ptr = new string(*rhs.ptr);
    i = rhs.i;
    return *this;
}

int main()
{
    string s("abc");
    hasptr a(s);
    
    hasptr b(a);
    b = a;
    
    return 0;
}
