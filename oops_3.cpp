//CONSTRUCTOR OVERLOADING
#include <iostream>
#include <string>
using namespace std;

class Human{
    private :
        int age;
        string name;
    public:
        // DEFAULT CONSTRUCTOR 
        Human(){
            name="Vaibhav";
            age=21;
            cout << "Default Constructor"<<endl;
        }
        // OVERLOADED CONSTRUCTOR WITH VALUES 
        // when we pass default values in the parameter then if we not provided the value during the object creation then it will take this values as parameter AND after passing default values like below if we remove now the default constructor then it will work without any error because then it will call constructor with default parameter 
        Human(int ageValue =0, string nameValue="NoName"){
            name=nameValue;
            age=ageValue;
            cout << "Overloaded Constructor "<<name<<age<<endl;
        }
        // DESTRUCTOR OF THE CLASS 
        ~Human(){
            cout<<"Destructor is called"<<endl;
        }
        

};

int main(){
    // DEFAULT CONSTRUCTOR IS CALLED 
    Human* h;
    h = new Human(12,"sumit");
    // THIS IS HOW TO CALL THE DESTRUCTOR    
    delete h;
    // OBVERLOADED CONSTRUCTOR IS CALLED 
    
}