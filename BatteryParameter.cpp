#include <iostream>
#include <string>
#include "BatteryParameter.h"

BatteryParameter::BatteryParameter(std::string parameter, float parameterValue, float lowerBound, float upperBound, int earlyWarning)
    : parameter(parameter), parameterValue(parameterValue), lowerBound(lowerBound), upperBound(upperBound), earlyWarning(earlyWarning)
{
}

BatteryParameter::~BatteryParameter()
{
}

void BatteryParameter::display() const
{
    std::cout << parameter << ", " << lowerBound << ", " << upperBound << std::endl;
}
