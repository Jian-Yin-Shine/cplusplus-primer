/*
 行为像指针的类(shared_ptr)
 */


#include <iostream>
#include <string>

using namespace std;

class hasptr {
public:
    hasptr(const string& str) : ptr (new string(str)), i(0), cnt( new int(1) ) {}
    ~hasptr();
    hasptr(const hasptr& org) : ptr (org.ptr), i(org.i), cnt(org.cnt) { ++*cnt; }
    hasptr& operator=(const hasptr& rhs);

private:
    string* ptr;
    int i;
    int* cnt;
};

hasptr::~hasptr() {
    if (--*cnt == 0) {
        delete ptr;
        delete cnt;
    }
}


// 防卫式赋值
hasptr&
hasptr::operator=(const hasptr& rhs) {
    if (this==&rhs)
        return *this;

    if (--*cnt == 0) {
        delete ptr;
        delete cnt;
    }
    ++*rhs.cnt;
    ptr = rhs.ptr;
    i = rhs.i;
    cnt = rhs.cnt;
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
