#include <Servo.h>

Servo servo;

//variables for servo control
int min = 40;
int max = 85;
int ang = min;
int dir = 1;

void setup() {
  Serial.begin(9600);
  //Set servo object to servo input pin and set angle
  servo.attach(9);
  servo.write(45);
}

void loop() {
  // put your main code here, to run repeatedly:
  //step angle by +/-1 and write to motor
  /*ang += dir;
  servo.write(ang);
  //Change direction if angle is 135
  if (ang <= min)
  {
    dir = -dir;
    delay(500);
  }
  //If angle returns to 90, deactivate arduino
  if (ang >= max)
  {
    dir = -dir;
    delay(500);
  }

  Serial.println(ang);
  delay(30);*/
}
