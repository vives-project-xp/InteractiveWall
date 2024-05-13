// set pin numbers
const int touchPin1 = 15;
const int touchPin2 = 13;
const int touchPin3 = 12;
const int touchPin4 = 14;
const int touchPin5 = 27;
const int touchPin6 = 4;

const int ledPin1 = 25; 
const int ledPin2 = 26;
const int ledPin3 = 17;
const int ledPin4 = 5;
const int ledPin5 = 2;
const int ledPin6 = 16;

// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // initialize the LED pin as an output:
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
  pinMode (ledPin5, OUTPUT);
  pinMode (ledPin6, OUTPUT);
}

void loop(){
  // Read touch sensor values for each pin
  int touchValue1 = touchRead(touchPin1);
  int touchValue2 = touchRead(touchPin2);
  int touchValue3 = touchRead(touchPin3);
  int touchValue4 = touchRead(touchPin4);
  int touchValue5 = touchRead(touchPin5);
  int touchValue6 = touchRead(touchPin6);

  Serial.println(touchValue1);
  Serial.println(touchValue2);
  Serial.println(touchValue3);
  Serial.println(touchValue4);
  Serial.println(touchValue5);
  Serial.println(touchValue6);


  // Check and control LED 1
  if(touchValue1 < threshold){
    digitalWrite(ledPin1, HIGH);
    //Serial.println("LED1 on");
  } else {
    digitalWrite(ledPin1, LOW);
    //Serial.println("LED1 off");
  }

  // Check and control LED 2
  if(touchValue2 < threshold){
    digitalWrite(ledPin2, HIGH);
    //Serial.println("LED2 on");
  } else {
    digitalWrite(ledPin2, LOW);
    //Serial.println("LED2 off");
  }

  // Check and control LED 3
  if(touchValue3 < threshold){
    digitalWrite(ledPin3, HIGH);
    //Serial.println("LED3 on");
  } else {
    digitalWrite(ledPin3, LOW);
    //Serial.println("LED3 off");
  }

  // Check and control LED 4
  if(touchValue4 < threshold){
    digitalWrite(ledPin4, HIGH);
    //Serial.println("LED4 on");
  } else {
    digitalWrite(ledPin4, LOW);
    //Serial.println("LED4 off");
  }

  // Check and control LED 5
  if(touchValue5 < threshold){
    digitalWrite(ledPin5, HIGH);
    //Serial.println("LED5 on");
  } else {
    digitalWrite(ledPin5, LOW);
    //Serial.println("LED5 off");
  }

  // Check and control LED 6
  if(touchValue6 < threshold){
    digitalWrite(ledPin6, HIGH);
    //Serial.println("LED6 on");
  } else {
    digitalWrite(ledPin6, LOW);
    //Serial.println("LED6 off");
  }
  
  delay(100); // Delay for stability
}
