/*
 * main.c
 *
 *  Created on: 2024 May 24 10:16:47
 *  Author: kot_g
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)


#define TIME_1_SEC	1000U

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

__IO uint32_t counter = 0;
void Timer_Callback(void){
	if(counter>=UINT32_MAX)
		counter = 0;
	counter++;
}



void Delay_ms(uint32_t time){
	const uint32_t prevTime = counter;
	while(counter<(prevTime+time));
}

int main(void)
{
  DAVE_STATUS_t status;
  uint32_t TimerId;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  TimerId = SYSTIMER_CreateTimer(TIME_1_SEC,SYSTIMER_MODE_PERIODIC,(void*)Timer_Callback,NULL);
  if(TimerId != 0U)
	{
	  //Timer is created successfully
	  // Start/Run Software Timer
	  status = SYSTIMER_StartTimer(TimerId);
	  if(status == SYSTIMER_STATUS_SUCCESS)
	  {
		// Timer is running
	  }
	  else
	  {
		// Error during software timer start operation
	  }
	}


  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_1);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_2);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_3);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_4);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_5);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_6);
	  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_7);
	  Delay_ms(1000);

	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_1);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_2);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_3);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_5);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_6);
	  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_7);
	  Delay_ms(1000);
  }
}
