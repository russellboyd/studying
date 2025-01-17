/*******************************************************
This program was created by the CodeWizardAVR V3.32 
Automatic Program Generator
� Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 9/4/2018
Author  : 
Company : 
Comments: 


Chip type               : ATxmega128B1
Program type            : Application
AVR Core Clock frequency: 2.000000 MHz
Memory model            : Small
Data Stack size         : 2048
*******************************************************/

// I/O Registers definitions
#include <xmega128b1.h>

// Clock System initialization function
#include "clock_init.h"

// Event System initialization function
#include "event_system_init.h"

// I/O Ports initialization function
#include "ports_init.h"

// Timers/Counters initialization functions
#include "timers_init.h"

// USARTs initialization functions
#include "usarts_init.h"

// Declare your global variables here

void main(void)
{
// Declare your local variables here
unsigned char n;

// Interrupt system initialization
// Optimize for speed
#pragma optsize- 
// Make sure the interrupts are disabled
#asm("cli")
// Low level interrupt: Off
// Round-robin scheduling for low level interrupt: Off
// Medium level interrupt: Off
// High level interrupt: On
// The interrupt vectors will be placed at the start of the Application FLASH section
n=(PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
	PMIC_HILVLEN_bm;
CCP=CCP_IOREG_gc;
PMIC.CTRL=n;
// Set the default priority for round-robin scheduling
PMIC.INTPRI=0x00;
// Restore optimization for size if needed
#pragma optsize_default

// System clocks initialization
system_clocks_init();

// Event system initialization
event_system_init();

// Ports initialization
ports_init();

// Virtual Ports initialization
vports_init();

// Timer/Counter TCC0 initialization
tcc0_init();

// Timer/Counter TCC1 initialization
tcc1_init();

// USARTC0 initialization
usartc0_init();

// Globally enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
		if(wheelRotationCaptured())
		{
		
			uint32_t newRotationCount;
			uint32_t rotationDuration;
			newRotationCount = getWheelRotationCount();
			rotationDuration = new RotationCount - lastRotationCount;
			lastRotationCount = new RotationCount;
			turnOffLedTime = 250 + getTime();
			putchar_usartc0('U');
			putchar_usartc0((uint8_t)(0xFF & (rotationDuration >> 8)));
			putchar_usartc0((uint8_t)(0xFF & (rotationDuration)));
			putchar_usartc0(0);
			adca_conv_start();
		}
      }
}
