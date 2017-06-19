#include <Arduino_FreeRTOS.h>
#include "taskTwo.h"
#include "motorController.h"


void blink(void *pvParameters)  // This is a task.
{
 
  (void) pvParameters;
  int pin = 8;

  // initialize digital pin 12 as an output.
  pinMode(pin, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
     DutyCycle++;
     if (DutyCycle >= 200 ) {
      DutyCycle = 0;
     }
    vTaskDelay( 50 / portTICK_PERIOD_MS ); // wait for one second
  }
}
