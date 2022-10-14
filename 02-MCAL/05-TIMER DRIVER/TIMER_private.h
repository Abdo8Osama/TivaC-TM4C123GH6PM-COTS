/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 20022                              */
/* File_Name : TIMER_PRIVATE_H                           */
/*********************************************************/

/***************************************************************************/
/********** This file defines Private functions for Timer Driver ***********/
/***************************************************************************/

/*Header Guard*/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/*GPTMTAMR BITS*/
#define  TAPLO      11
#define  TAMRSU     10
#define  TAPWMIE    9
#define  TAILD      8
#define  TASNAPS    7
#define  TAWOT      6
#define  TAMIE      5
#define  TACDIR		4
#define  TAAMS      3
#define  TACMR      2
#define  TAMR1		1
#define  TAMR0      0
/*GPTMTBMR BITS*/
#define  TBPLO      11
#define  TBMRSU     10
#define  TBPWMIE    9
#define  TBILD      8
#define  TBSNAPS    7
#define  TBWOT      6
#define  TBMIE      5
#define  TBCDIR		4
#define  TBAMS      3
#define  TBCMR      2
#define  TBMR1		1
#define  TBMR0      0
/*GPTMCTL BITS*/
#define  TBPWML     14
#define  TBOTE      13
#define  TBEVENT1   11
#define  TBEVENT0   10
#define  TBSTALL    9
#define  TBEN       8
#define  TAPWML     6
#define  TAOTE      5
#define  RTCEN      4
#define  TAEVENT1   3
#define  TAEVENT0   2
#define  TASTALL    1
#define  TAEN       0
/*INTERRUPT MASK BITS*/
enum{
   TATOIM   ,
	CAMIM   ,
	CAEIM   ,
	RTCIM   ,
	TAMIM   ,
   TBTOIM = 8  ,
	CBMIM   ,
	CBEIM   ,
	TBMIM   ,
	WUEIM =16
};
/*RAW INTERRUPT STATUS BITS*/
enum{
   TATORIS   ,
	CAMRIS   ,
	CAERIS   ,
	RTCRIS   ,
	TAMRIS   ,
   TBTORIS = 8   ,
	CBMRIS   ,
	CBERIS   ,
	TBMRIS   ,
	WUERIS =16
};
/*MASKED INTERRUPT STATUS BITS*/
enum{
   TATOMIS   ,
	CAMMIS   ,
	CAEMIS   ,
	RTCMIS   ,
	TAMMIS   ,
   TBTOMIS  = 8 ,
	CBMMIS   ,
	CBEMIS   ,
	TBMMIS   ,
	WUEMIS =16
};
/*INTERRUPT CLEAR BITS*/
enum{
   TATOCINT   ,
	CAMCINT   ,
	CAECINT   ,
	RTCCINT   ,
	TAMCINT   ,
   TBTOCINT  =8 ,
	CBMCINT   ,
	CBECINT   ,
	TBMCINT   ,
	WUECINT =16
};

/*CONFIGURATION PARAMETERS*/
typedef struct{
	timer_module_type  		  TIMER_MODULE    ;
	timer_mode_type    		  TIMER_MODE      ;
	A_B_type				  TIMER_A_B		  ; 
	direction_type     		  TIMER_DIRECTION ;
	
	match_INT_Enable_type	  TIMER_MATCH_INT			;
	snapshot_mode_type		  TIMER_SNAPSHOT_MODE		;
	pwm_INT_Enable_type		  TIMER_PWM_INT				;
	wait_trigger_type		  TIMER_WAIT_TRIG			;
	PWM_Legacy_Operation_type TIMER_PWM_LEGACY			;
	timer_stall_type		  TIMER_STALL				;
	output_trigger_type		  TIMER_OUT_TRIG			;
	pwm_outputLevel_type	  TIMER_PWM_OUT_LEVEL		;
	event_mode_type			  TIMER_EVENT_MODE			;
	
	update_reg_next_cycle_timout_type	REG_UPDATE_CASE	    ;
	update_match_next_cycle_timout_type	MATCH_UPDATE_CASE	;

}timer_config ;


/*TIMER MODULE TYPE*/
#define TIM0   		TIMER0_16_32
#define	TIM1   		TIMER1_16_32
#define	TIM2   		TIMER2_16_32
#define	TIM3   		TIMER3_16_32
#define	TIM4   		TIMER4_16_32
#define TIM5   		TIMER5_16_32

#define	TIM0_Wide   TIMER0_32_64
#define	TIM1_Wide   TIMER1_32_64
#define	TIM2_Wide   TIMER2_32_64
#define	TIM3_Wide   TIMER3_32_64
#define TIM4_Wide   TIMER4_32_64 
#define TIM5_Wide   TIMER5_32_64


typedef enum{
	TIM_CONCAT_ONE_SHOT ,
	TIM_CONCAT_PERIODIC ,
	TIM_CONCAT_CAPTURE_EDGE_COUNT  ,
	TIM_CONCAT_CAPTURE_EDGE_TIME   ,
	TIM_CONCAT_PWM ,

	TIM_RTC,
	
	TIM_INDIVIDUAL_A_ONE_SHOT , 
	TIM_INDIVIDUAL_A_PERIODIC , 
	TIM_INDIVIDUAL_A_CAPTURE_EDGE_COUNT  , 
	TIM_INDIVIDUAL_A_CAPTURE_EDGE_TIME   , 
	TIM_INDIVIDUAL_A_PWM , 
	TIM_INDIVIDUAL_B_ONE_SHOT , 
	TIM_INDIVIDUAL_B_PERIODIC , 
	TIM_INDIVIDUAL_B_CAPTURE_EDGE_COUNT  , 
	TIM_INDIVIDUAL_B_CAPTURE_EDGE_TIME   , 
	TIM_INDIVIDUAL_B_PWM , 
	TIM_INDIVIDUAL_A_B_ONE_SHOT , 
	TIM_INDIVIDUAL_A_B_PERIODIC , 
	TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_COUNT  , 
	TIM_INDIVIDUAL_A_B_CAPTURE_EDGE_TIME   , 
	TIM_INDIVIDUAL_A_B_PWM , 
}timer_mode_type;

typedef enum{
	ONE_SHOT ,
	PERIODIC ,
	CAPTURE_EDGE_COUNT  ,
	CAPTURE_EDGE_TIME   ,
	PWM 
}timer_op_mode_type;

typedef enum{
	A , 
	B ,
	A_B
}A_B_type;

typedef enum{
	DOWN_COUNT ,
	UP_COUNT 
}direction_type;

typedef enum{
	DISABLED ,
	ENABLED 
}match_INT_Enable_type;

typedef enum{
	DISABLED ,
	ENABLED 
}snapshot_mode_type;

typedef enum{
	DISABLED ,
	ENABLED 
}pwm_INT_Enable_type;

typedef enum{
	NEXT_CYCLE ,
	NEXT_TIMEOUT
}update_reg_next_cycle_timout_type;

typedef enum{
	NEXT_CYCLE ,
	NEXT_TIMEOUT
}update_match_next_cycle_timout_type;

typedef enum{
	NO_WAIT ,
	WAIT
}wait_trigger_type;

typedef enum{
	LOW_DRIVEN ,
	HIGH_DRIVEN
}PWM_Legacy_Operation_type;

typedef enum{
	NO_HALT ,
	HALTED
}timer_stall_type;

typedef enum{
	ADC_TRIG_DISABLED ,
	ADC_TRIG_ENABLED
}output_trigger_type;

typedef enum{
	NON_INVERT ,
	INVERTED
}pwm_outputLevel_type;

typedef enum{
	POSITIVE_EDGE ,
	NEGATIVE_EDGE ,
	BOTH_EDGE ,
	RESERVED
}event_mode_type;


#endif
