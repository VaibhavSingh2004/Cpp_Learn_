#include <iostream>
#include <string>

using namespace std;
class Person{
    public:
    void introduce(){
        cout<<"I am from the Base Person class"<<endl;
    }
};
class Student : public Person{
    public:
    void introduce(){
        cout<<"I am from the Child Student class"<<endl;
    }
};
void WhoIsTheBoss(Person p){
    // THIS WILL CALL THE FUNCTION PRESENT IN BASE CLASS NO MATTER WE PASS THE OBJECT OF CHILD CLASS OR BASE CLASS
    p.introduce();
};
int main(){
Student st;
// THIS WILL CALL THE FUNCTION PRESENT IN CHILD CLASS 
st.introduce();
WhoIsTheBoss(st);
}