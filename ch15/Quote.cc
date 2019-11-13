
#include "Quote.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

double print_total(ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << item.isbn() << n << ret << endl;
    return ret;
}

double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= quantity)
        return cnt * (1-discount) * price;
    else
        return cnt * price;
}

double Lim_quote::net_price(size_t cnt) const {
    size_t discounted = min(cnt, quantity);
    size_t undiscounted = cnt - discounted;
    return discounted * (1 - discount) * price + undiscounted * price;
}

int main() {
    Quote* ptr = new Quote("abc", 25);
    cout << *ptr << " " << ptr->net_price(100) << endl;
    
//    ptr = new Disc_quote("abcd", 30, 100, 0.5);
//    cout << *ptr << endl;
    ptr = new Bulk_quote("abcde", 30, 100, 0.5);
    cout << *ptr << " " << ptr->net_price(50) << endl;
    cout << *ptr << " " << ptr->net_price(120) << endl;
    
    ptr = new Lim_quote("abcdef", 30, 100, 0.5);
    cout << *ptr << " " << ptr->net_price(120) << endl;
    
    return 0;
}
