// /*
// * Runtime polymorphism is accomplished by performing function overriding.
// *
// * Function overriding occurs when a derived class function calls its own definition of a method, 
//     instead of the base class's implementation. In this case, the base class's method has been "overridden."
// *
// *
// * OBJECTIVES
// *   1. Declare Base and Derived class.
// *   2. Override some method.
// *   3. Leave other methods as inherited.
// *   4. Try to invoke them in main().
// */


// #include <iostream>

// // Define class Base
// class Base
// {
//     public:
//         // Declare an empty public constructor
//         Base() {}
    
//         // Define virtual print() function
//         virtual void print() {
//             std::cout << "Print from Base class" << "\n";
//         }
    
//         // Define non-virtual calc() function
//         void calc() {
//             std::cout << "Calc from Base class" << "\n";
//         }
// };



// // Define subclass Derived that publicly inherits from Base
// class Derived : public Base
// {
//     public:
//         // Declare an empty public constructor
//         Derived() {}
    
//         // Define print() function
//         void print() {
//             std::cout << "Print from Derived class" << "\n";
//         }
    
//         // Define calc() function
//         void calc() {
//             std::cout << "Calc from Derived class" << "\n";
//         }
// };


// int main() {
//     Base *base_ptr;
//     Derived derived;
    
//     base_ptr = &derived;
    
//     //virtual function, binded at runtime (Runtime polymorphism)
//     base_ptr->print();
    
//     // Non-virtual function, binded at compile time
//     base_ptr->calc();
// }


// /*
// * ---------------------------------------
// * OUPUT:
// *   Print from Derived class
// *   Calc from Base class
// * ---------------------------------------
// */

/*

Using function overload you can achieve the same thing. Consider the following example:

OBJECTIVES
    Create class Point
    Create coordinates for the point x and y as two variables of type double and a constructor to initialise them.
    Use print() function to implement overload.
    Overload function with zero, one, and two parameters.
    Check that when you invoke p.print() without any parameters, the original function is called.
    After that you can invoke it with parameters and the overloaded function will be called instead

*/

// Example solution of function overload
// include iostream for printing
#include<iostream>
// Define Point class
class Point {
    // Declare private attributes x and y
    private:
        int x, y;
    // Define public constructor
    // Define operator overload
    // Define Print() function
    // Overload Print() function to take 1 or 2 input params
    public:
        Point(int xc = 0, int yc = 0) : x(xc), y(yc) {}

        Point operator + (Point const &obj) {
            Point res;
            res.x = Point::x + obj.x;
            res.y = Point::y + obj.y;
            return res;
        }

        // Print function
        void Print() {
            std::cout << "{ x: " << Point::x << ", y: " << Point::y << " }" << "\n";
        }
        // Overloaded function, they are same print function, but they’re overloaded with number // of input parameters
        void Print(int x) {
            std::cout << "{ x: " << x << ", y: " << Point::y << " }" << "\n";
        }
        void Print(int x, int y) {
            std::cout << "{ x: " << x << ", y: " << y << " }" << "\n";
        }
};
// Test in main()
int main() {
    Point p1(10, 5), p2(2, 4);
    Point p = p1 + p2; // An example call to "operator +"
    p.Print();
    p.Print(66);
    p.Print(66, 77);
    p.Print();
}
