/*
 * bios.h
 *
 *  Created on: Mar 21, 2017
 *      Author: edi_b
 */

#ifndef BIOS_GPIO_H_
#define BIOS_GPIO_H_

#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
#define PORT_E 5

extern void BIOS_ConfigurePin(char port, char pin, char func, char inout, char irq, char drive_str);
extern void BIOS_Set_Output (char port, char pin, char state);
extern void BIOS_clean_portA_isr(void);
extern void BIOS_clean_portD_isr(void);
extern void BIOS_Set_Toggle(char port, char pin);
extern char BIOS_Read_Gpio_Input(char port, char pin);


#endif /* BIOS_GPIO_H_ */
