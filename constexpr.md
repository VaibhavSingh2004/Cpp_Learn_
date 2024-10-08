The `constexpr` keyword in C++ is used to declare that the value of a variable or the return value of a function is constant and can be evaluated at **compile-time**, rather than at run-time. This provides an opportunity for the compiler to perform optimizations by evaluating expressions and functions during the compilation phase.

### Key points about `constexpr`:
- **Compile-time evaluation**: It tells the compiler that the value can be computed at compile-time, improving performance.
- **Constant expressions**: `constexpr` functions or variables must have values that are known at compile time and must be able to return or hold a constant value.
- **Stricter than `const`**: While `const` indicates that a variable’s value is constant and cannot be changed, `constexpr` guarantees that the value is known at compile time. Every `constexpr` is implicitly `const`, but not every `const` is `constexpr`.

### `constexpr` Variables

A `constexpr` variable is one that is immutable and its value can be computed during compilation.

#### Syntax:
```cpp
constexpr dataType variableName = value;
```

#### Example:
```cpp
constexpr int width = 10;
constexpr int height = 20;
constexpr int area = width * height;  // Area is computed at compile-time
```

In this example, the `area` is calculated at compile time because all variables involved are marked as `constexpr`, meaning the compiler can evaluate their values during the compilation process.

### `constexpr` Functions

A `constexpr` function is a function that can be evaluated at compile-time when its input arguments are constants.

#### Syntax:
```cpp
constexpr returnType functionName(params) {
    // Function body
}
```

#### Example:
```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result = square(5);  // Compile-time evaluation
    int runtime_result = square(10);   // Run-time evaluation
}
```

In the above example, the call to `square(5)` is evaluated at compile-time because the argument `5` is a constant. However, the call to `square(10)` is evaluated at runtime because the argument could be a variable or determined during execution.

### Important rules for `constexpr` functions:
1. The function must have a return type and a body that consists of a single `return` statement.
2. All parameters and return values must be able to be evaluated at compile-time if used in a `constexpr` context.
3. You can use `constexpr` functions at runtime as well, but if you pass non-constant values as arguments, they are evaluated at runtime.
4. As of **C++14**, `constexpr` functions can have more flexibility (multiple statements, loops, etc.) as long as the result can still be computed at compile-time.

### `constexpr` vs `const`

- `const`: Ensures the value of a variable cannot be changed after initialization, but the value is not necessarily known at compile-time.
  
  Example:
  ```cpp
  const int x = getInput();  // Value can only be assigned at run-time
  ```

- `constexpr`: Ensures that the value is constant and must be known at compile-time, allowing the compiler to optimize it.
  
  Example:
  ```cpp
  constexpr int y = 5 * 10;  // Value is computed at compile-time
  ```

### Example Comparison:

```cpp
#include <iostream>
using namespace std;

constexpr int getFive() {
    return 5;
}

int main() {
    const int x = 10;         // Value is constant, but known only at run-time
    constexpr int y = 10;     // Value is constant and known at compile-time
    constexpr int z = getFive(); // Can call constexpr function at compile-time

    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
}
```

### Summary of `constexpr`:
1. **For variables**: `constexpr` guarantees the variable value is a constant and can be evaluated at compile time.
2. **For functions**: `constexpr` ensures that a function can be used in constant expressions, enabling compile-time evaluation if called with constant arguments.
3. **Compile-time optimization**: Allows the compiler to optimize code by precomputing values during compilation rather than waiting until runtime.