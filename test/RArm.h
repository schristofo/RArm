#ifndef RArm_h
#define RArm_h

#include "Arduino.h"
#include <Adafruit_PWMServoDriver.h>

class RArm {
  public:
    RArm();
    void set();
    void set(int freq);
    void finger(int pin, int power);  // finger "pin" opens "power"%
    void action(int a, int b, int c, int d, int e); // hand state
  private:
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  // SDA-Pin:A4 , SCL-Pin:A5
};

#endif
