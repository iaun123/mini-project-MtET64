#define echo1 15
#define trig1 9
#define echo2 17
#define trig2 7
#define inductive 12
#define optical 4

int maximumRange = 200;
int minimumRange = 0;
long duration1, dis_ultra1, duration2, dis_ultra2;
int induc;
int optic;
int c1 = 0; //ultra1
int c2 = 0; //ultra2

void sensor() {
  pinMode(optical, INPUT_PULLUP);
  pinMode(inductive, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}

void read_sensor() {
  optic = digitalRead(optical);
  induc = digitalRead(inductive);

  digitalWrite(trig1, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trig1, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echo1, HIGH);
  dis_ultra1 = duration1 * 0.0343 / 2; //cm

  digitalWrite(trig2, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trig2, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echo2, HIGH);
  dis_ultra2 = duration2 * 0.0343 / 2; //cm
}


void stage() {
  if (c1 == 2 && c2 == 2) {
    lcd.setCursor(7, 0);
    lcd.print("finish");

    lcd.setCursor(0, 3);
    lcd.print("                   ");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("finish");
  }

  else if (c1 == 1 || c2 == 1) {
    lcd.setCursor(7, 0);
    lcd.print("working");
  }
  else if (c1 > 2 || c2 > 2) {
    lcd.setCursor(0, 3);
    lcd.print("                   ");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("recheck");

    lcd.setCursor(7, 0);
    lcd.print("recheck");

    lcd.setCursor(9, 2);
    lcd.print("error");
    lcd.setCursor(9, 1);
    lcd.print("error");
  }
}

void c_ultra1() {
  if (dis_ultra1 >= 0 && dis_ultra1 <= 100) {
    c1 = c1 + 1;
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
    delay(500);
  }
}

void c_ultra2() {
  if (dis_ultra2 >= 0 && dis_ultra2 <= 210) {
    c2 = c2 + 1;
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
    delay(500);
  }
}
