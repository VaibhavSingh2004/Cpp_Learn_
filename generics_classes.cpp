#include <iostream>
using namespace std;

// C++ GEBERIC TYPE WITH ONE GENERIC TYPE 
template <class MyType>
class GenericClass{
    MyType p1;
    MyType p2;
    public:
    GenericClass(MyType x, MyType y){
        p1=x;
        p2=y;
    }
    void display(){
        cout<<p1<<" "<<p2<<endl;
    }
};
// EXPLICIT SPECIALIZATION OF GENERIC CLASSES 
template <> class GenericClass<int>{
    int p1;
    int p2;
    public:
    GenericClass(int x, int y){
        p1=x;
        p2=y;
    }
    void display(){
        cout<<"This is specially overloaded generic class for the integer type "<<endl;
        cout<<p1<<" "<<p2<<endl;
    }
};


// C++ GEBERIC TYPE WITH MORE THAN ONE GENERIC TYPE 
template <class MyType1,class MyType2>
class GenericClass2{
    MyType1 p1;
    MyType2 p2;
    public:
    GenericClass2(MyType1 x, MyType2 y){
        p1=x;
        p2=y;
    }
    void display(){
        cout<<p1<<" "<<p2<<endl;
    }
};

// DEFAULT DATA TYPES AS GENERIC PARAMETERS TO GENRIC CLASSES 
// when we have to declare default generic data types always start form the right otherwise we have to face error 
// The error in your code is caused by the template declaration for `GenericClassDefault`. When defining a template with default types, **all the template parameters after the one with a default type must either have defaults as well, or they should be omitted** when creating an object. However, in your case, you've provided a default type (`string`) for `MyType1`, but no default for `MyType2`.

// This creates ambiguity when you explicitly provide types like `GenericClassDefault<string, int>`, as the compiler expects either both or none to have defaults.

// To fix this, you can either:
// 1. **Provide a default for all template parameters**, or
// 2. **Omit the default when you want to pass both types explicitly.**

// ### Solution 1: Provide a default for all template parameters:

// ### Solution 2: Omit the default type and explicitly pass both types when creating the object:
// If you don't want a default for the second type (`MyType2`), you can rewrite the template without a default for `MyType1`.

// 

// Both solutions will work. In **Solution 1**, you get the added flexibility of not having to specify types every time if you want to use the default.


// template <class MyType1=string,class MyType2> This is wrong 
template <class MyType1,class MyType2=string>
class GenericClassDefault{
    MyType1 p1;
    MyType2 p2;
    public:
    GenericClassDefault(MyType1 x, MyType2 y){
        p1=x;
        p2=y;
    }
    void display(){
        cout<<p1<<" "<<p2<<endl;
    }
};
int main(){
    GenericClass<string> gc("vaibhav","singh");
    gc.display();
    // SPECIALLY OVERLOADED CLASS FOR THE INTEGR TYPE 
    GenericClass<int> gcI(8,9);
    gcI.display();
    // ----------------------------------------------
    GenericClass2<string,int> gc2("vaibhav",9);
    gc2.display();
    GenericClassDefault<string,int> gcd("vaibhav",9);
    gcd.display();
}