
/*
 改变个别成员的可访问性
 */

#include <iostream>
#include <cstddef>

using namespace std;


class Base {
public:
    size_t size() const { return n; }
protected:
    size_t n;
};

class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
};



int main()
{
    Derived* ptr = new Derived();
    ptr->size();
    
    return 0;
}
