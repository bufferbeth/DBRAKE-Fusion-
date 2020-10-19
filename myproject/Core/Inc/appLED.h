//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//                FILE: appLed.H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef __APP_LED_H__
#define __APP_LED_H__

#include "dbrakedefs.h"
 
#define LED_RED  LED_RED_ON;LED_GREEN_OFF;LED_BLUE_OFF;
#define LED_YELLOW  LED_RED_ON;LED_GREEN_ON;LED_BLUE_OFF;
#define LED_GREEN  LED_RED_OFF;LED_GREEN_ON;LED_BLUE_OFF;
#define LED_TEAL  LED_RED_OFF;LED_GREEN_ON;LED_BLUE_ON;
#define LED_BLUE  LED_RED_OFF;LED_GREEN_OFF;LED_BLUE_ON;
#define LED_VIOLET  LED_RED_ON;LED_GREEN_OFF;LED_BLUE_ON;
#define LED_WHITE  LED_RED_ON;LED_GREEN_ON;LED_BLUE_ON;
//---------------------GLOBAL DEFINITIONS--------------------------
#define LEDSTATE_IDLE           0
#define LEDSTATE_SIGNAL         1
#define LEDSTATE_PAIRING        2
extern uint8_t ledState;  
  //----------------------------
  //  
  //----------------------------
extern uint16_t opSignalTime;   

//---------------------GLOBAL VARIABLES--------------------------
 
//---------------------GLOBAL PROTOTYPES--------------------------
void LedTask(void);
 #endif
 
