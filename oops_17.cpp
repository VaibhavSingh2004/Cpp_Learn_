// OPERATOR OVERLOADING 
// SHORTHAND OVERLOADING --->  SHORTHAND ARE += OR -=
#include <iostream>
#include <string>

using namespace std;

class Marks{
    

    public:
    int internak_marks;
    int external_marks;
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
    // CURRENT OBJECT IS PASSED IMPLICITLY AND WE HAVE TO PASS ONE OBJECT 
    Marks operator+(Marks m){
        // TEMP OBJECT OF MARKS WHICH STORE THE RESULT OF SUMMATION BETWEEN TWO MARKS OBJECT ---> SOMETHING LIKE PYTHONF OVERLOADING WHY DUNDER METHODS
        Marks temp;
        temp.internak_marks=internak_marks + m.internak_marks;
        temp.external_marks = external_marks +m.external_marks;
        return temp;
        
    };
    // OVERLOADING OF SHORTHAND OPERATOR --- WE DONT NEED TO PASS THE OBJECT EXPLICITLY BECAUSE WE REQUIRE ONLY ONE INSTANCE FPR SHORTHAND OPERATORS WHICH IS PASSED IMPLICITLY
    void operator+=(int bonusMarks){
        internak_marks = internak_marks + bonusMarks;
        external_marks = external_marks+bonusMarks;
    };

    Marks& operator++(){
        internak_marks+=1;
        external_marks+=1;
        return *this;
    }

    // THIS IS A FRIEND FUNCTION NOT THE MEMBER FUNCTION OF CLASS THATS WHT WE HAVE TO PASS THE REFERENCE OF THE OBJECT BECAUSE IT HAVE NO ACCESS TO INSTANCE OF CLASS 
    friend void operator-=(Marks &curObj, int redMarks);

};

void operator-=(Marks &curObj, int redMarks){
    curObj.internak_marks = curObj.internak_marks - redMarks;
};

int main(){
    Marks m1(10,20),m2(10,20);
    Marks sum = m1+m2;
    sum+=33;
    sum-=3;
    Marks m = ++sum;
    m.display();
    return 0;
}