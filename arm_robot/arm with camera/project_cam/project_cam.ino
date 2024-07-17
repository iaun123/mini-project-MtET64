#include "lcd.h"
#include "set_pose.h"
#include "sensor.h"
#include "vaccum.h"
#include "switch_color.h"
#include "joy.h"
#include "control.h"
String data;



void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

//  set_pose();
  set_lcd();
//  sensor();
//  vac();

//  vac_off();
//  pose_home();
  switch_color();

}

void loop() {
  joy();
  control();
  switch_color();
  select();
  
}
