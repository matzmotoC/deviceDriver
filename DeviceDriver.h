
#pragma once
#include "FlashMemoryDevice.h"

#include <stdexcept>

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);

protected:
    FlashMemoryDevice* m_hardware;
};

class WriteFailException : public std::runtime_error {
public:
    explicit WriteFailException(const std::string& msg) : std::runtime_error(msg) {}
};