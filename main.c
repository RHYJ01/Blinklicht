

//Autor: Justin Rhyner
//Dateiname: Blinklicht
//Datum: 06.08.2018


#include <avr/io.h>
#include <stdlib.h>

#define TASTER_C5 !(PINC&(1<<PC5))
#define TASTER_C4 !(PINC&(1<<PC4))

	
uint8_t taster(uint8_t tast_nr) // Flankenerkennung
{
	static uint8_t pegel4=0;
	static uint8_t pegelalt4=0;
	static uint8_t pegel5=0;
	static uint8_t pegelalt5=0;
	uint8_t rueckgabe=0;
	
	switch(tast_nr)
	{
		case 5: 	if(TASTER_C5) //taster gedrückt
					{
						pegel5=1;
			
						if(pegelalt5==0)
						{
							rueckgabe=1;
						}
					}
					else
					{
						pegel5=0;
						rueckgabe=0;
					}
						
						
						
					pegelalt5=pegel5;
					break;
	
		case 4:		if(TASTER_C4) //taster gedrückt
					{
						pegel4=1;
			
						if(pegelalt4==0)
						{
							rueckgabe=1;
						}
					}
					else
					{
						pegel4=0;
						rueckgabe=0;
					}
						
						
						
					pegelalt4=pegel4;
					break;
	}
	return rueckgabe;
}


/*uint8_t taster() // Flankenerkennung
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
}*/

int main(void)
{
	DDRB=0b11111111; //Ganzer Port B als Ausgang definieren
	PORTB=0x00; 
	
	DDRC=0x00;
	PORTC=0x00;
	
	uint8_t zaehler=0;
	
	while(1)
	{ 
	
	if(taster(5))
	{
		zaehler++;
	}
	
	if(taster(4))
	{
		zaehler--;
	}
	
		PORTB=zaehler;		
	
	} //end while
}//end of main
