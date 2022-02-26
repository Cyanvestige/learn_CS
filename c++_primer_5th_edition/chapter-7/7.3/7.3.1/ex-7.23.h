/* Exercise 7.23: Write your own version of the Screen class. */
#ifndef SCREEN_WITH_ENLARGE_DATA_H
#define SCREEN_WITH_ENLARGE_DATA_H
#include <iostream>
#include <string>
class Screen_With_AlterSize {
public:
    typedef std::string::size_type pos;  
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen_With_AlterSize &move(pos r, pos c);
    // arguments are percentage of size change
    Screen_With_AlterSize &alterSize(double hp, double wp);
    std::string contents;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    
};
#endif