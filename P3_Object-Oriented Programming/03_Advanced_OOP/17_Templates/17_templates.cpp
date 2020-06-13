/*
Templates
With templates, the idea is to pass a data type as a parameter so that you don’t need
to write the same function code for operating on different data types.

For example, you might need a function that has to accept many different data
types in order for it to perform some operations or other actions on those data types.

Some of these actions can be dividing, sorting, etc.
Rather than writing and
maintaining the multiple function declarations, each accepting slightly different arguments,
you can write one function and pass the argument types as parameters.

At compile time, the compiler then expands the code using the types that are passed as parameters.

So if you write:

    template <typename Type>
        Type Sum(Type a, Type b) {
            return a+b;
    }

    int main() {
        std::cout << Sum<double>(20.0, 13.7) << std::endl;


The compiler adds the following internally:

double Sum(double a, double b) {
    return a+b;
}


Or in this case:

    std::cout << Sum<char> (‘Z’, ’j’) << std::endl;

The compiler adds:

    char Sum(char a, char b) {
        return a+b;
    }

In this example, you’ll notice that we use the keyword template to specify which
function is generic.

Generic code is the term used for code that is independent to types.

It is mandatory to put the template<> tag just above your function to specify and mark
which implementation is generic.

Besides template, you'll use the keyword typename, where you specify what mark is used to
indicate where the type is passed in a function prototype.

ex:
    template <typename XXX>
        XXX Sum(XXX a, XXX b) {
            return a+b;
    }

In stead of typename, C++ also
supports the keyword class ( template <class T>), but using typename is preferred.
Like normal parameters, you can specify the default arguments to templates.

Have a look at the example below in the notebook demonstrating the use of templates.

*/
#include<iostream>
#include <typeinfo>

//template<class T, class U = int>
template<typename T, typename U = int>

class ClassA  {
    public:
        T x;
        U y;
        ClassA() {
            std::cout << "Constructor Called" << "\n";
            std::cout << "x type:"<< typeid(x).name() << std::endl;
            std::cout << "y type:"<< typeid(y).name() << std::endl;
        }
};

template <typename Type>
    Type Sum(Type a, Type b) {
        return a+b;
}

template <typename Type, typename T2>
    Type Sum2(Type a, T2 b) {
        return a+b;
}

int main()
{
    ClassA<char,char> aobject01;  // This will call A<char, char>
    /*
    Constructor Called
    x type:c
    y type:c
    */
    ClassA<char> aobject02;  // This will call A<char, int>
    /*
    Constructor Called
    x type:c
    y type:i
    */

    //testing
    std::cout << Sum<double>(20.0, 13.7) << std::endl;
    std::cout << Sum(20.0, 13.7) << std::endl;
    std::cout << Sum(20, 13) << std::endl;
    std::cout << Sum2(20.1, 13) << std::endl;
}
