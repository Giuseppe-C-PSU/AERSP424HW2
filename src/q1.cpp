// cpp file for the first question in the 2nd Homework:
//  This file includes all function definitions for the 2nd
//  question and implementation

#include "q1.h"
#include <iostream>
#include <string> 

using namespace std;

// Implementaiton for problem 1, subpart 2, subsubpart c and d:
// I know it's kinda stupid but I think there's a point to doing it this way:
void IMU::gatherData() {
    cout << "Gathering data from the IMU sensor" << endl;
};

void IMU::processData() {
    cout << "Processing data from the IMU sensor" << endl;
};

void ADS::gatherData() {
    cout << "Gathering data from the ADS sensor" << endl;
};

void ADS::processData() {
    cout << "Processing data from the ADS sensor" << endl;
};

void AHRS::gatherData() {
    cout << "Gathering data from the AHRS sensor" << endl;
};

void AHRS::processData() {
    cout << "Processing data from the AHRS sensor" << endl;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Subpart 3, subsubpart b and c:

Sensor* SensorFactory::createSensor(const string& sensorType){
    if (sensorType == "IMU"){
        return new IMU();
    }else if (sensorType == "ADS") {
        return new ADS();
    }else if (sensorType == "AHRS"){
        return new AHRS();
    }else{
        return nullptr; // Return null pointer if the rest of the conditions aren't met
    };
    
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Subpart 4

// This function stores the sensors added into a vector for iteration purposes:
void AerospaceControlSystem::addSensor(Sensor* sensor){
    if(sensor){ // Check to see if the sensor is nullptr or not
        // If the sensor is not a nullptr:
        listsensors.push_back(sensor);
    }else{
        // If the sensor IS a nullprt:
        cout << sensor << " Is not a valid sensor for the Aerospace Control System" << endl;
    };
};

void AerospaceControlSystem::monitorAndAdjust(){
    for (Sensor* sensor : listsensors){
        sensor -> gatherData();
        sensor -> processData();
        cout << "Adjusting controls based upon sensor data" << endl;
    };
    
};



