// Do not remove the include below
#include "lass2_1.h"


define DUTY_CYCLE 20
#define REAR_LED_PIN 9

int a=0;

void PWM_Write(int pin, int on_time_perc){

	int on_time=DUTY_CYCLE*on_time_perc*0.01;
	int off_time=DUTY_CYCLE-on_time;
	digitalWrite(pin,HIGH);
	delay(on_time);
	digitalWrite(pin,LOW);
	delay(off_time);
}

void myAnalogWrite(int pin, int percent, int time){
	int numLoops=time/DUTY_CYCLE;
	int i;
	for(i=0; i<=numLoops; i++){
		PWM_Write(pin,percent);
	}
}
void setup()
{
	pinMode(REAR_LED_PIN,OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{

	if(a==0){
		myAnalogWrite(REAR_LED_PIN,100,2000);
		myAnalogWrite(REAR_LED_PIN,75,2000);
		myAnalogWrite(REAR_LED_PIN,50,2000);
		myAnalogWrite(REAR_LED_PIN,25,2000);
		}
	a=1;
	if(a==1){
		myAnalogWrite(REAR_LED_PIN,0,2000);
	}
}
