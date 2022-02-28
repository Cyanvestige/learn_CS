Exercise 7.56: What is a static class member? What are the advantages
of static members? How do they differ from ordinary members?

A static class member is a member that is associated with the class, rather than with individual objects of the class type. It exists outside any object of the class.

Advantages:

Even If a static member of a class changes, each object of the class can always use that new values.
A static member can be used as a default argument.
A static data member can have incomplete type(even as the class type of which it is a member).

Differences between ordinary members and static members:
A static member is associated with the class, an ordinary member bis associated with objects of the class.
