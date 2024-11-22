#ifndef Q2_H
#define Q2_H

#include <mutex>

class Robot {
public:
    Robot(int id, std::mutex& leftTool, std::mutex& rightTool);
    void performTask();

private:
    int id;
    std::mutex& leftTool;
    std::mutex& rightTool;
};

#endif // ROBOT_HPP