#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int joystick[2];

const int buzzer = 8;

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  pinMode(buzzer,OUTPUT);
}

void loop(void)
{
  if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      done = radio.read( joystick, sizeof(joystick) );
      Serial.println(joystick[0]);
      Serial.println(joystick[1]);
      tone(buzzer,1500);
    }
  }
  else
  {
    tone(buzzer,0);
    Serial.println("Rádio não disponível");
  }
  delay(1000);
}

