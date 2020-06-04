#include <iostream>
#include <thread>

// Once the thread enters runnable state,
// executation of the thread function may start at any time
void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work 0 in thread\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 1 in thread\n";
}

int main() {
  // create thread
  // after thread object has been constructed,
  // the main thread will continue and will execute remaining instructions
  // until it reaches the end and returns
  std::thread t(threadFunction);


  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work 0 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 1 in main\n";

  // wait for thread to finish
  t.join();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work 2 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 3 in main\n";

  return 0;
}
// note: join() is used to regulate the flow of the program
  