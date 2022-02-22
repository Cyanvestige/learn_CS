// Exercise 7.5
#include <iostream>
#include <string>
#include "ex-7.9.h"
int main(){
    Person p1;
    std::cin >> p1.name >> p1.address;
    std::cout << "Name: " << p1.getName() << std::endl;
    std::cout << "Address: " << p1.getAddress() << std::endl;
}