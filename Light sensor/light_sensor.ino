#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C // IC2 address, this can be found using code online.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define lightSens  A0

#define ledOne 8



void setup() {


  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;); 

  pinMode(ledOne, OUTPUT);
 }
   

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(32,0);
  display.println("Light Value");
  display.display();



 

}

void loop() {
  int lightVal = analogRead(lightSens);

  display.fillRect(0, 20, 128, 30, BLACK);
  display.setTextSize(3);
  display.setCursor(64,24);
  display.println(lightVal);
  display.display();
  
  if (lightVal <= 100) {
    analogWrite(ledOne, 255);
  } else if (lightVal >=250) {
    analogWrite(ledOne, 0);
  }
  
  
  




}