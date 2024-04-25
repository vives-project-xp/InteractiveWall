#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

const int NUM_SENSORS = 5; // Number of touch sensors
const int touchSounds[NUM_SENSORS] = {4, 15, 13, 12, 14};// Pins for touch sensors
const int touchButton = 27;
const int touchThreshold = 18 ; // Touch threshold
int soundToPlay = 0;
int soundsFolder = 0;

DFRobotDFPlayerMini dfPlayer;


void setup() {
  Serial.begin(115200);
  dfPlayer.begin(Serial);
  dfPlayer.volume(20);
  // Set touch pins as input
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(touchSounds[i], INPUT); 
  }

}

void loop() {
  // Read touch sensor values
  int touchValues[NUM_SENSORS];
  int buttonDetection = touchRead(touchButton);

  if (buttonDetection < touchThreshold)
 {
  soundsFolder = soundsFolder + 1;
  Serial.print("sound folder:");
  Serial.println(soundsFolder);
  delay(750);
 }
 
  for (int i = 0; i < NUM_SENSORS; i++) {
    touchValues[i] = touchRead(touchSounds[i]);
  }
  // Detect touched sensors
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (touchValues[i] < touchThreshold) {
      soundToPlay = i + 1;
      dfPlayer.playFolder(soundsFolder, soundToPlay);
      Serial.println(soundToPlay);
      Serial.print("Sensor ");
      Serial.print(i + 1); 
      Serial.println(" is touched.");
      touchValues[i] = 0;
    }
  }

  if (soundsFolder > 5)
  {
    soundsFolder = 0;
  }

  delay(100); // Adjust delay as needed
}
