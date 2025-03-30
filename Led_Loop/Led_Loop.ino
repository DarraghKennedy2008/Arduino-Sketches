void setup() {
  //Initalised LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Turns the LED on to high voltage
  digitalWrite(LED_BUILTIN, HIGH);
  // Waits one second
  delay(100);
  // Turns the LED voltage to low
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
