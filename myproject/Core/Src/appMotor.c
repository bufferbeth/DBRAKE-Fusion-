//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//                FILE: appMotor.c
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Processor: STM32F103R
// TOOLS: IAR Workbench 
// DATE:
// CONTENTS: This file contains  
//------------------------------------------------------------------------------
// HISTORY: This file  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "dbrakeDefs.h"
#include "appMotor.h"
#include "driverButtons.h"

 
 
//---------------------GLOBAL VARIABLES-----------------------------------
uint8_t action;
uint8_t motorOn;

//---------------------LOCAL VARIABLES------------------------------------
 
 
//---------------------LOCAL FUNCTION PROTOTYPES--------------------------  

	
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ---------------------------GLOBAL FUNCTIONS ----------------------------------
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:
//------------------------------------------------------------------------------
// This function
//
//==============================================================================
void BrakeInit(void)
{
	motorOn = FALSE;
	action = NONE;

	MotorOff(1);
}

 
 
 
//XXXXXXXXXXXXXXXXXXXXXXXXX MOTOR SETUP STUFF AND RUNNING XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 



//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:
//------------------------------------------------------------------------------
// This function
//
//==============================================================================
void MotorInit(void)
{

}
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:   MotorOff
//------------------------------------------------------------------------------
// This function Initializes registers to allow button interrupts
//==============================================================================
void MotorOff(uint8_t useHoldOff)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
  
	motorOn = FALSE; 
//	motorRunTime = 0;
	
	HAL_GPIO_WritePin(GPIOC, PIN_C4_ENA|PIN_C5_INA,GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = PIN_C4_ENA|PIN_C5_INA;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOB, PIN_B11_ENB|PIN_B0_INB,GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = PIN_B11_ENB|PIN_B0_INB;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOB, PIN_B10_PWM,GPIO_PIN_SET);
	GPIO_InitStruct.Pin = PIN_B10_PWM;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


	GPIO_InitStruct.Pin = PIN_B1_CS;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	action = NONE; 
	if (useHoldOff != 0)
	{
//		BrakeHoldOff(100);
	}
}



//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:   MotorCW
//------------------------------------------------------------------------------
// This function
//==============================================================================
void MotorCCW(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	motorOn = TRUE; 
/*
	motorRunTime = MOTOR_RUN_TIME;	
	maxCurrentRead = 0; 
	maxFSRRead = 0;  //V01_41
	encoderCount = 0;
	buildTableOffset = 0;	
*/
	HAL_GPIO_WritePin(GPIOC, PIN_C5_INA,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, PIN_B0_INB,GPIO_PIN_SET);

	GPIO_InitStruct.Pin = PIN_C4_ENA;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = PIN_B11_ENB;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	action = RETRACTING; 
/*
	prevEncoderCount = encoderCount; //01_38_#3
	actionEncoderSample = 0; //01_38_#3
	prevAction = action; 
*/
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:   MotorCW
//------------------------------------------------------------------------------
// This function  
//==============================================================================
void MotorCW(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};


	motorOn = TRUE; 
/*
	motorRunTime = MOTOR_RUN_TIME;	
	maxCurrentRead = 0;
	maxFSRRead = 0;  //V01_41
	encoderCount = 0;	
	encoderFlip = 0; 
	buildTableOffset = 0;
	encoderTableOffset = 0; 
*/
	HAL_GPIO_WritePin(GPIOC, PIN_C5_INA,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, PIN_B0_INB,GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = PIN_C4_ENA;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = PIN_B11_ENB;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


	action = EXTENDING; 
/*
	homeLimit = HOME_OUT;
	prevEncoderCount = encoderCount; //01_38_#3
	actionEncoderSample = 0; //01_38_#3
	prevAction = action; 
*/
}


