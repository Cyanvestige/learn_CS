#### Exercise 7.33: What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.

```
pos Screen::size() const
{
    return height \* width;
}
```

##### Solution:

we are not inside the class scope when we use the type member "pos". We must specify the class.

```
Screen::pos Screen::size() const
{
    return height \* width;
}
```
