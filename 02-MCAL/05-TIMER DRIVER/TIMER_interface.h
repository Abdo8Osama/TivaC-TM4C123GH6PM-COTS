/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_INTERFACE_H                          */
/*********************************************************/

/***********************************************************************************************/
/******** This file defines Function prototypes and Macro Definitions for Timer Driver *********/
/***********************************************************************************************/

/*Header Guard*/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/* functions prototype*/

void TIM_init(timer_config * t_config );
void TIM_startCount(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE);
void TIM_stopCount(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE);
void TIM_setMode(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE);

void TIMER0A_SetCallBack( void (*ptr) (void) );

void TIM_enableTimeOutInterrupt(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B);
void TIM_disableTimeOutInterrupt(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B);
void TIM_clearTimeOutInterruptFlag(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B);

void TIM_setLoadeValue_TA(timer_module_type TIMER_MODULE , u32 copy_value);
void TIM_setLoadeValue_TB(timer_module_type TIMER_MODULE , u32 copy_value);
void TIM_setPrescalValue_TA(timer_module_type TIMER_MODULE , u16 prescal_value);
void TIM_setPrescalValue_TB(timer_module_type TIMER_MODULE , u16 prescal_value);

void TIM_setMatchValue_TA(timer_module_type TIMER_MODULE , u32 copy_value);
void TIM_setMatchValue_TB(timer_module_type TIMER_MODULE , u32 copy_value);
void TIM_setPrescalMatchValue_TA(timer_module_type TIMER_MODULE , u16 prescal_value);
void TIM_setPrescalMatchValue_TB(timer_module_type TIMER_MODULE , u16 prescal_value);




#endif