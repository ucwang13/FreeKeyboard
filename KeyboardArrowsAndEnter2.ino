#include "Keyboard.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char input = Serial.read();
    if (input == '['){
      while (!Serial.available());
      char input = Serial.read();
      if (input == 'A') {
        Keyboard.press(KEY_UP_ARROW);
        delay(100);
        Keyboard.releaseAll();
      } else if (input == 'B') {
        Keyboard.press(KEY_DOWN_ARROW);
        delay(100);
        Keyboard.releaseAll();
      }  else if (input == 'C') {
        Keyboard.press(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.releaseAll();
      } else if (input == 'D') {
        Keyboard.press(KEY_LEFT_ARROW);
        delay(100);
        Keyboard.releaseAll();
      }
    } else if (input == 13) {
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
    } else if (input == 127) {
      Keyboard.press(KEY_BACKSPACE);
      delay(100);
      Keyboard.releaseAll();
    } else {
      Keyboard.write(input);
    }
  }
  
}
