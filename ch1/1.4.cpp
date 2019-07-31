/*
while循环
for 循环
读取数量不定的输入数据
*/

#include <iostream>

int main() {
    
    // while 循环1+2+...+10
    int sum = 0;
    int i = 1;

    while(i <= 10) {
        sum += i;    
        i +=1;
    }
    
    std::cout << sum << std::endl;

    // for
    sum  = 0;
    for(int i = 1; i <= 10; ++i) 
        sum+=i;

    std::cout << sum << std::endl;
    

    // 读取数量不定的输入数据
    std::cout << "输入整数数据求和" << std::endl;
    int value= 0;
    sum  = 0;
    while(std::cin >> value) {
        sum += value;    
    }
    
    std::cout << "全部求和得" << sum << std::endl; 

    return 0;    
}
