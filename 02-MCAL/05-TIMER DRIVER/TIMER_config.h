/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_CONFIG_H                          */
/*********************************************************/

/*********************************************************************/
/******** This file determine configurations for Timer Driver *********/
/*********************************************************************/

/*Header Guard*/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/*CONFIGURATION PARAMETERS*/

	timer_config  t0_config ; 

	t0_config.TIMER_MODULE    = TIM0;
	t0_config.TIMER_MODE      = TIM_INDIVIDUAL_A_PERIODIC;
	t0_config.TIMER_DIRECTION = DOWN_COUNT;
	t0_config.TIMER_A_B       = A;
	
	t0_config.TIMER_MATCH_INT     = DISABLED;
	t0_config.TIMER_SNAPSHOT_MODE = DISABLED;
	t0_config.TIMER_PWM_INT	      = DISABLED;
	t0_config.TIMER_WAIT_TRIG     = NO_WAIT;
	
	t0_config.TIMER_PWM_LEGACY	  = LOW_DRIVEN;
	t0_config.TIMER_STALL	      = NO_HALT;
	t0_config.TIMER_OUT_TRIG      = ADC_TRIG_DISABLED;
	t0_config.TIMER_PWM_OUT_LEVEL = NON_INVERT;
	t0_config.TIMER_EVENT_MODE    = BOTH_EDGE;
	
	t0_config.REG_UPDATE_CASE	=NEXT_CYCLE;
	t0_config.MATCH_UPDATE_CASE	=NEXT_CYCLE;



#endif
