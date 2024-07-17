#define solinoid 2
#define vaccum 3

void vac() {
  pinMode(vaccum, OUTPUT);
  pinMode(solinoid, OUTPUT);
}
void vac_on() {
  digitalWrite(vaccum, 1);
  digitalWrite(solinoid, 1);
}
void vac_off() {
  digitalWrite(vaccum, 0);
  digitalWrite(solinoid, 0);  
}
