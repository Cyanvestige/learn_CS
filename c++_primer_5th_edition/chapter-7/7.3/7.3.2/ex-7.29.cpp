/*
Exercise 7.29: Revise your Screen class so that move, set, and display
functions return Screen and check your prediction from the previous
exercise.
*/
#include <iostream>
#include <string>
using namespace std;
class Screen_With_AlterSize {
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

int main(){
    Screen_With_AlterSize myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    /*
    XXXXXXXXXXXXXXXXXXXX#XXXX
    XXXXXXXXXXXXXXXXXXXXXXXXX
    */
}