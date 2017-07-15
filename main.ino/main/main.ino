/**
 * This is the main module in the back controller program
 * The main program is running on Arduino Mega 2560
 */
#include <Arduino_FreeRTOS.h>
#include "motorController.h"
#include "comm.h"

// the setup function runs once when you press reset or power the board
void setup() {
    initCan();
  xTaskCreate(
    controlMotor
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
     testCan
    ,  (const portCHAR *)"TestCan"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );


  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
 
}
