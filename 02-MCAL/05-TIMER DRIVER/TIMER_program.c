/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_PROGRAM_C                          */
/*********************************************************/

/**************************************************************************/
/******** This file defines Function Definitions for Timer Driver *********/
/**************************************************************************/

/*Included files*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_private.h"
#include"TIMER_interface.h"
#include"TIMER_config.h"
#include"TIMER_register.h"

/*function definitions*/
void TIM_init(timer_config * t_config )
{
	/*SET TIMER MODE*/
	TIM_setMode(timer_config->TIMER_MODULE , timer_config->TIMER_MODE);
	
	/*SET COUNTER DIRECTION */
	if(t_config->TIMER_DIRECTION == DOWN_COUNT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TACDIR);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBCDIR);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TACDIR);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBCDIR);break ;
		}

	}
	else if(t_config->TIMER_DIRECTION == UP_COUNT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TACDIR);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBCDIR);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TACDIR);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBCDIR);break ;
		}
	}

	/*SET MATCH INTERRUPT ENABLE */
	if(t_config->TIMER_MATCH_INT == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAMIE);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBMIE);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAMIE);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBMIE);break ;
		}

	}
	else if(t_config->TIMER_MATCH_INT == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAMIE);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBMIE);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAMIE);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBMIE);break ;
		}
	}
	
	/*SET WAIT TRIG CASE  */
	if(t_config->TIMER_WAIT_TRIG == NO_WAIT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAWOT);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBWOT);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAWOT);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBWOT);break ;
		}

	}
	else if(t_config->TIMER_WAIT_TRIG == WAIT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAWOT);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBWOT);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAWOT);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBWOT);break ;
		}
	}
	
	/*SET SNAPSHOT MODDE */
	if(t_config->TIMER_SNAPSHOT_MODE == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TASNAPS);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBSNAPS);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TASNAPS);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBSNAPS);break ;
		}

	}
	else if(t_config->TIMER_SNAPSHOT_MODE == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TASNAPS);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBSNAPS);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TASNAPS);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBSNAPS);break ;
		}
	}
	
	/*SET REG UPDATE CASE MODDE */
	if(t_config->REG_UPDATE_CASE == NEXT_CYCLE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAILD);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBILD);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAILD);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBILD);break ;
		}

	}
	else if(t_config->REG_UPDATE_CASE == NEXT_TIMEOUT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAILD);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBILD);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAILD);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBILD);break ;
		}
	}
	
	/*SET MATCH UPDATE CASE MODDE */
	if(t_config->MATCH_UPDATE_CASE == NEXT_CYCLE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAMRSU);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBMRSU);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAMRSU);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBMRSU);break ;
		}

	}
	else if(t_config->MATCH_UPDATE_CASE == NEXT_TIMEOUT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAMRSU);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBMRSU);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAMRSU);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBMRSU);break ;
		}
	}

	/*SET PWM INTERRUPT MODE */
	if(t_config->TIMER_PWM_INT == DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAPWMIE);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBPWMIE);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAPWMIE);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBPWMIE);break ;
		}

	}
	else if(t_config->TIMER_PWM_INT == ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAPWMIE);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBPWMIE);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAPWMIE);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBPWMIE);break ;
		}
	}

	/*SET PWM INTERRUPT MODE */
	if(t_config->TIMER_PWM_LEGACY == LOW_DRIVEN)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAPLO);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_BMR , TBPLO);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_AMR , TAPLO);
					   CLR(t_config->TIMER_MODULE->GPTM_BMR , TBPLO);break ;
		}

	}
	else if(t_config->TIMER_PWM_LEGACY == HIGH_DRIVEN)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_AMR , TAPLO);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_BMR , TBPLO);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_AMR , TAPLO);
					   SET(t_config->TIMER_MODULE->GPTM_BMR , TBPLO);break ;
		}
	}
	
	/*SET OUTPUT TRIGGER */
	if(t_config->TIMER_OUT_TRIG == ADC_TRIG_DISABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAOTE);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TBOTE);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAOTE);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBOTE);break ;
		}

	}
	else if(t_config->TIMER_OUT_TRIG == ADC_TRIG_ENABLED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_CTL , TAOTE);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_CTL , TBOTE);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_CTL , TAOTE);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBOTE);break ;
		}
	}
	
	/*SET PWM OUTPUT LEVEL */
	if(t_config->TIMER_PWM_OUT_LEVEL == NON_INVERT)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAPWML);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TBPWML);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAPWML);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBPWML);break ;
		}

	}
	else if(t_config->TIMER_PWM_OUT_LEVEL == INVERTED)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_CTL , TAPWML);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_CTL , TBPWML);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_CTL , TAPWML);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBPWML);break ;
		}
	}

	/*SET TIMER_STALL */
	if(t_config->TIMER_STALL == NO_HALT)
	{
		CLR(t_config->TIMER_MODULE->GPTM_CTL , RTCEN);
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TASTALL);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_CTL , TASTALL);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
		}

	}
	else if(t_config->TIMER_STALL == HALTED)
	{
		SET(t_config->TIMER_MODULE->GPTM_CTL , RTCEN);
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_CTL , TASTALL);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_CTL , TASTALL);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBSTALL);break ;
		}
	}
	/*SET TIMER EVENT MODE */
	if(t_config->TIMER_EVENT_MODE == POSITIVE_EDGE)
	{
		
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}

	}
	else if(t_config->TIMER_EVENT_MODE == NEGATIVE_EDGE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}
	else if(t_config->TIMER_EVENT_MODE == BOTH_EDGE)
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}
	else
	{
		switch(t_config->TIMER_A_B)
		{
			case A   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);break ;
			case B   : CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
			case A_B : CLR(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TAEVENT1);
					   CLR(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT0);
					   SET(t_config->TIMER_MODULE->GPTM_CTL , TBEVENT1);break ;
		}
	}

}
void TIM_startCount(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE)
{
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))
	   	/*START BOTH A AND B*/
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);
	 SET(TIMER_MODULE->GPTM_CTL , TBEN);}
	 
	else if(TIMER_MODE == TIM_RTC)
	{/*******/}

	else if((TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_PWM))
		/*START A TIMER*/
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);}
	
		
	else if((TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_PWM))
			/*START B TIMER*/	
	{SET(TIMER_MODULE->GPTM_CTL , TBEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
		/*START BOTH A AND B */
	{SET(TIMER_MODULE->GPTM_CTL , TAEN);
	 SET(TIMER_MODULE->GPTM_CTL , TBEN);}
			
}

void TIM_stopCount(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE)
{
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))
	   /*STOP BOTH A AND B */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);
	 CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
	 
	else if(TIMER_MODE == TIM_RTC)
	{/*******/}

	else if((TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_PWM))
			/*STOP A */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_B_PWM))
			   /*STOP B */	
	{CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
	
	else if((TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT)||
		    (TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME)||
	        (TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))
	   /*STOP BOTH A AND B */
	{CLR(TIMER_MODULE->GPTM_CTL , TAEN);
	 CLR(TIMER_MODULE->GPTM_CTL , TBEN);}
}
void TIM_setMode(timer_module_type TIMER_MODULE , timer_mode_type TIMER_MODE)
{
	/*SET MODE IN GPTM_CFG REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_CONCAT_PERIODIC)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
	   (TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
	   (TIMER_MODE == TIM_CONCAT_PWM))  
	{TIMER_MODULE->GPTM_CFG =0;}	 
	else if(TIMER_MODE == TIM_RTC)
	{TIMER_MODULE->GPTM_CFG =1;}
	else{TIMER_MODULE->GPTM_CFG =4;}
 		 
	/*SET MODE IN GPTM_AMR REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT))  
	{SET(TIMER_MODULE->GPTM_AMR , TAMR0);
	 CLR(TIMER_MODULE->GPTM_AMR , TAMR1);}

	else if((TIMER_MODE == TIM_CONCAT_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC))  
	{CLR(TIMER_MODULE->GPTM_AMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_AMR , TAMR1);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT))  
	{SET(TIMER_MODULE->GPTM_AMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_AMR , TAMR1);
	 CLR(TIMER_MODULE->GPTM_AMR , TACMR);
	 CLR(TIMER_MODULE->GPTM_AMR , TAAMS);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME))  
	{SET(TIMER_MODULE->GPTM_AMR , TAMR0);
	 SET(TIMER_MODULE->GPTM_AMR , TAMR1);
	 SET(TIMER_MODULE->GPTM_AMR , TACMR);
	 CLR(TIMER_MODULE->GPTM_AMR , TAAMS);}

	else if((TIMER_MODE == TIM_CONCAT_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))  
	{CLR(TIMER_MODULE->GPTM_AMR , TAAMS);}
	
	/*SET MODE IN GPTM_BMR REG*/
	if((TIMER_MODE == TIM_CONCAT_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_B_ONE_SHOT)||
	   (TIMER_MODE == TIM_INDIVIDUAL_A_B_ONE_SHOT))  
	{SET(TIMER_MODULE->GPTM_BMR , TBMR0);
	 CLR(TIMER_MODULE->GPTM_BMR , TBMR1);}

	else if((TIMER_MODE == TIM_CONCAT_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_PERIODIC)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PERIODIC))  
	{CLR(TIMER_MODULE->GPTM_BMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_BMR , TBMR1);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT))  
	{SET(TIMER_MODULE->GPTM_BMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_BMR , TBMR1);
	 CLR(TIMER_MODULE->GPTM_BMR , TBCMR);
	 CLR(TIMER_MODULE->GPTM_BMR , TBAMS);}

	else if((TIMER_MODE == TIM_CONCAT_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME))  
	{SET(TIMER_MODULE->GPTM_BMR , TBMR0);
	 SET(TIMER_MODULE->GPTM_BMR , TBMR1);
	 SET(TIMER_MODULE->GPTM_BMR , TBCMR);
	 CLR(TIMER_MODULE->GPTM_BMR , TBAMS);}

	else if((TIMER_MODE == TIM_CONCAT_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_B_PWM)||
			(TIMER_MODE == TIM_INDIVIDUAL_A_B_PWM))  
	{CLR(TIMER_MODULE->GPTM_BMR , TBAMS);}

}


void TIM_enableTimeOutInterrupt(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_IMR , TATOIM);break ;
			case B   : SET(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
			case A_B : SET(TIMER_MODULE->GPTM_IMR , TATOIM);
					   SET(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
		}
}

void TIM_disableTimeOutInterrupt(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : CLR(TIMER_MODULE->GPTM_IMR , TATOIM);break ;
			case B   : CLR(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
			case A_B : CLR(TIMER_MODULE->GPTM_IMR , TATOIM);
					   CLR(TIMER_MODULE->GPTM_IMR , TBTOIM);break ;
		}
}

void TIM_clearTimeOutInterruptFlag(timer_module_type TIMER_MODULE , A_B_type TIMER_A_B)
{
	switch(TIMER_A_B)
		{
			case A   : SET(TIMER_MODULE->GPTM_IMR , TATOCINT);break ;
			case B   : SET(TIMER_MODULE->GPTM_IMR , TBTOCINT);break ;
			case A_B : SET(TIMER_MODULE->GPTM_IMR , TATOCINT);
					   SET(TIMER_MODULE->GPTM_IMR , TBTOCINT);break ;
		}
}

void TIM_setLoadeValue_TA(timer_module_type TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TAILR = copy_value ;
}

void TIM_setLoadeValue_TB(timer_module_type TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TBILR = copy_value ;
}

void TIM_setPrescalValue_TA(timer_module_type TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TAPR = prescal_value ;

}
void TIM_setPrescalValue_TB(timer_module_type TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TBPR = prescal_value ;

}


void TIM_setMatchValue_TA(timer_module_type TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TAMATCHR = copy_value ;
}

void TIM_setMatchValue_TB(timer_module_type TIMER_MODULE , u32 copy_value)
{
	TIMER_MODULE->GPTM_TBMATCHR = copy_value ;
}

void TIM_setPrescalMatchValue_TA(timer_module_type TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TAPMR = prescal_value ;

}
void TIM_setPrescalMatchValue_TB(timer_module_type TIMER_MODULE , u16 prescal_value)
{
		TIMER_MODULE->GPTM_TBPMR = prescal_value ;

}

void (*TIMER0A_CallBack) (void);

void TIMER0A_SetCallBack( void (*ptr) (void) )
{
	TIMER0A_CallBack = ptr;
}
void TIMER0A_Handler(void)
{
	TIMER0A_CallBack();
	TIM_clearTimeOutInterruptFlag(TIM0 , A);
}

