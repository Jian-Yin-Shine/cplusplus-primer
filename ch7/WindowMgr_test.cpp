#include <iostream>
#include "WindowMgr.h"
#include "Screen.h"

using namespace std;

int main() {
    Screen a(3, 5, 'a');
    Window_mgr win;
    win.addScreen(a);
    win.resize(3, 5, 0);

    return 0;    
}
