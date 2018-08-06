
/*
Author: Justin Rhyner
Dateiname: Blinklicht
Datum: 06.08.2018
*/

#include <avr/io.h>
#include <stdlib.h>


int main()
{
   DDRB=0xFF;  //Eingänge und Ausgänge deklarieren
   PORTB=0x00; //LEDs Ein und Ausschalten
   
   DDRC=0b11011111;
   PORTC=0x00;
   
   
   PORTB|=((1<<PB0)|(1<<PB1)); //setzen mehrerer Bits
   
   PORTB&=~(1<<PB7); //löschen eines Bits
   
   PORTB^=(1<<PB2); //Toggeln, das Bit invertieren
   
   
   while(1)
   {
   if (!(PINC&(1<<PC5)))//testen ob der Taster  LOW ist
	{
	PORTB|=(1<<PB7);    // Wenn der Schalter LOW ist, PB7 HIGH
	
	}
  
   }
   
}
