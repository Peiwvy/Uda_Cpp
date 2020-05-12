#include <iostream>
#include <thread>
#include <vector>

void printHello() {
  // perform work
  std::cout << "Hello from Worker thread #" 
            << std::this_thread::get_id()
            << std::endl;
}

int main() {
  // create threads
  std::vector<std::thread> threads;

  for (size_t i = 0; i < 5; ++i) {
    // copying thread objects causes a compile error
    /*
    std::thread t(printHello);
    threads.push_back(t);
    */

    // moving thread objects will work
    threads.emplace_back(std::thread(printHello));
  }

  // do something in main()
  std::cout << "Hello from Main thread #" 
            << std::this_thread::get_id()
            << std::endl;

  // call join on all thread objects using a range-based loop
  for (auto &t : threads) {
    t.join();
  }

  return 0;
}

// Hello from Main thread #Hello from Worker thread #0x116c2edc0Hello from Worker thread #
// Hello from Worker thread #0x70000c70e000
// Hello from Worker thread #0x70000c8140000x70000c897000
// 0x70000c91a000
// Hello from Worker thread #0x70000c791000