#include "q2.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Constructor to initialize a Ranger with a color and references to two mutexes representing the tools
Ranger::Ranger(const string& color, mutex& leftTool, mutex& rightTool)
    : color(color), leftTool(leftTool), rightTool(rightTool), taskCount(0) {}

// Method where the ranger performs its tasks until they each complete the task 4 times
void Ranger::performTask() {
    while (taskCount < 4) { //Ends the Loop after each robot completes 4 tasks

        // Create unique locks for the left and right tools but do not lock them immediately
        unique_lock<mutex> lockLeft(leftTool, defer_lock);
        unique_lock<mutex> lockRight(rightTool, defer_lock);

        // Lock both mutexes simultaneously to avoid deadlock
        lock(lockLeft, lockRight);

        // Print a message indicating the Ranger is grabbing the tools
        cout << "The" << color << " Ranger is grabbing tools.\n";
        // Simulate the time taken to grab the tools
        this_thread::sleep_for(std::chrono::seconds(1));

        // Print a message indicating the Ranger is performing the task
        cout << "The" << color << " Ranger is performing the task.\n";
        // Simulate the time taken to perform the task
        this_thread::sleep_for(std::chrono::seconds(5));

        // Print a message indicating the Ranger has completed the task and released the tools
        cout << "The" << color << " Ranger has completed the task and released the tools.\n";

        //Increment task counter
        ++taskCount;
    }
}