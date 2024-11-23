// Main cpp file for the entire project:


#include "q1.h"
#include "q2.h"
#include "airport_simulation.h"
#include <iostream>
#include <vector>
#include <thread>
#include <memory>

using namespace std;

int main(){


    cout << "#################################" << endl;
    cout << "START OF QUESTION 1" << endl;
    cout << "#################################" << endl;

    // Question 1, subpart 5:
    AerospaceControlSystem ctrlSys; // Instantiate object "ctrlSys"

    // Create one of each type of sensor
    IMU sensor1;
    ADS sensor2;
    AHRS sensor3;

    // Invoke addSensor() for each type of sensor:

    ctrlSys.addSensor(&sensor1);
    ctrlSys.addSensor(&sensor2);
    ctrlSys.addSensor(&sensor3);

    // Invoke monitorAndAdjust():

    ctrlSys.monitorAndAdjust();

    cout << "#################################" << endl;
    cout << "END OF QUESTION 1" << endl;
    cout << "#################################" << endl;


    cout << "#################################" << endl;
    cout << "START OF QUESTION 2" << endl;
    cout << "#################################" << endl;
    
    // Create an array of five mutexes, each representing a tool
    mutex tools[5];
    // Create a vector to hold the ranger threads
    vector<thread> rangers;
    // Assigns colors to the Rangers
    string colors[5] = {"Red", "Blue", "Yellow", "Pink", "Black"};

    // Loop to create and start five ranger threads
    for (int i = 0; i < 5; ++i) {
        // Create a new ranger with its corresponding color and references to two adjacent tools, then start its performTask method in a new thread
        rangers.emplace_back(&Ranger::performTask, Ranger(colors[i], tools[i], tools[(i + 1) % 5]));
    }

    // Loop to join all ranger threads
    for (auto& ranger : rangers) {
        // Wait for the thread to finish execution
        ranger.join();
    }
    cout << "#################################" << endl;
    cout << "END OF QUESTION 2" << endl;
    cout << "#################################" << endl;
    
    cout << "#################################" << endl;
    cout << "START OF QUESTION 3" << endl;
    cout << "#################################" << endl;

    // Question 3

    int totalAircraft = 10;
    int firstBatchSize = 2;
    AirportSimulation airport(totalAircraft);

    // Create a thread for ATC communication
    std::thread atcThread(&AirportSimulation::atcCommunication, &airport);

    // Create first batch of 2 aircraft
    for (int i = 1; i <= firstBatchSize; ++i) {
        auto aircraft = std::make_shared<Aircraft>(i);
        std::thread(&AirportSimulation::incomingAircraft, &airport, aircraft).detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate aircraft arrival time
    }

    // Wait for 5 seconds before creating the next batch
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Create second batch of 8 aircraft
    for (int i = firstBatchSize + 1; i <= totalAircraft; ++i) {
        auto aircraft = std::make_shared<Aircraft>(i);
        std::thread(&AirportSimulation::incomingAircraft, &airport, aircraft).detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate aircraft arrival time
    }

    // Wait for all aircraft to be processed
    atcThread.join();



    cout << "#################################" << endl;
    cout << "END OF QUESTION 3" << endl;
    cout << "#################################" << endl;    

    return 0;
}
    

