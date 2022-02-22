// Exercise 7.9 Added read and input to Persion objects
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
struct Person{
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string name;
    std::string address; 
};
std::ostream& read(std::ostream&, Person&);
std::istream& print(std::istream&, const Person&);


std::istream& read(std::istream& is, Person& p){
    is >> p.name >> p.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& p){
    os << "Name: " << p.getName();
    os << "Address: " << p.getAddress();
    return os;
}

#endif