

//Autor: Justin Rhyner
//Dateiname: Blinklicht
//Datum: 06.08.2018


#include <avr/io.h>
#include <stdlib.h>

#define TASTER_C5 !(PINC&(1<<PC5))

	


uint8_t taster(void)
{
static uint8_t pegel=0;
static uint8_t pegelalt=0;
uint8_t rueckgabe=0;

	if(TASTER_C5) //taster gedrückt
	{
		pegel=1;
			
		if(pegelalt==0)
		{
				rueckgabe=1;
		}
	}
	else
	{
		pegel=0;
		rueckgabe=0;
	}
		
		
		
	pegelalt=pegel;
	return rueckgabe;
}

int main(void)
{
	DDRB=0b11111111; //Ganzer Port B als Ausgang definieren
	PORTB=0x00; 
	
	DDRC=0x00;
	PORTC=0x00;
	
	uint8_t zaehler=0;
	
	while(1)
	{ 
	
	if(taster())
	{
	zaehler++;
	}
	
		PORTB=zaehler;		
	
	} //end while
}//end of main
