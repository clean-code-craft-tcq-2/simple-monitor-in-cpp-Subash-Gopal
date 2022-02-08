#include <assert.h>
#include <iostream>
using namespace std;

const float TEMPERATURE_UPPER_BOUND = 45;
const float TEMPERATURE_LOWER_BOUND = 0;
const float SOC_UPPER_BOUND = 80;
const float SOC_LOWER_BOUND = 20;
const float CHARGE_RATE_THRESHOLD = 0.8;


bool isTemperatureInRange(float temperature)
{
  if(temperature < TEMPERATURE_LOWER_BOUND || temperature > TEMPERATURE_UPPER_BOUND) {
    cout << "Temperature out of range!\n";
    return false;
  }
  return true;
}

bool isSocInRange(float soc)
{
  if(soc < SOC_LOWER_BOUND || soc > SOC_UPPER_BOUND)
  {
    cout << "State of Charge out of range!\n";
    return false;
  } 
  return true;
}

bool ischargeRateWithinThreshold(float chargeRate)
{
  if(chargeRate > CHARGE_RATE_THRESHOLD) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool isTemperatureInRange = isTemperatureInRange(temperature);
  bool isSocInRange = isSocInRange(soc);
  bool ischargeRateWithinThreshold = ischargeRateWithinThreshold(chargeRate);
  
  if((isTemperatureInRange) && (isSocInRange) && (ischargeRateWithinThreshold))  {
     return true;
  } else {
    return false;
  } 
}

void testbatteryIsOK(bool actualBatteryRangeStatus,bool expectedBatteryRangeStatus){
    assert(actualBatteryRangeStatus == expectedBatteryRangeStatus)
}

int main() {
  testBatteryIsOk(batteryIsOk(25, 70, 0.7),true);
  testBatteryIsOk(batteryIsOk(50, 85, 0),false);
}
