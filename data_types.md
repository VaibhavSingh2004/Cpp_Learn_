In C++, data types are classified into three major categories:

1. **Primitive Data Types** (also known as built-in data types)
2. **Derived Data Types**
3. **User-Defined Data Types**

Let's explore each in detail.

---

## 1. **Primitive Data Types**

Primitive data types are the fundamental building blocks of data manipulation in C++. These types are predefined by the language and directly supported by the compiler.

### Types of Primitive Data Types:

| Data Type      | Description                               | Size (on 32-bit architecture) |
|----------------|-------------------------------------------|-------------------------------|
| `int`          | Integer data type                         | 4 bytes                       |
| `char`         | Character data type                       | 1 byte                        |
| `bool`         | Boolean data type (`true` or `false`)      | 1 byte                        |
| `float`        | Single-precision floating-point number    | 4 bytes                       |
| `double`       | Double-precision floating-point number    | 8 bytes                       |
| `void`         | Represents the absence of a value         | No storage                    |
| `wchar_t`      | Wide character data type                  | 2 or 4 bytes (depends on OS)  |

### Explanation:

- **`int`**: Used to store whole numbers. Variants like `unsigned int` and `short int` are available.
- **`char`**: Used to store single characters like 'a', '1', etc.
- **`bool`**: Represents a boolean value that can be either `true` or `false`.
- **`float`**: Used for storing single-precision decimal numbers.
- **`double`**: Used for storing double-precision decimal numbers.
- **`void`**: Used in functions to specify that the function returns no value.
- **`wchar_t`**: Used to store wide characters (typically for extended character sets like Unicode).

### Example:
```cpp
int a = 10;
char letter = 'A';
bool isReady = true;
float pi = 3.14f;
double largeNumber = 1234567.89;
```

---

## 2. **Derived Data Types**

Derived data types are based on primitive data types, but are more complex. They include pointers, arrays, functions, and references.

### Types of Derived Data Types:

| Data Type  | Description                                                                 |
|------------|-----------------------------------------------------------------------------|
| Arrays     | Collection of elements of the same type                                     |
| Pointers   | Stores the memory address of another variable                               |
| References | An alias for another variable                                               |
| Functions  | Block of code that performs a specific task and can return a value or `void` |

### Explanation:

- **Arrays**: Arrays are collections of elements of the same type stored in contiguous memory locations. For example, `int arr[5]` can store 5 integers.
- **Pointers**: Pointers hold the address of a variable. For example, `int* ptr = &a` stores the memory address of the variable `a`.
- **References**: References act as an alias for another variable. For example, `int& ref = a;` means `ref` refers to the same memory location as `a`.
- **Functions**: Functions allow code reusability by encapsulating functionality that can be called with different arguments.

### Example:
```cpp
int arr[3] = {1, 2, 3};  // Array of integers
int* ptr = &a;           // Pointer to an integer
int& ref = a;            // Reference to variable 'a'
```

---

## 3. **User-Defined Data Types**

User-defined data types allow programmers to define their own data structures and types, which can be more complex than primitive or derived types. These include classes, structures, enumerations, and unions.

### Types of User-Defined Data Types:

| Data Type     | Description                                                         |
|---------------|---------------------------------------------------------------------|
| `struct`      | A collection of variables (possibly of different types) grouped together |
| `class`       | A blueprint for creating objects with data (attributes) and functions (methods) |
| `enum`        | A user-defined type consisting of a set of named integer constants  |
| `union`       | Similar to a structure but stores different data types in the same memory location |
| `typedef`     | Allows the creation of an alias for another data type               |

### Explanation:

- **`struct`**: Combines variables of different data types into a single logical unit. It is useful for modeling real-world entities.
- **`class`**: Defines the blueprint for objects, encapsulating data (attributes) and behaviors (methods) together. It is the foundation of Object-Oriented Programming (OOP).
- **`enum`**: Enumerations allow you to define a type that can only take one out of a small set of values. Internally, these values are represented by integers.
- **`union`**: A union is similar to a structure but stores different types in the same memory space. Only one member can hold a value at any time.
- **`typedef`**: Used to give a new name (alias) to an existing type.

### Example of User-Defined Types:

```cpp
// Structure
struct Person {
    string name;
    int age;
};

// Class
class Employee {
public:
    string name;
    int id;
    double salary;

    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nSalary: " << salary << endl;
    }
};

// Enum
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

// Union
union Data {
    int i;
    float f;
    char str[20];
};

// Typedef
typedef unsigned long ul;
ul age = 50;  // 'ul' is an alias for 'unsigned long'
```

### Example Breakdown:

1. **Structure (`struct`)**: Combines different data types (`string` and `int`) under one logical unit `Person`.
2. **Class**: Models an employee with attributes `name`, `id`, and `salary` and provides a method to display this information.
3. **Enum**: Defines the days of the week, where each day is internally assigned an integer value starting from 0 (Sunday = 0, Monday = 1, etc.).
4. **Union**: Allows different types of data to be stored in the same memory location, but only one member can hold a value at any given time.
5. **Typedef**: Creates an alias `ul` for `unsigned long`, simplifying its usage.

---

## Summary of All Data Types in C++:

### **Primitive Data Types:**
- **`int`**, **`float`**, **`double`**, **`char`**, **`bool`**, **`void`**, **`wchar_t`**

### **Derived Data Types:**
- **Arrays**, **Pointers**, **References**, **Functions**

### **User-Defined Data Types:**
- **`struct`**, **`class`**, **`enum`**, **`union`**, **`typedef`**

Each of these data types serves different purposes and allows for greater flexibility in how data is stored, manipulated, and accessed in a C++ program. Depending on the complexity of the program, you can use these different data types to model real-world entities and processes.