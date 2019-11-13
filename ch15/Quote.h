
#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <cstddef>
#include <memory>

using namespace std;

class Quote {
    friend istream& operator >> (istream&, Quote&);
    friend ostream& operator << (ostream&, const Quote&);
    

public:
    Quote(): price(0.0) { }
    Quote(const string& book, double sales_price) : bookNo(book), price(sales_price) { }
    
    virtual ~Quote() {}
    
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n*price; }
    
    // 虚函数返回，自身的动态分配的副本
    virtual Quote* clone() const { return new Quote(*this); }
    
private:
    string bookNo;
protected:
    double price;
};

ostream& operator << (ostream& os, const Quote& a) {
    os << a.bookNo << " " << a.price;
    return os;
}

istream& operator >> (istream& is, Quote& a) {
    is >> a.bookNo >> a.price;
    return is;
}

class Disc_quote : public Quote {
public:
    Disc_quote(): quantity(0), discount(0.0) { }
    Disc_quote(const string& book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }
    
    double net_price(size_t) const = 0;
    
    pair<size_t, double> discount_policy() const {
        return make_pair(quantity, discount);
    }
    
protected:
    size_t quantity;    // 打折阈值
    double discount;    // 打折
};

class Bulk_quote : public Disc_quote {
    
public:
    Bulk_quote() { }
    Bulk_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) { }
    
    double net_price(size_t) const;
    Bulk_quote* clone() const { return new Bulk_quote(*this); }
};

class Lim_quote : public Disc_quote {

public:
    Lim_quote(const string& book="", double sales_price =0.0, size_t qty = 0, double disc_rate = 0.0) : Disc_quote(book, sales_price, qty, disc_rate) { }
    
    double net_price(size_t) const;
    
    Lim_quote* clone() const { return new Lim_quote(*this); }
};

double print_total(ostream&, const Quote&, size_t);




#endif
