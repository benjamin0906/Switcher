/* 
 * File:   MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 13:02
 */

#ifndef MEMMAP_H
#define	MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "GPIO_MemMap.h"
#include "Timer1_MemMap.h"
#include "ISR_MemMap.h"
#include "SC_MemMap.h"
#include "PWM_MemMap.h"
    
extern dtGPIO_Ports * const Ports;
extern dtT1 *const T1;
extern dtISR *const ISR;
extern dtSC *const SC;
extern dtPWM *const PWM;

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMAP_H */

