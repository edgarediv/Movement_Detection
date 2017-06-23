/*
 * main.h
 *
 *  Created on: Mar 21, 2017
 *      Author: edi_b
 */

#ifndef MAIN_H_
#define MAIN_H_

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15
#define PIN16 16
#define PIN17 17
#define PIN18 18
#define PIN19 19
#define PIN20 20
#define PIN21 21
#define PIN22 22
#define PIN23 23
#define PIN24 24
#define PIN25 25
#define PIN26 26
#define PIN27 27
#define PIN28 28
#define PIN29 29
#define PIN30 30
#define PIN31 31
#define PIN32 32
#define PIN33 33
#define PIN34 34
#define PIN35 35

#define GPIO  0x1

#define DRIVE_STRENGHT_EN  0x1
#define DRIVE_STRENGHT_DIS 0x0 

#define INPUT   0x0
#define OUTPUT  0x1

#define TURN_OFF  0x0 //turning off leds of displays. inverted logic.
#define TURN_ON   0x1 //turning on leds of displays. inverted logic.


#define SYSTICK_CLK_SRC_REF            0x0
#define SYSTICK_CLK_SRC_CORE           0x1
#define SYSTICK_IRQ_DISABLED           0x0
#define SYSTICK_IRQ_ENABLED            0x1
#define SYSTICK_TIME_BIOS           208399 
// 104199 ticks needed for configuring systick to 1ms if clock freq is 20.84Mhz.  System tick isr will entry every  1ms. 24 bits maximum =0xFFFFFF =0d16777215 
// 208399 ticks needed for configuring systick to 10ms if clock freq is 20.84Mhz.  System tick isr will entry every 10ms. 24 bits maximum =0xFFFFFF =0d16777215 
// 479999 ticks needed for configuring systick to 10ms if clock freq is    48Mhz.  System tick isr will entry every 10ms. 24 bits maximum =0xFFFFFF =0d16777215 
#define FLAG_SYSTICK_TIME_TICKS_1000MS 100    //10ms as systick configured * multiplied by 100 to get 1000ms = 1S.
#define FLAG_SYSTICK_TIME_TICKS_500MS   50    //10ms as systick configured * multiplied by 5 to get 500ms.
#define FLAG_SYSTICK_TIME_TICKS_250MS   25   
#define FLAG_SYSTICK_TIME_TICKS_200MS   20   
#define FLAG_SYSTICK_TIME_TICKS_100MS   10   
#define FLAG_SYSTICK_TIME_TICKS_50MS     5     
#define FLAG_SYSTICK_TIME_TICKS_20MS     2   
#define FLAG_SYSTICK_TIME_TICKS_10MS     1  
#define FLAG_SYSTICK_TIME_TICKS_1MS      0 
 
#define TIME_1S FLAG_SYSTICK_TIME_TICKS_1000MS  

#define TRUE 0x1
#define FALSE 0x0

#define IRQ_DISABLED      0b0000
#define IRQ_RISING_EDGE   9//0b1001
#define IRQ_FALLING_EDGE  0b1010
#define IRQ_BOTH_EDGES    0b1011


#endif /* MAIN_H_ */
