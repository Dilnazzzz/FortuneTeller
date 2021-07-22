#include <Servo.h>

// C++ code
//
int servo_pin = 9;
int pinRandom = 10;
int pinButton = 2;
int array[6] = {15, 45, 75, 105, 135, 165};
int led1 = 5;
int led2 = 4;
int led3 = 3;
Servo my_servo;

void setup() {
  my_servo.attach(servo_pin);
  pinMode(pinRandom, INPUT);
  pinMode(pinButton, INPUT);
  randomSeed(analogRead(pinRandom));
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

}

void loop() {
  if (digitalRead(pinButton) == HIGH) {
    predict_the_future();
  }
  delay(100);
}

void predict_the_future() {
  for (int i = 0; i < 5; i ++) {
    digitalWrite(led1, HIGH);
    delay(250);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led3, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    int position = array[random (6)];
    my_servo.write(position);
    delay(750);
  } 
}