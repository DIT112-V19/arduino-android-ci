#include "AutomatedMover.h"
#include "MockExternalEnvironment.h"
#include "MockRotateableVehicle.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

namespace
{
const float kSpeed = 1.0;
}

class SerialInputOutputManagerSubscriptionDoneTest : public Test
{
public:
    void SetUp() override {}

    void TearDown() override {}

    NiceMock<MockExternalEnvironment> mEnvironment;
    NiceMock<MockRotateableVehicle> mVehicle;
    AutomatedMover mAutomatedMover{mVehicle};
};

TEST_F(SerialInputOutputManagerSubscriptionDoneTest, rotate_WhenZeroDegreesProvided_WillNotRotate)
{
    // Set out preconditions and expectations
    auto zeroDegrees = 0;
    // Set angle should NEVER be called with any value if we shouldn't rotate
    EXPECT_CALL(mVehicle, setAngle(_)).Times(0);

    // Run the unit under test
    mAutomatedMover.rotate(zeroDegrees, kSpeed);
}

TEST_F(SerialInputOutputManagerSubscriptionDoneTest, rotate_WhenPositiveDegreesProvided_WillTurnRight)
{
    auto degrees = 50;
    // Rotate right
    EXPECT_CALL(mVehicle, setAngle(90));
    EXPECT_CALL(mVehicle, setSpeed(kSpeed));
    // Stop when you are done at the end of the rotation
    EXPECT_CALL(mVehicle, setSpeed(0));
    // We (unfortunately) need to test this as well until we decouple things even more
    // Simulate a rotation to the target degrees, first by returning two values the delta
    // of which is equal to the target degrees.
    EXPECT_CALL(mVehicle, getHeading()).WillOnce(Return(0)).WillOnce(Return(degrees));

    mAutomatedMover.rotate(degrees, kSpeed);
}

TEST_F(SerialInputOutputManagerSubscriptionDoneTest, rotate_WhenNegativeDegreesProvided_WillTurnLeft)
{
    auto degrees = -50;
    EXPECT_CALL(mVehicle, setAngle(-90));
    EXPECT_CALL(mVehicle, setSpeed(kSpeed));
    EXPECT_CALL(mVehicle, setSpeed(0));

    EXPECT_CALL(mVehicle, getHeading()).WillOnce(Return(0)).WillOnce(Return(degrees));

    mAutomatedMover.rotate(degrees, kSpeed);
}
