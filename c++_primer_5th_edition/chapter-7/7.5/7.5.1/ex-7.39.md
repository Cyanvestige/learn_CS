Exercise 7.39: Would it be legal for both the constructor that takes a
string and the one that takes an istream& to have default arguments? If
not, why not?

Solution:
Not legal. The compiler does not know which default constructor it should go for
The error message is "error: call of overloaded ‘Sales_data()’ is ambiguous"
