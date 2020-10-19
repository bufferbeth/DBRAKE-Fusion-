//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//                FILE: buttons.c
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Processor: STM32F103R
// TOOLS: IAR Workbench 
// DATE:
// CONTENTS: This file contains  
//------------------------------------------------------------------------------
// HISTORY: This file  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "dbrakeDefs.h"
#include "driverbuttons.h"


//---------------------GLOBAL VARIABLES-----------------------------------

short int setup_pressed;


//---------------------LOCAL VARIABLES------------------------------------

uint16_t setup_hist = 0x0000;
uint8_t keyChanged; 


 
//---------------------LOCAL FUNCTION PROTOTYPES--------------------------  
 

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// ---------------------------GLOBAL FUNCTIONS ----------------------------------
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
#if BRAKEBOARD
uint8_t ButtonCheckPower(void)
{
	short int prevKey; 
	uint8_t i;
	
	for (i=0;i<12;i++)
	{
		power_hist = (power_hist << 1) + port_pin_get_input_level(BUTTON_POWER);
	 
		prevKey = power_pressed;
		if ((power_hist & 7) == 0)
		power_pressed = 1;
		else
		power_pressed = 0;
	}
		if (power_pressed != 0)
		{
			keyChanged |= KEY_POWER;
		}
		return power_pressed;
}
#endif 
*/


uint8_t ButtonChanged(void)
{
	uint8_t which; 
	which = keyChanged; 
	keyChanged = 0;	
	return which;
	
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:   ButtonInit
//------------------------------------------------------------------------------
// This function Initializes registers to allow button interrupts
//==============================================================================
void ButtonInit(void)
{
/*
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);	
  

	pin_conf.direction  = PORT_PIN_DIR_INPUT;
	pin_conf.input_pull = PORT_PIN_PULL_UP;
#if REMOTEBOARD	
	port_pin_set_config(BUTTON_SW1, &pin_conf);
	port_pin_set_config(BUTTON_SW2, &pin_conf);
	port_pin_set_config(BUTTON_SW3, &pin_conf);
	port_pin_set_config(BUTTON_SW4, &pin_conf);
#endif 
#if BRAKEBOARD
	port_pin_set_config(BUTTON_SETUP, &pin_conf);
	port_pin_set_config(BUTTON_POWER, &pin_conf);
	port_pin_set_config(INPUT_BREAKAWAY_RING, &pin_conf);	
	port_pin_set_config(INPUT_BREAKAWAY_TIP, &pin_conf);		
#endif
*/
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// FUNCTION:   ButtonSample
//------------------------------------------------------------------------------
// This function Delays then checks the buttons and updates button booleans
//==============================================================================
void ButtonSample(void)
{
	short int prevKey; 
/*
#if REMOTEBOARD	
  //------------------------
  //check pins
  right_hist = (right_hist << 1) + port_pin_get_input_level(BUTTON_SW1);
  center_hist = (center_hist << 1) + port_pin_get_input_level(BUTTON_SW2);
  left_hist = (left_hist << 1) + port_pin_get_input_level(BUTTON_SW3);
  brake_hist = (brake_hist << 1) + port_pin_get_input_level(BUTTON_SW4);
  
  //update vars
  prevKey = right_pressed; 
  if ((right_hist & 7) == 0)  
    right_pressed = 1;
  else
    right_pressed = 0;
  if (prevKey != right_pressed)
  {
	keyChanged |= KEY_RIGHT;
	schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE; 
  
  }

  prevKey = center_pressed;   
  if ((center_hist & 7) == 0)  
    center_pressed = 1;
  else
    center_pressed = 0;
  if (prevKey != center_pressed)
  {
	  keyChanged |= KEY_CENTER;
	  schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	  
  }

  prevKey = left_pressed;       
  if ((left_hist & 7) == 0)  
    left_pressed = 1;
  else
    left_pressed = 0;  
  if (prevKey != left_pressed)
  {
	  keyChanged |= KEY_LEFT;
	  schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	  
  }	
	
  prevKey = brake_pressed;  
  if ((brake_hist & 7) == 0)  
    brake_pressed = 1;
  else
    brake_pressed = 0;  
  if (prevKey != brake_pressed)
  {
	  keyChanged |= KEY_BRAKE;
	  schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	  
  }	
  
  if ((right_pressed != 0)&&(left_pressed != 0))
  {
	  breakaway_pressed = 1; 
  }
  else
  {
	  breakaway_pressed = 0; 
  }
  
#endif	
#if BRAKEBOARD
	//------------------------
	//check pins
	setup_hist = (setup_hist << 1) + port_pin_get_input_level(BUTTON_SETUP);
	power_hist = (power_hist << 1) + port_pin_get_input_level(BUTTON_POWER);
	breakawayRing_hist = (breakawayRing_hist << 1) + port_pin_get_input_level(INPUT_BREAKAWAY_RING);	
	breakawayTip_hist = (breakawayTip_hist << 1) + port_pin_get_input_level(INPUT_BREAKAWAY_TIP);		
	 
	//update vars
	prevKey = setup_pressed;
	if ((setup_hist & 7) == 0)
	setup_pressed = 1;
	else
	setup_pressed = 0;
	if (prevKey != setup_pressed)
	{
		keyChanged |= KEY_SETUP;
//		schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	
	}

	prevKey = power_pressed;
	if ((power_hist & 7) == 0)
	power_pressed = 1;
	else
	power_pressed = 0;
	if (prevKey != power_pressed)
	{
		keyChanged |= KEY_POWER;
//		schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	}
	
	prevKey = breakawayRing_pressed;
	if ((breakawayRing_hist & 7) == 0)
	breakawayRing_pressed = 1;
	else
	breakawayRing_pressed = 0;	
	if (prevKey != breakawayRing_pressed)
	{
		keyChanged |= KEY_BREAKAWAYRING;
//		schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	}	
	
	prevKey = breakawayTip_pressed;
	if ((breakawayTip_hist & 7) == 0)
	breakawayTip_pressed = 1;
	else
	breakawayTip_pressed = 0;	
	if (prevKey != breakawayTip_pressed)
	{
		keyChanged |= KEY_BREAKAWAYTIP;
//		schedByte |= SCHEDBYTE_APPSCREENKEYCHANGE;
	}	
		
	flimitState = port_pin_get_input_level(FLIMIT);	
	hlimitState = port_pin_get_input_level(HLIMIT);		
*/

/*
				if (((keyChanged & KEY_POWER)!= 0)&&(power_pressed != 0))
				{
					if (poweredUp == 0)
					{
						poweredUp = 1;
						MotorOff(1);  //added in v01_20						
						brakeState = BRAKESTATE_RESET;
						BrakeBoardStateMachineTask();	
					}
					else
					{
							poweredUp = 0;
							MotorOff(1);  //added in v01_20
							//V01_20 added below
//							port_pin_set_output_level(SUPERCAPEN,false);							
							deconfigure_wdt();
							NVIC_SystemReset();								
					}
				}	
	
#endif
*/
}

