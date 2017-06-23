/*
 * hal.c
 *
 *  Created on: Mar 22, 2017
 *      Author: edi_b
 */


#include "derivative.h" /* include peripheral declarations */
#include "main.h" // definitions. 
#include "hal.h" // driver functions. 

void HAL_clean_portA_isr(void);
void HAL_clean_portD_isr(void);
void HAL_Init_Drivers_Config(void);
void HAL_Set_AC_Light(char);
void HAL_Set_Buzzer_OFF(void);
void HAL_Toggle_Buzzer(void);
char HAL_Read_Alarm_Switch(void);
void HAL_Set_Toggle(char , char );
char HAL_Read_Gpio_Input(char, char);
void HAL_Set_Output(char, char, char);



void HAL_clean_portA_isr(void){
	BIOS_clean_portA_isr();
}

void HAL_clean_portD_isr(void){
	BIOS_clean_portD_isr();
}

void HAL_Init_Drivers_Config(void){
	//OUTPUT, with integrated LEDS
	BIOS_ConfigurePin(PORT_E, PIN20, GPIO, OUTPUT, IRQ_DISABLED, DRIVE_STRENGHT_EN);  //RED LED. Alarm Reached. AC Light 
	BIOS_ConfigurePin(PORT_E, PIN21, GPIO, OUTPUT, IRQ_DISABLED, DRIVE_STRENGHT_EN);  //GREEN LED. Alarm Activated. Buzzer.
	//BIOS_ConfigurePin(PORT_D, PIN2, GPIO, OUTPUT, IRQ_DISABLED, DRIVE_STRENGHT_EN); //BLUE LED BOARD ALSO.
	
	//INPUTS
	BIOS_ConfigurePin(PORT_A, PIN17, GPIO, INPUT, IRQ_RISING_EDGE, DRIVE_STRENGHT_DIS);  //Only port A & D have isr.
	BIOS_ConfigurePin(PORT_C, PIN12, GPIO, INPUT, IRQ_DISABLED, DRIVE_STRENGHT_DIS);     //Switch SetAlarm.
	
	//Systick
	BIOS_ConfigureSysTick(SYSTICK_CLK_SRC_CORE, SYSTICK_IRQ_ENABLED, SYSTICK_TIME_BIOS); //1ms tick.
}


void HAL_Set_AC_Light(char state){
	BIOS_Set_Output(PORT_E, PIN20, state); 
}

void HAL_Set_Buzzer_OFF(void){
	BIOS_Set_Output(PORT_E, PIN21, TURN_OFF);
}

void HAL_Toggle_Buzzer(void){
	HAL_Set_Toggle(PORT_E, PIN21);
}

char HAL_Read_Alarm_Switch(void){
	char value;
	value = HAL_Read_Gpio_Input(PORT_C, PIN12);
	return value;
}

void HAL_Set_Toggle(char port, char pin){
	BIOS_Set_Toggle(port, pin); 
}

char HAL_Read_Gpio_Input(char port, char pin){
	return (char)BIOS_Read_Gpio_Input(port, pin);
}

void HAL_Set_Output(char port, char pin, char state){
	BIOS_Set_Output(port, pin, state);
}
