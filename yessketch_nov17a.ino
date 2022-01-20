#include <Keyboard.h>
#include <Mouse.h>
#include <Joystick.h>

const double unarmed = 4;
const double Top1 = 16;
const double Top2 = 14;
const double Top3 = 15;
const double Top4 = 9;
const double Top5 = 10;
const double Top6 = 6;

  const double m3 = 5;
 #define outputA 4
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState; 


long previousMillis = 0;   
long interval = 30;
  
 void setup() { 
  
   pinMode (outputA,INPUT_PULLUP);
   pinMode (outputB,INPUT_PULLUP);
   pinMode (5,INPUT_PULLUP);
   
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode (8,INPUT_PULLUP);
  
Serial.begin(315200);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA); 
     Keyboard.begin();
  Mouse.begin();    
 } 
 void loop() { 

   unsigned long currentMillis = millis();
   
   if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
 
if (digitalRead(4) == LOW){ 
Mouse.move(0, 0, 1);}

  
 
if (digitalRead(7) == LOW){ 
Mouse.move(0, 0, -1);}
   }

if (digitalRead(16) == LOW){ 
Keyboard.press('r');}else Keyboard.release('r');
if (digitalRead(15) == LOW){ 
Keyboard.press('t');}else Keyboard.release('t');
if (digitalRead(14) == LOW){ 
Keyboard.press('.');}else Keyboard.release('.');
if (digitalRead(6) == LOW){ 
Keyboard.press('w');}else Keyboard.release('w');
if (digitalRead(9) == LOW){ 
Keyboard.press(KEY_ESC);}else Keyboard.release(KEY_ESC);
if (digitalRead(10) == LOW){ 
Keyboard.press(KEY_LEFT_SHIFT);}else Keyboard.release(KEY_LEFT_SHIFT); 
if(digitalRead(5) == LOW){ 
Keyboard.press('z');}else Keyboard.release('z');

if(digitalRead(8) == LOW){ 
Keyboard.press('4');}else Keyboard.release('4');


///////////////////
  
   
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
