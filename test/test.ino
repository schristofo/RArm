#include <Wire.h>
#include "RArm.h"

RArm x = RArm();

void setup() {
  x.set();  
  Serial.begin(9600);
  Serial.println("RArm 1.2:");  
}

void loop(){ 

   delay(1500);
   x.action(0,0,0,0,0);
   delay(1500);
   x.action(100,100,100,100,100);
}

