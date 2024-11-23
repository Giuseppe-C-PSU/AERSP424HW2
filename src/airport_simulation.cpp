#include "airport_simulation.h"
#include <iostream>
#include <thread>
#include <chrono>

Aircraft::Aircraft(int id) : id(id) {}

int Aircraft::getId() const {
    return id;
}

AirportSimulation::AirportSimulation(int totalAircraft)
        : atcBusy(false), aircraftCount(0), processedAircraft(0), totalAircraft(totalAircraft) {}

void AirportSimulation::incomingAircraft(std::shared_ptr<Aircraft> aircraft) {
    std::unique_lock<std::mutex> lock(mtx);
    if (aircraftCount < 3) {
        trafficPattern.push(aircraft);
        aircraftCount++;
        std::cout << "Aircraft " << aircraft->getId() << " entered the traffic pattern.\n";
        cv.notify_one();
    } else {
        std::cout << "Aircraft " << aircraft->getId() << " diverted to another airport.\n";
        processedAircraft++;
        cv.notify_one(); // Notify ATC in case it needs to check processed aircraft count
    }
}


void AirportSimulation::atcCommunication() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        if (trafficPattern.empty() && !atcBusy) {
            std::cout << "ATC is sleeping on the job.\n";
        }
        cv.wait(lock, [this] { return !trafficPattern.empty() || processedAircraft == totalAircraft; });

        if (processedAircraft == totalAircraft) {
            std::cout << "No more airc...  Honk-mimimimi...\n";
            break;
        }

        if (!trafficPattern.empty()) {
            auto aircraft = trafficPattern.front();
            std::cout << "Pilot of aircraft " << aircraft->getId() << " woke up ATC.\n";
            trafficPattern.pop();
            atcBusy = true;
            lock.unlock();

            std::cout << "ATC communicating with Aircraft " << aircraft->getId() << ".\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate communication time
            std::cout << "Aircraft " << aircraft->getId() << " is landing.\n";

            // Simulate landing process outside the lock
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate landing process

            lock.lock();
            std::cout << "Aircraft " << aircraft->getId() << " has landed.\n";
            aircraftCount--;
            processedAircraft++;
            atcBusy = false;
            cv.notify_all();
        }
    }
}