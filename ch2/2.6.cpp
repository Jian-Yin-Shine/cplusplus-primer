/**
struct 自定义类型
**/
#include <iostream>
#include "Sales_data.h"
#include <string>

using namespace std;

int main() {
    Sales_data data1, data2;
    double price;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    
    std::cout << data1.bookNo << data1.units_sold << data1.revenue;

    return 0;    
}
