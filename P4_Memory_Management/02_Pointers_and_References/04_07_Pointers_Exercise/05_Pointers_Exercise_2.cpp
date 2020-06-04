/*
LAB 2
Objectives 2
In this example we are showing technique of an implementation of function which
will return multiple values. Using pointers we can implement this via references.
If we take into consideration that passage of data by reference doesn't copy this object,
we can pass our object to a function and execute required actions. In this example we are
going to make a primitive function which calculates cosine and sine values of a specific
angle (in radians) using just one function.

Steps 2
    Include standard library iostream
    Include math.h library for usage of trigonometrical functions
    create a function which will have three parameters: _sin, _cos and angle. all
        parameters are double
    Return type of this function is void
    Declare input parameters (except angle variable) as pointers to double type
    Create main function
    Declare three double variables: angle, _sin, _cos
    Ask for input value of angle via cin from a user
    Call trigonometry function (pass sin and cos variables by references)
    Print results in console
*/

#include <iostream>
#include <cmath>

void trigonometry(double angle, double *_sin, double *_cos){
    *_sin = std::sin(angle);
    *_cos = std::cos(angle);
}

int main(){
    double _sin, _cos;
    double angle = 0;

    double *ptr = nullptr;
    ptr = &angle;

    std::cout << "angle memory address:" << ptr << std::endl;
    std::cout << "angle memory address value:" << *ptr << std::endl;

    std::cout << " Trigonometry values are: " << std::endl;
    trigonometry(*ptr, &_sin, &_cos);
    // trigonometry(angle, &_sin, &_cos);  OK too
    std::cout << "Sine is: "<< _sin << std::endl;
    std::cout << "Cosine is: "<< _cos << std::endl;

    return 0;
}
// angle memory address:0x7ffee080b7b0
// angle memory address value:0
//  Trigonometry values are: 
// Sine is: 0
// Cosine is: 1