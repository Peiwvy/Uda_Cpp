/*
* Static methods are functions that are a part of the class interface, but they are instance independent.
* The scope of static methods is much larger in the sens that it don't require any object to initialize it.
*/

// 1.Refactor class Sphere to move the volume calculation into a static function.
// 2.Verify that the class still functions as intended.
// 3.Make that static function public.
// 4.Call that static function directly from main() to calculate the hypothetical volume of
//     a sphere you have not yet instantiated.

#include <iostream>

class Abstraction
{
    private:
        int number;
        char character;

    public:
        void static PrintCharAsNumber(char c);
};

void Abstraction::PrintCharAsNumber(char c) {
    int result = 'c';
    std::cout << c << "\n";
    std::cout << result << "\n";
}

int main() {
    char c = 'A';
    Abstraction::PrintCharAsNumber(c);  // calling class method without creating class instance
}