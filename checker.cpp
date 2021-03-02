#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

void toConsoleExtreamValue(string parameter_name)
{
  cout << parameter_name << "is extreamly low or high!\n";
}

void extreamValueCheck(float Parameter_value, string parameter_name, float lower_limit, float upper_limit)
{
 if((Parameter_value < lower_limit)||(Parameter_value > upper_limit))
  {
    toConsoleExtreamValue(parameter_name);
  } 
  else
  {
   //do nothing;
  }
}
  
void toConsole(float Parameter_value, string parameter_name)
{
  cout << parameter_name << "out of range!\n";
  
  if(parameter_name == "Temperature ")
  {
    extreamValueCheck(Parameter_value, parameter_name, -10, 100);
  }
  else if(parameter_name == "State of Charge ")
  {
    extreamValueCheck(Parameter_value, parameter_name, -10, 150);
  } 
  else
  {
       extreamValueCheck(Parameter_value, parameter_name, -5, 15);
  }
}


bool isBatteryParameterInRange(float Parameter_value, float min, float max, string parameter_name)
{
  if((Parameter_value < min) || (Parameter_value > max))
  {
    toConsole(Parameter_value,parameter_name);
    return false;
  } 
  else
  {
    return true;
  }
}


bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
    return isBatteryParameterInRange(temperature, 0, 45, "Temperature ") && 
    isBatteryParameterInRange(soc, 20, 80, "State of Charge ") &&
    isBatteryParameterInRange(chargeRate,-1,0.8,"Charge Rate ");
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(-1, 70, 0.7) == false);
  assert(batteryIsOk(25, 10, 0.7) == false);
  assert(batteryIsOk(25,70, -2) == false);
  assert(batteryIsOk(50, 70, 0.7) == false);
  assert(batteryIsOk(25, 90, 0.7) == false);
  assert(batteryIsOk(25,70, 2) == false);
  assert(batteryIsOk(50, 85, 0) == false);
}
