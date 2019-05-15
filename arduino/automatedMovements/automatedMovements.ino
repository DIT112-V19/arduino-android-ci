#include "ArduinoExternalEnvironment.h"
#include "AutomatedMover.h"
#include "SmartCarRotateableVehicle.h"
#include <Smartcar.h>

const unsigned short LEFT_ODOMETER_PIN  = 2;
const unsigned short RIGHT_ODOMETER_PIN = 3;
const float carSpeed                    = 1.0;
const long distanceToTravel             = 40;
const int degreesToTurn                 = 90;

BrushedMotor leftMotor(8, 10, 9);
BrushedMotor rightMotor(12, 13, 11);
DifferentialControl control(leftMotor, rightMotor);

GY50 gyroscope(37);
DirectionlessOdometer leftOdometer(100);
DirectionlessOdometer rightOdometer(100);

SmartCar car(control, gyroscope, leftOdometer, rightOdometer);

SmartCarRotateableVehicle rotateableVehicle(car);
AutomatedMover automatedMover(rotateableVehicle);

void setup()
{

    leftOdometer.attach(LEFT_ODOMETER_PIN, []() { leftOdometer.update(); });
    rightOdometer.attach(RIGHT_ODOMETER_PIN, []() { rightOdometer.update(); });

    car.enableCruiseControl();

    // Travel around an imaginary square
    automatedMover.go(distanceToTravel, carSpeed);
    automatedMover.rotate(degreesToTurn, carSpeed);

    automatedMover.go(distanceToTravel, carSpeed);
    automatedMover.rotate(degreesToTurn, carSpeed);

    automatedMover.go(distanceToTravel, carSpeed);
    automatedMover.rotate(degreesToTurn, carSpeed);

    automatedMover.go(distanceToTravel, carSpeed);
    automatedMover.rotate(degreesToTurn, carSpeed);
}

void loop()
{
    // put your main code here, to run repeatedly:
}
