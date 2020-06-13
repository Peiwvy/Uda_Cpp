
/*
Instructions
    1.Update the derived classes so that one has protected inheritance and one has private inheritance.
    2.Try to access a protected member from main(). Is it possible?
    3.Try to access a private member from main(). Is it possible?
    4.Try to access a member of the base class from within the derived class that has protected inheritance. Is it possible?
    5.Try to access a member of the base class from within the derived class that has private inheritance. Is it possible?
*/

// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
    void set_wheel(int w){
        wheels = w;
    }
};

class Scooter : private Vehicle {
public:
    bool electric = false;
    void set_wheel(int w){
        wheels = w;
    }
};

int main()
{
    Car car;
    car.wheels=4;

    Bicycle bicycle;
    bicycle.set_wheel(2);//pass
    
    Scooter scooter;
    scooter.set_wheel(2);
}
