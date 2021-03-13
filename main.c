/*
 * speed_Control_DC_Motor.c
 *
 * Created: 3/7/2021 2:33:46 PM
 * Author : lenovo
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int count = 256;

int main(void)
{
	
    DDRB |= (1<<PB1);
    PORTB |= 0b00000000;
	
	TCCR0B |= (1<<CS00) | (1<<CS01);
	TCNT0 = 0x00;			// define clock source and prescaler 
	TIMSK0 |= (1<<TOIE0);		//enable local interrupt
	sei();
	
    while (1) 
    {
		while (TCNT0<count)
		{
			PORTB=0b00000000;
		}
		while (TCNT0>=count)
		{
			PORTB|=(1<<PB1);
		}
	}
}
ISR(TIMER0_OVF_vect)
{
	
		count = count - 64;		
		if (count<0)
		{
			count=0;
		}
}


