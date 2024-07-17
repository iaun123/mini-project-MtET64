#include "lcd.h"
#include "set_pose.h"
#include "sensor.h"
#include "vaccum.h"
int data, flag = 0;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  set_pose();
  set_lcd();
  sensor();
  vac();

  vac_off();
  pose_home();

}

void loop() {
  delay(800);
  read_sensor();
  delay(1000);

  while (Serial1.available()) {
    Serial.println(data);
    data = Serial1.read();

    if (data == '1' ) {
      flag = 1;
    } else if (data == '2' ) {
      flag = 2;
    }
  }

  // state1 QR1
  if (flag == 1 ) {
    work();
    delay(1000);
    pose_start();
    vac_on();
    delay(800);
    pose_pick();
    delay(500);
    stageone();
    delay(1000);
    read_sensor();
    c_ultra1();
    delay(100);
    vac_off();
    down();
    stage();
    pose_home();
    delay(800);
    flag = 0;  // Reset the flag to 0
  }

  // state2 QR 2
  if (flag == 2) {
    work();
    delay(1000);
    pose_start();
    vac_on();
    delay(800);
    pose_pick();
    delay(500);
    stagetwo();
    delay(1000);
    read_sensor();
    c_ultra2();
    delay(100);
    vac_off();
    down();
    stage();
    pose_home();
    delay(800);
    flag = 0;  
  }
}
