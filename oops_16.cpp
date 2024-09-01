// LOCAL CLASSES ARE THE CLASSES WHICH IS DEFINED INSIDE A FUNCTION AND CAN BE ONLY ACCESIBLE WITHIN THE FUNCTION 

#include <iostream>
#include <string>

using namespace std;

void Demo(){
    // THIS CLASS IS A LOCAL CLASS DEFINED AND ACCESSIBLE ONLY INSIDE THE DEMO FUNCTION 
    class LocalClass{
        public:
        string name;
        int age;

        void display(){
            cout<<name<<age<<endl;
        };
    };

    LocalClass lc;
    lc.name="Vaibhav";
    lc.age=122;
    lc.display();
};

int main(){
    Demo();
    return 0;
}