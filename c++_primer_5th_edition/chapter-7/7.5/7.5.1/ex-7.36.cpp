/*Exercise 7.36: The following initializer is in error. Identify and fix the
problem.*/
#include <iostream>
struct X {
    X(int i, int j): base(i), rem(base % j) { }
    int base, rem; //"int rem, base" order of definition is wrong
};

int main(){
    X x(3,2);
    std::cout << x.base << x.rem;
    return 0;
}