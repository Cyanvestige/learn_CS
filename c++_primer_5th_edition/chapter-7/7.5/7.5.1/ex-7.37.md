Exercise 7.37: Using the version of Sales_data from this section,
determine which constructor is used to initialize each of the following
variables and list the values of the data members in each object:

```
class Sales_data {
public:
    // defines the default constructor as well as one that takes a string argument
    (A)Sales_data(std::string s = ""): bookNo(s) { }
    // remaining constructors unchanged
    (B)Sales_data(std::string s, unsigned cnt, double rev):
          bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
    (C)Sales_data(std::istream &is) { read(is, *this); }
    // remaining members as before
};
```

Solution:

```
Sales_data first_item(cin); // construector C
int main() {
    Sales_data next; // constructor A
    Sales_data last("9-999-99999-9"); // constructor A
}
```
