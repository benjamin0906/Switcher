/* 
 * File:   PWM_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 10., 16:26
 */

#ifndef PWM_MEMMAP_H
#define	PWM_MEMMAP_H

#include <stdint.h>

typedef union uPTCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t SEVTPS :4;
        uint16_t SYNCSRC:3;
        uint16_t SYNCEN :1;
        uint16_t SYNCOEN:1;
        uint16_t SYNCPOL:1;
        uint16_t EIPU   :1;
        uint16_t SEIEN  :1;
        uint16_t SESTAT :1;
        uint16_t PTSIDL :1;
        uint16_t        :1;
        uint16_t PTEN   :1;
    } B;
} dtPTCON;

typedef union uPTCON2
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t PCLKDIV:3;
        uint16_t        :13;
    } B;
} dtPTCON2;

typedef union uCHOP
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CHOPCLK    :10;
        uint16_t            :5;
        uint16_t CHPCLKEN   :1;
    } B;
} dtCHOP;

typedef union uPWMCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t IUE    :1;
        uint16_t XPRES  :1;
        uint16_t CAM    :1;
        uint16_t        :2;
        uint16_t DTCP   :1;
        uint16_t DTC    :2;
        uint16_t MDCS   :1;
        uint16_t ITB    :1;
        uint16_t TRGIEN :1;
        uint16_t CLIEN  :1;
        uint16_t FLTIEN :1;
        uint16_t TRGSTAT:1;
        uint16_t CLSTAT :1;
        uint16_t FLTSTAT:1;
    } B;
} dtPWMCON;

typedef union uIOCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t OSYNC  :1;
        uint16_t SWAP   :1;
        uint16_t CLDAT  :2;
        uint16_t FLTDAT :2;
        uint16_t OVRDAT :2;
        uint16_t OVRENL :1;
        uint16_t OVRENH :1;
        uint16_t PMOD   :2;
        uint16_t POLL   :1;
        uint16_t POLH   :1;
        uint16_t PENL   :1;
        uint16_t PENH   :1;
    } B;
} dtIOCON;

typedef union uFCLCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t FLTMOD :2;
        uint16_t FLTPOL :1;
        uint16_t FLTSRC :5;
        uint16_t CLMOD  :1;
        uint16_t CLPOL  :1;
        uint16_t CLSRC  :5;
        uint16_t        :1;
    } B;
} dtFCLCON;

typedef union uDTR
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t DTR1   :14;
        uint16_t        :2;
    } B;
} dtDTR;

typedef union uALTDTR
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t ALTDTR1    :14;
        uint16_t            :2;
    } B;
} dtALTDTR;

typedef union uTRGCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t TRGSTRT    :6;
        uint16_t            :6;
        uint16_t TRGDIV     :4;
    } B;
} dtTRGCON;

typedef union uLEBCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t BPLL   :1;
        uint16_t BPLH   :1;
        uint16_t BPHL   :1;
        uint16_t BPHH   :1;
        uint16_t BCL    :1;
        uint16_t BCH    :1;
        uint16_t        :4;
        uint16_t CLLEBEN:1;
        uint16_t FLTLEBEN:1;
        uint16_t PLF    :1;
        uint16_t PLR    :1;
        uint16_t PHF    :1;
        uint16_t PHR    :1;
    } B;
} dtLEBCON;

typedef union uLEBDLY
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t LEB    :12;
        uint16_t        :4;
    } B;
} dtLEBDLY;

typedef union uAUXCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CHOPLEN    :1;
        uint16_t CHOPHEN    :1;
        uint16_t CHOPSEL    :4;
        uint16_t            :2;
        uint16_t  BLANKSEL  :4;
        uint16_t            :4;
    } B;
} dtAUXCON;

typedef struct sPWM_GEN
{
    dtPWMCON PWMCON;
    dtIOCON IOCON;
    dtFCLCON FCLCON;
    uint16_t PDC;
    uint16_t PHASE;
    dtDTR DTR;
    dtALTDTR ALTDTR;
    uint16_t TRIG;
    dtTRGCON TRGCON;
    uint16_t PWMCAP;
    dtLEBCON LEBCON;
    dtLEBDLY LEBDLY;
    dtAUXCON AUXCON;
}dtPWM_GEN;

typedef struct sPWM
{
    dtPTCON PTCON;
    dtPTCON2 PTCON2;
    uint16_t PTPER;
    uint16_t SEVTCMP;
    uint16_t MDC;
    dtCHOP CHOP;
    uint16_t PWMKEY;
    dtPWM_GEN GEN[3];
} dtPWM;


#endif	/* PWM_MEMMAP_H */

