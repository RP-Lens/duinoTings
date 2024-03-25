//Load cell amp and servo libraries
#include <HX711.h>
#include <Servo.h>

//HX711 and servo objects
HX711 scale;
Servo servo;

//Input pins on arduino from load cell amp
#define SVO  9
#define DAT  6
#define CLK  7

//This value is obtained using the SparkFun_HX711_Calibration sketch
#define calibration_factor -431.875 

//variables for servo control
int max = 85;
int min = 45;
int ang = min;
int dir = 1;


void setup() {
  Serial.begin(9600);

  
  //Set servo object to pin 9 and set angle
  servo.attach(9);
  servo.write(ang);
  delay(500);

  //Set pinmodes
  pinMode(DAT, INPUT);
  pinMode(CLK, INPUT);

  //set up the scale
  scale.begin(DAT, CLK);
  scale.set_scale(calibration_factor); 

  //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale.tare();	 
}

void loop() {

  //scale.get_units();
  //returns a float, sends to serial monitor
  Serial.print(ang);
  Serial.print(',');
  Serial.print(scale.get_units());
  Serial.println(',');
  delay(100);
  //Serial.println(ang);
  //Turn between min and max angle

 //step angle by +/-1 and write to motor
  ang += dir;
  servo.write(ang);

  //Change direction if angle reachezs min or max angle
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
}
