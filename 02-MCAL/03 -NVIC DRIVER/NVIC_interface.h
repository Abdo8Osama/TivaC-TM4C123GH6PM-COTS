/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : NVIC_INTERFACE_H                          */
/*********************************************************/

/**********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for NVIC Driver *********/
/**********************************************************************************************/

/*Header Guard*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/*Function declarations*/
void NVIC_enableInterrupt(u8 peripheral_ID);
void NVIC_disableInterrupt(u8 peripheral_ID);

void NVIC_SetPendingFlag(u8 peripheral_ID);
void NVIC_ClearPendingFlag(u8 peripheral_ID);

void NVIC_SetPriority(u8 peripheral_ID, u8 peripheral_Periority);

u8 NVIC_getPendingFlag(u8 peripheral_ID);
u8 NVIC_getActiveFlag( u8 peripheral_ID );


#endif
