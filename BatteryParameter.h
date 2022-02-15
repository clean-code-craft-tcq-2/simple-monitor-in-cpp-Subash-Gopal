#ifndef _BATTERYPARAMETER_H_
#define _BATTERYPARAMETER_H_

#include <string>
class BatteryParameter
{
private:
    std::string parameter;
    float parameterValue;
    float lowerBound;
    float upperBound;
    int earlyWarning;

public:
    BatteryParameter(std::string parameter, float parameterValue, float lowerBound, float upperBound, int earlyWarning);
    ~BatteryParameter();

    void setParameter(std::string parameter) { this->parameter = parameter; }
    std::string getParameter() const { return parameter; }

    void setParameterValue(float parameterValue) { this->parameterValue = parameterValue; }
    float getParameterValue() const { return parameterValue; }

    void setLowerBound(float lowerBound) { this->lowerBound = lowerBound; }
    float getLowerBound() const { return lowerBound; }

    void setUpperBound(float upperBound) { this->upperBound = upperBound; }
    float getUpperBound() const { return upperBound; }

    void setEarlyWarning(int earlyWarning) { this->earlyWarning = earlyWarning; }
    int getEarlyWarning() const { return earlyWarning; }

    void display() const;
};

#endif