#include <iostream>
#include <string>
#include "Screen.h"

using namespace std;

int main() {
    Screen a(3,5,'a');
    a.set('#').display(cout);
    
    const Screen b(3, 5, 'b');
    b.display(cout);
    return 0;    
}
