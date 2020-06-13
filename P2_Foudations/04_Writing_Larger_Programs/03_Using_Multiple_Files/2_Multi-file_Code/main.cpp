/*
Multi-file Code
In the next few cells these functions have been separated into several different files.
The structure of the included files is as follows:
        increment_and_sum -->main
*/

#include <iostream>
#include <vector>

#include "increment_and_sum.h"

using std::vector;
using std::cout;

int main()
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}

/*
IDEA:

    g++ -std=c++17 ./main.cpp ./increment_and_sum.cpp


    If you look carefully at the files above, you will see several things:

    a.vect_add_one.h is included in increment_and_sum.cpp.

        This is becuase AddOneToEach is used in IncrementAndComputeVectorSum.
        Including the vect_add_one.h header means that the AddOneToEach function declaration is pasted into  increment_and_sum.cpp,
        so no compiler error will occur when the AddOneToEach function is used.

    b.Only the header file needs to be included in another file.

        As long as the header file is included, the corresponding function declarations will be included. When the compiler finds an undefined function,
        it has already seen the function's declaration. This means the compiler can continue on without error until
        it finds the definition of the function, regardless of where that definition is.

    c.Some libraries, like <vector> are included in mutliple files.

        Each file is compiled alone and must have all the declarations and libraries necessary to compile,
        so the necessary libraries must be included. This is another reason why include guards are important -
        if multiple headers were included in main, each with the same #include <vector> statement,
        you wouldn't want the vector header pasted multiple times into the code.


*/