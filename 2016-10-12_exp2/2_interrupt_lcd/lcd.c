/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 2016/10/12
Author  : NeVaDa
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#include <alcd.h>

// Declare your global variables here
unsigned int i=0;
bit refresh_flag=1;

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
      delay_ms(20);
      if (!PIND.2) {
            if (i!=9) i++;
            refresh_flag=1;
      }
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
      delay_ms(20);
      if (!PIND.3) {
            if (i!=0) i--;
            refresh_flag=1;
      }
}

void main(void)
{
      // Declare your local variables here

      // Input/Output Ports initialization
      // Port A initialization
      // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
      // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
      PORTA=0x00;
      DDRA=0x00;

      // Port B initialization
      // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
      // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
      PORTB=0x00;
      DDRB=0x00;

      // Port C initialization
      // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
      // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
      PORTC=0x00;
      DDRC=0x00;

      // Port D initialization
      // Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
      // State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
      PORTD=0x00;
      DDRD=0x00;

      // Timer/Counter 0 initialization
      // Clock source: System Clock
      // Clock value: Timer 0 Stopped
      // Mode: Normal top=0xFF
      // OC0 output: Disconnected
      TCCR0=0x00;
      TCNT0=0x00;
      OCR0=0x00;

      // Timer/Counter 1 initialization
      // Clock source: System Clock
      // Clock value: Timer1 Stopped
      // Mode: Normal top=0xFFFF
      // OC1A output: Discon.
      // OC1B output: Discon.
      // Noise Canceler: Off
      // Input Capture on Falling Edge
      // Timer1 Overflow Interrupt: Off
      // Input Capture Interrupt: Off
      // Compare A Match Interrupt: Off
      // Compare B Match Interrupt: Off
      TCCR1A=0x00;
      TCCR1B=0x00;
      TCNT1H=0x00;
      TCNT1L=0x00;
      ICR1H=0x00;
      ICR1L=0x00;
      OCR1AH=0x00;
      OCR1AL=0x00;
      OCR1BH=0x00;
      OCR1BL=0x00;

      // Timer/Counter 2 initialization
      // Clock source: System Clock
      // Clock value: Timer2 Stopped
      // Mode: Normal top=0xFF
      // OC2 output: Disconnected
      ASSR=0x00;
      TCCR2=0x00;
      TCNT2=0x00;
      OCR2=0x00;

      // External Interrupt(s) initialization
      // INT0: On
      // INT0 Mode: Falling Edge
      // INT1: On
      // INT1 Mode: Falling Edge
	// INT2: Off
	GICR|=0xC0;
	MCUCR=0x0A;
	MCUCSR=0x00;
	GIFR=0xC0;

	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=0x00;

	// USART initialization
	// USART disabled
	UCSRB=0x00;

	// Analog Comparator initialization
	// Analog Comparator: Off
	// Analog Comparator Input Capture by Timer/Counter 1: Off
	ACSR=0x80;
	SFIOR=0x00;

	// ADC initialization
	// ADC disabled
	ADCSRA=0x00;

	// SPI initialization
	// SPI disabled
	SPCR=0x00;

	// TWI initialization
	// TWI disabled
	TWCR=0x00;

	// Alphanumeric LCD initialization
	// Connections specified in the
	// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
	// RS - PORTB Bit 0
	// RD - PORTB Bit 1
	// EN - PORTB Bit 2
	// D4 - PORTD Bit 4
	// D5 - PORTD Bit 5
	// D6 - PORTD Bit 6
	// D7 - PORTD Bit 7
	// Characters/line: 16
	lcd_init(16);

	// Global enable interrupts
	#asm("sei")

	while (1) {
            if (refresh_flag) {
                  lcd_gotoxy(0,0);
                  lcd_putchar('0'+i);
                  refresh_flag=0;
	      }
      }
}
