#include "lcd.h"
#include "set_pose.h"
#include "sensor.h"
#include "vaccum.h"

void setup() {
  Serial.begin(9600);
  set_pose();
  set_lcd();
  sensor();
  vac();

  pose_home();
  vac_off();
  //  stagetwo();

}

void loop() {
  delay(3000);
  read_sensor();
  delay(800);
  stage();


  //state1 ultra metal
  if (optic == 0 && induc == 0) {
    work();
    delay(1000);
    vac_on();
    pose_start();
    delay(800);
    pose_pick();
    delay(500);
    stageone();
    delay(1000);
    read_sensor();
    c_ultra1();
    delay(800);
    vac_off();
    stage();
    pose_home();
  }

  //state2 ultra plastic
  if (optic == 0 && induc == 1) {
    work();
    delay(1000);
    vac_on();
    pose_start();
    delay(800);
    pose_pick();
    delay(500);
    stagetwo();
    delay(1000);
    read_sensor();
    c_ultra2();
    delay(800);
    vac_off();
    stage();
    pose_home();
  }
}

void c_ultra1() {
  if (dis_ultra1 >= 0 && dis_ultra1 <= 50) {
    c1 = c1 + 1;
    vac_off();
    Serial.println(dis_ultra1);
    down();
    if (c1 == 1) {
      lcd.setCursor(9, 1);
      lcd.print(c1);
      Serial.print("c1 = ");
      Serial.println(c1);
    }
    else if (c1 > 1) {
      lcd.setCursor(9, 1);
      lcd.print("full");
      Serial.println("c1 full");
    }
  }
}

void c_ultra2() {
  if (dis_ultra2 >= 0 && dis_ultra2 <= 50) {
    c2 = c2 + 1;
    vac_off();
    Serial.println(dis_ultra2);
    down();
    if (c2 == 1) {
      lcd.setCursor(9, 2);
      lcd.print(c2);
      Serial.print("c2 = ");
      Serial.println(c2);
    }
    else if (c2 > 1) {
      lcd.setCursor(9, 2);
      lcd.print("full");
      Serial.println("c2 full");
    }
  }
}
