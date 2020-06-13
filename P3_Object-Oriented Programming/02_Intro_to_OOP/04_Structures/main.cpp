// Include iostream for output
#include <iostream>

// Define a simple structure
struct Date {
  int day;
  int month;
  int year;
};

// Define a main function to instantiate and test
int main()
{
    Date date;
    date.day = 1;
    date.month = 10;
    date.year = 2019;
    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}
