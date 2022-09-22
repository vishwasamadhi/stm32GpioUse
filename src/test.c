/* my_main.c: main file for monitor */
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include "common.h"

/* This include will give us the CubeMX generated defines */
#include "main.h"

/* This function is called from the CubeMX generated main.c, after all
 * the HAL peripherals have been initialized. */
 /* This function is called from inside the CubeMX generated main.c,
 * inside the while(1) loop. */

ParserReturnVal_t CmdLab2(int mode)     
{
  uint32_t val,rc;													//declaring val and rc variables
  uint32_t val2,rc2;   												// declaring val2 and rc2 varialbles
  
  if(mode != CMD_INTERACTIVE) return CmdReturnOk;

 rc2 = fetch_uint32_arg(&val2);
  if(rc2) {
    printf("Enter a pin number for led on or off \n");
    return CmdReturnBadParameter1;
  }
  rc = fetch_uint32_arg(&val);
  if(rc) {
    printf("Please supply 1 | 0 to turn on or off the LED \n");
    return CmdReturnBadParameter1;
  }
  
//GPIO inistialising starts  
 __HAL_RCC_GPIOA_CLK_ENABLE();
GPIO_InitTypeDef GPIO_InitStruct;
GPIO_InitStruct.Pin = (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8);		// initialised gpio pins
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed =  GPIO_SPEED_FREQ_HIGH;
GPIO_InitStruct.Alternate = 0;
HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
// GPIO Initialising ends


  val = val ? 1 : 0;
  
  switch (val2)    													// switch cases for gpio pins starts
  {
   case 0:
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, val);									// declaring gpio0
        HAL_Delay(500);
  break;
   case 1:
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, val);								  	// declaring gpio1
  	HAL_Delay(500);
   case 5:
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, val);									// declaring gpio5
  	HAL_Delay(500);
  break;
   case 6:
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, val);									// declaring gpio6
  	HAL_Delay(500);
  break;
   case 7:
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, val);									// declaring gpio7
  	HAL_Delay(500);
  break;
   case 8:
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, val);									// declaring gpio8
  	HAL_Delay(500);
  break;
   default:
  	printf("enter the value less than 16 \n");
  }															// switch cases for gpio ends
  return CmdReturnOk;
}

ADD_CMD("Lab2",CmdLab2,"0|1     control LED")										// LED controls
