// Example solution for creating a BankAccount class
/*
* Objectives:
*   1. Create class called BankAccount
*   2. Use typical info about bank accounts to design attributes, such as the account number, the owner name, and the available funds.
*   3. Set the access modifiers so that member data are protected from other parts of the program.
*   4. Create getters and setters for all class attributes.
*/
#include <iostream>
#include <string>

class BankAccount
{
    private:
      // Class attributes:
        long int number;
        std::string owner;
        float amount;

    public:
      // Set  methods:
        void setNumber(long int number);
        void setOwner(std::string owner);
        void setAmount(float amount);
      // Get methods:
        long int getNumber() const;
        std::string getOwner() const;
        float getAmount() const;
};

// Implementation of Set methods:
void BankAccount::setNumber(long int number) {
    // Changing attribute to incoming value
    BankAccount::number = number;
}

void BankAccount::setOwner(std::string owner) {
    BankAccount::owner = owner;
}

void BankAccount::setAmount(float amount) {
    BankAccount::amount = amount;
}

// Implementation of Get methods:
long int BankAccount::getNumber() const {
    // Getting specified attribute
    return BankAccount::number;
}

std::string BankAccount::getOwner() const {
    return BankAccount::owner;
}

float BankAccount::getAmount() const {
    return BankAccount::amount;
}

// main function
int main(){
    BankAccount acc1;
    acc1.setOwner("Deep");
    acc1.setNumber(12345);
    acc1.setAmount(1000.0);
    
    std::cout << "Account OwnerName : " << acc1.getOwner() << "\n";
    std::cout << "Account Number : " << acc1.getNumber() << "\n";
    std::cout << "Account Amount : " << acc1.getAmount() << "\n";
}