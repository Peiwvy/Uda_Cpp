// Partial example solution for Car class 
/*
* Objectives:
*   1. Create a class called Car.
*   2. Create 3 member variables: horsepower, weight and brand. The brand attribute must be a character array.
*   3. Create getter and setter functions for all attributes. The setter function for brand must accept a C++ string as a parameter 
*      and convert that string into a C-style string (a character array ending in null character) to set the value of brand.
*   4. The getter function for the brand must return a string, so in this function you first will need to convert brand to a std::string, and then return it.
*/
// getters and setters for brand only
#include <string>
#include <cstring>
#include <iostream>
// Define Car class
class Car {
    // Define private attributes
    private:
        int horse_power;
        int weight;
        char *brand;
        // 1. 这个地方之所以是*brand 是因为大小一开并不知道 要是动态的 比如BMW 和 Mercedez就不一样 要用指针
    // Declare public getter and setter
    public:
        void SetBrand(std::string brand_name);
        std::string GetBrand() const;
};

// Define setter
void Car::SetBrand(std::string brand_name) {
    // Initialization of char array
    Car::brand = new char[brand_name.length() + 1];
    // copying every character from string to char array;
    // 2.c_str()返回的是指针
    strcpy(Car::brand, brand_name.c_str());
}

// Define getter
std::string Car::GetBrand() const {
    std::string result = "Brand name: ";
    // Specifying string for output of brand name
    result += Car::brand;
    return result;
};

// Test in main()
int main() {
    Car car;
    car.SetBrand("peugeot");
    std::cout << car.GetBrand() << "\n";
}