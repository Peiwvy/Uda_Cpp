/*
    - When passing the string variable name to the thread function, it needs to be explicitly marked as a reference, 
        so the compiler will treat it as such. 
    - This can be done by using the std::ref function.
*/
#include <iostream>
#include <string>
#include <thread>

void printName(std::string &name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  name += " (from Thread)";
  std::cout << name << std::endl;
}

int main() {
  std::string name("MyThread");

  // starting thread
  std::thread t(printName, std::ref(name), 50);

  // wait for thread before returning
  t.join();

  // print name from main
  name += " (from Main)";
  std::cout << name << std::endl;

  return 0;
}

// MyThread (from Thread)
// MyThread (from Thread) (from Main)