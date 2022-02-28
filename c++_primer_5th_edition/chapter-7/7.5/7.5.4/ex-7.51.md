Exercise 7.51: Why do you think vector defines its single-argument constructor as explicit, but string does not?
We do not want any type other than "int" to be passed to the parameter and used as the size of the vector(like a char)
However, it is not a problem when we try to construct a new string.
