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
//---------------------GLOBAL DEFINITIONS--------------------------------


//Color	        R	G	B
//RED	        1	0	0
//Yellow	1	1	0
//Green	        0	1	0
//Teal	        0	1	1
//Blue	        0	0	1
//Violet	1	0	1
//White	        1	1	1
//BLACK	        0	0	0



//---------------------LOCAL VARIABLES------------------------------------
 
uint8_t ledState = LEDSTATE_IDLE; 

uint16_t opSignalTime = 0;  

 

//---------------------LOCAL FUNCTION PROTOTYPES--------------------------  
 

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ---------------------------GLOBAL FUNCTIONS ----------------------------------
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:  AppLEDSignal
//------------------------------------------------------------------------------
//  
//==============================================================================
void AppLEDSignal(void)
{
          if (opSignalTime > (DELAY_1SEC * 8))
          {
              LED_RED_ON;
              LED_GREEN_OFF;
              LED_BLUE_OFF;
          }
          else if (opSignalTime > (DELAY_1SEC * 7))
          {
            LED_RED_OFF;
            LED_GREEN_ON;
            LED_BLUE_OFF;
          }
          else if (opSignalTime > (DELAY_1SEC * 6))
          {
            LED_RED_ON;
            LED_GREEN_ON;
            LED_BLUE_OFF;
          }
          else if (opSignalTime > (DELAY_1SEC * 5))
          {
            LED_RED_OFF;
            LED_GREEN_OFF;
            LED_BLUE_ON;
          }
          else if (opSignalTime > (DELAY_1SEC * 4))
          {
            LED_RED_ON;
            LED_GREEN_OFF;
            LED_BLUE_ON;
          }
           else if (opSignalTime > (DELAY_1SEC * 3))
          {
            LED_RED_OFF;
            LED_GREEN_ON;
            LED_BLUE_ON;
          }
          else if (opSignalTime > (DELAY_1SEC * 2))
          {
            LED_RED_ON;
            LED_GREEN_ON;
            LED_BLUE_ON;
          }
           else if (opSignalTime > (DELAY_1SEC * 1))
          {
            LED_RED_OFF;
            LED_GREEN_OFF;
            LED_BLUE_OFF;
          }
        
          
}

uint8_t ledToggle = 0; 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:  LedTask
//------------------------------------------------------------------------------
//  
//==============================================================================
void LedTask(void)
{
  uint8_t currentAppState,done; 
  uint16_t currentAppEvent; 
  
  currentAppState = AppStateGet();
  
  ledToggle = 0;
  switch(currentAppState)
  {
    case APPSTATE_TESTFORWARD:
    {
        if (ledToggle ==0)
        {
          ledToggle = 1; 
          LED_BLUE;
        }
        else
        {
          ledToggle = 0; 
          LED_ALL_OFF;
        }      
        break;
    }
    case APPSTATE_TESTREVERSE:
    {
        if (ledToggle ==0)
        {
          ledToggle = 1; 
          LED_RED;
        }
        else
        {
          ledToggle = 0; 
          LED_ALL_OFF;
        }            
      break;
    }
    default:
    {
    	LED_VIOLET;
    	break;
    }
  }
}

 
