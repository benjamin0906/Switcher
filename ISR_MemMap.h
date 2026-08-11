/* 
 * File:   ISR_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 9., 22:14
 */

#ifndef ISR_MEMMAP_H
#define	ISR_MEMMAP_H

#include <stdint.h>

typedef union uINTCON4
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t SGHT:1;
       uint16_t ECCDBE:1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
    } B;
} dtINTCON4;

typedef union uINTREG
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t VECNUM:8;
       uint16_t ILR:3;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
    } B;
} dtINTREG;

typedef union uINTCON1
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t :1;
       uint16_t OSCFAIL:1;
       uint16_t STKERR:1;
       uint16_t ADDRERR:1;
       uint16_t MATHERR:1;
       uint16_t DMACERR:1;
       uint16_t DIV0ERR:1;
       uint16_t SFTACERR:1;
       uint16_t COVTE:1;
       uint16_t OVBTE:1;
       uint16_t OVATE:1;
       uint16_t COVBERR:1;
       uint16_t COVAERR:1;
       uint16_t OVBERR:1;
       uint16_t OVAERR:1;
       uint16_t NSTDIS:1;
    } B;
} dtINTCON1;

typedef union uINTCON2
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t INT0EP:1;
       uint16_t INT1EP:1;
       uint16_t INT2EP:1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t AIVTEN:1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t SWTRAP:1;
       uint16_t DISI:1;
       uint16_t GIE:1;
    } B;
} dtINTCON2;

typedef union uINTCON3
{
    uint16_t U;
    int16_t I;
    struct
    {
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1; 
       uint16_t DOOVR:1;
       uint16_t DAE:1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t :1;
       uint16_t DMT:1;
    } B;
} dtINTCON3;

typedef struct sISR
{
    uint16_t IFS[12];
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t IEC[12];
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t IPC[47];
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    uint16_t :16;
    dtINTCON1 INTCON1;
    dtINTCON2 INTCON2;
    dtINTCON3 INTCON3;
    dtINTCON4 INTCON4;
    dtINTREG INTREG;
} dtISR;

#endif	/* ISR_MEMMAP_H */

