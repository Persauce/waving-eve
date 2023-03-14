#include <Servo.h>
Servo serve;
const int  buttonPin = 3;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to
int pos=0;
 
// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
 
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  serve.attach(2);
  Serial.begin(9600);

}
 
 
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
 
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      //if its high aka touched
      Serial.println("on");
      for(pos=0;pos<=55;pos+=1){
        serve.write(pos);
        delay(5);
      }
      for(pos=55;pos>=0;pos-=1){
        serve.write(pos);
        delay(5);
      }
      
    }
    else {
      // if its low that means its off
      Serial.println("off");
    }
  }
  //makes the previous state the current as it goes into the next state
  lastButtonState = buttonState;

}
