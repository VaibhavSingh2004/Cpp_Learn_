#include <iostream>
#include <string>

using namespace std;

class father{
    public:
    int height;
    void askFather(){
        cout<<"Ask me anything i am you Father"<<endl;
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
    void setHeightAndSkinColor(int ih, string isc){
        skinColor =isc;
        height =ih;
    }
    void display(){
        cout<<"SkinColor "<<skinColor<<"Height "<<height<<endl;
    }
};
int main(){
    child c;
    c.setHeightAndSkinColor(8,"black");
    c.display();
    c.askMother();
    c.askFather();
    return 0;
}
