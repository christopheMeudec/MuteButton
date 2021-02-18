#include <Keyboard.h>

/*
*****************
** Mute button **
*****************
* 
*/

// use this option for Windows and Linux:
char ctrlKey = KEY_LEFT_CTRL;
char shftKey = KEY_LEFT_SHIFT;
char winKey = KEY_LEFT_GUI;

// constant to define pin number
const int BUTTON_PIN = 18;        // the number of the used pin (A0)

// Variables will change:
int currentState;                // the current state from the input pin
int previousState = LOW;         // the previous state from the input pin

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // read the current state of the pin
  currentState = digitalRead(BUTTON_PIN);

  if (currentState == HIGH && previousState == LOW)
  {
    executeShortKeys();
  }

  previousState = currentState;
}

void executeShortKeys() {
  // Activate Team window with Win Key + {Number} //position of Teams in taskbar
  //Keyboard.press(winKey);
  //Keyboard.press('1'); // Position in task bar
  //delay(100);
  //Keyboard.releaseAll();
  //delay(100);
  Keyboard.press(ctrlKey);
  Keyboard.press(shftKey);
  Keyboard.press(';'); //Using ';' instead of 'm' for AZERTY keyboard
  delay(100);
  Keyboard.releaseAll();
}