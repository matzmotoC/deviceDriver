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
	
	int fakeAddress = 0x100;

	EXPECT_CALL(mockFMD, read(fakeAddress)).WillRepeatedly(Return((unsigned char)2));

	EXPECT_THAT(dD.read(fakeAddress), Eq(0));

}


TEST(deviceTest, memoryReadFail)
{
	FlashMemoryDeviceMock mockFMD;
	DeviceDriver dD(&mockFMD);

	int fakeAddress = 0x100;


	EXPECT_CALL(mockFMD, read(fakeAddress)).WillOnce(Return((unsigned char)2))
	.WillOnce(Return((unsigned char)2))
	.WillOnce(Return((unsigned char)2))
	.WillOnce(Return((unsigned char)2))
	.WillOnce(Return((unsigned char)1));

	EXPECT_THAT(dD.read(fakeAddress), Ne(0));

}


TEST(deviceTest, memoryWriteSucces)
{
	FlashMemoryDeviceMock mockFMD;
	DeviceDriver dD(&mockFMD);
	int data = 5;
	int matchValue = 0xFF;

	int fakeAddress = 0x100;

	EXPECT_CALL(mockFMD, read(fakeAddress)).WillOnce(Return((unsigned char)matchValue));
	EXPECT_CALL(mockFMD, write(fakeAddress, data)).Times(1);
	
	dD.write(fakeAddress, data);

}

TEST(deviceTest, memoryWriteFail)
{
	FlashMemoryDeviceMock mockFMD;
	DeviceDriver dD(&mockFMD);
	int data = 5;
	int matchValue = 0xFF;

	int fakeAddress = 0x100;

	int matchCount = 0;


	EXPECT_CALL(mockFMD, read(fakeAddress)).WillOnce(Return((unsigned char)0));
	
	EXPECT_THROW
	(
		{ 
				dD.write(fakeAddress, data);
		}
	, WriteFailException);	

}


int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
