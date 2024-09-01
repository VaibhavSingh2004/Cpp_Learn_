// DIAMOND PROBLEM AND VIRTUAL INHERITANCE
#include <iostream>

using namespace std;

class Animal{
    public:
    int age;
    void walk(){
        cout<<"Animal Walk"<<endl;
    };
};
class Tiger : virtual public Animal{
    public:
    int age;
    // void walk(){
    //     cout<<"Tiger Walk"<<endl;
    // };
};
class Lion : virtual public Animal{
    public:
    int age;
    // void walk(){
    //     cout<<"Lion Walk"<<endl;
    // }
};
class Liger :public Tiger, public Lion{
    public:
    int age;
    // void walk(){
    //     cout<<"liger Walk"<<endl;
    // }
};
int main(){
    Liger lg;
    // THIS LINE WILL THROW ERROR ---> REQUEST FOR MEMBER WALK IS AMBIGUOUS BECAUSE THE CODE CONFUSE WHETHER HE SHOULD CALL WALK FROM THE OBJECT OF TIGER OR LION --->  THIS IS CALLED DIAMOND PROBLEM --> WHEN WALK FUNCTION OF LION AND TIGER CLASS IS COMMENTED IF WE UNCOMMENT THOSE STILL THE ERROR WILL BE THEIR FOR THE SAME REASON

// Solution: Virtual Inheritance
// To solve the diamond problem, C++ provides virtual inheritance. This ensures that only one copy of the base class (A in this  case) is inherited, regardless of how many paths reach it.
    lg.walk();
    return 0;
}

// Constructor Execution Order with Virtual Inheritance:
// Base Class Constructor: The constructor of the virtual base class (A in this case) is called first, even if it's indirectly inherited via multiple paths.
// Intermediate Class Constructors: The constructors of the classes that virtually inherit from the base class (B and C) are called next.
// Derived Class Constructor: Finally, the constructor of the most derived class (D in this case) is called.

// CONSTRUCTOR CALL WHEN USE VIRTUAL INHERITANCE ----> ANIMAL->TIGER->LION->LIGER
// CONSTRUCTOR CALL WHEN WE DONT USE VIRTUAL INHERITANCE ----> ANIMAL->TIGER->ANIMAL->LION->LIGER