# NameSpaces

### 1. **Using Directives**
The `using` directive allows you to bring all names from a namespace into scope without qualifying them. It is often used to avoid writing `std::` everywhere for standard library types like `std::string`.

**Example:**
```cpp
#include <iostream>
using namespace std; // Now we don't need to write std:: before cout

int main() {
    cout << "Hello, World!" << endl; // No need for std::cout
    return 0;
}
```

**Note**: Avoid putting `using namespace` in header files to prevent name conflicts.

---

### 2. **Declaring Namespaces and Namespace Members**
A namespace groups related classes, functions, and variables to avoid name collisions, especially in large codebases.

**Example:**
```cpp
namespace MyNamespace {
    class MyClass {
    public:
        void sayHello() {
            std::cout << "Hello from MyNamespace!" << std::endl;
        }
    };
}

int main() {
    MyNamespace::MyClass obj; // Accessing using fully qualified name
    obj.sayHello();
    return 0;
}
```

---

### 3. **The Global Namespace**
Identifiers not declared in an explicit namespace are in the global namespace. To differentiate between global and namespace-scoped identifiers, you can use the `::` (scope resolution) operator.

**Example:**
```cpp
int var = 10; // Global variable

namespace MyNamespace {
    int var = 20; // Same name in a namespace
}

int main() {
    std::cout << ::var << std::endl;       // Accessing global 'var' (10)
    std::cout << MyNamespace::var << std::endl; // Accessing 'var' in MyNamespace (20)
    return 0;
}
```

---

### 4. **The `std` Namespace**
All C++ Standard Library types, such as `std::vector`, `std::string`, etc., are declared in the `std` namespace.

**Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVec = {1, 2, 3};
    for (int x : myVec) {
        cout << x << " "; // Using std::cout due to the 'using namespace std;'
    }
    return 0;
}
```

---

### 5. **Nested Namespaces**
Namespaces can be nested inside other namespaces. Members of the parent namespace are accessible in the child namespace, but not the other way around unless `inline` is used.

**Example:**
```cpp
namespace OuterNamespace {
    void outerFunction() {
        std::cout << "Outer function!" << std::endl;
    }

    namespace InnerNamespace {
        void innerFunction() {
            outerFunction(); // Accessing parent namespace function
        }
    }
}

int main() {
    OuterNamespace::InnerNamespace::innerFunction();
    return 0;
}
```

---

### 6. **Inline Namespaces (C++11)**
Inline namespaces allow members of a nested namespace to be accessed as if they were part of the parent namespace. It helps with versioning.

**Example:**
```cpp
namespace Library {
    namespace old_version {
        void Func() { std::cout << "Old version" << std::endl; }
    }

    inline namespace new_version {  // Members of this namespace act as if in `Library`
        void Func() { std::cout << "New version" << std::endl; }
    }
}

int main() {
    Library::Func(); // Calls the new version by default
    return 0;
}
```

---

### 7. **Namespace Aliases**
If a namespace name is too long, you can create an alias to make your code more readable.

**Example:**
```cpp
namespace VeryLongNamespaceName {
    void someFunction() {
        std::cout << "Inside VeryLongNamespaceName!" << std::endl;
    }
}

namespace VLN = VeryLongNamespaceName; // Alias for the long namespace name

int main() {
    VLN::someFunction(); // Using the alias
    return 0;
}
```

---

### 8. **Anonymous (Unnamed) Namespaces**
Anonymous namespaces provide internal linkage, meaning their members are only accessible within the same translation unit (i.e., the file).

**Example:**
```cpp
namespace {
    int secretFunction() {
        return 42;
    }
}

int main() {
    std::cout << "Secret: " << secretFunction() << std::endl;
    return 0;
}
```

In this example, `secretFunction()` is only accessible within this file and cannot be used in other files even if they include this one.

---

### Summary:
- **Namespaces** are used to group code to prevent name collisions.
- **Using directives** bring identifiers from a namespace into the current scope.
- The **global namespace** contains identifiers not in any explicit namespace.
- The **std** namespace contains all standard library components.
- **Nested namespaces** can encapsulate more specific parts of code.
- **Inline namespaces** allow versioning within a namespace.
- **Namespace aliases** shorten long namespace names.
- **Anonymous namespaces** are useful for internal linkage (file-local scope).

This approach helps in organizing code efficiently and preventing name conflicts across large projects or when using multiple libraries.