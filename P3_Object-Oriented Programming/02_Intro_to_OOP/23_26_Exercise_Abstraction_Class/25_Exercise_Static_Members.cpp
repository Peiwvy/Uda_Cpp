/*
* NOTES:
*  Abstraction is used to show only relevant information to the user and hide any irrelevant details.
* Static attribute is shared by all instances of a class in a program.
*/

// Class members can be declared static, which means that the member belongs to the entire class, 
// instead of to a specific instance of the class. More specifically, 
// a static member is created only once and then shared by all instances (e.g. objects) of the class. 
// That means that if the static member gets changed, either by a user of the class or
// within a member function of the class itself, 
// then all members of the class will see that change the next time they access the static member

// Most of the code is similar to previous exercise with minor addition for static attributes

#include <iostream>

class Abstract
{
    private:
        static int counter; // Counter of class objects
        int number;
        char character;
        void ProcessAttributes();

        public:
            Abstract() { counter++; }
            void SetVariables(int num, char chr); 
            void GetMethod();
            int GetCounter();
};

/* 
* It is required to specify the initial value in the global scope of the program.
* Declaration and initialization in class body it viewed as declaration of const static member.
*/ 

int Abstract::counter = 0;

void Abstract::ProcessAttributes() {
    Abstract::number *= 6;
    Abstract::character++;
    }

void Abstract::SetVariables(int num, char chr) { 
    Abstract::number = num; 
    Abstract::character = chr; 
    }

void Abstract::GetMethod() {
    Abstract::ProcessAttributes();
    std::cout << "Modified value of number : " << Abstract::number << "\n";
    std::cout << "Modififed value of character : " << Abstract::character << "\n";
    }

int Abstract::GetCounter() { 
    return Abstract::counter; 
    }

int main() {
    Abstract ab1;
    ab1.SetVariables(3, 'a');
    ab1.GetMethod();
    std::cout << "Value of static counter : " << ab1.GetCounter() << "\n";

    Abstract ab2;
    ab2.SetVariables(1, 'x');
    ab2.GetMethod();
    std::cout << "Value of static counter : " << ab2.GetCounter() << "\n";
}