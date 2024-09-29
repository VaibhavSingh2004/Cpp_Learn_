In this example, the key concept is understanding the difference between pointer constants and pointer variables.

- **Pointer Constant**: `intarray` is a pointer constant, meaning it holds the base address of the array and cannot be incremented or changed. It's essentially a fixed address where your array is stored.
  
- **Pointer Variable**: `ptrint` is a pointer variable that holds the address of the array but can be incremented, allowing it to traverse through the array elements.

### Explanation
In the code snippet:

```cpp
int intarray[] = { 31, 54, 77, 52, 93 }; // array
int* ptrint;                             // pointer to int
ptrint = intarray;                       // points to intarray
for(int j=0; j<5; j++)                   // for each element
    cout << *(ptrint++) << endl;         // print value
```

1. `ptrint = intarray;` sets `ptrint` to point to the start of `intarray`.
2. In the `for` loop, `*(ptrint++)` accesses the value at the current address pointed to by `ptrint` and then increments `ptrint` to point to the next array element.

### Why can't you write `*(intarray++)`?
The expression `intarray++` is invalid because `intarray` is a pointer constant, and you cannot change its value. In contrast, `ptrint` is a pointer variable, and thus it can be incremented, allowing you to traverse the array.
