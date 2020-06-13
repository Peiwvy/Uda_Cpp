/*
Polymorphism: Overriding --> run time

The second type of polymorphism is function overriding.

"Overriding" a function occurs when multiple definitions of a function have the same signature (same name and same arguments).
In practice, each of the function definitions should have a different function definition (i.e. implementation).
That's not strictly required, but there's really no benefit to function overriding if the same
function signature leads to the same function definition.

Each time that function signature is called, one definition of the function will override the others.
Which version overrides the others may change based on context.

When a member function is defined in both a base class and a derived class, the definition in the derived
class overrides the definition in the base class.

Exercise
In this exercise, you will build two vehicle motion models, and overload the Move() member function.


//Model 1
The first motion model will be class ParticleModel.
In this model, the state is x, y, and theta (heading).
The Move(double v, double theta) function for this model includes instantaneous steering:

    theta += phi
    x += v * cos(theta)
    y += v * cos(theta)




//Model 2
The second motion model will be class BicycleModel.
In this model, the state is x, y, theta (heading),
and L (the length of the vehicle).
The Move(double v, double theta) function for this model is affected by the length of the vehicle:

    theta += v / L * tan(phi)
    x += v * cos(theta)
    y += v * cos(theta)


You are encouraged to read more about vehicle motion, but for the purposes of practicing function overriding,
the precise motion models are not so important. What is important is that the two models, and thus to the two Move()
functions, are different.

http://www.cs.cmu.edu/~motionplanning/reading/PlanningforDynamicVeh-1.pdf

Instructions:
    1.Define class ParticleModel, including its state and Move() function.
    2.Extend class BicycleModel from class ParticleModel.
    3.Override the Move() function within class BicycleModel.
    4.Pass the tests in main() by verifying that the two Move() functions override each other in different scenarios.

*/

#include <assert.h>
#include <cmath>
#include <iostream>
// TODO: Define PI
#define PI 3.1415926
// TODO: Define ParticleModel

class ParticleModel{
    // TODO: Define the Move() function for ParticleModel
public:
    void Move(double v, double phi){
        theta += phi;
        x += v * cos(theta);
        y += v * cos(theta);
        std::cout <<"Move in ParticleModel"<<std::endl;
    }

    void get_info(){
        std::cout<< x<< ",add:"<< &x << std::endl;
        std::cout<< y<< ",add:"<< &y << std::endl;
        std::cout<< theta<< ",add:"<< &theta << std::endl;
        std::cout <<"get_info in ParticleModel"<<std::endl;
    }

//private:
    //x, y is the position
    double x = 0;
    double y = 0;
    //theta is the heading of object
    double theta = 0;
};

// TODO: Inherit BicycleModel from ParticleModel
class BicycleModel : public ParticleModel{
    // TODO: Define the move() function for BicycleModel
public:
    void Move(double v, double phi){
        theta += v / L * tan(phi);
        x += v * cos(theta);
        y += v * cos(theta);
        std::cout <<"Move in BicycleModel"<<std::endl;
    }
    void get_info(){
        std::cout<< x<< ",add:"<< &x << std::endl;
        std::cout<< y<< ",add:"<< &y << std::endl;
        std::cout<< theta<< ",add:"<< &theta << std::endl;
        std::cout <<"get_info in BicycleModel"<<std::endl;
    }
private:
    //the length of the vehicle
    double L = 1;
};
// TODO: Pass the tests
int main()
{
    ParticleModel particle;
    BicycleModel bicycle;

    particle.get_info();
    bicycle.get_info();

    particle.Move(10, PI/9);
    bicycle.Move(10, PI/9);
    
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);

    particle.get_info();
    bicycle.get_info();
}
