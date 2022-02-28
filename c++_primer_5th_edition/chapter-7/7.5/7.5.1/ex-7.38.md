Exercise 7.38: We might want to supply cin as a default argument to the
constructor that takes an istream&. Write the constructor declaration that
uses cin as a default argument.

```
class Sales_data {
public:
    // defines the default constructor as well as one that takes a string argument
    Sales_data(std::string s): bookNo(s) { }
    // remaining constructors unchanged
    Sales_data(std::string s, unsigned cnt, double rev):
          bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
    Sales_data(std::istream &is = std::cin) { read(is, *this); }
    // remaining members as before
};
```
