
#ifndef HOMEWORK2_AIRPORT_SIMULATION_H
#define HOMEWORK2_AIRPORT_SIMULATION_H


#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <memory>

class Aircraft {
public:
    Aircraft(int id);
    int getId() const;

private:
    int id;
};

class AirportSimulation {
public:
    AirportSimulation(int totalAircraft);
    void incomingAircraft(std::shared_ptr<Aircraft> aircraft);
    void atcCommunication();

private:
    std::queue<std::shared_ptr<Aircraft>> trafficPattern;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> atcBusy;
    std::atomic<int> aircraftCount;
    std::atomic<int> processedAircraft;
    int totalAircraft;
};


#endif //HOMEWORK2_AIRPORT_SIMULATION_H
