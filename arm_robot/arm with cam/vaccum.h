int solinoid = 2;
int vaccum = 3;

void vac() {
  pinMode(vaccum, OUTPUT);
  pinMode(solinoid, OUTPUT);
}
void vac_on() {
  digitalWrite(vaccum, 1);
  digitalWrite(solinoid, 1);
}
void vac_off() {
  digitalWrite(vaccum, 0); //1
  digitalWrite(solinoid, 0);
}
