//SERVO MOTOR ARCHIMEDES SCREW//
//This program runs on an Adafruit Featherwing 

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

bool sensor_passed = false;
#define METAL_DETECTED 0
#define SERVOMIN 150
#define SERVOMAX 600
#define SERVOSUPERMAX 4000
#define SERVOMED 375

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  // copied from servo demo code
  delay(10);
}

void loop() {
  delay(500);
  int sensor_ball = digitalRead(5);
  if (sensor_ball != METAL_DETECTED) {    //no metal detected
    pwm.setPWM(0, 0, 0); // do not run
    Serial.println("Not detected :(");
    
  } else {    // here, sensor_motor is detecting metal
    Serial.println("Detected :)");
    for (uint16_t pulselen = 280; pulselen < 330; pulselen+=1) {
    pwm.setPWM(0, 0, pulselen);
    Serial.println("Pulse length:");
    Serial.println(pulselen);
    delay(500);
    
    // note: at about pulselen ~ 340 the servo seems to switch direction,
    // with the servo rotating at different speeds around the switch point.

    }
  }
}

