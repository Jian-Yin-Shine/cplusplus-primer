#ifndef __WINDOW_MGR__
#define __WINDOW_MGR__

#include <vector>
#include <string>
#include "Screen.h"

using namespace std;

class Window_mgr {
public:
    typedef vector<Screen>::size_type ScreenIndex;
    ScreenIndex addScreen(const Screen&);
    void clear(ScreenIndex);
    void resize(Screen::pos r, Screen::pos c, ScreenIndex i); 
private:
    vector<Screen> screens{Screen(24, 80, ' ')}; 
};

inline
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

inline
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

inline
void
Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i) {
    screens[i].height = r;
    screens[i].width = c;
    screens[i].contents = string(r*c, ' ');
}
#endif
