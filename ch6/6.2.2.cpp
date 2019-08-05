/*
数组作为参数
*/

#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

void prints(int *p) {
    cout << *p << endl;    
}

void prints_int_array(int *p) {
    if(p) {
        while(*p!=-1) {
            cout << *p++ << " ";
        }
        cout << endl;
    }    
}

// C 风格
// const char *p
// const char p[] 
// 虽然可以指向该数组对象，但是不能改变该对象
void prints_char_array(const char p[]) {
    if(p) {
        while(*p) {
            cout << *p++ << " ";    
        }
        cout << endl;
    }    
}

// C++ 风格
void cplusplus_prints(const int *beg, const int *end) {
    while(beg != end) {
        cout << *beg++ << " ";    
    }    
    cout << endl;
}

//打印二维数组，array 仍然是第一个元素的地址，用指针接住,
//              他解析是一个数组
void print_tow_array(int (*p)[3], int row) {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < 3; j++) { 
            cout << *(*(p+i) + j) << " " ;
        }
        cout << endl;
    }
    
}

int main() {
    int i = -1;
    int a[] = {1,2,3,-1};
    prints(&i);
    prints(a);
    
    char str[] = "abcd";
    prints_int_array(a);
    prints_char_array(str);

    cplusplus_prints(begin(a), end(a));
    
    int b[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    print_tow_array(b, 3);

    return 0;    
}
