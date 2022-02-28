Exercise 7.49: For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:
(a) Sales_data &combine(Sales_data); // correct, s will be constructed to a Sales_data and the method does its work

(b) Sales_data &combine(Sales_data&);// wrong, s will not be successfully constructed because we cannot refer to a temporary object which is what implicit conversion creates.

(c) Sales_data &combine(const Sales_data&) const; // wrong, combine should not be a const member function
