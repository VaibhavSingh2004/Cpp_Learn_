// OPERATOR OVERLOADING 
#include <iostream>
#include <string>

using namespace std;

class Marks{
    int internak_marks;
    int external_marks;

    public:
    // DEFAULT CONSTRUCTOR 
    Marks(){
        internak_marks = 0;
        external_marks = 0;
    };
    // CONSTRUCTOR WITH ARGUMENTS 
    Marks(int im,int em){
        internak_marks = im;
        external_marks = em;
    };

    void display(){
        cout<<internak_marks<<external_marks<<endl;
    };
    // OPERATOR OVERLOADING FOR MY CUSTOM CLASS MARKS 
    Marks operator+(Marks m){
        // TEMP OBJECT OF MARKS WHICH STORE THE RESULT OF SUMMATION BETWEEN TWO MARKS OBJECT ---> SOMETHING LIKE PYTHONF OVERLOADING WHY DUNDER METHODS
        Marks temp;
        temp.internak_marks=internak_marks + m.internak_marks;
        temp.external_marks = external_marks +m.external_marks;
        return temp;
        
    };
};
int main(){
    Marks m1(10,20),m2(10,20);
    Marks sum = m1+m2;
    sum.display();
    return 0;
}