//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//                FILE: BUTTONS.H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef __BUTTONS_H__
#define __BUTTONS_H__

 

//---------------------GLOBAL DEFINITIONS--------------------------

#define KEY_SETUP 0x01
#define KEY_POWER 0x02

//---------------------GLOBAL VARIABLES--------------------------

extern short int setup_pressed;
extern short int power_pressed;

//---------------------GLOBAL PROTOTYPES--------------------------
void ButtonInit(void);
void ButtonSample(void);
uint8_t ButtonChanged(void);
uint8_t ButtonCheckPower(void);


#endif
