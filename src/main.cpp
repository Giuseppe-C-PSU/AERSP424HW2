// Main cpp file for the entire project:


#include "q1.h"
#include <iostream>
#include <vector>



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
    
}
