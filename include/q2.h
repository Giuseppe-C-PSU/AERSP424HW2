#ifndef Q2_H
#define Q2_H

#include <mutex>
#include <string>

using namespace std;

class Ranger {
public:
    Ranger(const string& color, mutex& leftTool, mutex& rightTool);
    void performTask();

private:
    string color;
    mutex& leftTool;
    mutex& rightTool;
    int taskCount; // Counter to keep track of how many tasks are completed
};

#endif 