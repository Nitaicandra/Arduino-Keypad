#include <Keyboard.h>
#include <Mouse.h>
#include <Joystick.h>


const int SW_pin = 15; //digital pin connected to switch output
const double X_pin = 3; //analog pin connected to x output
const double Y_pin = 2; //analog pin connected to y output


const double m1 = 5;
const double m2 = 6;
const double m3 = 4;
 #define outputA 2
 #define outputB 3
 int counter = 0; 
 int aState;
 int aLastState;  
 const double m4 = 7;

const double low1 = 8;
const double low2 = 9;
const double low3 = 10;


const double top1 = 14;
const double top2 = 16;

const double Switch = 2;
                                                                                                                            
void setup() {

  

pinMode (outputA,INPUT_PULLUP);
pinMode (outputB,INPUT_PULLUP);
pinMode(5, INPUT_PULLUP); 
pinMode(4, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP); 

 pinMode(2, INPUT_PULLUP);
  pinMode(m4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  Serial.begin(315200);
  Keyboard.begin();
  Mouse.begin();   
  aLastState = digitalRead(outputA); 

}
                                                        
void loop () {
                                                                                                   
if(digitalRead(SW_pin) == LOW){ 
Keyboard.press('4');}else Keyboard.release('4');

 if (digitalRead(m1) == LOW){ 
Mouse.press(MOUSE_LEFT);}else Mouse.release(MOUSE_LEFT); 

 if(digitalRead(m2) == LOW){ 
Mouse.press(MOUSE_RIGHT);}else Mouse.release(MOUSE_RIGHT);

if (digitalRead(m3) == LOW){ 
Mouse.press(MOUSE_MIDDLE);}else Mouse.release(MOUSE_MIDDLE);
  
if(digitalRead(m4) == LOW){ 
Keyboard.press('a');}else Keyboard.release('a');



if(digitalRead(low1) == LOW){ 
Keyboard.press('/');}else Keyboard.release('/');
  
if(digitalRead(low2) == LOW){ 
Keyboard.press(']');}else Keyboard.release(']');

if (digitalRead(low3) == LOW){ 
Keyboard.press('z');}else Keyboard.release('z');



if (digitalRead(top1) == LOW){ 
Keyboard.press('.');}else Keyboard.release('.');
 
if(digitalRead(top2) == LOW){ 
Keyboard.press('g');}else Keyboard.release('g');

if (digitalRead(Switch) == LOW){ 
Keyboard.press(KEY_RIGHT_ALT );Keyboard.press('0');
}else Keyboard.release('0');Keyboard.release(KEY_RIGHT_ALT );

aState = digitalRead(outputA);
  

// Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
  /* if (aState != aLastState){    


    
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++; Mouse.move(0, 0, -1); 
 
       
     } else if (digitalRead(outputB) == aState){
       counter --; Mouse.move(0, 0, 1);
     } 
     //Serial.print("Position: ");
    // Serial.println(counter);
    aLastState = aState;
   }
    // Updates the previous state of the outputA with the current state 


*/
                                                                              

if(analogRead(X_pin)<422){ 
Keyboard.press(KEY_UP_ARROW);}else Keyboard.release(KEY_UP_ARROW);
  
if(analogRead(X_pin)>602){  
Keyboard.press(KEY_DOWN_ARROW);} else Keyboard.release(KEY_DOWN_ARROW);
  
if(analogRead(Y_pin)<222){
Keyboard.press(KEY_RIGHT_ARROW);}else Keyboard.release(KEY_RIGHT_ARROW);
  
if(analogRead(Y_pin)>1002){
Keyboard.press(KEY_LEFT_ARROW);} else Keyboard.release(KEY_LEFT_ARROW);                                                                                          
 
Serial.print("X ");                                                                                             
Serial.println(  analogRead(X_pin));
Serial.println( "" );
Serial.print("Y ");
Serial.println(  analogRead(Y_pin));
Serial.println( "" );



}
