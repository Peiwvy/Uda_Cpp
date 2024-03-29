#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in thread\n";
}

int main() {
  // create thread
  std::thread t(threadFunction);
  std::cout << "is t.joinable before detach "<< t.joinable() << std::endl;
  std::cout << "t.id: "<< t.get_id() << std::endl;
  // detach thread and continue with main
  t.detach();
  
  std::cout << "is t.joinable after detach "<< t.joinable() << std::endl;
  std::cout << "t.id: "<< t.get_id() << std::endl;

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate work
  std::cout << "Finished work in main\n";

  return 0;
}
/*
Side note:
    In some situations, it might make sense to not wait for a thread to finish its work. 
    This can be achieved by "detaching" the thread, by which the internal state variable "joinable" is set to "false".
    This can be done by calling detach() method on a thread object.
    The destructor of a detached thread does nothing: It neither blocks nor does it terminate the thread.
    A detached thread can not be joined ever again.
*/