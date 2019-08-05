/*
函数
*/

#include <iostream>
#include <cstddef>


using std::cin;
using std::cout;
using std::endl;


// 函数局部静态对象，直到程序结束才销毁
size_t count_calls() 
{
    static size_t ctr = 0;
    return ++ctr;
}


int main() {
    
    for(size_t i = 0;  i != 10; ++i) {
        cout << count_calls() << endl;
    }


    return 0;
}
