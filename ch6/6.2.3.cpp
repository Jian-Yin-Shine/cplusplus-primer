/*
main:处理命令行选项
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//           形参个数，  argv是数组，然后里面是char指针
int main(int argc, char *argv[]) {
    
    for(int i = 0; i < argc; ++i) 
        cout << argv[i] << endl;
    
}
