#include <iostream>
#include <string>

using namespace std;
class HumanBeing{
    // ACCESS MODIFIERS
    public:
    // PROPERTIES OF CLASS 
        string name;
        // FUNCTION OF CLASS 
        void display(){
            cout << "Hello this is display function inside human being class "<< name<<endl;
        }
        // Declaring the method inside the class 
        void scopeResolutionLearn();
};

// with the help of scope resolution operator defining the method outside the class which is already declared inside the class
// ------------------------------
// In this way we can only define the function outside the classes or if we try to assign values to the variables outside the classes using SRO we will get error .. But we can assign values to the static variable outside the classes using SRO. 

void HumanBeing ::scopeResolutionLearn(){
    cout << HumanBeing::name<<endl;
}

int main(){
    // 2 ways of OBJECT INSTANTIATION --- 

    // in this way object (hb) is stored in stack not in heap but if we use new key word then object is stored in heap and that object is dynamic and new keyword going to return the address so we need a pointer to point that address.
    HumanBeing hb;
    // ACCESING PROPERTIES OF CLASS USING DOT OPERATOR 
    hb.name="Vaibhav";
    hb.display();

    // When we create object using new keyword then for accessing the properties of class we have to use the arrow operator
    HumanBeing *hb_2 = new HumanBeing();
    hb_2->name="Aditya";
    hb_2->display();

    hb_2->scopeResolutionLearn();
    return 0;
}