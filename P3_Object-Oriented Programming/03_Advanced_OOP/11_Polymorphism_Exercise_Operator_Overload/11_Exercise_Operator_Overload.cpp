/*

Exercise: Operator Overload
Thus far, you've experimented with two types of polymorphism in C++.

These are runtime and compile time polymorphism. You've already seen how compile time
polymorphism is achieved with function overloading.


In this lab you'll see it can be
used for operator overloading as well. In fact, you can define any operator in the
ASCII table and give it your own set of rules!

Operator overloading can be useful for many things. Consider the + operator.
We can use it to add ints, doubles, floats, or even std::strings.

Imagine vector addition. You might want to perform vector addition on a pair of
points to add their x and y components.

The compiler won't recognize this type of
operation on its own, because this data is user defined. However, you
can overload the + operator so it performs the action that you want to implement.


OBJECTIVES
    1.Create Point class.
    2.Define its constructor.
    3.Define its methods and interface.
    4.Declare prototype of overload method for + operator.
    5.Implement logic.
    6.Write main() function test.
*/


#include <iostream>

class Point{
private:
    int x;
    int y;
public:
    Point(int inx=0,int iny=0): x(inx), y(iny){}

    Point operator - (Point const &obj){
        Point res;
        res.x = x-obj.x;
        res.y = y-obj.y;
        return res;
    }
    Point operator + (Point const &obj)
    {
        Point res;
        res.x = Point::x + obj.x;
        res.y = Point::y + obj.y;
        return res;
    }

    void Print(){
        std::cout << "Point: (" << Point::x << ", " << Point::y << ")"<< "\n";
    }
};

int main()
{
    Point p1(10, 5);
    Point p2(2, 4);
    Point p = p1 + p2;
    p1.Print();
    p2.Print();
    p.Print();

    p = p1-p2;
    p.Print();

}
