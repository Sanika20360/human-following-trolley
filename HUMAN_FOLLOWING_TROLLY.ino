#include <Wire.h>


int vSpeed = 80;
int turn_speed = 80;
int t_p_speed = 125;
int stop_distance = 20;
int turn_delay = 10;


const long interval1 = 500;

const int trigPin = 11;
const int echoPin = 12;

//L293 Connection
const int motorA1      = 7;
const int motorA2      = 6;
const int motorAspeed  = 8;
const int motorB1      = 5;
const int motorB2      = 4;
const int motorBspeed  = 13;

//Sensor Connection
const int left_sensor_pin = 10;
const int right_sensor_pin = 9;

int turnspeed;
int left_sensor_state;
int right_sensor_state;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(left_sensor_pin, INPUT);
  pinMode(right_sensor_pin, INPUT);

  Serial.println("Setup Complete");
}

void loop() {
  delay(1);
  left_sensor_state = digitalRead(left_sensor_pin);
  Serial.print("left_sensor_state: ");
  Serial.println(left_sensor_state);
  right_sensor_state = digitalRead(right_sensor_pin);
  Serial.print("right_sensor_state: ");
  Serial.println(right_sensor_state);

  if (currentMillis - previousMillis1 >= interval1) {
    // save the last time you read the ultrasonic sensor
    previousMillis1 = currentMillis;
    // Ultrasonic read
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
  }

  if (right_sensor_state == LOW && left_sensor_state == HIGH && distance > 20) {
    Serial.println("turning right ");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorAspeed, 80);
    analogWrite(motorBspeed, 80);
  }
  if (right_sensor_state == HIGH && left_sensor_state == LOW && distance > 20) {
    Serial.println("turning left  ");
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorAspeed, 80);
    analogWrite(motorBspeed, 80);
    delay(turn_delay);
  }
  if (right_sensor_state == LOW && left_sensor_state == LOW && distance > 20) {
    Serial.println("going forward");
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorAspeed, 80);
    analogWrite(motorBspeed, 80);
    delay(turn_delay);
  }
  if (right_sensor_state == HIGH && left_sensor_state == HIGH) {
    Serial.println("stop");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    analogWrite(motorAspeed, 0);
    analogWrite(motorBspeed, 0);
  }
  if (distance < stop_distance) {
    Serial.println(".....Stop.....");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    analogWrite(motorAspeed, 0);
    analogWrite(motorBspeed, 0);
  }
}
