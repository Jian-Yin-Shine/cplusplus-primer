/**
数组
**/


#include <iostream>
#include <string>
#include <vector>
#include <iterator> //数组begin(), end()函数
#include <cstddef>  //索引访问数组的下标类型

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() 
{
    // 初始化
    const int sz = 10;
    int arr[sz] = {0, 1, 2};
    int arr2[] = {0, 1, 2};
    char arr3[] = {'C', '+', '+'};
    char arr4[] = "C++"; // = {'C', '+', '+', '\0'}
   
    // 不允许拷贝和赋值
    //int a[] = arr;
    //a = arr;

    // 访问数组
    for(auto &c : arr4) {
        cout << c ;
    }


    for(int i = 0; i < 4; ++i) 
        cout << arr4[i];

    for(size_t i = 0; i < 4; ++i)
        cout << arr4[i];
    
    // 数组也是对象，也可以有数组的指针，数组的引用
    // 指针也是对象，数组里面可以指针
    // 数组里面只能存对象，不能存引用

    int *ptr[10];  // 数组里面存指针
    // int &ptrs[10] = 错误
    
    int (*Parray)[10] = &arr; // 指向arr数组的指针，大小必须为10
    int (&arrRef)[10] = arr;  // 数组arr的引用

    int *(&arry)[10] = ptr;

    // 指针和数组，这里的指针指的是数组元素的指针, 数组名是第一个元素的地址
    string nums[] = {"one", "two", "there"};
    string *p = &nums[0];
    cout << *p << *(p+1) << endl;
    
    string *p1 = nums;
    cout << *p1 << *(p+2) << endl;
    
    // 指针也是迭代器
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *parray = array;
    int *earray = &array[10];
    while(parray!=earray) {
        cout << *parray << endl;
        ++parray;
    }

    int *beg = begin(array);
    int *last = end(array);
    cout << last - beg << endl;

    while(beg != last) {
        cout << *beg << endl;
        ++beg;
    }
   
    // 指针和下标
    // 下标其实在编译的时候转为指针
    int ia[] = {0, 2, 4, 6, 8};
    int *iap = &ia[2];
    int j = iap[1];
    int k = iap[-2];

    return 0;    
}
