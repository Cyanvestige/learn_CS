/*
Exercise 7.32: Define your own versions of Screen and Window_mgr in
which clear is a member of Window_mgr and a friend of Screen.
*/
#ifndef MY_SCREEN_H
#define MY_SCREEN_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//we have to declare the "Screen" class before defining "Window" becuase "Windows" has a container for "Screen"
class Screen_With_AlterSize;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen_With_AlterSize>::size_type;
    // we need a constructor to create a new instance later
    Window_mgr();
    // added a method to check the ith element inside the screens vector
    Screen_With_AlterSize getScreen(ScreenIndex i);
    void clear(ScreenIndex);
private:
    // we cannot initialize screens now because the "Screen" class is incomplete until this point 
    vector<Screen_With_AlterSize> screens;
};



class Screen_With_AlterSize {
    // has the clear method from "Window" as a friend
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;  
    Screen_With_AlterSize() = default;
    Screen_With_AlterSize(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' '){ }
    Screen_With_AlterSize(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){ }
    Screen_With_AlterSize set(char);
    Screen_With_AlterSize set(pos, pos, char); 
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen_With_AlterSize move(pos r, pos c);
    Screen_With_AlterSize alterSize(double hp, double wp);
    Screen_With_AlterSize display(std::ostream &os) 
        { do_display(os); return *this; };
    const Screen_With_AlterSize &displsay(std::ostream &os) const 
        { do_display(os); return *this; }
    std::string contents;
private:
    void do_display(std::ostream &os) const{
        os << contents;
    }
    pos cursor = 0;
    pos height = 0, width = 0;
};

inline
char Screen_With_AlterSize::get(pos r, pos c) const{
    pos row = r * width;
    return contents[row + c];
}

inline
Screen_With_AlterSize Screen_With_AlterSize::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
Screen_With_AlterSize Screen_With_AlterSize::alterSize(double hp, double wp){
    height += height * hp;
    width += width * wp;
    std::string newScreen(height * width, contents[0]);
    contents.assign(newScreen);
    return *this;
}

inline
Screen_With_AlterSize Screen_With_AlterSize::set(char c){
    contents[cursor] = c;
    return *this;
}

inline
Screen_With_AlterSize Screen_With_AlterSize::set(pos row, pos column, char ch){
    contents[row * width + column] = ch;
    return *this;
}

inline
Screen_With_AlterSize Window_mgr::getScreen(ScreenIndex i){
    { return screens[i]; }
}

// use constructor to initialize "screens" to have one blank screen with height 2, width 2.
Window_mgr::Window_mgr() : screens{Screen_With_AlterSize(2,2)} {}

// define the clear method in Window_mgr after the "Screen" class is defined because it uses the "Screen" class;
void Window_mgr::clear(ScreenIndex i){
    // it is a friend of "Screen" so it can access all members in "Screen"
    Screen_With_AlterSize &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif