# <-- BENEFITS OF SMART POINTERS -->
- Resource management
- Avoiding Memory leaks
- Avoiding Dangling pointers
- Pointer Owenership
- Simplify Memory Management
- Avoiding Manual Memory Management Error

<!-- UNIQUE_PTR DELETES THE OBJECT WHEN THE UNIQUE_PTR OBJECT IS DELETED  -->

## <-- exmaple of memory leak -->
    int f1(){
        int *p = new int(10);
        if (some condition){
            <!-- If our code reached at this point then the function will return and delete statement will never execute and the p destroys after the function call but the memory location on which p is pointing is still their (THIS IS CALLED MEMORY LEAK) -->
            return value;
        }
        <!-- This delete statement will only run if the condition written inside the if blocks returns false  -->
        delete p;
    }

## <-- code for unique pointers -->
    int f1(){
        <!-- HERE WE ARE CREATING THE OBJECT OF UNIQUE_PTR CLASS AND PASSING THE RAW POINTERS AS THE ARGUMENT  -->
        unique_ptr<int> p(new int(10));
        if (some condition){
            return value;
        }
        <!-- NOW WHEN P DESTROY THEN THE DESTRUCTOR OF CLASS OBJECT WILL RUN AND THE CODE INSIDE THE 
        DESTRUCTOR WILL DESTROY THE RAW POINTERS AS WELL WE DON'T NEED TO EXPLIXITLY DESTROY/DELETE THE RAW POINTERS  -->
    }

## <-- WAYS TO CREATE UNIQUE_PTR -->
-     unique_ptr<int> p(new int(10));

-     unique_ptr<int> p;
      p.reset(new int(10));
#### reset function
if p is already holds a pointer to an existing object this object is deleted first and then the new pointer is stored 
WE CAN ALSO CALL THE RESET FUNCTION WITHOUT ARGUMENT THEN IT SIMPLY DELETES THE PREVIOUS OBJECT AND STORE NULL IN THE UNIQUE_PTR-->

## <-- PROPERTIES OF UNIQUE_PTR  -->

1 -> A unique_ptr is a container for a raw pointer

2 -> unique_ptr explicitly prevents copying of its contained pointer, but move() function can be used to transfer the ownership of   the contained pointer to another unique_ptr

3 -> No support of copy constructor and copy assignment operator.

### <-- example of nove function  -->
    unique_ptr<int> p(new int(1));
    unique_ptr<int> new_owner;
    new_owner = move(p);


<!-- SHARED POINTERS  -->