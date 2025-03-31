#include "gmock/gmock.h"
#include "FlashMemoryDevice.h"

class FlashMemoryDeviceMock : public FlashMemoryDevice
{
public:
    MOCK_METHOD(unsigned char, read, (long address), ());
    MOCK_METHOD(void, write, (long address, unsigned char data), ());
};
