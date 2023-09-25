#include <Arduino.h>
#include <HCSR04.h>

int readPin = 25;
float scale = 0.0f;
float minimum = 15.0f;
float maximum = 60.0f;
float adc_max = 4095.0f;
float distance = 0.0f;
float offset = 0.0f;

UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.

void setup() {
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop() {
  // Measure distance using the analog sensor
  float x = analogRead(readPin);
  scale = (float)(((maximum - minimum) / adc_max));
  distance = (float) (scale * x + minimum - offset);

  Serial.print(F("Analog Distance: "));
  if (distance <= minimum){
    Serial.print("<=");
  }
 else if(distance >= maximum){
    Serial.print(">=");
 }
    Serial.print(distance);

  Serial.println(F("cm"));

  // Measure distance using the ultrasonic sensor
  double ultrasonicDistance = distanceSensor.measureDistanceCm();

  Serial.print(F("Ultrasonic Distance: "));
  Serial.print(ultrasonicDistance);
  Serial.println(F("cm"));

  delay(1000);
}