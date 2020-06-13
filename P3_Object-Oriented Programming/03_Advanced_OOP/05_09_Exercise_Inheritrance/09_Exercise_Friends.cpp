/*

Friends

In C++, friend classes provide an alternative inheritance mechanism to derived classes.

The main difference between classical inheritance and friend inheritance is that a
friend class can access private members of the base class,
which isn't the case for classical inheritance.

In classical inheritance, a derived class can only access public and protected members of the base class.

example:

class A
{
    friend class B;
};

class B
{
};

Class B is declared as a friend of class A in the above code. 
So, now all the member functions of class B became friend functions of class A.

Instructions
In this exercise you will experiment with friend classes. In the notebook below, implement the following steps:
    1.Declare a class Rectangle.
    2.Define a class Square.
    3.Add class Rectangle as a friend of the class Square.
    4.Add a private attribute side to class Square.
    5.Create a public constructor in class Square that initializes the side attribute.
    6.Add private members width and height to class Rectangle.
    7.Add a Rectangle() constructor that takes a Square as an argument.
    8.Add an Area() function to class Rectangle.
*/

// Example solution for Rectangle and Square friend classes
#include <assert.h>
#include <iostream>

class Rectangle;

class Square{
public:
    Square(int s): side(s){}
    void test(){
        std::cout << side << std::endl;
    }
private:
    friend class Rectangle;
    int side;
};

class Rectangle{
public:
    Rectangle(Square& s): width(s.side),height(s.side){};
    float Area() const{
        return width*height;
    }
private:
    float width;
    float height;
};

int main()
{
    Square square(4);
    square.test();
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
    std::cout << rectangle.Area() <<  std::endl;
}
