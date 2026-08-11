/* 
 * File:   SC.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 10., 11:02
 */

#ifndef SC_H
#define	SC_H

typedef enum eClockSrc
{
    ClockSrc_FRC,
            ClockSrc_FRC_DivN_PLL,
            ClockSrc_Primary,
            ClockSrc_Primary_PLL,
            ClockSrc_Reserved_Backup,
            ClockSrc_LPRC,
            ClockSrc_FRC_Div16,
            ClockSrc_FRC_DivN,
} dtClockSrc;

typedef struct sClockConfig
{
    dtClockSrc ClockSrc;
    uint16_t DOZE:3;
    uint16_t DOZEN:1;
    uint16_t FRCDIV:3;
    uint16_t PLLPOST:2;
    uint16_t PLLPRE:5;
    uint16_t PLLDIV:9;
} dtClockConfig;

extern void SC_ClockConfig(const dtClockConfig *const cfg);

#endif	/* SC_H */

