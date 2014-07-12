#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

char movimentoDesignado;

RF24 radio(9,10);

const uint64_t pipe = 0xE8E8F0F0E1LL;
int x = 0;
int botao = 4;
int flag = 0;


void setup(void)
{ 
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(botao, INPUT);
}

void loop(void)
{
  flag = digitalRead(botao); //Flag recebe o valor do botao

  if(flag == 1){
    x = 1;
  }else{
    x = 0;
  }
  
  char entrada[20];
  sprintf(entrada,"y:%d;x:%d",x);
  
  radio.write(&entrada, sizeof(unsigned char[20]));  
   
 }
