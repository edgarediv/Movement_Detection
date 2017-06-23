/*
 * bios.c
 *
 *  Created on: Mar 21, 2017
 *      Author: edi_b
 */
#include "bios_gpio.h" // definitions. 
#include "derivative.h" /* include peripheral declarations */
#include "kl25z.h"

void BIOS_ConfigurePin(char, char, char, char, char, char);
void BIOS_Set_Output (char, char, char) ; 
void BIOS_clean_portA_isr(void);
void BIOS_clean_portD_isr(void);
void BIOS_Set_Toggle(char, char);	   
char BIOS_Read_Gpio_Input(char, char);



void BIOS_clean_portA_isr(void){
	PORTA_ISFR = 0xFFFFFFFF;
}

void BIOS_clean_portD_isr(void){
	PORTD_ISFR = 0xFFFFFFFF;
}

void BIOS_Set_Toggle(char port, char pin){
	switch(port){
	case(PORT_A):
			GPIOA_PTOR |= 1<<pin;
			break;
	case(PORT_B):
			GPIOB_PTOR |= 1<<pin;
			break;
	case(PORT_C):
			GPIOC_PTOR |= 1<<pin;
			break;
	case(PORT_D):
			GPIOD_PTOR |= 1<<pin;
			break;
	case(PORT_E):
			GPIOE_PTOR |= 1<<pin;
			break;
			
	}
}


void BIOS_ConfigurePin(char port, char pin, char func, char inout, char irq, char drive_str) {
	switch(port){		
				case (PORT_A):
		             SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
		             PORT_PCR_REG(PORTA_BASE_PTR, pin) |= (PORT_PCR_MUX(func) | PORT_PCR_IRQC(irq) | (drive_str<<PORT_PCR_DSE_SHIFT));
					if(func==0x1){
						if(inout==0x0){  // 0 = input
							GPIOA_PDDR &= ~(1<<pin); //set a 0 on bit "pin" only.
							if(0x0 != irq){
							NVIC_ICPR |= (1<<30); //HARCODED PORT A IRQ is on pin 30
							NVIC_ISER |= (1<<30); //HARCODED PORT A IRQ is on pin 30
							}
						}else if(inout ==0x1) // 1 = output
							GPIOA_PDDR |= (1<<pin); //set a 1 on bit "pin" only. 
					}
					break;
				case (PORT_B):
		             SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
		             PORT_PCR_REG(PORTB_BASE_PTR, pin) |= (PORT_PCR_MUX(func) | PORT_PCR_IRQC(irq) | (drive_str<<PORT_PCR_DSE_SHIFT));
					if(func==0x1){
						if(inout==0x0)  // 0 = input
							GPIOB_PDDR &= ~(1<<pin); //set a 0 on bit "pin" only. 
						else if(inout ==0x1) // 1 = output
							GPIOB_PDDR |= (1<<pin); //set a 1 on bit "pin" only. 
					}
					break;
				case (PORT_C):
		             SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
				     PORT_PCR_REG(PORTC_BASE_PTR, pin) |= (PORT_PCR_MUX(func) | PORT_PCR_IRQC(irq) | (drive_str<<PORT_PCR_DSE_SHIFT));
					if(func==0x1){
						if(inout==0x0)  // 0 = input
							GPIOC_PDDR &= ~(1<<pin); //set a 0 on bit "pin" only. 
						else if(inout ==0x1) // 1 = output
							GPIOC_PDDR |= (1<<pin); //set a 1 on bit "pin" only. 
					}
					break;
				case (PORT_D):
		             SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
		             PORT_PCR_REG(PORTD_BASE_PTR, pin) |= (PORT_PCR_MUX(func) | PORT_PCR_IRQC(irq) | (drive_str<<PORT_PCR_DSE_SHIFT));
					if(func==0x1){
						if(inout==0x0){  // 0 = input
							GPIOD_PDDR &= ~(1<<pin); //set a 0 on bit "pin" only.
							if(0x0 != irq){
							NVIC_ICPR |= (1<<31); //HARCODED PORT D IRQ is on pin 31. Clear pending Interrupts
					    	NVIC_ISER |= (1<<31); //HARCODED PORT D IRQ is on pin 31. Enable interrupts for PORTD module.
							}
						}else if(inout ==0x1) // 1 = output
							GPIOD_PDDR |= (1<<pin); //set a 1 on bit "pin" only. 
					}
					break;
				case (PORT_E):
		             SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
		             PORT_PCR_REG(PORTE_BASE_PTR, pin) |= (PORT_PCR_MUX(func) | PORT_PCR_IRQC(irq) | (drive_str<<PORT_PCR_DSE_SHIFT));
					if(func==0x1){
						if(inout==0x0)  // 0 = input
							GPIOE_PDDR &= ~(1<<pin); //set a 0 on bit "pin" only. 
						else if(inout ==0x1) // 1 = output
							GPIOE_PDDR |= (1<<pin); //set a 1 on bit "pin" only. 
					}
					break;
	}
}


void BIOS_Set_Output (char port, char pin, char state) {
	switch(port){
		case(PORT_A):
			if(state==0x0)  // 0 = turn-off
				GPIOA_PDOR &= ~(1<<pin); //set a 0 on bit "pin" only. 
			else if(state ==0x1) // 1 = output
				GPIOA_PDOR |= (1<<pin); //set a 1 on bit "pin" only.    
		break;
		case(PORT_B):
			if(state==0x0)  // 0 = turn-off
				GPIOB_PDOR &= ~(1<<pin); //set a 0 on bit "pin" only. 
			else if(state ==0x1) // 1 = output
				GPIOB_PDOR |= (1<<pin); //set a 1 on bit "pin" only.    
		break;
		case(PORT_C):
			if(state==0x0)  // 0 = turn-off
				GPIOC_PDOR &= ~(1<<pin); //set a 0 on bit "pin" only. 
			else if(state ==0x1) // 1 = output
				GPIOC_PDOR |= (1<<pin); //set a 1 on bit "pin" only.    
		break;
		case(PORT_D):
			if(state==0x0)  // 0 = turn-off
				GPIOD_PDOR &= ~(1<<pin); //set a 0 on bit "pin" only. 
			else if(state ==0x1) // 1 = output
				GPIOD_PDOR |= (1<<pin); //set a 1 on bit "pin" only.    
		break;
		case(PORT_E):
			if(state==0x0)  // 0 = turn-off
				GPIOE_PDOR &= ~(1<<pin); //set a 0 on bit "pin" only. 
			else if(state ==0x1) // 1 = output
				GPIOE_PDOR |= (1<<pin); //set a 1 on bit "pin" only.    
		break;
	}
	 
}


char BIOS_Read_Gpio_Input(char port, char pin){
	int value;
	switch(port){
		case(PORT_A):
			value = GPIOA_PDIR & 1<<pin;
			break;
		case(PORT_B):
			value = GPIOB_PDIR & 1<<pin;
			break;
		case(PORT_C):
			value = GPIOC_PDIR & 1<<pin;
			break;
		case(PORT_D):
			value = GPIOD_PDIR & 1<<pin;
			break;
		case(PORT_E):
			value = GPIOE_PDIR & 1<<pin;
			break;
		default:
			value = 0;
			break;
	}
	value =  value>>pin;
	return (char)value;
}


