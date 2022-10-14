/*********************************************************/
/* Author    : Abd_Elrahman Osama                        */
/* Date      : 12 Aug 2022                               */
/* File_Name : LED_Control_mainApp_C                     */
/*********************************************************/

/******************************************************************************/
/** This program Controls blinking LED for a user-defined ON and OFF periods **/
/******************************************************************************/

 /* */
 
 void blinkLed (ON_Time_sec , OFF_Time_sec)
 {
	 /* blinkLed function is an App layer function that takes as an input from the user 
		a specific ON time and OFF time in seconds . 
		
		It lights the LED for the given ON time, and dim it for the given OFF time. 
		This function implements implicitly the PWM module using Timer Overflow.
	 */
	 
	 
void LED_Control_OV_Isr()
{
	/*Toggle Led Staate */
	
	/*LOAD TIMER WITH NEW VALUE*/
}
	 
 }
 
 void main()
 {
	 /*ENABL GPIO CLOCK AND TIMER CLOCK*/
	 
	 /*initialise GPIO Pin as output */
	 
	 /*initialise Interrupt Driver for Timer overflow*/
	 
	 /*SET TIMER CALLBACK*/

	 /*initialise Timer Driver to generate pwm signal */
	 
	/*Ask the User to enter the off and on times in sec*/
	 
	 /*pass the on and off time to the timer to start counting */
	 
	 
	 /*when overflow happens it will fire interrupt and jump to the LED_Control_TIME_OUT_Isr function */
	 
 }