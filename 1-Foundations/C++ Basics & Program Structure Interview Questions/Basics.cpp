//1. How does C++ enable both high-level and low-level programming, and what features make it suitable for systems-level development?
   //C++ is called a middle-level language because it combines the features of both high-level and low-level programming. 

  //  High-level features: It supports abstraction, object-oriented programming, templates, and 
  //the standard library, which make writing complex applications easier and closer to human thinking.

  //  Low-level features: It allows direct memory management using pointers, inline assembly, and 
  // hardware-level manipulation, which makes it suitable for systems programming like operating systems, 
  // compilers, and device drivers.

  //Reasons why C++ is suitable for systems-level development:

  //1- Direct Memory Access: Through pointers and pointer arithmetic.
  //2- Manual Resource Management: Developers can control memory allocation/deallocation using new and delete.
  //3- Performance: Minimal runtime overhead compared to other higher-level languages.
  //4- Object-Oriented Design: Helps in organizing large system codebases (e.g., OS kernels, databases).

  #include <iostream>
using namespace std;

int main() {
    int x = 10;          // high-level: simple variable
    int* p = &x;         // low-level: direct memory access with pointer

    *p = 20;             // modifying value through pointer
    cout << "x = " << x << endl;

    return 0;
}

// High-level: int x = 10; shows simple variable handling.
// Low-level: int* p = &x; and *p = 20; show direct memory manipulation.
// It clearly demonstrates how C++ can act at both levels in just a few lines.


//2. Whats is 'namespace std'?
//'std' stands for Standard. It is a namespace in C++. Namespace is a feature that provides a way 
// to group related identifiers such as variables, functions, and classes under a single name. The line 
// "using namespace std" informs the compiler to add everything under the std namespace and inculcate 
// them in the global namespace. This all inculcation of global namespace benefits us to use "cout" and 
// "cin" without using "std::_operator_".

#include <iostream>
using namespace std;

int main() {
    cout << "Hello using std namespace!" << endl;
    return 0;
}


// 3. What are references in C++?

// In C++, references is a way to create an alias for another variable.

//  1-   A reference acts as a synonym for a variable, allowing you to access the variable directly without
//      any additional syntax.
//   2-  They must be initialized when created and cannot be changed to refer to another variable afterward.
//   3-  This feature makes it easier to manipulate variables in functions while avoiding the overhead of 
//     copying large objects. A reference variable is preceded with a '&' symbol.

// Syntax:

//     int GFG = 10;
//     // reference variable
//     int& ref = GFG;

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &ref = a;

    ref = 20;
    cout << "a = " << a << ", ref = " << ref << endl;
    return 0;
}


// 4. Define the Block scope variable. 

// A block scope variable is also known as a local scope variable. A variable that is defined inside a 
// function (like main) or inside a block (anything enclosed with curly braces like loops and if else) 
// is a local variable. A block-scoped variable will not be available outside the block even if the 
// block is inside a function.

#include <iostream>
using namespace std;

int main() {
    int a = 10; // local to main

    if (a > 5) {
        int b = 20;  // block scope inside if-block
        cout << "Inside if-block: a = " << a << ", b = " << b << endl;
    }
    for (int i = 0; i < 3; i++) {
        int temp = i * 10;  // block scope inside for-loop
        cout << "temp = " << temp << endl;
    }

    return 0;
}


// 5. What does the "auto" keyword do?

// The auto keyword is a type inference specifier introduced in C++11, which tells the compiler to automatically deduce the type of a variable from its initializer expression.

// Primary Function of auto:

//     Simplifies declarations (especially for iterators, lambdas, template types).
//     Enhances code readability and maintainability.
//     Reduces redundancy and typing errors.
//     Promotes use of generic programming.

// Use Case: With Iterators use this

#include <iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4};
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    return 0;
}

//Instead of this:

//std::vector<int>::iterator it = v.begin();



// 6. What do you mean by Pass by Value and Pass by Reference?

// In this programming language to call a function we have 2 methods: Pass by Value and Pass by Reference
// Pass by Value                                            Pass by Reference
	
// A copy of a variable is passed.	                    Either the address of variable or reference to 
//                                                       the variable is passed.

//                                                     The changes made in the functions can be seen 
//                                                     outside the function on the passed function. 
//                                                   In short, the original value is altered in Call 
//   The changes made in the function are never            by reference.
// reflected outside the function on the variable. 
// In short, the original value is never altered 
// Passed actual and formal parameters are stored 
// in different memory locations. Therefore, making
//  Call by Value a little memory inefficient. 

//                                                     Passed actual and formal parameters are stored in 
//                                                     the same memory location. Therefore, making Call 
//                                                     by Reference a little more memory efficient.