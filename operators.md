C++ extends the functionality of C with several new operators that are not present in the C language. These operators enhance C++'s capabilities, particularly in object-oriented programming, memory management, and type safety. Here’s a breakdown of the C++ operators that are not available in C, along with detailed explanations.

### 1. **Scope Resolution Operator (`::`)**
The scope resolution operator `::` is used to define or access something that belongs to a particular scope, especially in the context of classes and namespaces in C++.

- **Purpose**:
  - To specify which namespace, class, or object a method or variable belongs to when there is ambiguity.
  - To access global variables or functions when local variables or functions have the same name.
  - To define functions outside of their class declaration.

- **Usage**:

    ```cpp
    int globalVar = 10;

    class MyClass {
    public:
        static int x;
        void showX();
    };

    // Define static member outside of the class
    int MyClass::x = 0;

    void MyClass::showX() {
        cout << "x: " << x << endl;
    }

    int main() {
        int localVar = 5;

        // Access global variable using scope resolution
        cout << "Global Var: " << ::globalVar << endl;

        MyClass obj;
        obj.showX();
    }
    ```

- **Key Uses**:
  - Defining class member functions outside the class.
  - Accessing global variables that share names with local variables.
  - Referencing variables and functions in specific namespaces.

---

### 2. **New and Delete Operators (`new` and `delete`)**
C++ introduces `new` and `delete` operators for dynamic memory allocation and deallocation, replacing the C-style `malloc()` and `free()` functions.

- **`new`**: Allocates memory for an object or array of objects of a given type and returns a pointer to the allocated memory.
  
- **`delete`**: Deallocates memory allocated by `new` to prevent memory leaks.

- **Syntax**:
  ```cpp
  // Allocate memory
  int* ptr = new int;       // For single object
  int* arr = new int[10];   // For array of objects

  // Deallocate memory
  delete ptr;               // For single object
  delete[] arr;             // For array of objects
  ```

- **Advantages**:
  - Constructor is called when memory is allocated, and destructor is called when memory is deallocated.
  - `new` automatically returns a pointer of the appropriate type.
  - Exception handling: `new` throws an exception (`std::bad_alloc`) if memory allocation fails.

---

### 3. **Type Cast Operators**
C++ introduces several type casting operators that are more specific and type-safe than C-style casting. These include:

- **`static_cast`**: Used for normal/ordinary type conversions, like converting between related types (e.g., between integers and floating-point types).

    ```cpp
    float f = 3.5;
    int a = static_cast<int>(f); // Safe conversion from float to int
    ```

- **`dynamic_cast`**: Used primarily for converting pointers/references of polymorphic types (types with virtual functions), ensuring type safety at runtime.

    ```cpp
    class Base { virtual void foo() {} };
    class Derived : public Base {};

    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);  // Safe downcasting
    ```

- **`const_cast`**: Used to add or remove the `const` qualifier from a variable.

    ```cpp
    const int* ptr = &a;
    int* modifiablePtr = const_cast<int*>(ptr); // Remove const
    ```

- **`reinterpret_cast`**: Used for low-level type casting, often for casting between unrelated pointer types or interpreting data as a different type.

    ```cpp
    int* p = new int(10);
    char* c = reinterpret_cast<char*>(p);  // Unsafe type casting
    ```

---

### 4. **Function Call Operator (`()`) Overloading**
In C++, you can overload the function call operator `()` for objects. This makes it possible to treat objects like functions, allowing for **functors** (function objects) or callable objects.

- **Usage**:

    ```cpp
    class Functor {
    public:
        void operator()(int x) {
            cout << "Called with argument: " << x << endl;
        }
    };

    int main() {
        Functor fun;
        fun(5);  // Functor object behaves like a function
    }
    ```

- **Purpose**:
  - Used to create **functors**, which are objects that can be called like functions.
  - Enhances flexibility in certain contexts like STL algorithms.

---

### 5. **Member Access Operator (`->*` and `.*`)**
These operators are used in conjunction with pointers to class members to access class members (both variables and functions) through an object pointer or reference.

- **Usage**:

    ```cpp
    class MyClass {
    public:
        int data;
        void display() {
            cout << "Data: " << data << endl;
        }
    };

    int main() {
        MyClass obj;
        obj.data = 10;

        // Pointer to data member
        int MyClass::*ptrToData = &MyClass::data;
        cout << "Data: " << obj.*ptrToData << endl;

        // Pointer to member function
        void (MyClass::*ptrToFunc)() = &MyClass::display;
        (obj.*ptrToFunc)();
    }
    ```

- **Purpose**:
  - Useful in situations where you want to pass or store pointers to class members.
  - These operators give more flexibility in handling pointers to member functions and variables.

---

### 6. **Namespace Operator (`::`)**
C++ introduces **namespaces** to avoid name collisions in large programs or when integrating multiple libraries. The scope resolution operator `::` is used to specify the namespace from which a symbol (variable, function, class, etc.) is being accessed.

- **Usage**:

    ```cpp
    namespace ns1 {
        int value = 10;
    }

    namespace ns2 {
        int value = 20;
    }

    int main() {
        cout << ns1::value << endl;  // Access value from namespace ns1
        cout << ns2::value << endl;  // Access value from namespace ns2
    }
    ```

- **Purpose**:
  - Helps organize code and prevents naming conflicts, especially in large projects.
  - Multiple entities can have the same name but belong to different namespaces, allowing the code to be modular.

---

### 7. **Overloading of Operators**
C++ allows **operator overloading**, where most operators can be redefined to work with user-defined types (like classes). C, on the other hand, does not support this feature.

- **Example** of Overloading `+` Operator:

    ```cpp
    class Complex {
    public:
        int real, imag;

        Complex(int r, int i) : real(r), imag(i) {}

        // Overload the + operator
        Complex operator+(const Complex& obj) {
            return Complex(real + obj.real, imag + obj.imag);
        }
    };

    int main() {
        Complex c1(10, 5), c2(2, 4);
        Complex c3 = c1 + c2;  // Operator overloaded
        cout << "Result: " << c3.real << " + i" << c3.imag << endl;
    }
    ```

- **Purpose**:
  - To provide intuitive syntax for operations between user-defined objects (e.g., adding complex numbers, multiplying matrices).
  - Makes custom types behave like built-in types, improving code readability and usability.

---

### 8. **`typeid` and `sizeof` for Type Information**
C++ introduces the `typeid` operator (from RTTI - Run-Time Type Information) to determine the type of an object at runtime. While `sizeof` exists in C, `typeid` is a new feature.

- **Usage**:

    ```cpp
    #include <iostream>
    #include <typeinfo>
    using namespace std;

    class Base {};
    class Derived : public Base {};

    int main() {
        Base* b = new Derived();
        cout << "Type of object: " << typeid(*b).name() << endl;
    }
    ```

- **Purpose**:
  - **`typeid`** is used to inspect the type of an object at runtime, especially in cases of polymorphism.
  - Helps ensure type safety in complex type hierarchies.

---

### Summary

Here’s a recap of C++-specific operators that are not available in C:

| **Operator**        | **Description**                                                                              |
|---------------------|----------------------------------------------------------------------------------------------|
| **Scope Resolution (`::`)**  | Resolves ambiguity and specifies scope (class, namespace, global)                            |
| **`new` and `delete`**       | Dynamic memory allocation and deallocation                                             |
| **Type Cast Operators**      | `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast` provide type-safe casting  |
| **Function Call (`()`)**     | Allows functors and callable objects by overloading the function call operator            |
| **Pointer-to-member (`.*`, `->*`)** | Access class members using pointers to members                                      |
| **Namespace (`::`)**         | Allows usage of namespaces