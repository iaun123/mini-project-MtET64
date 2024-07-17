int X = A0;
int XValue = 0;
int Y = A1;
int YValue = 0;
int SW = A2;
int SWValue;


void joy() {
  XValue = analogRead(X);
  YValue = analogRead(Y);
  SWValue = analogRead(SW);

}
