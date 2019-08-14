#include <string>
#include "Account.h"

using namespace std;

void Account::rate(double newRate) {
    interestRate = newRate;    
}

double Account::interestRate = initRate();
const string accountType("Savings Account");

