#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int joystick[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
const int rele = 7; 

void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  pinMode(rele, OUTPUT);
}

void loop(void)
{
  if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      done = radio.read( joystick, sizeof(joystick));
      digitalWrite(rele, HIGH);      
    }
  }
  else
  {
    digitalWrite(rele, LOW);
    Serial.println("Rádio não disponível");
  }
  delay(100);
}
