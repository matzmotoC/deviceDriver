#include "gmock/gmock.h"
#include <string>
#include <vector>
#include "DeviceDriver.h"
#include "FlashMemoryDeviceMock.cpp"


using namespace std;
using namespace testing;

TEST(deviceTest, memoryReadSucces)
{
	FlashMemoryDeviceMock mockFMD;
	DeviceDriver dD(&mockFMD);
	int a = 5;
	int matchValue = 2;

	int fakeAddress = 0x100;

	int matchCount = 0;



	EXPECT_CALL(mockFMD, read(fakeAddress)).WillRepeatedly(Return((unsigned char)2));

	for (int i = 0; i < 5; i++)
	{
		if (matchValue == dD.read(fakeAddress))
		{
			matchCount++;
		}
	}

	EXPECT_THAT(matchCount, Eq(5));

}


TEST(deviceTest, memoryReadFail)
{
	FlashMemoryDeviceMock mockFMD;
	DeviceDriver dD(&mockFMD);
	int a = 5;
	int matchValue = 2;

	int fakeAddress = 0x100;

	int matchCount = 0;



	EXPECT_CALL(mockFMD, read(fakeAddress)).WillRepeatedly(Return((unsigned char)2));

	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			EXPECT_CALL(mockFMD, read(fakeAddress)).WillOnce(Return((unsigned char)3));
		}
		if (matchValue == dD.read(fakeAddress))
		{
			matchCount++;
		}
	}

	EXPECT_THAT(matchCount, Ne(5));

}


int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
