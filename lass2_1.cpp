// Do not remove the include below
#include "lass2_1.h"


#define FRONT_LED_PIN 10
#define REAR_LED_PIN 9

   int val=0;
   int val1=255;
   int inc=0;

//The setup function is called once at startup of the sketch
void setup() {
	pinMode(FRONT_LED_PIN, OUTPUT);
	pinMode(REAR_LED_PIN, OUTPUT);
}

// The loop function is called in an endless loop
void loop() {


        if(inc==0){

        	analogWrite(FRONT_LED_PIN, val);
        	val++;
        	analogWrite(REAR_LED_PIN, val1);
        	val1--;
        	delay(5000/255);
        }
		if(inc==0&&val==255 && val1==0){
			inc=1;
		}
		if(inc==1){
			analogWrite(FRONT_LED_PIN, val);
			val--;

			analogWrite(REAR_LED_PIN, val1);
			val1++;

			delay(5000/255);
		}
		if(inc==1&&val==0 && val1==255){
			inc=0;
		}




}
