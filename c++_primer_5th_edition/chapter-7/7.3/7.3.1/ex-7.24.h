/* Exercise 7.24: Give your Screen class three constructors: a default
constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor
that takes values for height, width, and a character to use as the contents of the screen. */
#ifndef SCREEN_WITH_AlterSize_DATA_H
#define SCREEN_WITH_AlterSize_DATA_H
#include <iostream>
#include <string>
class Screen_With_AlterSize {
public:
    typedef std::string::size_type pos;  
    Screen_With_AlterSize() = default;
    Screen_With_AlterSize(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' '){ }
    Screen_With_AlterSize(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){ }
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen_With_AlterSize &move(pos r, pos c);
    Screen_With_AlterSize &alterSize(double hp, double wp);
    std::string contents;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    
};

inline
char Screen_With_AlterSize::get(pos r, pos c) const{
    pos row = r * width;
    return contents[row + c];
}

inline
Screen_With_AlterSize &Screen_With_AlterSize::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
Screen_With_AlterSize &Screen_With_AlterSize::alterSize(double hp, double wp){
    height += height * hp;
    width += width * wp;
    std::string newScreen(height * width, contents[0]);
    contents.assign(newScreen);
    return *this;
}
#endif