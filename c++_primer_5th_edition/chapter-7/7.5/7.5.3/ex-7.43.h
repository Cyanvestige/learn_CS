/*
Exercise 7.43: Assume we have a class named NoDefault that has a
constructor that takes an int, but has no default constructor. Define a class
C that has a member of type NoDefault. Define the default constructor for
C.
*/
#ifndef C_H
#define C_H
class NoDefault {
public:
    NoDefault(int i) : integer(i) {}
private:
    int integer;
};

class C{
public:
    C(): nd(0) {}
private:
    NoDefault nd;
};
#endif