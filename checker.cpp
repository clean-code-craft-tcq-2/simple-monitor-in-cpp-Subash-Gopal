#include <assert.h>
#include <iostream>
using namespace std;

const float TEMPERATURE_UPPER_BOUND = 45;
const float TEMPERATURE_LOWER_BOUND = 0;
const float SOC_UPPER_BOUND = 80;
const float SOC_LOWER_BOUND = 20;
const float CHARGE_RATE_UPPER_BOUND = 0.8;
const float CHARGE_RATE_LOWER_BOUND = 0;

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
  if(chargeRate < CHARGE_RATE_LOWER_BOUND || chargeRate > CHARGE_RATE_UPPER_BOUND) {
    cout << "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  //The below functions nearly do the same thing, this functions can be clubed to Avoid duplication
  return (isTemperatureInRange(temperature) && isSocInRange(soc) && ischargeRateWithinThreshold(chargeRate))
}

void testbatteryIsOK(bool actualBatteryRangeStatus,bool expectedBatteryRangeStatus){
    assert(actualBatteryRangeStatus == expectedBatteryRangeStatus)
}

int main() {
  assert(isTemperatureInRange(-10) == false)
  assert(isTemperatureInRange(0) == true)
  assert(isTemperatureInRange(45) == true)
  assert(isTemperatureInRange(46) == false)
  
  assert(isSocInRange(19) == false)
  assert(isSocInRange(20) == true)
  assert(isSocInRange(80) == true)
  assert(isSocInRange(81) == false)
    
  assert(ischargeRateWithinThreshold(-10) == false)  
  assert(ischargeRateWithinThreshold(0) == true)
  assert(ischargeRateWithinThreshold(0.8) == true)
  assert(ischargeRateWithinThreshold(0.9) == false)
    
  testBatteryIsOk(batteryIsOk(25, 70, 0.7),true);
  testBatteryIsOk(batteryIsOk(50, 85, 0),false);
}
