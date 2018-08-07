

//Autor: Justin Rhyner
//Dateiname: Blinklicht
//Datum: 06.08.2018


#include <avr/io.h>
#include <stdlib.h>

#define TASTER_C5 !(PINC&(1<<PC5)) //TASTER_C5 als makro festlegen
#define TASTER_C4 !(PINC&(1<<PC4)) //TASTER_C4 als makro festlegen

uint8_t dezimal(uint8_t wert) // funktion mit dem nahmen dezimal und einer 8 bit Variablel namens wert
{
	switch(wert)
	{
		case 1: wert=wert;
				break;
		
		case 2: wert+=1;
				break;
		
		case 3: wert+=4;
				break;
		
		case 4: wert+=11;
				break;
		
		case 5: wert+=26;
				break;
		
		case 6: wert+=57;
				break;
		
		case 7: wert+=120;
				break;
		
		case 8: wert+=247;
				break;
	}
	
	return wert; //wert wird zur�ckgegeben
}
	
uint8_t taster(uint8_t tast_nr) // Flankenerkennung
{
	static uint8_t pegel4=0;		//VAriabeln initialisieren
	static uint8_t pegelalt4=0;
	static uint8_t pegel5=0;
	static uint8_t pegelalt5=0;
	uint8_t rueckgabe=0;
	
	switch(tast_nr)
	{
		case 5: 	if(TASTER_C5) //taster gedr�ckt
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
	
		case 4:		if(TASTER_C4) //taster gedr�ckt
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
						
						
						
					pegelalt4=pegel4; // Beide Pegel gleichsetzen
					break;
	}
	return rueckgabe; //rueckgabe wird zur�ckgegeben
}




int main(void)
{
	DDRB=0b11111111; //Ganzer Port B als Ausgang deklarieren
	PORTB=0x00; 
	
	DDRC=0x00;		 //Ganzer Port C als Eingang deklarieren
	PORTC=0x00;
	
	uint8_t zaehler=0; //Deklarieren und Initialisieren der Variabel zaehler
	
	while(1) // Endlosschlaufe
	{ 
	
	if(taster(5)) // Funktion taster(5) wird ausgef�hrt
	{
		zaehler++; // eins nach oben z�hlen
	}
	
	if(taster(4)) //Funktion taster(4) wird ausgef�hrt
	{
		zaehler--; //eins nach unten z�hlen
	}
	
	if(zaehler>8) // h�chste m�gliche Zahl ist 8
	{
		zaehler=0; 
	}
	
	

	
		PORTB=dezimal(zaehler);	 //Wert des zaehlers wird an die Funktion Dezimal �bergeben und auf Port B ausgegeben
		
	
	
	} //end while
}//end of main
