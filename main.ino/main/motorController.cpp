#include <Arduino_FreeRTOS.h>
#include "motorController.h"


/**
 * Arduino offers six PWM outputs, and they are connected to three timers in the circuit in pairs:
 * Timer0: pins 5 and 6
 * Timer1: pins 9 and 10
 * Timer2: pins 11 and 3
 * 
 * 
 * Selecting the frequency can be done by writing the Clock Select (CSn[2:0]) bits values 
 * to the Timer/Counter Control Register TCCRnx where:
 *  x is the nubmer of the timere 0,1 or 2 
 *  n can be A or B
 *  if now value is written to CSn[2:0] bits the default value is CSn=0x0 and the timer is stopped. 
 */
int DutyCycle = 0;
void controlMotor(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);

//  // Both outputs in toggle mode  
//  TCCR1A = _BV( COM1A0 ) |_BV( COM1B0 );
//  TCCR1B = _BV( WGM13) | _BV( WGM12);
//  
//
//  // prescaler of 1 will get us 8MHz - 488Hz
//  // User a higher prescaler for lower freqncies
//
//#define PRESCALER 1
//#define PRESCALER_BITS 0x01
//
//#define CLK 16000000UL    // Default clock speed is 16MHz on Arduino Uno
//
//unsigned long freq = 800;
//int shift = 45;
//
//  unsigned long clocks_per_toggle = (CLK / freq) / 2;    // /2 becuase it takes 2 toggles to make a full wave
//
//  ICR1 = clocks_per_toggle; // we used the Input Capture Register Low byte to define the TOP value which in turn define the frequency
//
//  unsigned long offset_clocks = (clocks_per_toggle * shift) / 180UL; // Do mult first to save precision
//  OCR1A = 149;    // First output is the base, it always toggles at 0
//  OCR1B= 150;
//
//  // Turn on timer now if is was not already on
//  // Clock source = clkio/1 (no prescaling)
//  // Note: you could use a prescaller here for lower freqnencies by setting bits
//  /**
//   _____________________________________________________
//   |CS12 |  CS11 |   CS10 | timer max frequency        |
//   |_____|_______|________|____________________________|
//   |0    | 0     |1       |clkI/O/1 (No prescaling)    |
//   |0    | 1     |0       |clkI/O/8 (From prescaler)   |
//   |0    | 1     |1       |clkI/O/64 (From prescaler)  |
//   |1    | 0     |0       |clkI/O/256 (From prescaler) |
//   |1    | 0     |1       |clkI/O/1024 (From prescaler)|
//   |_____|_______|________|____________________________|
//   */
//  TCCR1B |= _BV( CS10); //| _BV( CS12);
TCNT1=0x7FFF;
  for (;;) // A Task shall never return or exit.
  {
    analogWrite(9, DutyCycle);
    analogWrite(11,DutyCycle);
//  OCR1B = 12;
//TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
//  TCCR2B =  _BV(CS22) ;
// OCR1B = 10;
// OCR2B = 128;
  }
}

