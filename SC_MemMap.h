/* 
 * File:   Osc_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 10., 10:49
 */

#ifndef OSC_MEMMAP_H
#define	OSC_MEMMAP_H

#include <stdint.h>

typedef union uRCON
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t POR     :1;
       uint16_t BOR     :1;
       uint16_t IDLE    :1;
       uint16_t SLEEP   :1;
       uint16_t WDTO    :1;
       uint16_t SWDTEN  :1;
       uint16_t SWR     :1;
       uint16_t EXTR    :1;
       uint16_t VREGS   :1;
       uint16_t CM      :1;
       uint16_t         :1;
       uint16_t VREGSF  :1;
       uint16_t         :1;
       uint16_t         :1;
       uint16_t IOPUWR  :1;
       uint16_t TRAPR   :1;
    } B;
} dtRCON;

typedef union uOSCCON
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t OSWEN   :1;
       uint16_t         :1;
       uint16_t         :1;
       uint16_t CF      :1;
       uint16_t         :1;
       uint16_t LOCK    :1;
       uint16_t IOLOCK  :1;
       uint16_t CLKLOCK :1;
       uint16_t NOSC    :3;
       uint16_t :1;
       uint16_t COSC    :3;
       uint16_t :1;
    } B;
} dtOSCCON;

typedef union uCLKDIV
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t PLLPRE  :5;
       uint16_t         :1;
       uint16_t PLLPOST :2;
       uint16_t FRCDIV  :3;
       uint16_t DOZEN   :1;
       uint16_t DOZE    :3;
       uint16_t ROI     :1;
    } B;
} dtCLKDIV;

typedef union uPLLFBD
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t PLLDIV  :9;
       uint16_t         :7;
    } B;
} dtPLLFBD;

typedef union uOSCTUN
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t TUN :6;
       uint16_t     :10;
    } B;
} dtOSCTUN;

typedef struct sSC
{
    dtRCON RCON;
    dtOSCCON OSCCON;
    dtCLKDIV CLKDIV;
    dtPLLFBD PLLFBD;
    dtOSCTUN OSCTUN;
} dtSC;

#endif	/* OSC_MEMMAP_H */

