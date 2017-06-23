/*
 * bios_systick.c
 *
 *  Created on: Jun 21, 2017
 *      Author: edi_b
 */


#include "bios_gpio.h" // definitions. 
#include "derivative.h" /* include peripheral declarations */
#include "kl25z.h"

void BIOS_ConfigureSysTick(char, char, int);

void BIOS_ConfigureSysTick(char source, char irq, int time_ticks) {
	SYST_CSR  =  (source<<SysTick_CSR_CLKSOURCE_SHIFT | irq<<SysTick_CSR_TICKINT_SHIFT); 
	SYST_RVR  =  time_ticks;
	SYST_CSR |=  SysTick_CSR_ENABLE_MASK;  //enable/start counting. 
}
