#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

const int NUM_SENSORS = 9;
int soundNumbers[NUM_SENSORS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int touchSensors[NUM_SENSORS] = {4, 2, 15, 12, 13, 14, 27, 33, 32};

int soundsFolder = 1;

int button1 = 25;
int button2 = 26;

int buttonState1 = 0;
int buttonState2 = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int lastButtonState;

int tresHold = 50;
DFRobotDFPlayerMini dfPlayer;

void setup() {
  Serial.begin(115200);
  dfPlayer.begin(Serial);
  dfPlayer.volume(20);
}


void loop()
{

    int ButtonState1 = digitalRead(button1);
    int ButtonState2 = digitalRead(button2);
    int debounceState1 = debounce(ButtonState1);
    int debounceState2 = debounce(ButtonState2);
    int lastButtonState1;
    int lastButtonState2;
    
    //if button is pressed, toggle the folder value
    if (debounceState1 != lastButtonState1) {
       
        soundsFolder = 2;
        lastButtonState1 = debounceState2;

    }
    if (debounceState2 != lastButtonState2) {
       
        soundsFolder = 1;
        lastButtonState2 = debounceState2;
    }

    //if the touch sensor is touched play the corresponding sound from the folder
    for (int i = 0; i < NUM_SENSORS; i++) {    
        if (touchSensors[i] > tresHold) {       
        dfPlayer.playFolder(soundsFolder, soundNumbers[i]);      
        break; // Exit loop after playing the sound   
        } 
    }
      
}

int debounce(int buttonState) {
  // Get the current time
  unsigned long currentTime = millis();
  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // Reset the debounce timer
     lastDebounceTime = currentTime;
  }

  // Check if enough time has passed since the last change
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    // Update the last button state
    lastButtonState  = buttonState;
  }

  return lastButtonState ;
}
