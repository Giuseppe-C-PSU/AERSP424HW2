// Main cpp file for the entire project:


#include "q1.h"
#include <iostream>
#include <vector>
#include <thread>
#include "airport_simulation.h"
#include <memory>



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
