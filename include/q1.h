// q1.h 
// Header file for question 1. Has subparts 1-4 which define 
// and create the multiple class and function names for the 
// first question of the homework

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef Q1_H
#define Q1_H

#include <string>
#include <vector>
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Subpart 1. Abstract class "Sensor" with two functions "gatherData()" and "processData()"

class Sensor {
    private:
    // Edit this with private variable names as much as needed

    public:
    // Edit this with public variable and function names for the first question
    //  Setting these functions = 0 makes them pure virtual and allows
    //  overriding from the derived subclasses 

    virtual void gatherData() = 0;
    virtual void processData() = 0;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Subpart 2. Three sensors used in Aircraft with separate classes 
// that are derived from "Sensors" class:
//  Using "override" makes it so that these functions in the 
//  derived subclasses instantiate objects instead of the ones
//  in Sensor

// All these classes are derived from Sensor:

// Inertial Measurement Sensor (IMU)
class IMU : public Sensor {
    public:
        void gatherData() override;
        void processData() override;
};

// Air Data Sensor (ADS)
class ADS : public Sensor {
    public:
        void gatherData() override;
        void processData() override;
};

// Attitude and Heading Reference Systems (AHRS)
class AHRS : public Sensor {
    public:
        void gatherData() override;
        void processData() override;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Subpart 3. SensorFactory class:

class SensorFactory {
    private:
        // Edit this with any private variables required for the class
    public:
        // Edit this with any public vars and functions required for the class
        static Sensor* createSensor(const string& sensorType);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Subpart 4. Control System Class:

class AerospaceControlSystem{
    private:
        // Edit this with any private vars required for class
        vector<Sensor*> listsensors; // Vector that stores the sensor pointers for iteration

    public:
        // Edit this with any public vars and func required for class
        void addSensor(Sensor* sensor); // This function adds sensors to the class

        void monitorAndAdjust(); // This function will iterate through sensors

};

#endif 