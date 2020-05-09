/*
One implementation of this philosphy is created as unique pointer class, which has main function 
to prevent memory leakage. It is essentially wrapper class for typical pointer and its operations 
and actions (allocation, deallocation, incrementation, retrieval of memory address etc.). 
Main concept of unique pointer stands in a fact that we will get compile time errors with every action 
which results that two pointers are showing same memory resource. So, when using unique pointers, 
we are sure that there can only be at most one unique pointer at any one memory location and when that 
pointer is destroyed (out of scope), the resource is automatically claimed. 
This approach doesn't prevent actions of moving specified pointer to another location. 
But when we do that, we are using safe way to move our pointer with usage of function move, 
which we pass our pointer data.


Illustrate the use of unique_ptr in C++. With this example
use the common method when handling these type of pointers.

1.  Declare simple class called A
2.  Add one method which is non - return type
3.  Print something in it
4.  Declare new pointer unique_ptr which is same type as declared class
5.  Using constructor syntax, as part of declaration of pointer declare new class
    A instace
6.  Using pointer reference syntax "->" invoke class method
7.  Use .get() method to retrieve memory address from declared pointer
8.  Use move method to transfer memory data from first pointer to second one
9.  Try to print both addresses via get()
10. Add third pointer
11. Try same thing
12. Notice that info is transfered to next pointer without leaving copies in
    previous ones
*/

// C++ program to illustrate the use of unique_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
  public:
  void show() { 
    cout << "Class A::classMethod" << endl; 
    }
};

int main() {
  unique_ptr<A> ptr_1(new A);
  ptr_1->show();

  // returns the memory address of ptr_1
  cout << ptr_1.get() << endl;
  cout << endl;

  // transfers ownership to ptr_2
  unique_ptr<A>
  ptr_2 = move(ptr_1);
  ptr_2->show();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << endl;

  // transfers ownership to ptr_3
  unique_ptr<A> ptr_3 = move(ptr_2);
  ptr_3->show();
  cout << ptr_1.get() << endl;
  cout << ptr_2.get() << endl;
  cout << ptr_3.get() << endl;

  return 0;
}
/*	
outcome:

Class A::classMethod
0x7fc6efc01790

Class A::classMethod
0x0
0x7fc6efc01790

Class A::classMethod
0x0
0x0
0x7fc6efc01790
*/