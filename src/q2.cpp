#include "q2.h"
#include <iostream>
#include <thread>
#include <chrono>
//sdg
// Constructor to initialize the robot with an ID and references to two mutexes representing the tools
Robot::Robot(int id, std::mutex& leftTool, std::mutex& rightTool)
    : id(id), leftTool(leftTool), rightTool(rightTool) {}

// Method where the robot performs its task in an infinite loop
void Robot::performTask() {
    while (true) {
        // Create unique locks for the left and right tools but do not lock them immediately
        std::unique_lock<std::mutex> lockLeft(leftTool, std::defer_lock);
        std::unique_lock<std::mutex> lockRight(rightTool, std::defer_lock);

        // Lock both mutexes simultaneously to avoid deadlock
        std::lock(lockLeft, lockRight);

        // Print a message indicating the robot is grabbing the tools
        std::cout << "Robot " << id << " is grabbing tools.\n";
        // Simulate the time taken to grab the tools
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Print a message indicating the robot is performing the task
        std::cout << "Robot " << id << " is performing the task.\n";
        // Simulate the time taken to perform the task
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Print a message indicating the robot has completed the task and released the tools
        std::cout << "Robot " << id << " has completed the task and released the tools.\n";
    }
}