#include <iostream>
#include <string>

using namespace std;

class person{
    public:
    person(){
        cout<< "Constructor of the person class is executed"<<endl;
    }
    ~person(){
        cout<< "Destructor of the person class is executed"<<endl;
    }

};

class Student : public person {
    public :
    Student(){
        cout<<"student constructor is called"<<endl;
    }
    ~Student(){
        cout<<"student destructor is called"<<endl;
    }
    
};

int main(){
    Student st;
    return 0;
};

// FINDINGS --> CONSTRUCTOR OF BASE CLASS IS CALLED FIRST THEN THE CONSTRUCTOR OF CHILD CLASS IS EXECUTED 
// BUT --> DESTRUCTOR OF CHILD CLASS IS EXECUTED FIRST AND THEN THE DESTRUCTOR OF BASE CLASS IS CALLED 