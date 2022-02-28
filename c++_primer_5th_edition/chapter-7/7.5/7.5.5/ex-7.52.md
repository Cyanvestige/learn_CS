Exercise 7.52: Using our first version of Sales_data from § 2.6.1 (p. 72),
explain the following initialization. Identify and fix any problems.

```
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

Sales_data item = {"978-0590353403", 25, 15.99};

We need to delete the initial values of units_sold and revenue
