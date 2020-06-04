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
    WaitingVehicles() : _numVehicles(0) {}

    int getNumVehicles() 
    { 
        std::lock_guard<std::mutex> uLock(_mutex);
        return _numVehicles; 
    }

    bool dataIsAvailable()
    {
        std::lock_guard<std::mutex> myLock(_mutex);
        return !_vehicles.empty();
    }

    Vehicle popBack()
    {
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // remove last vector element from queue
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();
        --_numVehicles;

        return v; // will not be copied due to return value optimization (RVO) in C++
    }

    void pushBack(Vehicle &&v)
    {
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));


        // add vector to queue
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(std::move(v));
        ++_numVehicles;
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::mutex _mutex;
    int _numVehicles;
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
        if (queue->dataIsAvailable())
        {
            Vehicle v = queue->popBack();
            std::cout << "   Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;

            if(queue->getNumVehicles()<=0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                break;
            }
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished : " << queue->getNumVehicles() << " vehicle(s) left in the queue" << std::endl;

    return 0;
}

// Spawning threads...
// Collecting results...
//    Vehicle #0 will be added to the queue
//    Vehicle #1 will be added to the queue
//    Vehicle #2 will be added to the queue
//    Vehicle #3 will be added to the queue
//    Vehicle #4 will be added to the queue
//    Vehicle #5 will be added to the queue
//    Vehicle #6 will be added to the queue
//    Vehicle #7 will be added to the queue
//    Vehicle #8 will be added to the queue
//    Vehicle #8 has been removed from the queue
//    Vehicle #7 has been removed from the queue
//    Vehicle #6 has been removed from the queue
//    Vehicle #5 has been removed from the queue
//    Vehicle #9 will be added to the queue
//    Vehicle #9 has been removed from the queue
//    Vehicle #4 has been removed from the queue
//    Vehicle #3 has been removed from the queue
//    Vehicle #2 has been removed from the queue
//    Vehicle #1 has been removed from the queue
//    Vehicle #0 has been removed from the queue
// Finished : 0 vehicle(s) left in the queue