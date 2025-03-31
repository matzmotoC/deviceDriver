#include "DeviceDriver.h"
#include <thread>  
#include <chrono>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{
}

int DeviceDriver::read(long address)
{
    int readTimes = 5; 
    int matchCount = 0;
	int matchValue = 2; // success enum need to make enum class 

	for (int i = 0; i < 5; i++)
	{
		if (matchValue == (int)(m_hardware->read(address)))
		{
			matchCount++;
		}
	}
	
	if (readTimes == matchCount) return 0; // true

    return 1; // false 
}

void DeviceDriver::write(long address, int data)
{
	int matchValue = 0xFF; // Nono Data enum need to make enum class 

	if (matchValue == (int)(m_hardware->read(address)))
	{
		m_hardware->write(address, (unsigned char)data);
	}
	else
	{
		throw WriteFailException("Data exist");
	}

	

    
}