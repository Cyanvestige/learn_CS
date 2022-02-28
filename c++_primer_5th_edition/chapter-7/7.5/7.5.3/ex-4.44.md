Exercise 7.44: Is the following declaration legal? If not, why not?
vector&lt;NoDefault> vec(10);

It is illegal.
"NoDefault" does not have a default constructor, so vector cannot initialize it using the constructor with one parameter.(vector uses the default constructor of the element)
