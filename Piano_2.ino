#include <Wire.h>
#include "Adafruit_MPR121.h"
//MPR121 library is altered to avoid hangup if board is missing
//in Adafruit_MPR121.ccp while() is replaced with if()

// You can have up to 4 on one i2c bus
Adafruit_MPR121 cap = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();
Adafruit_MPR121 cap3 = Adafruit_MPR121();
Adafruit_MPR121 cap4 = Adafruit_MPR121();


// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;

uint16_t lasttouched3 = 0;
uint16_t currtouched3 = 0;

uint16_t lasttouched4 = 0;
uint16_t currtouched4 = 0;

char notes[] = {'1','2','3','4','5','6','7','8','9','0','-','='};
char notes2[] = {'q','w','e','r','t','y','u','i','o','p','[',']'};
char notes3[] = {'a','s','d','f','g','h','j','k','l',';','\'','`'};
char notes4[] = {'z','x','c','v','b','n','m',',','.','/','\t','\r'};

////////////////////////////////////
void setup() {
  Serial.begin(9600);

  // this is inside the loop so you can plug boards hot
// if you do not need hot plugin you may put it in setup()
  cap.begin(0x5A);
  cap2.begin(0x5B);
  cap3.begin(0x5C);
  cap4.begin(0x5D);
}

void loop() {
// Get the currently touched pads
  currtouched = cap.touched();
  currtouched2 = cap2.touched();
  currtouched3 = cap3.touched();
  currtouched4 = cap4.touched();
  
  for (uint8_t i=0; i<12; i++) {

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
       //when sensor is touched do something
       //Serial.println('A');
       //Serial.println(i);
       Serial.write(notes[i]);
    }
    
//2///////////////////////////////////////////////////
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
       //when sensor is touched do something
       //Serial.println('B');
       //Serial.println(i);
       Serial.write(notes2[i]);
    }
  
//3///////////////////////////////////////////////////
    if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
       //when sensor is touched do something
       //Serial.println('C');
       //Serial.println(i);
       Serial.write(notes3[i]);
    }
  
//4///////////////////////////////////////////////////
    if ((currtouched4 & _BV(i)) && !(lasttouched4 & _BV(i)) ) {
      //when sensor is touched do something
       //Serial.println('D');
       //Serial.println(i);
       Serial.write(notes4[i]);
    }
  
  }

  // reset our state
  lasttouched = currtouched;
  lasttouched2 = currtouched2;
  lasttouched3 = currtouched3;
  lasttouched4 = currtouched4;
  return;
}
