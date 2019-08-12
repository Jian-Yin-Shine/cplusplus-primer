#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
    // 类型成员：在类中定义某种类型的别名
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }
        
    // 成员函数默认inline
    char get() const {
        return contents[cursor];   
    }
    // 显式声明了inline
    // 重载了成员函数
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    
    // 可变数据成员mutable
    void some_member() const;
    
    // 返回*this的成员函数
    Screen &set(char);
    Screen &set(pos, pos, char);
    
    // const 成员函数返回*this
    // const 修饰成员函数，this 的类型是 const Sales_data * const this
    // 返回 *this, 则返回类型应该是(用这个接受) const Sales_data &
    // 然后使用
    // Screen myScreen;
    // myScreen.display(cout).set('*')
    // 出错，因为display版本返回的是const 对象，不能对const对象修改。

    // 基于const的重载
    // 矛盾：
    // 1. 非常量函数，常量对象不可用，即 this是指向常量的指针，非常量函数里面的this没有const修饰
    // 2. 非常量对象，可以调用普通函数，也可以调用常量函数。调用常量函数的时候，this指针原本是指向普通对象，const修饰的函数，this指针是指向const对象的，于是非常量对象也可以使用const函数
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;    
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    mutable size_t access_ctr;  // 即使一个const成员函数也能修改他

    void do_display(ostream& os) const {
        os << contents;    
    }
};

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
void Screen::some_member() const {
    ++access_ctr;    
}

inline
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;
    return *this;
}


#endif
