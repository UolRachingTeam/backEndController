#include <Arduino_FreeRTOS.h>
#include "motorController.h"
#include "comm.h"

/** 
 *  We are going to use timer 0 to control the motor
 *  Timer 0 contorl pin 5 and 6 
 *  the duty cycle is cotroled by setting oput compare registers OC0A and OC0B 
 */
int DutyCycle = 0;
int motorPwmPin = 5;
void controlMotor(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  pinMode(motorPwmPin, OUTPUT);
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

  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B =  _BV(CS01) ;
  for (;;) // A Task shall never return or exit.
  {
    OCR0B = teValue;
  }
}

