#include <iostream>
#include <string>
// Declaring function:
// Prototype of this function
// has input parameters of constant referenced pointer to
// char data type
// Note: Notice that function doesn't have any return values.

void addSpaces(const char* &str) {
    char *temp = new char(sizeof(str)*2);
    char *start = temp;

    while (*str != '\0') {
        *temp++ = *str++;
        *temp++ = ' ';
    }

    str = start;
}


int main() {
    std::string str = "Hello World";
    const char* ptr = str.c_str();
    std::cout<<"string is: "<<ptr<<std::endl;
    addSpaces(ptr);
    std::cout<<"string is: "<<ptr<<std::endl;
    return 0;
}
// outcome:
// string is: Hello World
// string is: H e l l o   W o r l d 