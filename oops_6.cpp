// Inheritance Polymorphism

#include <iostream>
#include <string>

using namespace std;

class person{
    protected:
        string city;
    public :
        string name;
        int age;
        void setName(string iname){name=iname;}
        void setAge(int iage){age=iage;}
        void setCity(string icity){city=icity;}

};
// STUDENT IS INHERITING THE PROPERTIES OF PERSON CLASS 
// TYPES OF INHERITANCE ---- 1: PUBLIC 2: PROTECTED 3: PRIVATE 
// WHEN WE DO PUBLIC INHERITANCE THEN ALL THE PROPERTIES OF BASE CLASS MAINTAIN THEIR ACCESSS MODIFIERS SAME FOR THE CHILD CLASS FOR E.G., IF A VARIABLE IS PROTECTED IN BASE CLASS THEN IT IS ALSO PROTECTED FOR THE CHILD CLASS MEANS IF ANY CLASS INHERITS THE CHILD CLASS THEN THEY CAN ACCESS THAT VARIABLE BUT OUTSIDE THE CLASS VARIBLE IS NOT ACCESSIBLE 

// PUBLIC INHERITANCE 
class Student : public person{
    public :
        int studentId;
        void setId(int iID){studentId=iID;}
        void introduce(){
            // WE CAN ACCESS ALL THE PROPERTIES OF BASE CLASS INSIDE CHILD CLASS 
            cout<<name<<age<<studentId<<endl;
            cout << city<<endl;
        }
};
// But if we use protected inheritance then we can not use public method of base class outside the child class because after inheritance all the methods and properties used in base class becomes protected e.g.,---


// PROTECTED INHERITANCE 
class Teacher : protected person{
    public :
        int teacherId;
        void setTeacherId(int id){teacherId=id;}
        void useBasemethod(int iage,string iname){
            setAge(iage);
            setName(iname);
        }
        void display(){
            cout<<name<<age<<teacherId<<endl;
        }
};
int main(){
    Student Anil;
    Anil.setName("Anil");
    Anil.setAge(78);
    Anil.setId(7888);
    Anil.setCity("Delhi");
    Anil.introduce();

    Teacher teach;
    teach.useBasemethod(67,"Suresh");
    teach.display();
    // this function will not work because it becomes protected for the child class so we can not access it outside the class for making this accessible we have to create function in child class 
    // teach.setName("Suresh");
    
    return 0;
}