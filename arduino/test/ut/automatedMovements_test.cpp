#include "MockExternalEnvironment.h"
#include "MockRotateableVehicle.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

class SerialInputOutputManagerSubscriptionDoneTest : public Test
{
public:
    void SetUp() override {}

    void TearDown() override {}

    NiceMock<MockExternalEnvironment> mEnvironment;
    NiceMock<MockRotateableVehicle> mVehicle;
};

TEST(DummyTest, unitUnderTest_whenPrecondition_WillResult) {}