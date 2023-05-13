/*
 * seven segment driver.c
 *
 * Created: 17/09/2021 10:53:20 PM
 * Author : kamar salah
 */ 

#include <avr/io.h>
#include "seven segment.h"
#include "DIO drivers.h"
#include "macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	seven_seg_vinti ('A');
	seven_seg_vinti ('B');
	unsigned char counter1,counter2;
    
    while (1) 
    {
		for(counter1=0;counter1<=9;counter1++)
	     {
			 seven_seg_vwrite ('A', counter1);
			 _delay_ms(1000);
		 }
		 
		 for(counter2=0;counter2<=5;counter2++)
		 {
			 DIO_vwrite_port('A',0x06);
			 seven_seg_vwrite ('B', counter2);
			 _delay_ms(1000);
		 }
		 DIO_vwrite_port('B',0x0);
			 
    }
	
	
}

