// memset:Memset is usually used for initialization of values
#include <iostream>

int main() {

    char *ptr = new char;
    *ptr = 'c';
    char str[4] = "AAA";

    std::cout << "Initial ptr value : " << *ptr << "\n";
    std::cout << "Initial str array value : " << str << "\n";

    memset(ptr, 'A', 1);
    memset(str+1, 'B', 1);

    std::cout << "1After ptr value : " << *ptr << "\n";
    std::cout << "1After str array value : " << str << "\n";

    memset(ptr, 'A', 1);
    memset(str, 'C', 2);

    std::cout << "2After ptr value : " << *ptr << "\n";
    std::cout << "2After str array value : " << str << "\n";
}
/*
outcome:
Initial ptr value : c
Initial str array value : AAA
1After ptr value : A
1After str array value : ABA
2After ptr value : A
2After str array value : CCA
*/