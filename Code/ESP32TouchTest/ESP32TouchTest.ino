
#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
const int NUM_SENSORS = 8; // Number of touch sensors
const int touchPins[NUM_SENSORS] = {4, 15, 13, 12, 14, 27, 33, 32}; // Pins for touch sensors
const int touchThreshold = 18 ; // Touch threshold
int soundToPlay = 0;
int soundsFolder = 1;
DFRobotDFPlayerMini dfPlayer;
void setup() {
  Serial.begin(115200);
  dfPlayer.begin(Serial);
  dfPlayer.volume(20);
  // Set touch pins as input
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(touchPins[i], INPUT);
  }
}

void loop() {
  // Read touch sensor values
  int touchValues[NUM_SENSORS];

  for (int i = 0; i < NUM_SENSORS; i++) {
    touchValues[i] = touchRead(touchPins[i]);
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
    }
  }

  delay(100); // Adjust delay as needed
}
