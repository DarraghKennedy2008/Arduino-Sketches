#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C // IC2 address, this can be found using code online.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define buttonOne 2
#define buttonTwo 3
#define buttonThree 4
#define buzzer 8

  int count = 0;
  int buttonStateOne = 0;
  int buttonStateTwo = 0;
  int buttonStateThree = 0;


void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;); 
 }

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(32,0);
  display.println("Counter");
  display.display();

  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
  pinMode(buttonThree, INPUT);
  pinMode(buzzer, OUTPUT);
  

 

}

void loop() {
  buttonStateOne = digitalRead(buttonOne);
  buttonStateTwo = digitalRead(buttonTwo);
  buttonStateThree = digitalRead(buttonThree);
  
  display.fillRect(0, 20, 128, 30, BLACK);
  display.setTextSize(3);
  display.setCursor(64,24);
  display.print(count);
  display.display();
  
  
  
  if (buttonStateOne == HIGH) {
    count++;
    tone (buzzer, 1500,100);
    while(digitalRead(buttonOne) == HIGH);
  }

  if (buttonStateTwo == HIGH) {
    count--;
    tone (buzzer, 300,100);
    tone (buzzer, 600,100);
    while(digitalRead(buttonTwo) == HIGH);
  }


 if (buttonStateThree == HIGH) {
    count = 0;
    for (int t = 500;t > 100; t -= 50) {
      tone(buzzer, 1500,100);
      delay(20);
      tone(buzzer, 300,100);
      delay(20);
    }
    while(digitalRead(buttonThree) == HIGH);
      
  }

}

