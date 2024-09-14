# --> PRE PROCESSOR DIRECTIVES <--

Preprocessor directives are lines of source code that are processed before compilation 

# include is also a pre preocessor directives 

--> In C/C++, the preprocessor directive #define creates a macro, which is a token string associated with an identifier or parameterized identifier. The compiler can then substitute the token string for each occurrence of the identifier in the source file.

# MACROS 
A macro is a label defined in the source code that is replaced by its value by the preprocessor before compilation. Macros are initialized with the #define preprocessor command and can be undefined with the #undef command.

## There are two types of macros: object-like macros and function-like macros.

### Object-Like Macros
These macros are replaced by their value in the source code before compilation. Their primary purpose is to define constants to be used in the code.

- #### Note: Macro definitions are not followed by a semicolon ;.

### Function-Like Macros
These macros behave like functions, in that they take arguments that are used in the replaced code.

- #### Note: When defining a function-like macro, there cannot be a space between the macro name and the opening parenthesis.

# Conditional macros
- are achieved using the preprocessor directives #if, #ifdef, #ifndef, #elif, #else, and #endif. 
- These directives allow you to include or exclude portions of your code based on certain conditions.

## Here's how they work:
- #ifdef: Checks if a macro is defined.
- #ifndef: Checks if a macro is not defined.
- #if: Checks if an expression evaluates to true.
- #elif: Used for else-if conditions.
- #else: Used for else conditions.
- #endif: Marks the end of the conditional block.