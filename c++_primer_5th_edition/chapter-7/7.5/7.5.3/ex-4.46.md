Exercise 7.46: Which, if any, of the following statements are untrue? Why?
(a) A class must provide at least one constructor.
false. If we do not define any constructor, the compiler will generate a synthesized default constructor/

(b) A default constructor is a constructor with an empty parameter list.
false. If we define a constructor that initializes all members to its default value. Then it is also a default constructor

(c) If there are no meaningful default values for a class, the class should not provide a default constructor.
false. We should always make class provide a default constructor because sometimes we cannot use the class without default constructor(like "vector&lt;NoDefault> nd(10);"in ex-4.45)

(d) If a class does not define a default constructor, the compiler generates
one that initializes each data member to the default value of its associated
type.
false. If there is any other constructor, the system will not generate a default constructor/
