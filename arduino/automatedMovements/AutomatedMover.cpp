#include "AutomatedMover.h"

namespace
{
constexpr long getAbsolute(long num)
{
    return num > 0 ? num : -num;
}
} // namespace

AutomatedMover::AutomatedMover(RotateableVehicle& rotateableVehicle)
    : mRotateableVehicle{rotateableVehicle}
{
}

void AutomatedMover::rotate(int degrees, float speed)
{
    speed = getAbsolute(speed);
    degrees %= 360; // Put degrees in a (-360,360) scale
    if (degrees == 0)
    {
        return;
    }

    mRotateableVehicle.setSpeed(speed);
    if (degrees > 0)
    {
        mRotateableVehicle.setAngle(90);
    }
    else
    {
        mRotateableVehicle.setAngle(-90);
    }

    unsigned int initialHeading  = mRotateableVehicle.getHeading();
    bool hasReachedTargetDegrees = false;
    while (!hasReachedTargetDegrees)
    {
        mRotateableVehicle.update();
        int currentHeading = mRotateableVehicle.getHeading();
        if (degrees < 0 && currentHeading > initialHeading)
        {
            // If we are turning left and the current heading is larger than the
            // initial one (e.g. started at 10 degrees and now we are at 350), we need to substract 360
            // so to eventually get a signed displacement from the initial heading (-20)
            currentHeading -= 360;
        }
        else if (degrees > 0 && currentHeading < initialHeading)
        {
            // If we are turning right and the heading is smaller than the
            // initial one (e.g. started at 350 degrees and now we are at 20), so to get a signed displacement (+30)
            currentHeading += 360;
        }
        // Degrees turned so far is initial heading minus current (initial heading
        // is at least 0 and at most 360. To handle the "edge" cases we substracted or added 360 to currentHeading)
        int degreesTurnedSoFar  = initialHeading - currentHeading;
        hasReachedTargetDegrees = getAbsolute(degreesTurnedSoFar) >= getAbsolute(degrees);
    }

    mRotateableVehicle.setSpeed(0);
}

void AutomatedMover::go(long centimeters, float speed)
{
    if (centimeters == 0)
    {
        return;
    }
    // Ensure the speed is towards the correct direction
    speed = getAbsolute(speed) * ((centimeters < 0) ? -1 : 1);
    mRotateableVehicle.setAngle(0);
    mRotateableVehicle.setSpeed(speed);

    long initialDistance          = mRotateableVehicle.getDistance();
    bool hasReachedTargetDistance = false;
    while (!hasReachedTargetDistance)
    {
        mRotateableVehicle.update();
        auto currentDistance = mRotateableVehicle.getDistance();
        auto travelledDistance
            = initialDistance > currentDistance ? initialDistance - currentDistance : currentDistance - initialDistance;
        hasReachedTargetDistance = travelledDistance >= getAbsolute(centimeters);
    }
    mRotateableVehicle.setSpeed(0);
}
