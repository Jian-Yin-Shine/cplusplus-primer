/*
多维数组
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() 
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for(size_t i = 0; i != rowCnt; ++i) 
        for(size_t j = 0; j != colCnt; ++j) 
            ia[i][j] = i * colCnt + j;
    
    //多维数组与指针
    int (*p)[4] = ia; //多维数组名字，还是数组的名字，也就是返回第一个元素的地址，指针接住，指向的对象是，一个数组大小为4的int
    p = &ia[2];

    for(const auto &row : ia)
        for(auto col : row)
            cout << col << endl;
    // p 是指针，指向一个数组对象，要想遍历指向的对象，那先解引用，然后返回数组，数组名是第一个元素的地址, 指针接住； 
    for(auto p = ia; p != ia+3; ++p) {
        for(auto q = *p; q != *p + 4; ++q) {
            cout << *q << " ";    
        }
        cout << endl;
    }

    return 0;    
}
