// POLYMORPHISM AND VIRTUAL FUNCTION 

#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
    virtual void introduce(){
        cout<<"Hi I am person class"<<endl;
    };
};

class Student : public Person{
    public:
    void introduce(){
        cout<<"Hi I am student class"<<endl;
    }
};
class farmer : public Person{
    public:
    void introduce(){
        cout<<"Hi I am farmer"<<endl;
    }
};
void whoIsThis(Person &p){

    // Person &p = ramesh ---- means ramesh and p points to the same object they have different name so ramesh introduce function is called    WE HAVE TO ALWAYS USE PASS BY REFERENCE TO CALL OVERRIDEDE FUNCTION

    // Person p = ramesh ----- ramesh and person are two different object but they have equal values ___ NOW THIS WILL CALL ALWAYS PARENT CLASS INTRODUCE FUNCTION 

    // whenever we call the whoIsThis function it will always call the person class introduce method but what we want is that if we pass student it will call student introduce method or if we pass farmer it will farmer introduce method 

    // for implementing the above requirements we need to make the base class method -- VIRTUAL then it is available for overriding  
    p.introduce();
};
int main(){

    farmer ramesh;
    Student ram;
    whoIsThis(ramesh);
    whoIsThis(ram);
    return 0;
}

// When you pass an object by value in C++, a copy of the object is made. This copy is of the static type declared in the function parameter list, which is Person in your whoIsThis function. Therefore, even though you pass an object of a derived class (Student or farmer), the whoIsThis function will only see and use it as a Person object.

// Here's a breakdown of why this happens:

// Passing by Value:
// When you pass an object by value:

// The object is sliced. This means only the Person part of the Student or farmer object is copied. This is known as object slicing.
// Since the object is now a Person type (even though it was originally a Student or farmer), the Person version of introduce() is called, even if introduce() is a virtual function.
// Passing by Reference:
// When you pass an object by reference:

// No slicing occurs. The reference still refers to the original object, not just the Person part of it.
// The virtual function mechanism works as expected, and the correct overridden method is called based on the actual type of the object, not the reference type.

// Base class ---- virtual function def
//   |
//   |
// Child Class ---- overirde function
//   |
//   |
// Sub child class ----- override function

// then always child class function is called if we use the pass by reference tecnique and if definition is not available then parent for that class is seen for the definition for e.g., if definition is not availbale for the sub child class then the child class defintion is executed 