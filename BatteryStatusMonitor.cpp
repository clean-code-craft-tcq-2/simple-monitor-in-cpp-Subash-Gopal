#include <assert.h>
#include <iostream>
#include "BatteryStatusMonitor.h"
#include <string>
using namespace std;

const int NO_EARLY_WARNING = 0;
const int YES_EARLY_WARNING = 1;

bool BatteryStatusMonitor::addBatteryParameters(std::string parameter, float parameterValue, float lowerBound, float upperBound, int earlyWarning)
{
    for (const BatteryParameter &batteryParameter : batteryParameters)
    {
        if (batteryParameter.getParameter() == parameter)
        {
            return false;
        }
    }
    BatteryParameter temp{parameter, parameterValue, lowerBound, upperBound, earlyWarning};
    batteryParameters.push_back(temp);
    return true;
}
void BatteryStatusMonitor::display() const
{
    if (batteryParameters.size() == 0)
    {
        std::cout << "No battery Parameters included" << std::endl;
    }
    else
    {
        for (const auto &batteryParameter : batteryParameters)
        {
            batteryParameter.display();
        }
    }
}
float calcLowerBound(float LowerBound)
{
    return LowerBound + ((LowerBound * 5) / 100);
}
float calcUpperBound(float UpperBound)
{
    return UpperBound - ((UpperBound * 5) / 100);
}

bool BatteryStatusMonitor::batteryIsOk()
{
    if (batteryParameters.size() == 0)
    {
        std::cout << "No battery Parameters included" << std::endl;
        return false;
    }
    else
    {
        for (const auto &batteryParameter : batteryParameters)
        {
            if (batteryParameter.getEarlyWarning() == YES_EARLY_WARNING)
            {
                if (batteryParameter.getParameterValue() == calcLowerBound(batteryParameter.getLowerBound()))
                {
                    cout << batteryParameter.getParameter() << " Warning: Approaching discharge!\n";
                }
                else if (batteryParameter.getParameterValue() == calcUpperBound(batteryParameter.getUpperBound()))
                {
                    cout << batteryParameter.getParameter() << " Warning: Approaching charge-peak!\n";
                }
                else
                {
                }
            }

            if (batteryParameter.getParameterValue() < batteryParameter.getLowerBound() || batteryParameter.getParameterValue() > batteryParameter.getUpperBound())
            {
                cout << batteryParameter.getParameter() << " out of range!\n";
                return false;
            }
        }
    }
    return true;
}
void testBatteryIsOK()
{
    BatteryStatusMonitor BatteryStatusMonitor;
    assert(false == BatteryStatusMonitor.batteryIsOk()); //Returns false and warns developer to Test When No checks is done
    BatteryStatusMonitor.addBatteryParameters("Temperature", 20, 0, 45, YES_EARLY_WARNING);
    BatteryStatusMonitor.addBatteryParameters("Soc", 25, 20, 80, YES_EARLY_WARNING);
    BatteryStatusMonitor.addBatteryParameters("ChargeRate", 0.5, 0, 0.8, YES_EARLY_WARNING);
    assert(true == BatteryStatusMonitor.batteryIsOk());
}

int main()
{
    testBatteryIsOK();
}
