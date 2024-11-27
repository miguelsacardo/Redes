const byte LED = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH); //liga o led
  delay(2000); //espera 1s
  digitalWrite(LED, LOW); //apaga o led
  delay(2000); //espera 1 segundo
}
