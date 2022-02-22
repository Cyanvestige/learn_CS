// Exercise 7.15 Added appropriate constructors to your Person class
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
struct Person{
    Person() = default;
    Person(const std::string& n, const std::string& a): name(n), address(a) { }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string name;
    std::string address; 
};
std::ostream& read(std::istream&, Person&);
std::istream& print(std::ostream&, const Person&);


std::istream& read(std::istream& is, Person& p){
    is >> p.name >> p.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& p){
    os << "Name: " << p.getName() << std::endl;
    os << "Address: " << p.getAddress();
    return os;
}
#endif