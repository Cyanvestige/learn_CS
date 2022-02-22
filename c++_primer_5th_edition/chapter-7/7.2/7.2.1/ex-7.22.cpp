// Exercise 7.22: Update your Person class to hide its implementation
#include <iostream>
#include <string>
class Person{
friend std::ostream& print(std::ostream&, const Person&);
friend std::istream& read(std::istream&, Person&);
public:
    Person() = default;
    Person(const std::string& n, const std::string& a): name(n), address(a) { }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:
    std::string name;
    std::string address; 
};
std::ostream& print(std::ostream&, const Person&);
std::istream& read(std::istream&, Person&);


std::istream& read(std::istream& is, Person& p){
    is >> p.name >> p.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& p){
    os << "Name: " << p.getName();
    os << "Address: " << p.getAddress();
    return os;
}

int main(){
    Person p("1","2");
    print(std::cout, p);
}