// CONSTRUCTOR--PRIVATE SCOPE--GETTER AND SETTER

#include <iostream>
#include <string>

using namespace std;
class Human{
    // ACCESS MODIFIERS
    // if we directly try to access the private varible outside the class it will give error
    private :
        int age;
        int getAge(){
            return age-4;
        }

    public:
    // PROPERTIES OF CLASS 
        string name;
        // THIS IS A CONSTRUCTOR --- Constructor have no return type and it is called whenever we create a object of that class 
        // We can also define this constructor using scope resolution operator outside the class 
        Human(){
            // We can also initialize the variable inside the constructor 
            name = "Vaiibhav";
            age = 21;
            cout <<"Constructor is called"<<endl;

        }
        // FUNCTION OF CLASS 
        void display(){
            cout << getAge()<< name<<endl;
        }
        // FUNCTION FOR ACCESSING THE PRIVATE VARIABLE 
        void display_age(){
            // age=9;
            cout<<getAge()<<endl;
        }
        // void setAge(int ageValue){
        //     age=ageValue;
        // }
        
};
int main(){
    Human hb;
    // hb.setAge(8);
    hb.display_age();
    
}