#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)(use135)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)(use615)

void set_pose() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void pose_home() {
  pwm.setPWM(3, 0, 350);  //90  350
  delay(300);
  pwm.setPWM(2, 0, 350);  //90 350
  delay(300);
  pwm.setPWM(1, 0, 226);  //5
}

void pose_start() {
  pwm.setPWM(1, 0, 226);  //
  delay(300);
  pwm.setPWM(2, 0, 187);  //30 176
  delay(300);
  pwm.setPWM(3, 0, 497); //130
}

void pose_pick() {
  pwm.setPWM(3, 0, 294);  //100
  delay(300);
  pwm.setPWM(2, 0, 258);  //46
}

void stageone() {
  pwm.setPWM(1, 0, 469);  //125 447
  delay(800);
  pwm.setPWM(2, 0, 258);  //45 258
  delay(400);
  pwm.setPWM(3, 0, 469);  //125 461
}

void stagetwo() {
  pwm.setPWM(1, 0, 538);  //125
  delay(800);
  pwm.setPWM(2, 0, 218); //33 204
  delay(400);
  pwm.setPWM(3, 0, 433); //120 433
}
