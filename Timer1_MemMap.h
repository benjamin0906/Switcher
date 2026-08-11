/* 
 * File:   Timer1_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 9., 21:55
 */

#ifndef TIMER1_MEMMAP_H
#define	TIMER1_MEMMAP_H

typedef union
{
    uint16_t U;
    int16_t  I;
    struct
    {
        uint16_t        :1;
        uint16_t TCS    :1;
        uint16_t TSYNC  :1;
        uint16_t        :1;
        uint16_t TCKPS  :2;
        uint16_t TGATE  :1;
        uint16_t        :1;
        uint16_t        :1;
        uint16_t        :1;
        uint16_t        :1;
        uint16_t        :1;
        uint16_t        :1;
        uint16_t TSIDL  :1;
        uint16_t        :1;
        uint16_t TON    :1;
    } B;
} dtT1CON;

typedef struct sT1
{
    uint16_t TMR;
    uint16_t PR;
    dtT1CON T1CON;
} dtT1;

#endif	/* TIMER1_MEMMAP_H */

