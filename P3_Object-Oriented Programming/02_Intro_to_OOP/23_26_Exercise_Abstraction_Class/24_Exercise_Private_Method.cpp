// In this exercise, you'll update the class Sphere so that it becomes possible to change 
// the radius of a sphere after it has been initialized. In order to do this, 
// you'll move the two class invariants into private member functions.

// 1.Move the range-check on radius_ into a private member function.
// 2.Move the volume_ calculation, which depends on the value of radius_ into the same private member function.
// 3.Verify that the class still functions correctly.
// 4.Add a mutator method to change the radius of an existing Sphere.
// 5.Verify that the mutator method successfully updates both the radius and the volume.
#include <iostream>
#include <cmath>

class Sphere {
public:
    Sphere(int radius)
    {
        Update_(radius);
    }
    
    int radius() const { return radius_; }
    void radius(int length) { Update_(length); }
    
    double volume() const { return volume_; }
    
    const double pi = 3.14159;

private:
    int radius_ {0};
    double volume_ {0};
    
    void Update_(int radius)
    {
        // DONE: Move this block into a private member function
        if(radius >= 0) {
            radius_ = radius;
            volume_ = pi * 4 / 3 * pow(radius_, 3);
        }
    }
};
    
// Test in main()
int main(void)
{
    Sphere s(5);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
    s.radius(3);
    std::cout << s.radius() << "\n";
    std::cout << s.volume() << "\n";
}