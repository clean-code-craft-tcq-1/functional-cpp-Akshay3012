#include <assert.h>
#include <iostream>
using namespace std;

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool l_status_b = true;
  if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
   l_status_b = false;
  } else if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    l_status_b = false;
  } else if(chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    l_status_b = false;
  }
  return l_status_b;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
