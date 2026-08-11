/* 
 * File:   Timer1.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 9., 21:55
 */

#ifndef TIMER1_H
#define	TIMER1_H

#include <stdint.h>

typedef enum eT1_Presc
{
    T1_Presc_1,
    T1_Presc_8,
    T1_Presc_64,
    T1_Presc_256,
} dtT1_Presc;

typedef struct sT1_Cfg
{
    uint16_t On :1;
    uint16_t StopInIdle :1;
    uint16_t ExtClk :1;
    dtT1_Presc Presc;
    void (*Handler)(void);
    uint16_t Period; //Period + 1 cycles
} dtT1_Cfg;

#endif	/* TIMER1_H */

