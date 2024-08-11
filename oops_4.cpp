#include <iostream>
#include <string>

using namespace std;

class Human{
    public:
    // Static variables have class scope they are same for all the objects 
    static string name;
    static int age;

    Human(){
        age++;
    }
    // We can only use static member inside the static member function 
    static void display(){
        cout <<name<<age<<endl;
    }

};
// Static variables can only be initialized outside the class 
string Human::name = "Vaibhav";
int Human::age=90;

// static varible inside function without usinf classes 
void trial(){
        static int try1=0;
        cout<<try1++<<endl;
    }

int main(){
    Human man;
    Human Vaibhav;
    // If we have to access the static variable we can access with the help of class name 
    cout<<Human::age<<endl;
    Vaibhav.display();
    man.display();

    // Here we call function 3 times but inside function we declare try1 varibale as static so the initialization of that varible happens only once and for the next two calls the initialization line will be skipped 
    trial();
    trial();
    trial();
}