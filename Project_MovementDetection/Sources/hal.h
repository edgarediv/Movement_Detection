/*
 * hal.h
 *
 *  Created on: Mar 22, 2017
 *      Author: edi_b
 */

#ifndef HAL_H_
#define HAL_H_

#include "derivative.h" /* include peripheral declarations */
#include "main.h" // definitions. 
#include "bios_gpio.h" // driver functions. 
#include "bios_systick.h" // driver functions. 

extern void HAL_clean_portA_isr(void);
extern void HAL_clean_portD_isr(void);
extern void HAL_Init_Drivers_Config(void);
extern void HAL_Set_AC_Light(char);
extern void HAL_Set_Buzzer_OFF(void);
extern void HAL_Toggle_Buzzer(void);
extern char HAL_Read_Alarm_Switch(void);
extern void HAL_Set_Toggle(char , char );
extern char HAL_Read_Gpio_Input(char, char);
extern void HAL_Set_Output(char, char, char);


#endif /* HAL_H_ */
