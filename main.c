

//Autor: Justin Rhyner
//Dateiname: Blinklicht
//Datum: 06.08.2018


#include <avr/io.h>
#include <stdlib.h>


int main(void)
{
	DDRB=0b11111111; //Ganzer Port B als Ausgang definieren
	PORTB=0x00; 
	
	DDRC=0x00;
	PORTC=0x00;
	

	uint8_t test=0;
	uint8_t pegel=0;
	uint8_t pegelalt=0;
	
	while(1)
	{ 
		
		if(!(PINC&(1<<PC5))) //taster gedrückt
		{
			pegel=1;
			
			if(pegelalt==0)
			{
				test++;
			}
		}
		
		else
		{
			pegel=0;
		}
		
		
		PORTB=test;
		pegelalt=pegel;
		
	
	} //end while
}//end of main
