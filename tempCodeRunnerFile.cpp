// Inheritance Polymorphism

#include <iostream>
#include <string>

using namespace std;

class person{
    public :
    string name;
    int age;
    void setName(string iname){name=iname;}
    void setAge(int iage){age=iage;}

};

class Student : public person{