// Defines what pins they are attached too
#define buzzer 8
#define button 2

//Buttonstate set to zero
int buttonState = 0;


void setup() {
  //Sets devices to their respective use.
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // Reads button state and stores it in buttonState
  buttonState = digitalRead(button);

  //If button is pressed play a tone. If not do nothing
  if (buttonState == HIGH ) {
    tone (buzzer, 10000,10);
  } Else {

  }
  
}
