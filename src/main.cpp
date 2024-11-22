// Main cpp file for the entire project:


#include "q1.h"
#include "q2.h"
#include <iostream>
#include <vector>
#include <thread>



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
    return 0;



    cout << "#################################" << endl;
    cout << "START OF QUESTION 2" << endl;
    cout << "#################################" << endl;
// Create an array of five mutexes, each representing a tool
    std::mutex tools[5];
    // Create a vector to hold the robot threads
    std::vector<std::thread> robots;

    // Loop to create and start five robot threads
    for (int i = 0; i < 5; ++i) {
        // Create a new robot with its ID and references to two adjacent tools, then start its performTask method in a new thread
        robots.emplace_back(&Robot::performTask, Robot(i, tools[i], tools[(i + 1) % 5]));
    }

    // Loop to join all robot threads
    for (auto& robot : robots) {
        // Wait for the thread to finish execution
        robot.join();
    }
    cout << "#################################" << endl;
    cout << "END OF QUESTION 2" << endl;
    cout << "#################################" << endl;
    return 0;
}
    

