#include <iostream>
#include <thread>
#include <vector>
#include <future>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() : _tmpVehicles(0) {}

    void printSize()
    {
        std::cout << "#vehicles = " << _tmpVehicles << std::endl;
    }

    void pushBack(Vehicle &&v)
    {
        int oldNum = _tmpVehicles;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        _tmpVehicles = oldNum + 1;
    }

private:
    std::vector<Vehicle> _vehicles; 
    int _tmpVehicles; 
};

int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles); 
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 1000; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}

// #vehicles = 689 random change