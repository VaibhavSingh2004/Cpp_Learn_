The `noexcept` keyword in C++ is used to specify whether a function is **guaranteed** not to throw any exceptions. This helps the compiler optimize code and enables better exception handling strategies, such as knowing which functions can throw exceptions and which cannot.

### Key points about `noexcept`:
1. **Guarantees no exceptions**: When a function is marked with `noexcept`, it promises not to throw any exceptions. If an exception is thrown within a `noexcept` function, the program will call `std::terminate()`, leading to program termination.
2. **Optimization**: Marking functions as `noexcept` can lead to better performance optimizations, as the compiler can assume no exception-handling code is required.
3. **Conditional `noexcept`**: You can make the `noexcept` specification conditional, depending on whether certain expressions can throw exceptions.

### Syntax:

#### Declaring a function as `noexcept`:
```cpp
returnType functionName(parameters) noexcept {
    // function body
}
```

#### Example:
```cpp
void func() noexcept {
    // This function is guaranteed not to throw any exceptions
}
```

#### Conditional `noexcept`:
You can specify a condition in the `noexcept` specifier. The function will be `noexcept` only if the condition is true.

```cpp
returnType functionName(parameters) noexcept(condition) {
    // function body
}
```

#### Example:
```cpp
void func() noexcept(noexcept(someOtherFunction())) {
    // This function is noexcept if 'someOtherFunction()' is noexcept
}
```

### Example Use Case:

```cpp
#include <iostream>
using namespace std;

void noThrow() noexcept {
    cout << "This function does not throw exceptions." << endl;
}

void mightThrow() {
    throw "This function throws an exception!";
}

int main() {
    noThrow();  // This is safe, no exceptions
    try {
        mightThrow();  // This throws an exception
    } catch (const char* e) {
        cout << "Caught exception: " << e << endl;
    }

    // Checking if a function is noexcept at compile-time
    cout << "noThrow is noexcept: " << noexcept(noThrow()) << endl;  // true
    cout << "mightThrow is noexcept: " << noexcept(mightThrow()) << endl;  // false
}
```

### Output:
```
This function does not throw exceptions.
Caught exception: This function throws an exception!
noThrow is noexcept: 1
mightThrow is noexcept: 0
```

### Explanation:
- **`noThrow()`** is marked as `noexcept`, so it cannot throw any exceptions. The call to `noThrow()` is safe and does not involve any exception handling.
- **`mightThrow()`** throws an exception, and the exception is caught using a `try-catch` block.
- The `noexcept()` operator is used to check at compile-time whether a particular function is declared as `noexcept`.

### `noexcept` vs. `throw()`:
In C++03, `throw()` was used to indicate that a function would not throw any exceptions:
```cpp
void func() throw();
```
However, `throw()` was deprecated in favor of `noexcept` in C++11 because `noexcept` is more flexible and efficient.

### Advantages of `noexcept`:
1. **Performance Optimizations**: The compiler can optimize code better because it doesn't have to generate exception-handling code paths for `noexcept` functions.
2. **Safer Code**: By using `noexcept`, you provide a strong guarantee that certain parts of the code are exception-free, reducing potential runtime errors.
3. **Improved Exception Safety**: When dealing with destructors or move operations, using `noexcept` ensures that certain operations, like moving objects, won't fail due to exceptions.

### When to use `noexcept`:
- **Destructors**: Destructors should generally be `noexcept` because exceptions during object destruction can cause undefined behavior during stack unwinding.
- **Move constructors and move assignment operators**: Mark these as `noexcept` when possible, as containers like `std::vector` rely on this for optimal performance during resizing.
- **Small utility functions**: Functions that are simple and not expected to throw exceptions (like getters or simple setters) should be marked `noexcept`.

### Conditional `noexcept`:

You can make the `noexcept` specifier conditional based on whether certain expressions or function calls within the function might throw.

#### Example:
```cpp
#include <iostream>
using namespace std;

void mayThrow() { throw "An error!"; }
void wontThrow() noexcept {}

template <typename T>
void myFunc(T&& arg) noexcept(noexcept(wontThrow())) {
    wontThrow();  // Since wontThrow() is noexcept, this function is also noexcept
}

int main() {
    cout << boolalpha;  // Print booleans as true/false
    cout << "Is myFunc() noexcept? " << noexcept(myFunc(5)) << endl;  // true
}
```

In this case, `myFunc` is marked `noexcept` only if the expression `noexcept(wontThrow())` is true.

### Summary:
- **`noexcept`** guarantees that a function will not throw any exceptions.
- It helps in optimizing the code by allowing the compiler to skip generating exception-handling mechanisms.
- You can make `noexcept` conditional, depending on other function calls or expressions.
- It is especially useful in destructors, move constructors, and small utility functions.