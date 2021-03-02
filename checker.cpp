#include <assert.h>
#include <iostream>
using namespace std;

bool isBatteryParameterInRange(float Parameter_value, float max, float min)
{
  if(Parameter_value < min || Parameter_value > max)
  {
    return false;
  } 
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return isBatteryParameterInRange(temperature,0,45) && 
    isBatteryParameterInRange(soc,20,80) &&
    isBatteryParameterInRange(chargeRate, chargeRate -1 , 0.8)
 // if(temperature < 0 || temperature > 45) {
 //   cout << "Temperature out of range!\n";
 //  return false;
 //} else if(soc < 20 || soc > 80) {
 //   cout << "State of Charge out of range!\n";
 //   return false;
 // } else if(chargeRate > 0.8) {
 //   cout << "Charge Rate out of range!\n";
 //   return false;
 // }
 //return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
