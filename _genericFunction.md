Let's break down the key concepts of generic classes, generic members, and non-type template parameters in **Modern C++** with simple examples.

### 1. **Generic Classes (Template Classes)**

A **generic class** allows you to write a single class definition that can work with different data types. Instead of defining multiple classes for each data type (e.g., `int`, `double`, `std::string`), you can use a **template** to write one class that works with any type.

**Example:**

```cpp
#include <iostream>
#include <string>

template<typename T> // Define a template with type parameter T
class Box {
    T value; // Use the generic type T
public:
    Box(T v) : value(v) {} // Constructor to initialize value
    T getValue() const { return value; } // Getter function for value
};

int main() {
    Box<int> intBox(123); // Box for int
    Box<std::string> strBox("Hello"); // Box for std::string

    std::cout << "intBox contains: " << intBox.getValue() << std::endl;
    std::cout << "strBox contains: " << strBox.getValue() << std::endl;
}
```

Here, `Box<int>` and `Box<std::string>` are instances of a generic class. The class works with both `int` and `std::string` types without duplicating code.

### 2. **Generic Members**

A class may have **generic member functions** even if the class itself isn't generic. This means only some member functions are template-based, while the rest are regular functions.

**Example:**

```cpp
#include <iostream>
#include <string>
#include <sstream> // for std::ostringstream

class Converter {
public:
    template<typename T>
    std::string convertToString(T value) {
        std::ostringstream oss;
        oss << value; // Convert value to string
        return oss.str();
    }
};

int main() {
    Converter c;
    std::cout << "Integer to string: " << c.convertToString(123) << std::endl;
    std::cout << "Double to string: " << c.convertToString(45.67) << std::endl;
}
```

Here, `convertToString` is a **generic member function** that converts any type to a string. Even though the class `Converter` is not generic, the function is.

### 3. **Non-type Template Parameters**

In some cases, template parameters can be **non-type** values, such as integers, that are used as part of the class or function definition. A common use case is for defining the size of an array.

**Example:**

```cpp
#include <iostream>
#include <array>

template<size_t N> // N is a non-type template parameter
class FixedArray {
    std::array<int, N> arr; // An array of size N
public:
    void fill(int value) {
        arr.fill(value); // Fill the array with the given value
    }
    void print() const {
        for (int i : arr) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    FixedArray<5> myArray; // Create an array of size 5
    myArray.fill(10); // Fill it with 10s
    myArray.print(); // Print the array: 10 10 10 10 10
}
```

Here, `FixedArray<5>` is a class with a compile-time constant size of 5. The class uses this size to create a fixed-size array of integers.

### 4. **Combining Everything Together**

You can combine **generic classes**, **generic member functions**, and **non-type template parameters** to create highly flexible and reusable code.

**Example:**

```cpp
#include <iostream>
#include <array>

template<typename T, size_t N>
class FlexibleArray {
    std::array<T, N> arr;
public:
    void fill(T value) {
        arr.fill(value); // Fill the array with the given value
    }
    T sum() const {
        T total = 0;
        for (const T& element : arr) {
            total += element; // Sum all elements
        }
        return total;
    }
    void print() const {
        for (const T& element : arr) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    FlexibleArray<int, 5> intArray; // Array of 5 integers
    intArray.fill(2); // Fill it with 2s
    intArray.print(); // Output: 2 2 2 2 2
    std::cout << "Sum: " << intArray.sum() << std::endl; // Output: Sum: 10

    FlexibleArray<double, 3> doubleArray; // Array of 3 doubles
    doubleArray.fill(3.14); // Fill it with 3.14s
    doubleArray.print(); // Output: 3.14 3.14 3.14
    std::cout << "Sum: " << doubleArray.sum() << std::endl; // Output: Sum: 9.42
}
```

In this example:
- `FlexibleArray<T, N>` is a generic class that takes both a **type parameter** `T` and a **non-type template parameter** `N` for the array size.
- It can work with any data type (`int`, `double`, etc.), and the size of the array is determined at compile-time.

### Summary of Concepts:

1. **Generic Classes**: Classes that use the `template` keyword and allow the class to work with any data type.
   - Example: `template<typename T> class MyClass { ... };`

2. **Generic Member Functions**: Specific functions within a class can be generic, even if the class itself is not.
   - Example: `template<typename T> T myFunction(T value) { ... }`

3. **Non-type Template Parameters**: Template parameters that are values (like integers) rather than types, useful for things like array sizes.
   - Example: `template<size_t N> class MyArray { ... };`

By using templates, C++ allows you to write flexible, reusable code that can adapt to different types or values without rewriting the same logic multiple times.