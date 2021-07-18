#include <MsTimer2.h>    
int pinInterrupt = 2; 
int i=0;

void onTimer()
{
  if(i==10)
    i=0;
  digitalWrite(4,i&0x1);
      digitalWrite(5,(i>>1)&0x1);
      digitalWrite(6,(i>>2)&0x1);
      digitalWrite(7,(i>>3)&0x1);
   i++;
}
void myfunc()
{
	i=0;
}

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode( pinInterrupt, INPUT);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
  MsTimer2::set(1000, onTimer); 
  MsTimer2::start(); 
 
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
}

void loop()
{
	
}
