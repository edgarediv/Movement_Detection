/*! @file		kl25z.h
 *  @brief 		
 *  @details  
 */
#ifndef KL25Z_PINNAMES_H_
#define KL25Z_PINNAMES_H_

#include "derivative.h"

#define PORT_BASE  ((PORT_MemMapPtr)0x40049000u)
#define PORT_OFFSET_MASK(x) (0x7000 & x)

#define GPIO_BASE ((GPIO_MemMapPtr)0x400FF000u)
#define GPIO_OFFSET_MASK(x) ((0x7000 & x) >> 6)

#define PORT_CLOCK_GATE(x)	0x200 << (PORT_OFFSET_MASK(x) >> 12) 

typedef enum {
    PORTA = 0x0,
    PORTB = 0x1000,
    PORTC = 0x2000,
    PORTD = 0x3000,
    PORTE = 0x4000
}PortBase;

typedef enum {
	PCR0 = 0x0,
	PCR1 = 0x4,
    PCR2 = 0x8,
    PCR3 = 0xc,
    PCR4 = 0x10,
    PCR5 = 0x14,
    PCR6 = 0x18,
    PCR7 = 0x1c,
    PCR8 = 0x20,
    PCR9 = 0x24,
    PCR10 = 0x28,
    PCR11 = 0x2c,
    PCR12 = 0x30,
    PCR13 = 0x34,
    PCR14 = 0x38,
    PCR15 = 0x3c,
    PCR16 = 0x40,
    PCR17 = 0x44,
    PCR18 = 0x48,
    PCR19 = 0x4c,
    PCR20 = 0x50,
    PCR21 = 0x54,
    PCR22 = 0x58,
    PCR23 = 0x5c,
    PCR24 = 0x60,
    PCR25 = 0x64,
    PCR26 = 0x68,
    PCR27 = 0x6c,
    PCR28 = 0x70,
    PCR29 = 0x74,
    PCR30 = 0x78,
    PCR31 = 0x7c,
}PinBase;

/*! Interrupt Configuration */
typedef enum {
    DISABLED = 0, 	/*! Interrupt/DMA request disabled */
    DMA_RIS,		/*! DMA request on rising edge */
    DMA_FALL,		/*! DMA request on falling edge */
    DMA_BOTH,		/*! DMA request on either edge */
    INT_ZERO = 8,	/*! Interrupt when logic zero */
    INT_RIS,		/*! Interrupt on rising edge */
    INT_FALL,		/*! Interrupt on falling edge */
    INT_BOTH,		/*! Interrupt on either edge */
    INT_ONE			/*! Interrupt when logic one */
} IRQConfig;

/*! Pin Mux Control */
typedef enum {
	ALT0 = 0, 	/*! Pin disabled (analog) */
	ALT1,		/*! Alternative 1 (GPIO) */
	ALT2,		/*! Alternative 2 (chip-specific) */
	ALT3,		/*! Alternative 3 (chip-specific) */
	ALT4,		/*! Alternative 4 (chip-specific) */
	ALT5,		/*! Alternative 5 (chip-specific) */
	ALT6,		/*! Alternative 6 (chip-specific) */
	ALT7		/*! Alternative 7 (chip-specific) */
} MUXSel;

/*! Drive Strength Enable */
typedef enum {
	LOW_DS = 0, /*! 0 Low drive strength is configured on the corresponding pin */
	HIGH_DS		/*! 1 High drive strength is configured on the corresponding pin */ 
} DSEn;

/*! Slew Rate Enable */
typedef enum {
	FAST_SR = 0,	/*! 0 Fast slew rate is configured on the corresponding pin */
	SLOW_SR			/*! 1 Slow slew rate is configured on the corresponding pin */
} SREn;

/*! Pull Enable */
typedef enum {
	PS_DIS = 0,	/*! 0 Internal pullup or pulldown resistor is not enabled on the corresponding pin */
	PS_EN		/*! 1 Internal pullup or pulldown resistor is enabled on the corresponding pin */
}PEn;

/*! Pull Select */
typedef enum {
	PULLDOWN = 0,	/*! 0 Internal pulldown resistor is enabled on the corresponding pin */
	PULLUP			/*! 1 Internal pullup resistor is enabled on the corresponding pin */
}PSel;

#define PIN_SHIFT(x)	1 << x

#endif /* KL25Z_PINNAMES_H_ */
