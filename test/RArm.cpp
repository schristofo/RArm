#include "Arduino.h"
#include "RArm.h"

RArm::RArm(){
  // define RArm
}

void RArm::set(){
  pwm.begin();
  pwm.setPWMFreq(60);
  // open-hand initial values
  pwm.setPWM(0, 0, 580);
  pwm.setPWM(1, 0, 200);
  pwm.setPWM(2, 0, 380);
  pwm.setPWM(3, 0, 560);
  pwm.setPWM(4, 0, 410);
}
void RArm::set(int freq){
  pwm.begin();
  pwm.setPWMFreq(freq);
  // open-hand initial values
  pwm.setPWM(0, 0, 580);
  pwm.setPWM(1, 0, 200);
  pwm.setPWM(2, 0, 380);
  pwm.setPWM(3, 0, 560);
  pwm.setPWM(4, 0, 410);
}

void RArm::finger(int pin, int power) {

  int pulse;
  // pin correction
  if(pin<0) pin = 0;
  else if(pin>4) pin = 4;
  // power correction
  if(power<0) power = 0;
  else if(power>100) power = 100;

  // pin range match
  if(pin==0) pulse =      map(power,0,100,320,580);
  else if(pin==1) pulse = map(power,0,100,400,200);
  else if(pin==2) pulse = map(power,0,100,520,380);
  else if(pin==3) pulse = map(power,0,100,330,560);
  else if(pin==4) pulse = map(power,0,100,270,410);

  // motor set position
  pwm.setPWM(pin, 0, pulse);
}

void RArm::action(int a, int b, int c, int d, int e) {
    delay(5);
    finger(0,a);
    delay(5);
    finger(1,b);
    delay(5);
    finger(2,c);
    delay(5);
    finger(3,d);
    delay(5);
    finger(4,e);
}
