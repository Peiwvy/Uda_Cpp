/*

Composition
Composition is a closely related alternative to inheritance. Composition involves constructing ("composing")
classes from other classes, instead of inheriting traits from a parent class.

A common way to distinguish "composition" from "inheritance" is to think about what an object can do,
rather than what it is. This is often expressed as "has a" versus "is a".

    1. has a -> Composition
    2. is a -> Inheritance

From the standpoint of composition, a cat "has a" head and "has a" set of paws and "has a" tail.

From the standpoint of inheritance, a cat "is a" Aniamal.

There is no hard and fast rule about when to prefer composition over inheritance.

In general,
if a class needs only extend a small amount of functionality beyond what is already offered by another class,
it makes sense to inherit from that other class.

However, if a class needs to contain functionality from a
variety of otherwise unrelated classes, it makes sense to compose the class from those other classes.

In this example, you'll practice working with composition in C++.
*/

/*

Instructions
In this exercise, you will start with a LineSegment class and create a Circle class.

Note that you will compose Circle from LineSegment, instead of inheriting Circle from LineSegment.
Specifically, the length attribute from LineSegment will become the circle's radius.

    1.Create a class LineSegment.
    2.Declare an attribute length in class LineSegment.
    3.Define pi (3.14159) with a macro.
    4.Create a class Circle, composed of a LineSegment that represent's the circle's radius.
    Use this radius to calculate the area of the circle (area of a circle = \pi r^2πr2).
    5.Verify the behavior of Circle in main().
*/
#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
//static const float pi = 3.1415926;
#define PI 3.14159

// Define Line Class
class LineSegment{
public:
    // Define protected attribute length
    double get_len(){return length;}
    void set_len(double l){
        length = l;
    }
protected:
    double length;
};

// Define Circle subclass
class Circle{
public:
    Circle(LineSegment& l):radius_(l){}
    void setRadius(LineSegment& r){
        radius_ = r;
    }
    double Area(){
        return PI*pow(Circle::radius_.get_len(),2);
    }
private:
    LineSegment& radius_;
};

// Test in main()
int main()
{
    LineSegment radius;
    radius.set_len(3);
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
    std::cout << circle.Area() << std::endl;
}
