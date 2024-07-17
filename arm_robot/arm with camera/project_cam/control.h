int cx = 0;
int cy = 0;
int ok = 0;

String ad11;
String ad12;
String ad21;
String ad22;

void control() {
  if (XValue == 0) {
    cx--;
    if (cx < 1) {
      cx = 0;
    }
  }
  if (XValue == 1023) {
    cx++;
    if (cx > 1) {
      cx = 1;
    }
  }
  if (YValue == 0) {
    cy++;
    if (cy > 1) {
      cy = 1;
    }
  }
  if (YValue == 1023) {
    cy--;
    if (cy < 1) {
      cy = 0;
    }
  }
  if (SWValue == 0) {
    ok++;
  }
}

void select() {
  if (ok == 1) {
    //address11
    if (cx == 0 && cy == 0) {
      lcd.setCursor(9, 1);
      lcd.print("_");
      delay(300);
      lcd.setCursor(9, 1);
      lcd.print(" ");
      delay(300);
      select_color();
      if (bb == 1) {
        ad11 = "BB";
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print("BB");
      }
      if (bu == 1) {
        ad11 = "BU";
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print("BU");
      }
      if (w1 == 1) {
        ad11 = "W1";
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print("W1");
      }
      if (w2 == 1) {
        ad11 = "W2";
        lcd.setCursor(10, 1);
        lcd.print(" ");
        lcd.setCursor(10, 1);
        lcd.print("W2");
      }
    }

    //address12
    if (cx == 0 && cy == 1) {
      lcd.setCursor(13, 1);
      lcd.print("_");
      delay(300);
      lcd.setCursor(13, 1);
      lcd.print(" ");
      delay(300);
      select_color();
      if (bb == 1) {
        ad11 = "BB";
        lcd.setCursor(14, 1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print("BB");
      }
      if (bu == 1) {
        ad11 = "BU";
        lcd.setCursor(14, 1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print("BU");
      }
      if (w1 == 1) {
        ad11 = "W1";
        lcd.setCursor(14, 1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print("W1");
      }
      if (w2 == 1) {
        ad11 = "W2";
        lcd.setCursor(14, 1);
        lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print("W2");
      }
    }

    //address21
    if (cx == 1 && cy == 0) {
      lcd.setCursor(9, 2);
      lcd.print("_");
      delay(300);
      lcd.setCursor(9, 2);
      lcd.print(" ");
      delay(300);
      select_color();
      if (bb == 1) {
        ad11 = "BB";
        lcd.setCursor(10, 2);
        lcd.print(" ");
        lcd.setCursor(10, 2);
        lcd.print("BB");
      }
      if (bu == 1) {
        ad11 = "BU";
        lcd.setCursor(10, 2);
        lcd.print(" ");
        lcd.setCursor(10, 2);
        lcd.print("BU");
      }
      if (w1 == 1) {
        ad11 = "W1";
        lcd.setCursor(10, 2);
        lcd.print(" ");
        lcd.setCursor(10, 2);
        lcd.print("W1");
      }
      if (w2 == 1) {
        ad11 = "W2";
        lcd.setCursor(10, 2);
        lcd.print(" ");
        lcd.setCursor(10, 2);
        lcd.print("W2");
      }
    }

    //address22
    if (cx == 1 && cy == 1) {
      lcd.setCursor(13, 2);
      lcd.print("_");
      delay(300);
      lcd.setCursor(13, 2);
      lcd.print(" ");
      delay(300);
      select_color();
      if (bb == 1) {
        ad11 = "BB";
        lcd.setCursor(14, 2);
        lcd.print(" ");
        lcd.setCursor(14, 2);
        lcd.print("BB");
      }
      if (bu == 1) {
        ad11 = "BU";
        lcd.setCursor(14, 2);
        lcd.print(" ");
        lcd.setCursor(14, 2);
        lcd.print("BU");
      }
      if (w1 == 1) {
        ad11 = "W1";
        lcd.setCursor(14, 2);
        lcd.print(" ");
        lcd.setCursor(14, 2);
        lcd.print("W1");
      }
      if (w2 == 1) {
        ad11 = "W2";
        lcd.setCursor(14, 2);
        lcd.print(" ");
        lcd.setCursor(14, 2);
        lcd.print("W2");
      }
    }
  }

  if (ok > 1) {
    lcd.setCursor(7, 0);
    lcd.print("ok      ");

    lcd.setCursor(10, 1);
    lcd.print(ad11);
    lcd.setCursor(10, 2);
    lcd.print(ad21);
    lcd.setCursor(14, 1);
    lcd.print(ad12);
    lcd.setCursor(14, 2);
    lcd.print(ad22);

    lcd.setCursor(13, 2);
    lcd.print(" ");
    lcd.setCursor(9, 2);
    lcd.print(" ");
    lcd.setCursor(9, 1);
    lcd.print(" ");
    lcd.setCursor(13, 1);
    lcd.print(" ");

    lcd.setCursor(0, 3);
    lcd.print("done select      ");
  }
}
