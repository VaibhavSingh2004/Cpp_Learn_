#include <iostream>
#include <string>

using namespace std;

// In C++, the `this` keyword is a pointer that points to the current instance of the class in which the member function is being executed. It is implicitly passed to all non-static member functions and can be used to refer to the invoking object.

// ### Key Points about `this`:

// 1. **Pointer to the Current Object**:
//    - `this` is a pointer, so if you want to access a member using `this`, you must use the arrow operator (`->`).
//    - Example: `this->memberVariable`.

// 2. **Used for Disambiguation**:
//    - `this` is often used when member variables are shadowed by function parameters or local variables with the same name.
   
// 3. **Returning `*this`**:
//    - In member functions, you can return `*this` to allow function chaining.
  
class MyClass {
    
public:
    int x;
    MyClass& setX(int x) {
        this->x = x; // 'this->x' refers to the member variable, 'x' refers to the parameter
        // THIS WILL RETURN A REFERENCE TO THE CURRENT OBJECT 
        return *this;
    }
};
// Explanation:
// -> return *this; returns a reference (MyClass&) to the current object, not the memory address.
// -> The *this expression dereferences the this pointer to get the current object itself. Since the return type is MyClass&, it returns a reference to the object, which allows for method chaining.
// -> If you wanted to return the memory address of the object, you would return this (which is of type MyClass*), not *this. However, that would change the return type of the method to MyClass*.

int main(){
    MyClass obj;
    obj.setX(10).setX(20); // Function chaining
    int *abc = (&obj.x);
    int ** ab = &abc;
    int *** a = &ab;
    cout<<***a<<endl;
    int y=10;
    cout<<*(&(*(*(&(*(*(&x)))))))<<endl;
    cout<<abc<<endl;
    cout<<ab<<endl;
    cout<<a<<endl;
    cout<<*(&obj.x)<<endl;
    return 0;
}
     
// 4. **Non-static Member Functions**:
//    - `this` is only available in non-static member functions because static functions do not belong to a specific instance of a class.

class Rectangle {
    int width, height;
public:
    Rectangle(int width, int height) {
        // Use 'this' to distinguish between the member variables and the parameters
        this->width = width;
        this->height = height;
    }
    int area() {
        return this->width * this->height; // Using 'this' is optional here
    }
    void display() {
        cout << "Width: " << this->width << ", Height: " << this->height << endl;
    }
};

// int main() {
//     Rectangle rect(10, 20);
//     rect.display();
//     cout << "Area: " << rect.area() << endl;
//     return 0;
// }

// In this example, `this->width` and `this->height` refer to the object's member variables, while `width` and `height` without `this` refer to the constructor's parameters.