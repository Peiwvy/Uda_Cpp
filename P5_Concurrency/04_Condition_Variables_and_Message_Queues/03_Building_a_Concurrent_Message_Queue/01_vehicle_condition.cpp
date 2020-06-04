#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    int getID() { return _id; }

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    Vehicle popBack()
    {
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_vehicles.empty(); });

        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();

        return v; // will not be copied due to return value optimization (RVO) in C++
    }

    void pushBack(Vehicle &&v)
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.push_back(std::move(v));
        _cond.notify_one(); // notify client after pushing new Vehicle into vector
    }

    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
private:
    std::mutex _mutex;
    std::condition_variable _cond;
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // create a new Vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        // popBack wakes up when a new element is available in the queue
        Vehicle v = queue->popBack();
        std::cout << "   Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;
    }

    std::cout << "Finished!" << std::endl;

    return 0;
}

// Spawning threads...
// Collecting results...
//    Vehicle #0 will be added to the queue
//    Vehicle #0 has been removed from the queue
//    Vehicle #2 will be added to the queue
//    Vehicle #5 will be added to the queue
//    Vehicle #3 will be added to the queue
//    Vehicle #4 will be added to the queue
//    Vehicle #6 will be added to the queue
//    Vehicle #7 will be added to the queue
//    Vehicle #9 will be added to the queue
//    Vehicle #8 will be added to the queue
//    Vehicle #1 will be added to the queue
//    Vehicle #1 has been removed from the queue
//    Vehicle #8 has been removed from the queue
//    Vehicle #9 has been removed from the queue
//    Vehicle #7 has been removed from the queue
//    Vehicle #6 has been removed from the queue
//    Vehicle #4 has been removed from the queue
//    Vehicle #3 has been removed from the queue
//    Vehicle #5 has been removed from the queue
//    Vehicle #2 has been removed from the queue