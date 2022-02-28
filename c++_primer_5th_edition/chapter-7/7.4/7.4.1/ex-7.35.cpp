#include<iostream>
#include<string>
typedef std::string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;            // ok to redefine "Type" here at the beginning of the class;
    Type setVal(Type);    
    // Type initVal();                  error: initVal() is not defined
    Type initVal(){ return 1; };
private:
    int val;
};
// Type Exercise::setVal(Type parm) error: should be "Exercise::Type" 
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();         // the initVal() inside "Exercise" is used
    return val;
}   

int main(){
    // Exercise ex;
 
}


