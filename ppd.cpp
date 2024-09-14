// PRE PROCESSOR DIRECTIVES 
// Preprocessor directives are lines of source code that are processed before compilation 

// #include is also a pre preocessor directives 
#include "oops_13.cpp"

// In C/C++, the preprocessor directive #define creates a macro, which is a token string associated with an identifier or parameterized identifier. The compiler can then substitute the token string for each occurrence of the identifier in the source file.

// EXAMPLE OF MACROS OBJECT TYPE MACRO

#define LEARN "I am learning the basic of pre processor \
directives if my macro is extend to multiple line \
then i have to use backslash like i am using here"

#define ONE 1
#define TWO ONE+ONE
#define THREE TWO+ONE

#define WINDOWS 1
#define LINUX 2
#define MAC 3

#define OS MAC


// EXAMPLE OF FUNCTION TYPE MACROS 
#define LARGEST(num1,num2) (num1 < num2 ? num2 : (num1))
int main(){
    // EXAMPLE OF CONDITIONAL MACROS  
    #if OS == MAC
        cout<<"mac user"<<endl;
    #elif OS == WINDOWS
        cout<<"windows user"<<endl;
    #else
        cout<<"Linux user"<<endl;
    #endif
    // CHECKS FOR THAT OS MACRO IS DEFINED OR NOT IF YES THEN BLOCK INSIDE THIS EXECUTED
    #ifdef OS 
    cout<<"define"<<endl;
    #endif

    // OPPOSITE OF #ifdef 
    #ifndef OS1
    cout<<"not defined"<<endl;
    #endif
    // USED TO UNDEFINE A MACRO  
    #undef OS

    // C++ PRDEFINED MACROS 

    cout<<"current line is "<<__LINE__<<endl;
    cout<<"current file is "<<__FILE__<<endl;
    cout<<"todays date is "<<__DATE__<<endl;
    cout<<"current time is "<<__TIME__<<endl;
    cout<<"standard c++ code "<<__STDC__<<endl;
    cout<<"standard c plus plus conforming "<<__cplusplus<<endl;

    // HOW TO CHANGE THE VALUE OF LINE AND FILE MACROS 

    #line 1000 "vaibhav.txt"
    cout<<"current line is "<<__LINE__<<endl;
    cout<<"current file is "<<__FILE__<<endl;

    Student st;
    whoIsThis(st);
    cout<<LEARN<<endl;
    cout<<THREE<<endl;
    cout<<LARGEST(2,3)<<endl;
    return 0;
}
