#include "ex-7.24.h"
int main(){
    Screen_With_AlterSize swe(1,2,'h');
    std::cout << swe.get(0,1) <<"s";  
    swe.alterSize(1,1);
    std::cout << swe.get(2,3);              
}