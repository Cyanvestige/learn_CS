Exercise 7.48: Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions
Click here to view code image

```
string null_isbn("9-999-99999-9");
```

Defines a string "9-999-99999-9" with constructor of "string"

```
Sales_data item1(null_isbn);
```

Defines a Sales_data object whose isbn is "9-999-99999-9" with constructor of "Sales_data"

```
Sales_data item2("9-999-99999-9");
```

First it implicitly converts the parameter to a string object by calling the constructor of "string", then it calls the constructor of "Sales_data".

What happens if the Sales_data constructors are explicit?
