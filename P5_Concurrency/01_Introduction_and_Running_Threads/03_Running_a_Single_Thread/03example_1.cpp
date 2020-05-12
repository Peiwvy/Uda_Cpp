#include <iostream>
#include <thread>

int main() {
  std::cout << "Hello concurrent world from main! Thread id = "
            << std::this_thread::get_id() << std::endl;

  return 0;
}

// Hello concurrent world from main! Thread id = 0x108156dc0