Exercise 7.58: Which, if any, of the following static data member
declarations and definitions are errors? Explain why.

```
// example.h
class Example {
public:
    static double rate = 6.5;            // wrong
    static const int vecSize = 20;
    static vector<double> vec(vecSize);  // wrong
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

Static members cannot be initialized in class unless they are "const" or constexpr"
