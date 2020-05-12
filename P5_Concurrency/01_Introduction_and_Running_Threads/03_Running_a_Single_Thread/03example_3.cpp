// 02_two_threads.cpp
#include <iostream>
#include <thread>

// Once the thread enters runnable state,
// executation of the thread function may start at any time
void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));  // simulate work
  std::cout << "Finished work in thread\n";
}

int main() {
  // create thread
  std::thread t(threadFunction);
  // after thread object has been constructed,
  // the main thread will continue and will execute remaining instructions
  // until it reaches the end and returns

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in main\n";

  // wait for thread to finish
  t.join();

  return 0;
}

// Finished work in main
// Finished work in thread
