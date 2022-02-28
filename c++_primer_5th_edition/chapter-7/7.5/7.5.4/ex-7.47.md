Exercise 7.47: Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the
constructor explicit? What are the drawbacks?

It should be explicit because I think it does not make sense to combine the data of a book with a new book without any data except for the isbn number.

Benefits: Flexibility, ok not to use constructor when we just want to use implicit conversion.
Drawback: (1)nly the constructors that can be called with a single argument are able to use it. (2)The constructed object is discarded later.
