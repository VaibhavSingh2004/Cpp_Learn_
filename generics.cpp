#include <iostream>
using namespace std;

// Simplest form of generic function
template <typename myType> void display(myType x){
    cout<<x<<endl;
};

// Multiple parameters and return values
// WE CAN PASS SAME TYPE VALUES IN FUNCTION IF WE DECLARE GENERIC FUNCTION LIKE THIS 
template <typename T> T returnValue(T x,T y){
    cout << "this is second parameter "<<y<<endl;
    return x;
};

// PASSING STANDARD PARAMETER TO C++ GENERIC FUNCTION 
// SECOND PARAMETER OF THR FUNCTION MUST BE INTEGER 
template <typename T> T stdParam(T x,int y){
    cout << "this is second parameter "<<y<<endl;
    return x;
};

// GENERIC FUNCTION WITH MULTIPLE GENERICS TYPES 
// we can pass different types parameter in function example string and integer or integer and float etc. 
template <typename T, typename T2> T mulParam(T x,T2 y){
    cout << "this is second parameter "<<y<<endl;
    return x;
};

// EXPLICITLY OVERLOADING GENERIC FUNCTION 
template <typename T> T explOvl(T x){
    cout << "this is generic function explOvl "<<x<<endl;
    return x;
};

// int explOvl(int x){
//     cout<<"This is explixitly overloaded function "<<x<<endl;
//     return x;
// };

// WE CAN ALSO OVERLOAD THE FUNCTION LIKE THIS 
template<> int explOvl<int>(int x){
    cout<<"This is more correct way of overloading "<<x<<endl;
    return x;
};

// OVERLOADING GENERIC FUNCTION TEMPLATE only difference is number of parameter 

template<typename t> void genDisplay(t x){
    cout<<"generic function with one parameter "<<x<<endl;
}
template<typename t> void genDisplay(t x,t y){
    cout<<"generic function with two parameter "<<x<<" "<<y<<endl;
}

int main(){
    display("hello");
    display(78);
    int x = returnValue(6,8);
    cout << x << endl;
    mulParam("Vaibhav",45);
    mulParam(45,"Vaibhav");
    // This will call the geberic function 
    explOvl("Vaibhav");
    // This will call the overloaded function 
    explOvl(77);
    genDisplay(78);
    genDisplay("vaibhav","singh");

}