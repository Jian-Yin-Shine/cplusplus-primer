#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

class Sales_data {

friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
    // Sales_data() = default;
    Sales_data(): units_sold(0), revenue(0.0) { }
    Sales_data(const string &s): bookNo(s), units_sold(0), revenue(0.0) { }
    Sales_data(const string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &);

    string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold;
    double revenue;
    
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);



#endif
