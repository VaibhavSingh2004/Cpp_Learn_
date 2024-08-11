#include <iostream>
#include <string>

using namespace std;

class person{
    protected:
        string city;
    public :
        string name;
        int age;
        void setName(string iname){name=iname;}
        void setAge(int iage){age=iage;}
        void setCity(string icity){city=icity;}

};

// PRIVATE INHERITANCE 
class Student : private person{
    public :

        // ACCESS DECLARATION 
        // NOW THIS ALL MEMEBER OF BASE CLASS BECOMES PUBLIC FOR CHILD CLASS 
        using person::age;
        using person::name;
        using person::city;
        using person::setAge;
        using person::setCity;
        using person :: setName;

        int studentId;
        void setId(int iID){studentId=iID;}
        void introduce(){
            // WE CAN ACCESS ALL THE PROPERTIES OF BASE CLASS INSIDE CHILD CLASS 
            cout<<name<<age<<studentId<<endl;
            cout << city<<endl;
        }
};
int main(){
    Student st;
    // THIS IS NOT ACCESIBLE OUTSIDE THE STUDENT CLASS BECAUSE ALL MEMBER OF PERSON CLASS BECOME PRIVATE FOR STUDENT CLASS 
    // st.setAge(78);

    // bUT WE HAVE A CONCEPT TO CHANGE THE ACCESS LEVEL OF ANY MEMEBER INSIDE THE DERIVED CLASS KNOWN AS ACCESS DECLARATION 
    st.setAge(78);
    st.setCity("Delhi");
    st.setId(345);
    st.setName("Vaibhav");
    st.introduce();
}