/*
Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
Y, and Y has an object of type X.
*/

#ifndef X_AND_Y_H
#define X_AND_Y_H
#include <iostream>
#include <string>
class X{
    Y *y;
};

class Y{
    X x;
}
#endif