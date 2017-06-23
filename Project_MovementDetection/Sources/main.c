/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "main.h" // definitions. 
#include "hal.h"  // hal. 


/************************  TYPE DEFINITIONS  **********************/

typedef enum {
  ST_Alarm_OFF,
  ST_Alarm_ON
}SM_ALARM_ENUM;


/**********************  FUNCTION PROTOTYPES   ********************/

void APP_SM_ALARM(void);


/************************  GLOBAL VARIABLES  **********************/

volatile int u16_SensorMov;
volatile char u8_SwitchAlarm;
char Time_Lapse_Ticks;
SM_ALARM_ENUM SM_ALARM;


/*************************  IRQ FUNCTIONS  ************************/

void PORTA_IRQHandler(void){
	HAL_clean_portA_isr();
	if(u8_SwitchAlarm){
		u16_SensorMov = TRUE;
	}
}

void PORTD_IRQHandler(void){
	HAL_clean_portD_isr();
}

void SysTick_Handler(void) {
	Time_Lapse_Ticks++;
}

/*****************************************************************/
/************************  PRIMARY LOOP MAIN  ********************/
/*****************************************************************/

int main(void)
{
	//Initialize Drivers configuration
	HAL_Init_Drivers_Config();
	SM_ALARM = ST_Alarm_OFF;
	
	//infinite loop
	for(;;) {	
		if( FALSE != Time_Lapse_Ticks ){
		  APP_SM_ALARM(); //Update State Machine every systick.
		  Time_Lapse_Ticks = FALSE;
		} else {
			//do nothing. Stay on background :D
		}
	}
	
	return 0;
}

/*****************************************************************/
/************************  STATE MACHINES   **********************/

void APP_SM_ALARM(void){
  
/*Update switch readings, by polling */
u8_SwitchAlarm = HAL_Read_Alarm_Switch();

  switch(SM_ALARM){
     case ST_Alarm_OFF: 
                    if(u16_SensorMov){ 
                      SM_ALARM = ST_Alarm_ON;        /*changing state to alarm ON, when movement is detected and alarm switch is set*/
                      HAL_Set_AC_Light(TURN_ON);  // Activates AC light. by hardware, inverse logic.
                      u16_SensorMov = FALSE;
                    }else{
                    	/*Do nothing, alarm is continues off*/ 
                    }
                    break;
     case ST_Alarm_ON: 
                    if(FALSE == u8_SwitchAlarm){
                      SM_ALARM = ST_Alarm_OFF;      /*changing state to alarm OFF*/   
                      HAL_Set_Buzzer_OFF();       // Turn Off buzzer.
                      HAL_Set_AC_Light(TURN_OFF);  // De-activates AC light. by hardware, inverse logic.
                    }else{  
                    	HAL_Toggle_Buzzer();  /*toggling buzzer every 1ms -> 2msPeriod -> 500Hz Freq, until switch is turn off, */ 
                    }
                    break;
     default: break;                 
   }
}


