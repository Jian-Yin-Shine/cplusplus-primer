#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
public:
    Account(): amount(0.0) { }
    Account(const string &s, double amt): owner(s), amount(amt) { }
    void calculate() {
        amount += amount * interestRate;
    }
    double balance() {
        return interestRate;
    }

public:
    static double rate() { return interestRate; }
    // 实现文件中定义
    static void rate(double);

private:
    string owner;
    double amount;
    // 实现文件中定义
    static double interestRate;
    static double initRate() { return .0225; }
    // 实现文件中定义
    static const string accountType;
    static const int period = 30;
    double dail_tbl[period];
};

#endif
