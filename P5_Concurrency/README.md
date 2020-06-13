## P5:Concurrency并发

- Path of execution of code in C++ is called a `thread`
- Multi path of execution that have potential to run in parallel is called `mutlithreading`
- Programs using multiple threads are called `concurrent`
- A system performing multiple independent tasks in parallel is called `multi-tasking` system

### Content:
- 01 Introduction_and_Running_Threads
    - Introduce process and threads
    - Running_a_Single_Thread
    - Starting_a_Thread_with_Function_Objects
    - Starting_a_Thread_with_Variadic_Templates_and_Member_Functions
    - Running_Multiple_Threads
- 02 Passing_Data_Between_Threads
    - Promises_and_Future
    - Threads_vs_Tasks
    - Avoiding_Data_Races
- 03 Mutexes and locks
    - Using_a_Mutex_to_Protect_Shared_Data
    - Using_Locks_to_Avoid_Deadlocks
- 04 conditional variable and message queues
    - The_Monitor_Object_Pattern
    - Building_a_Concurrent_Message_Queue
- CppND-Program-a-Concurrent-Traffic-Simulation

### Build instructions:
```bash
g++ -std=c++17 program_name.cpp
```