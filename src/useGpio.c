/* example.c:
 *
 *   Template code for implementing a simple task, using the ADD_TASK()
 *   macro.  Also contains template code for a simple monitor command.
 *
 */

#include <stdio.h>
#include <stdint.h>

#include "common.h"
#include "main.h"

 
 
void useGpioInit(void *data)
{



  /* Place Initialization things here.  This function gets called once
   * at startup.
   */
  __HAL_RCC_GPIOB_CLK_ENABLE(); 
  
  HAL_GPIO_WritePin(GPIOA, 	GPIO_PIN_0|
	  			GPIO_PIN_1|
	  			GPIO_PIN_4|
	  			GPIO_PIN_5|
	  			GPIO_PIN_6|
	  			GPIO_PIN_7|
	  			GPIO_PIN_8|
	  			GPIO_PIN_9|
	  			GPIO_PIN_10|
	  			GPIO_PIN_11|
	  			GPIO_PIN_12|
	  			GPIO_PIN_15 , GPIO_PIN_RESET); // initialise except GPIOa 2,3,13,14 
  			
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); 
   
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_0|
  			GPIO_PIN_1|
  			GPIO_PIN_4|
  			GPIO_PIN_5|
  			GPIO_PIN_6|
  			GPIO_PIN_7|
  			GPIO_PIN_8|
  			GPIO_PIN_9|
  			GPIO_PIN_10|
  			GPIO_PIN_11|
  			GPIO_PIN_12|
  			GPIO_PIN_15 ;
  			
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = 0;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void useGpio(void *data)
{

  /* Place your task functionality in this function.  This function
   * will be called repeatedly, as if you placed it inside the main
   * while(1){} loop.
   */
/*
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_SET);
   HAL_Delay(1000);
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_RESET);
   HAL_Delay(1000);
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_SET);
   HAL_Delay(1000);
   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_RESET);
   HAL_Delay(1000);

*/
}

ADD_TASK(useGpio,  /* This is the name of the function for the task */
	 useGpioInit,  /* This is the initialization function */
	 NULL,         /* This pointer is passed as 'data' to the functions */
	 0,            /* This is the number of milliseconds between calls */
	 "This is the help text for the task")


  ParserReturnVal_t CmdGpioPin(int mode)
{
  uint32_t gpio,rc1;
  uint32_t pinState,rc2;
  
  if(mode != CMD_INTERACTIVE) return CmdReturnOk;
  
  rc1 = fetch_uint32_arg(&gpio);
  rc2 = fetch_uint32_arg(&pinState);
  if(rc1 || rc2) {
    printf("please enter pin no and state: pin <GPIOA no, 0~15> <State, 0|1>\n");
    return CmdReturnBadParameter1;
  }
  


switch(gpio)
{
	case 1:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,pinState);
	break;
	
	case 4:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,pinState);
	break;
	
	case 5:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,pinState);
	break;
	
	case 6:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,pinState);
	break;
	
	case 7:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,pinState);
	break;
	
	case 8:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,pinState);
	break;
	
	case 9:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,pinState);
	break;
	
	case 10:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,pinState);
	break;
	
	case 11:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,pinState);
	break;
	
	case 12:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,pinState);
	break;
	
	case 15:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,pinState);
	break;
	
	default:
		printf("Please enter valid GPIO pin\n");
}
  return CmdReturnOk;
}

ADD_CMD("pin",CmdGpioPin,"pin <GPIOA no, 0~15> <State, 0|1>")




