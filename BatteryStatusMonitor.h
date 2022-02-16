#include <iostream>
#include <vector>
#include "BatteryParameter.h"
class BatteryStatusMonitor
{
private:
    std::vector<BatteryParameter> batteryParameters;

public:
    bool addBatteryParameters(std::string parameter, float parameterValue, float lowerBound, float upperBound, int earlyWarning);
    void display() const;
    bool batteryIsOk();
};
