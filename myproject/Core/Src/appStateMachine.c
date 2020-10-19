//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//                FILE: appLED.c
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Processor: STM32
// TOOLS: IAR Workbench 
// DATE:
// CONTENTS: This file contains  
//------------------------------------------------------------------------------
// HISTORY: This file  

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "dbrakedefs.h"
#include "appLED.H"
#include "appStateMachine.h"
#include "appMotor.h"
//---------------------GLOBAL DEFINITIONS--------------------------------


//---------------------LOCAL VARIABLES------------------------------------
uint8_t appState =  APPSTATE_IDLE;
 

//---------------------LOCAL FUNCTION PROTOTYPES--------------------------  
 

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ---------------------------GLOBAL FUNCTIONS ----------------------------------
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:  AppStateInit
//------------------------------------------------------------------------------
//  
//==============================================================================
void AppStateInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	appState =  APPSTATE_IDLE;

	GPIO_InitStruct.Pin = PIN_C2_LRVSTOPLTAD|PIN_C3_RRVSTOPLTAD;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}


uint8_t AppStateGet(void)
{
	return appState;
}

void AppTask(void)
{
	short int inputRead1,inputRead2;
	inputRead1 = HAL_GPIO_ReadPin(GPIOC,PIN_C2_LRVSTOPLTAD);
	inputRead2 = HAL_GPIO_ReadPin(GPIOC,PIN_C3_RRVSTOPLTAD);

	if (inputRead1 != 0)
	{
		appState = APPSTATE_TESTFORWARD;
		if(action != EXTENDING)
		{
			if (motorOn != FALSE)
			{
				MotorOff(1);
			}
			else
			{
				MotorCW();
			}
		}
	}
	else
	{
		if (inputRead2 != 0)
		{
			appState = APPSTATE_TESTREVERSE;
			if(action != RETRACTING)
			{
				if (motorOn != FALSE)
				{
					MotorOff(1);
				}
				else
				{
					MotorCCW();
				}
			}
		}
		else
		{
			appState = APPSTATE_IDLE;
			if (motorOn != FALSE)
			{
				MotorOff(1);
			}
		}
	}



}
