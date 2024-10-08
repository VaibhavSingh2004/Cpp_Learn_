// constant value should be defined only once at the time of declaration only 
// We can not modify the constant value after it is defined 

// how to create a constant data member ?

// We know that inside a class we can only declare the data member we can not initialize them this is the rule of class creation so and we also know the constant value should be defined only once at the time of declaration only 

// So How to deal with this problem ?

class SimpleInterset{
    int t;
    float p;
    // This is how we declare and defined a const data member inside the class 
    const float rate;
    public :
    SimpleInterset(): rate(4.5){};

};

// constant member functions are called accessors 
// normal member function is called modifier