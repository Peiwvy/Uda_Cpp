/*
* Objectives
*   1. Create a class called Sphere.
*   2. Add one member variable: radius.
*   3. Create a member function to return the volume of the sphere.
*   4. Create a constructor to initialize the variable.
*   5. Write a main() function to initialize an object of type Sphere and print the volume.
*/
// Include iostream for printing
#include <iostream>
#include <cmath>

// Define class Sphere
class Sphere {
public:
    // Define public constructor
    Sphere(int radius)
    {
        if(radius >= 0) {
            radius_ = radius;
            volume_ = pi * 4 / 3 * pow(radius_, 3);
        }
    }
    
    // Define an accessor for the radius
    int radius() const { return radius_; }
    
    // Define an accessor for the volume
    double volume() const { return volume_; }
    
    constexpr double pi = 3.14159;

private:
    // Define private attributes
    int radius_ {0};
    double volume_ {0};
};
    
// Test in main()
int main(void)
{
    Sphere s(5);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
}


