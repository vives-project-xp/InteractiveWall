//William
//Code voor geluid uit een set afspelen, nadat een fysieke knop is gedrukt?


#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>

#define RX_PIN 1
#define TX_PIN 0
#define SOUND_SWITCH_PIN 2

DFRobotDFPlayerMini dfplayer;

const String soundsSet1[] = {
  "A cat meowing",
  "A dog barking",
  "A duck quacking"
};
const String soundsSet2[] = {
  "Mario jump",
  "Mario coin",
  "Mario death"
};
const int amount_of_sounds_set1 = sizeof(soundsSet1) / sizeof(soundsSet1[0]);
const int amount_of_sounds_set2 = sizeof(soundsSet2) / sizeof(soundsSet2[0]);
int currentSoundSet = 1; // Start with sound set 1

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SWITCH_PIN, INPUT_PULLUP);

  Serial.println("Initializing DFPlayer Mini...");
  Serial.println("Setting up serial communication...");
  HardwareSerial hs(1);
  hs.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  dfplayer.begin(hs);
  dfplayer.setTimeOut(500);
  dfplayer.volume(30); // Set volume (0-30)

  Serial.println("Sound set 1 initialized.");
}

void loop() {
  if (digitalRead(SOUND_SWITCH_PIN) == LOW) {
    // Switch sound set
    if (currentSoundSet == 1) {
      currentSoundSet = 2;
      Serial.println("Switching to sound set 2...");
    } else {
      currentSoundSet = 1;
      Serial.println("Switching to sound set 1...");
    }
  }

  // Play sound based on the current set
  if (currentSoundSet == 1) {
    playSoundSet(soundsSet1, amount_of_sounds_set1);
  } else {
    playSoundSet(soundsSet2, amount_of_sounds_set2);
  }

  delay(100); // Delay to debounce the button
}

void playSoundSet(const String* sounds, int size) {
  int randomIndex = random(size); // Choose a random sound index from the set
  String sound = sounds[randomIndex];
  Serial.println("Playing sound: " + sound);
  dfplayer.play(randomIndex + 1);
  delay(5000); // Play each sound for 5 seconds
}
