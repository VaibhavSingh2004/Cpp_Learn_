// Static member function 

// static member function can work on only static data member they can not work with non static data member 
// becuse when we run the cpp file no memory is allocated to class and non static member but memory is allocate to static member and we are trying to access those varible which is not exixt in the memory yet
// static member function is never attached with this pointer 
// They are associated with both class and object that means we can call the static member function with both by class name and object name   
// They should not be constant or volatile  or virtual
#include <iostream>
using namespace std;
class Test{
    public :
    int a ;

    void geta() const{
        cout<<a<<endl;
    }

};