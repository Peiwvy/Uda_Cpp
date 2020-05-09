/*
* Objectives:
*    1. Create a class: Pyramid.
*    2. Create 3 attributes: base_length, base_width, height (this is a square pyramid).
*    3. Create a constructor to initialize all the attributes.
*    4. Create getters and setters for all attributes.
*    5. Create a member function to calculate the volume of the pyramid.
*    6. Optional: create a member function to calculate the surface area of the pyramid.
*    7. Optional: create a member function to check if the attribute values are less than or equal to zero and return an error if they are.
*
* Volume : (bl x bw × h)/3
* Area : (bl*bw + bl*sqrt((bw/2)*(bw/2) + h*h) + bw*sqrt((bl/2)*(bl/2) + h*h))
*       where, bw = base_width
*              bl = base_length
*               h = height
*/
#include <iostream>
#include <cmath>
 // Partial example solution (no surface area or error checking)

class Pyramid {

    private:
        // private class attributes
        double base_length;
        double base_width;
        double height;

    public:
        // constructor for "Pyramid"
        Pyramid (double bl, double bw, double h){

            base_length = bl;
            base_width = bw;
            height = h;
        }

        // getter methods
        double getBaseLength(){
            return base_length;
        }
            // gets base width
        double getBaseWidth(){
            return base_width;
        }
          // gets base height
        double getHeight(){
            return height;
        }
        // public method that finds volume of pyramid
        double returnVolume(){
            // formula for calculating volume of pyramid
            return (base_length*base_width*height) / 3;
        }
};

int main(){
    Pyramid p(1, 1, 1);
    std::cout << p.returnVolume() << std::endl;
}