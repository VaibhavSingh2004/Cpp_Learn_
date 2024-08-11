#include <iostream>
#include <string>

using namespace std;
class HumanBeing{
    // ACCESS MODIFIERS
    private:
    // PROPERTIES OF CLASS 
        string name;
        int age;
    public:
        HumanBeing(string iname, int iage){
            name = iname;
            age = iage;

        };
        // FUNCTION OF CLASS 
        void display(){
            cout << "Hello this is display function inside human being class "<< name<<endl;
        }
        // Declaring the friend method inside the class 
        // The above properties name and age are private with the help of friend method we can access the private member outside the class if we want to declare a class as a friend class 
        // Syntax--- friend class className; 
        friend void friend_method(HumanBeing man);
};

void friend_method(HumanBeing man)
{
    cout<<man.name<<man.age<<endl;
};

int main(){
    HumanBeing ravi = HumanBeing("Ravi",78);
    friend_method(ravi);
}