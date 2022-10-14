/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : RCC_INTERFACE_H                           */
/*********************************************************/

/*********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for RCC Driver *********/
/*********************************************************************************************/

/*Header Guard*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void GPIO_enableClock(u8 PORT_ID);
void GPIO_disableClock(u8 PORT_ID);

void TIMER_enableClock(u8 TIMER_ID);
void TIMER_disableClock(u8 TIMER_ID);

void WTIMER_enableClock(u8 WTIMER_ID);
void WTIMER_disableClock(u8 WTIMER_ID);

#endif
