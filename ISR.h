/* 
 * File:   ISR.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 9., 22:19
 */

#ifndef ISR_H
#define	ISR_H

#include <stdint.h>

typedef enum eISR_Vector
{
    ISR_Vector_INT0,
    ISR_Vector_IC1,
    ISR_Vector_OC1,
    ISR_Vector_T1,
    ISR_Vector_DMA0,
    ISR_Vector_IC2,
    ISR_Vector_OC2,
    ISR_Vector_T2,
    ISR_Vector_T3,
    ISR_Vector_SPI1E,
    ISR_Vector_SPI1,
    ISR_Vector_U1RX,
    ISR_Vector_U1TX,
    ISR_Vector_AD1,
    ISR_Vector_DMA1,
    ISR_Vector_NVM,
    ISR_Vector_SI2C1,
    ISR_Vector_MI2C1,
    ISR_Vector_CMP,
    ISR_Vector_CN,
    ISR_Vector_INT1,
    ISR_Vector_DMA2 = 24,
    ISR_Vector_OC3,
    ISR_Vector_OC4,
    ISR_Vector_T4,
    ISR_Vector_T5,
    ISR_Vector_INT2,
    ISR_Vector_U2RX,
    ISR_Vector_U2TX,
    ISR_Vector_SPI2E,
    ISR_Vector_SPI2,
    ISR_Vector_C1RX,
    ISR_Vector_C1,
    ISR_Vector_DMA3,
    ISR_Vector_IC3,
    ISR_Vector_IC4,
    ISR_Vector_PSEM = 57,
    ISR_Vector_U1E = 65,
    ISR_Vector_U2E,
    ISR_Vector_C1TX = 70,
    ISR_Vector_CTMU = 77,
    ISR_Vector_PWM1 = 94,
    ISR_Vector_PWM2,
    ISR_Vector_PWM3,
    ISR_Vector_ICD = 142,
    ISR_Vector_I2C1 = 173,
    ISR_Vector_SENT1ERR = 182,
    ISR_Vector_SENT1,
    ISR_Vector_SENT2ERR,
    ISR_Vector_SENT2,
    ISR_Vector_ECCSBE,
} dtISR_Vector;

extern void ISR_Enable(dtISR_Vector vector);
extern void ISR_Disable(dtISR_Vector vector);
extern void ISR_ClearFlag(dtISR_Vector vector);
extern void ISR_EnableGlobal(void);
extern void ISR_DisableGlobal(void);

#endif	/* ISR_H */

