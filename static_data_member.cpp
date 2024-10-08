// Static Data member -- when a varible is declared static inside a class its default value is zero 
// and if we declared a varible and not initilized default value become garbage (in case of local varibale ) 
// static data member are class member not the object member only one instance of varible is created 


// """ Destruction process is always from right to left  """ 

// static data members are created in data segments which is a public area thats why every object can access it 
// static data member are declared inside the class and defined outside the class 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Test {
    public :
    static int a ; //declaration
    Test(){
        a++;
        cout<<"object created"<<a<<endl;
    }
    ~Test(){
        cout<<"object deleted"<<a<<endl;
        a--;
    }
    int get(){
        cout<<a<<endl;
    };

};
int Test::a;  //defined

int main(){
    // int Test::a = 10;  --- This line is giving error because 
    // Local shadowing of the static member: In the main function, the line int Test::a = 10; is trying to redeclare Test::a, but Test::a has already been declared as a static member of the class. You don't need to declare it again, and doing so causes the error.

    cout<<Test::a<<endl;
    
    Test t, t2, t3;
    // t.get();
}

