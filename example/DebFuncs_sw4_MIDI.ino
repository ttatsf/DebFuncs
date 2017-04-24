// MIDI transport controller for DAW software (such as Ableton LIVE)
//
//The circuit:
// * switch(momentary) 1,2,3,4 connected to digital in ,4,6,8,10  and ground pin 5,7,9,11.
// * digital pin 1 connected to MIDI jack pin 5
// * MIDI jack pin 2 connected to ground
// * MIDI jack pin 4 connected to +5V through 220-ohm resistor
// Attach a MIDI cable to the jack.
//
// USAGE:
// 1. Download ZIP from https://github.com/ttatsf/DebFuncs/archive/master.zip
// 2. Follow this: https://www.arduino.cc/en/Guide/Libraries
// 3. Open, compile, and upload this sketch into your Arduino.
// 4. Connect cables.
// 5. Assign each MIDI CC to your DAW's transport function.

#include <DebFuncs.h>

const int ND = 4;
const int LED_PIN = 13;
const int IN_PIN[ ND ] = {4, 6, 8, 10};
const int GND_PIN[ ND ] = {5, 7, 9, 11};
const int MSG = 176;    //CC (channel:0)
const int VAL1[ ND ] = {70, 71, 72, 73};  // CC number

DF::Debounce debounce[ ND ];
DF::IsDROPPED isDropped[ ND ];
DF::IsRAISED isRaised[ ND ];

void setup() {
  pinMode(LED_PIN, OUTPUT);
  for (int i = 0; i < ND; i++) {
    pinMode(IN_PIN[i], INPUT_PULLUP);
    pinMode(GND_PIN[i], OUTPUT);
    digitalWrite(GND_PIN[i], LOW);
  }
  Serial.begin(31250);  //Originally for Duemilanove.Also available for Uno.
                        //Use "Serial1.begin(31250)" for Leonardo 
                        //or other 32U4 boards.
}

void loop() {
  for (int i = 0; i < ND; i++) {
    const int DEBOUNCED_DATA = debounce[ i ](digitalRead( IN_PIN[i] ) );
    if ( isDropped[i](DEBOUNCED_DATA) ) {
      MIDI_TX(MSG, VAL1[i], 127);
      digitalWrite(LED_PIN,HIGH);
    }
    if ( isRaised[i](DEBOUNCED_DATA) ) {
      MIDI_TX(MSG, VAL1[i], 0);
      digitalWrite(LED_PIN,LOW);
    }
  }
  delay(1);
}

void MIDI_TX(const int MESSAGE, const int VAL1, const int VAL2) 
{
  Serial.write(MESSAGE);
  Serial.write(VAL1);
  Serial.write(VAL2);
}

