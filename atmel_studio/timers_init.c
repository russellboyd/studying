/*******************************************************
Timers/Counters initialization created by the
CodeWizardAVR V3.32 Automatic Program Generator
� Copyright 1998-2017 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
*******************************************************/

// I/O Registers definitions
#include <xmega128b1.h>

// Disable a Timer/Counter type TC0
void tc0_disable(TC0_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

// Disable a Timer/Counter type TC1
void tc1_disable(TC1_t *ptc)
{
// Timer/Counter off
ptc->CTRLA=TC_CLKSEL_OFF_gc;
// Issue a reset command
ptc->CTRLFSET=TC_CMD_RESET_gc;
}

// Timer/Counter TCC0 initialization
void tcc0_init(void)
{
unsigned char s;
unsigned char n;

// Note: The correct PORTC direction for the Compare Channels
// outputs is configured in the ports_init function.

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc0_disable(&TCC0);
// Clock source: ClkPer/1
TCC0.CTRLA=TC_CLKSEL_DIV1_gc;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: Off
// Compare/Capture on channel B: Off
// Compare/Capture on channel C: Off
// Compare/Capture on channel D: Off
TCC0.CTRLB=(0<<TC0_CCDEN_bp) | (0<<TC0_CCCEN_bp) | (0<<TC0_CCBEN_bp) | (0<<TC0_CCAEN_bp) |
	TC_WGMODE_NORMAL_gc;
// Capture event source: None
TCC0.CTRLD=TC_EVACT_OFF_gc | TC_EVSEL_OFF_gc;

// Set Timer/Counter in Normal mode
TCC0.CTRLE=TC_BYTEM_NORMAL_gc;

// Overflow interrupt: High Level
// Error interrupt: Disabled
TCC0.INTCTRLA=TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_HI_gc;

// Compare/Capture channel A interrupt: Disabled
// Compare/Capture channel B interrupt: Disabled
// Compare/Capture channel C interrupt: Disabled
// Compare/Capture channel D interrupt: Disabled
TCC0.INTCTRLB=TC_CCDINTLVL_OFF_gc | TC_CCCINTLVL_OFF_gc | TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_OFF_gc;

// High resolution extension: Off
HIRESC.CTRLA&= ~HIRES_HREN0_bm;

// Advanced Waveform Extension initialization
// Optimize for speed
#pragma optsize- 
// Disable locking the AWEX configuration registers just to be sure
n=MCU.AWEXLOCK & (~MCU_AWEXCLOCK_bm);
CCP=CCP_IOREG_gc;
MCU.AWEXLOCK=n;
// Restore optimization for size if needed
#pragma optsize_default

// Pattern generation: Off
// Dead time insertion: Off
AWEXC.CTRL=(0<<AWEX_PGM_bp) | (0<<AWEX_CWCM_bp) | (0<<AWEX_DTICCDEN_bp) | (0<<AWEX_DTICCCEN_bp) | 
	(0<<AWEX_DTICCBEN_bp) | (0<<AWEX_DTICCAEN_bp);

// Fault protection initialization
// Fault detection on OCD Break detection: On
// Fault detection restart mode: Latched Mode
// Fault detection action: None (Fault protection disabled)
AWEXC.FDCTRL=(AWEXC.FDCTRL & (~(AWEX_FDDBD_bm | AWEX_FDMODE_bm | AWEX_FDACT_gm))) |
	(0<<AWEX_FDDBD_bp) | (0<<AWEX_FDMODE_bp) | AWEX_FDACT_NONE_gc;
// Fault detect events: 
// Event channel 0: Off
// Event channel 1: Off
// Event channel 2: Off
// Event channel 3: Off
// Event channel 4: Off
// Event channel 5: Off
// Event channel 6: Off
// Event channel 7: Off
AWEXC.FDEMASK=0b00000000;
// Make sure the fault detect flag is cleared
AWEXC.STATUS|=AWEXC.STATUS & AWEX_FDF_bm;

// Clear the interrupt flags
TCC0.INTFLAGS=TCC0.INTFLAGS;
// Set Counter register
TCC0.CNT=0x0000;
// Set Period register
TCC0.PER=0x07CF;
// Set channel A Compare/Capture register
TCC0.CCA=0x0000;
// Set channel B Compare/Capture register
TCC0.CCB=0x0000;
// Set channel C Compare/Capture register
TCC0.CCC=0x0000;
// Set channel D Compare/Capture register
TCC0.CCD=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}

// Timer/Counter TCC0 Overflow/Underflow interrupt service routine
interrupt [TCC0_OVF_vect] void tcc0_overflow_isr(void)
{
// Write your code here

}

// Timer/Counter TCC1 initialization
void tcc1_init(void)
{
unsigned char s;

// Note: The correct PORTC direction for the Compare Channels
// outputs is configured in the ports_init function.

// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Disable and reset the timer/counter just to be sure
tc1_disable(&TCC1);
// Clock source: ClkPer/256
TCC1.CTRLA=TC_CLKSEL_DIV256_gc;
// Mode: Normal Operation, Overflow Int./Event on TOP
// Compare/Capture on channel A: On
// Compare/Capture on channel B: Off
TCC1.CTRLB=(0<<TC1_CCBEN_bp) | (1<<TC1_CCAEN_bp) |
	TC_WGMODE_NORMAL_gc;
// Capture event source: Event Channel 0
TCC1.CTRLD=TC_EVACT_CAPT_gc | TC_EVSEL_CH0_gc;

// Set Timer/Counter in Normal mode
TCC1.CTRLE=TC_BYTEM_NORMAL_gc;

// Overflow interrupt: Disabled
// Error interrupt: Disabled
TCC1.INTCTRLA=TC_ERRINTLVL_OFF_gc | TC_OVFINTLVL_OFF_gc;

// Compare/Capture channel A interrupt: High Level
// Compare/Capture channel B interrupt: Disabled
TCC1.INTCTRLB=TC_CCBINTLVL_OFF_gc | TC_CCAINTLVL_HI_gc;

// High resolution extension: Off
HIRESC.CTRLA&= ~HIRES_HREN1_bm;

// Clear the interrupt flags
TCC1.INTFLAGS=TCC1.INTFLAGS;
// Set Counter register
TCC1.CNT=0x0000;
// Set Period register
TCC1.PER=0xFFFF;
// Set channel A Compare/Capture register
TCC1.CCA=0x0000;
// Set channel B Compare/Capture register
TCC1.CCB=0x0000;

// Restore interrupts enabled/disabled state
SREG=s;
}

// Timer/Counter TCC1 Compare/Capture A interrupt service routine
interrupt [TCC1_CCA_vect] void tcc1_compare_capture_a_isr(void)
{
// Ensure that the Compare/Capture A interrupt flag is cleared
if (TCC1.INTFLAGS & TC1_CCAIF_bm) TCC1.INTFLAGS|=TC1_CCAIF_bm;
// Write your code here

}

