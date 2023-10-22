#include <Wire.h> //Library which allows I2C communication.
#include <Adafruit_PWMServoDriver.h> //This library must be downloaded to run the code.
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();//Instantiating objects with the Adafruit_PWMServoDriver class.
 
#define MIN_PULSE_WIDTH 500   //These are the minimum and maximum wavelength values which serve MG 995.
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 60
 
int pulseWidth(int angle){ //This function calculates servo's motion angle.
int pulse_wide, analog_value;
pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH); //This function get angle from 0 to 180 degrees and map from length minimum value to maximum. 
analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
Serial.println(analog_value);
return analog_value; //The value this function returns.
}
  
void setup(){
Serial.begin(9600);
//Serial.println("16 channel Servo test!");
pwm.begin();  //Initialize the library and send PWM signals.
pwm.setPWMFreq(FREQUENCY); //Servo's update frequency at 60 Hertz.
pwm.setPWM(1,0,pulseWidth(0)); 
pwm.setPWM(2,0,pulseWidth(0)); 
pwm.setPWM(3,0,pulseWidth(0)); 
pwm.setPWM(4,0,pulseWidth(0));
pwm.setPWM(5,0,pulseWidth(0));
pwm.setPWM(6,0,pulseWidth(0));
}
 
void loop(){ 
// pwm.setPWM(6,0,pulseWidth(45));
// pwm.setPWM(4,0,pulseWidth(0));
// delay(1000);  
// pwm.setPWM(3,0,pulseWidth(0));
pwm.setPWM(1,0,pulseWidth(180));
delay(5500);
// pwm.setPWM(3,0,pulseWidth(90));
pwm.setPWM(1,0,pulseWidth(0));
delay(5000);
 pwm.setPWM(1,0,pulseWidth(90));
  delay(6000);
//  pwm.setPWM(1,0,pulseWidth(45));
//  delay(2000);
// pwm.setPWM(2,0,pulseWidth(0));
// pwm.setPWM(6,0,pulseWidth(0));
// delay(2000);
}
 
//TESTING THE ARM.
//pwm.setPWM(1,0,pulseWidth(27)); //Open claw.
//pwm.setPWM(1,0,pulseWidth(100)); //Close claw.
//pwm.setPWM(2, 0, pulseWidth(90)); //WRIST Moving claw's position.
 
//pwm.setPWM(3,0,pulseWidth(20)); //Low number raise the hand.
//pwm.setPWM(3,0,pulseWidth(0)); //High number put down the hand.
 
//pwm.setPWM(4, 0, pulseWidth(180));//High number put down the elbow.
//pwm.setPWM(4, 0, pulseWidth(70));