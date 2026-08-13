/* 
 * File:   ADC_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 13.
 */

#ifndef ADC_MEMMAP_H
#define	ADC_MEMMAP_H

#include <stdint.h>

typedef union uAD1CON1
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t DONE   :1;
        uint16_t SAMP   :1;
        uint16_t ASAM   :1;
        uint16_t SIMSAM :1;
        uint16_t SSRCG  :1;
        uint16_t SSRC   :3;
        uint16_t FORM   :2;
        uint16_t AD12B  :1;
        uint16_t        :1;
        uint16_t ADDMABM:1;
        uint16_t ADSIDL :1;
        uint16_t        :1;
        uint16_t ADON   :1;
    } B;
} dtAD1CON1;

typedef union uAD1CON2
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t ALTS   :1;
        uint16_t BUFM   :1;
        uint16_t SMPI   :5;
        uint16_t BUFS   :1;
        uint16_t CHPS   :2;
        uint16_t CSCNA  :1;
        uint16_t        :2;
        uint16_t VCFG   :3;
    } B;
} dtAD1CON2;

typedef union uAD1CON3
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t ADCS   :8;
        uint16_t SAMC   :5;
        uint16_t        :2;
        uint16_t ADRC   :1;
    } B;
} dtAD1CON3;

typedef union uAD1CHS123
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CH123SA0:1;
        uint16_t CH123NA:2;
        uint16_t CH123SA :2;
        uint16_t        :3;
        uint16_t CH123SB0:1;
        uint16_t CH123NB:2;
        uint16_t CH123SB :2;
        uint16_t        :3;
    } B;
} dtAD1CHS123;

typedef union uAD1CHS0
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CH0SA  :6;
        uint16_t        :1;
        uint16_t CH0NA  :1;
        uint16_t CH0SB  :6;
        uint16_t        :1;
        uint16_t CH0NB  :1;
    } B;
} dtAD1CHS0;

typedef union uAD1CSSH
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CSS19_16:4;
        uint16_t         :4;
        uint16_t CSS31_24:8;
    } B;
} dtAD1CSSH;

typedef union uAD1CSSL
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CSS    :16;
    } B;
} dtAD1CSSL;

typedef union uAD1CON4
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t DMABL  :3;
        uint16_t        :5;
        uint16_t ADDMAEN:1;
        uint16_t        :7;
    } B;
} dtAD1CON4;

typedef struct sADC1
{
    uint16_t ADC1BUF[16];
    dtAD1CON1 AD1CON1;
    dtAD1CON2 AD1CON2;
    dtAD1CON3 AD1CON3;
    dtAD1CHS123 AD1CHS123;
    dtAD1CHS0 AD1CHS0;
    uint16_t RESERVED[2];
    dtAD1CSSH AD1CSSH;
    dtAD1CSSL AD1CSSL;
    dtAD1CON4 AD1CON4;
} dtADC1;

#endif	/* ADC_MEMMAP_H */