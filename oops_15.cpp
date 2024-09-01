// NESTED CLASS

#include <iostream>
#include <string>

using namespace std;

class Person{
    public :
    string name;

    class InsidePerson{
        public:
        string InsideName;
        int age;

    };
    // OBJECT OF NESTED CLASS DECLARED INSIDE CLASS 
    InsidePerson ip;

    void introduce(){
        cout<<name<<ip.InsideName<<ip.age<<endl;
    };
};
int main(){
    // TO ACCESS THE NESTED CLASS OUTSIDE THE CLASS WE CAN USE SCOPE RESOLUTION operator 
    Person :: InsidePerson ip1;
    
    Person p;
    p.name="Vaibhav";
    // ASSIGNING VALUES TO NESTED CLASS VARIBLES OR ATTRIBUTES 
    p.ip.InsideName="Singh";
    p.ip.age=21;

    p.introduce();
    return 0;
}