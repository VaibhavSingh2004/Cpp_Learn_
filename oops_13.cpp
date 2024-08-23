// Pure Virtual function and Abstract class 

// IF A CLASS HAVE ONE OR MORE PURE VIRTUAL FUNCTION THEN THAT CLASS IS CALLED ABSTRACT CLASS 

#include <iostream>

using namespace std;

class Person {
    public:
    // THIS IS HOW WE DEFINE THE PURE VIRTUAL FUNCTION
    // IF THERE IS AN PURE VIRTUAL FUNCTION IS PRESENT IN THE BASE CLASS THEN ALL THE CHILD CLASS MUST NEED TO OVERRIDE THAT FUNCTION 
    virtual void introduce()=0;
};

// IF WE ALSO WANT TO DEFINE FOR THE BASE CLASS ITSELF THEN WE NEED TO USE SCOPE RESOLUTION OPERATOR 

void Person :: introduce(){
    cout<<"hi form the person base class"<<endl;
};

class Student :public Person{
    public:
    // WE HAVE TO OVERIDE THE INTRODUCE FUNCTION OTHERWISE THE CODE THROWS AN ERROR FOR NOT OVERRIDING THE PURE VIRTUAL FUNCION
    void introduce(){
        cout<<"hi from the child class student"<<endl;
        Person::introduce();
    }
};
whoIsThis(Person &p){
    p.introduce();
};

int main(){
    Student st;
    whoIsThis(st);
    return 0;
}