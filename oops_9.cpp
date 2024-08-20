#include <iostream>
#include <string>

using namespace std;

class father{
    protected:
    int height;
    public:
    father(int h){
        height = h; // THIS IS LINE X WE CAN REMOVE THIS LINE AS WELL AND REMOVE THE ARGUMENTS FROM THE CONSTRUCTOR
    }
    void askFather(){
        cout<<"Ask me anything i am you Father"<<endl;
    }
    void example_overriding(){
        cout<<"someone going to override me"<<endl;
    }
};
class mother{
    public:
    string skinColor;
    void askMother(){
        cout<<"Ask me anything i am you Mother"<<endl;
    }
};

class child :public father,public mother{
    public:
    // IN THIS WAY WE CAN PASS VALUE TO BASE CLASS CONSTRUCTOR FROM THE CHILD CLASS 
    child(int x, string y): father(x), mother(){
        // ADD LINE X HERE WHICH WE REMOVE FORM ABOVE AND REMOVE PARAMETER FROM THE FATHER(X) THIS IS ALSO CORRECT TO PASS THE VALUE FORM BASEL CLASS TO CHILD CLASS CONSTRUCTOR e.g., mother class constructor
        skinColor =y;
        cout<<"child class constructor is called"<<endl;
    }
    void setHeightAndSkinColor(int ih, string isc){
        skinColor =isc;
        height =ih;
    }
    void display(){
        cout<<"Height "<<height<<" Skin color "<<skinColor<<endl;
    }
    // OVERRIDING THE METHOD PRESENT IN FATHER CLASS WHICH IS THE BASE CLASS OF CHILD CLASS 
    void example_overriding(){
        cout<<"I am overriding the method in child class"<<endl;
    }
};
int main(){
    child c(78,"Black");
    // c.setHeightAndSkinColor(8,"black");
    c.display();
    c.askMother();
    c.askFather();
    // THIS WILL RUN THE CHLILD CLASS METHOD NOW THE QUESTION IS HOW TO RUN THE BASE CLASS METHOD 
    c.example_overriding();
    // ANSWER using scope resolution operator we can do this 
    c.father::example_overriding();
    return 0;
}
