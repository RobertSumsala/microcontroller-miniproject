/********************************************** ZADANIE.10 & 11 **********************************************/
//meno: Robert Sumsala
//ID: 111 464
//***********************************************************
// Mikropoc�ta�e a ich programovanie
// Cvicenie c. 11 a 12
// Riadenie inteligentneho alfanumerickeho displeja DEM16217 - dvojriadkovy
// MSP-EXP430G2 _LaunchPad_Extended_Board_2
//***********************************************************

#include <msp430.h>
#include "evb2.h"

const unsigned char text1[] = "Mikropo""\x01""\x02""ta""\x01""e a ich";
                                        // x01 je nami vytvorene č
                                                // x02 je nami vytvorene í

const unsigned char text2[] = "   programovanie   ";


void main(void)
{
	char i = 0;
	
	evb2_io_init();
	
	lcd_init();
	lcd_clear();
	lcd_puts(&text1[0]);
	lcd_goto(0x40);
	lcd_puts(&text2[0]);
	LCD_RS_L;				
	lcd_write(0x0C);
	// mnou doplnene (č)
	lcd_goto(0x42);
	lcd_gotoCG(0b001000); // prvy riadok
	LCD_RS_H; // info ze "budu data"
	// bitmi vytvoreny znak, displej ma rozmery 8x5 (preto dany pocet bitov), vyzualizaciu sme robili v painte
	lcd_write(0b10010);
	lcd_write(0b01100);
	lcd_write(0b00000);
	lcd_write(0b01100);
	lcd_write(0b10000);
	lcd_write(0b10000);
    lcd_write(0b01100);
    lcd_write(0b00000);

    // mnou vytvorene í
    lcd_gotoCG(0b010000); // zmena riadok (druhy riadok)
    LCD_RS_H; // info ze "budu data"
    // bitmi vytvoreny znak, displej ma rozmery 8x5 (preto dany pocet bitov), vyzualizaciu sme robili v painte
    lcd_write(0b00100);
    lcd_write(0b01000);
    lcd_write(0b00000);
    lcd_write(0b01100);
    lcd_write(0b00100);
    lcd_write(0b00100);
    lcd_write(0b01110);
    lcd_write(0b00000);

	while(1)
	{
		for(i=0;i<16;i++)
		{
			__delay_cycles(250000);
			lcd_write(0x1C);
		}
		for(i=0;i<35;i++)
		{
			__delay_cycles(250000);
			lcd_write(0x18);
		}
		for(i=0;i<19;i++)
		{
			__delay_cycles(250000);
			lcd_write(0x1C);
		}
	}
}

/********************************************** ZAVER **********************************************/
/* Dnes sme pracovali s displejom, pricom sme si museli vytvorit/navrhnut/naprgoramovat vlastne znaky
   s diaktritikou. Najskor sme si vytvorili dizajn v painte, aby sme si to vedeli lepsie predstavit.
   potom sme ich nakodovali pomocou aktivovania spavnych bitov. */
