int k1 = 52; //yellow
int k2 = 50; //green
int k3 = 48; //red
int k4 = 46; //blue

int BB;
int BU;
int W1;
int W2;

int bb;
int bu;
int w1;
int w2;


void switch_color() {
  pinMode(k1, INPUT_PULLUP);
  pinMode(k2, INPUT_PULLUP);
  pinMode(k3, INPUT_PULLUP);
  pinMode(k4, INPUT_PULLUP);

  BB = digitalRead(k1);
  BU = digitalRead(k2);
  W1 = digitalRead(k3);
  W2 = digitalRead(k4);

}

void select_color() {
  //  switch_color();
  if (BB == 0) {
    bb++;
    bu = 0;
    w1 = 0;
    w2 = 0;
    if (bb > 1) {
      bb = 1;
    }
  }
  if (BU == 0) {
    bb = 0;
    bu++;
    w1 = 0;
    w2 = 0;
    if (bu > 1) {
      bu = 1;
    }
  }
  if (W1 == 0) {
    bb = 0;
    bu = 0;
    w1++;
    w2 = 0;
    if (w1 > 1) {
      w1 = 1;
    }
  }
  if (W2 == 0) {
    bb = 0;
    bu = 0;
    w1 = 0;
    w2++;
    if (w2 > 1) {
      w2 = 1;
    }
  }
}
