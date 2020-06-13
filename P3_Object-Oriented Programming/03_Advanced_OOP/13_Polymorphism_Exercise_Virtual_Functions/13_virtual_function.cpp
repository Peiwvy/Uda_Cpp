/*
Exercise: Virtual Functions

Polymorphism is one of the crucial components of OOP within C++. In this lab,
you'll use virtual methods and see their role in class interfaces and in the process of inheritance.

*
This approach declares an interface at the base level, 
but*delegates the implementation of the interface to the derived classes.
*

Virtual methods are declared (and possibly defined) in a base class, and are meant
to be overridden by derived classes. This approach creates interfaces for your classes at the base level.

Here, you'll start with a Shape class as the base class for geometrical 2D entities.
Geometrical shapes (closed curves) can be described by an area and the length of their perimeter.
area and perimeter_length should be methods of the base class interface.

You'll declare each of these as virtual functions with a const = 0 flag to identify them as prototypes in the base class like this:

    class Shape {
        public:
            Shape() {}
            virtual double Area() const = 0;
            virtual double PerimeterLength() const = 0;
    };
We said that in the base class, virtual methods can but do not have to be implemented.
If we delegate with instruction = 0 we are notifying compiler that this (base) class doesn’t
have virtual method implementation but every other derived class is required to implement this method.

virtual double Function() const override{
}

OBJECTIVES
    1.Create base class called Shape.
    2.Chose mutual characteristics of every shape in geometry.
    3.Divide it in individual logical responsibilities.
    4.Design methods for base class and make them pure virtual functions const = 0.
    5.Write the derived classes.
        Inherit parent Shape class.
        Write derived implementation of overridden base methods.
    6.Test in main()

*/


#include <iostream>
#include <cmath>
#define PI 3.1415926
class Shape{
public:
    Shape(){}
    // Define public virtual Area() and PerimeterLength()
    virtual double Area() const = 0;
    virtual double PerimeterLength() const = 0 ;
    //const = 0 specifier in interface is telling the compiler that this method must be implemented in one of the derived classes
    // For this class it is just part of the interface
};

class Rectangle : public Shape{
private:
    double width = 0;
    double height = 0;
public:
    Rectangle(double w, double h) :width(w), height(h){}
    // Override virtual base class functions
    virtual double Area() const override{
        std::cout << "Rectangle Area:" << width * height << "\n";
        return width * height;
    }
    virtual double PerimeterLength() const override {
        std::cout << "Rectangle PerimeterLength:" <<2*(width + height)<< "\n";
        return 2*(width + height);
    }
};

class Circle : public Shape{
private:
    double radius = 0;
public:
    Circle(double r): radius(r){}
    virtual double Area() const override{
        std::cout << "Circle Area:" <<PI*pow(radius,2)<< "\n";
        return  PI*pow(radius,2);
    }
    virtual double PerimeterLength() const override{
        std::cout << "Circle PerimeterLength:" <<2*PI*radius<< "\n";
        return 2*PI*radius;
    }
};

int main(){
    // Generic containter of Shapes (array) :
    Shape** shapes = new Shape*[2];
    shapes[0] = new Circle(12.31);
    shapes[1] = new Rectangle(10, 6);
    for (int i = 0;i < 2;i++) {
        std::cout << "Area: " << shapes[i]->Area()<< "\n";
        std::cout << "Perimeter: " << shapes[i]->PerimeterLength() << "\n";
        }
}
// Area: Circle Area:476.065
// 476.065
// Perimeter: Circle PerimeterLength:77.346
// 77.346
// Area: Rectangle Area:60
// 60
// Perimeter: Rectangle PerimeterLength:32
// 32