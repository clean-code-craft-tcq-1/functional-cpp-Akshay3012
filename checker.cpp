#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

void toConsole(string parameter_name)
{
  cout << parameter_name << "out of range!\n";
}

bool isBatteryParameterInRange(float Parameter_value, float min, float max, string f_parameter_name)
{
  if((Parameter_value < min) || (Parameter_value > max))
  {
    toConsole(f_parameter_name);
    return false;
  } 
  else
  {
    return true;
  }
}


bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
    return isBatteryParameterInRange(temperature, 0, 45, "Temperature") && 
    isBatteryParameterInRange(soc, 20, 80, "State of Charge") &&
    isBatteryParameterInRange(chargeRate,-1,0.8,"Charge Rate");
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
