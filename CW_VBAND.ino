/*  USB Keyboard Emulator for CW practise V1.0                                              */
/*                                                                                          */
/*  Created by Fazlay Rabby S21RC, November, 2024.                                          */
/*                                                                                          */
/*  RELEASED AS OPEN SOURCE                                             */
/*  Feel free to use/change as you wish                                                     */

/* For use with Hamsolution VBand online CW practise system.
"{" (ascii 123) and "}" (ascii 125) keyboard press has been emulated.
paddle DIT connection to GPIO 3, paddle DASH connection to GPIO 2. Ground COMMON

Need natiive USB supported arduino, tested with pro micro clone.
*/


#include "Keyboard.h" //please load Keyboard library from library manager

//declaring button pins
const int buttonPin_dit = 3;          
const int buttonPin_dash = 2;

int previousButtonState_dit = HIGH; 
int previousButtonState_dash = HIGH; 

void setup() {
  //declare the buttons as input_pullup
  pinMode(buttonPin_dit, INPUT_PULLUP);
  pinMode(buttonPin_dash, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  //checking the state of the buttons
  int buttonState_dit = digitalRead(buttonPin_dit);
  int buttonState_dash = digitalRead(buttonPin_dash);
 //replaces button press with UP arrow
  if (buttonState_dit == LOW && previousButtonState_dit == HIGH) {
      // and it's currently pressed:
    Keyboard.press(123);
    delay(50);
  }

  if (buttonState_dash == LOW && previousButtonState_dash == HIGH) {
      // and it's currently pressed:
    Keyboard.press(125);
    delay(50);
  }

  if (buttonState_dit == HIGH && previousButtonState_dit == LOW) {
      // and it's currently released:
    Keyboard.release(123);
    delay(50);
  }
  
  if (buttonState_dash == HIGH && previousButtonState_dash == LOW) {
      // and it's currently released:
    Keyboard.release(125);
    delay(50);
  }
 
  previousButtonState_dit = buttonState_dit;
  previousButtonState_dash = buttonState_dash;

}
