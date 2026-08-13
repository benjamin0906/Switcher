/* 
 * File:   DMA_MemMap.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 13.
 */

#ifndef DMA_MEMMAP_H
#define	DMA_MEMMAP_H

#include <stdint.h>

typedef union uDMAxCON
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t MODE   :2;
        uint16_t        :2;
        uint16_t AMODE  :2;
        uint16_t        :5;
        uint16_t NULLW  :1;
        uint16_t HALF   :1;
        uint16_t DIR    :1;
        uint16_t SIZE   :1;
        uint16_t CHEN   :1;
    } B;
} dtDMAxCON;

typedef union uDMAxREQ
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t IRQSEL :8;
        uint16_t        :7;
        uint16_t FORCE  :1;
    } B;
} dtDMAxREQ;

typedef union uDMAxSTAH
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t STA    :8;
        uint16_t        :8;
    } B;
} dtDMAxSTAH;

typedef union uDMAxSTBH
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t STB    :8;
        uint16_t        :8;
    } B;
} dtDMAxSTBH;

typedef union uDMAxCNT
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t CNT    :14;
        uint16_t        :2;
    } B;
} dtDMAxCNT;

typedef union uDMAPWC
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t PWCOL  :4;
        uint16_t        :12;
    } B;
} dtDMAPWC;

typedef union uDMARQC
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t RQCOL  :4;
        uint16_t        :12;
    } B;
} dtDMARQC;

typedef union uDMAPPS
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t PPST   :4;
        uint16_t        :12;
    } B;
} dtDMAPPS;

typedef union uDMALCA
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t LSTCH  :4;
        uint16_t        :12;
    } B;
} dtDMALCA;

typedef union uDSADRH
{
    uint16_t U;
    int16_t I;
    struct
    {
        uint16_t DSADR  :8;
        uint16_t        :8;
    } B;
} dtDSADRH;

typedef struct sDMA_Channel
{
    dtDMAxCON CON;
    dtDMAxREQ REQ;
    uint16_t STAL;
    dtDMAxSTAH STAH;
    uint16_t STBL;
    dtDMAxSTBH STBH;
    uint16_t PAD;
    dtDMAxCNT CNT;
} dtDMA_Channel;

typedef struct sDMA
{
    dtDMA_Channel CH[4];
    uint16_t RESERVED[88];
    dtDMAPWC DMAPWC;
    dtDMARQC DMARQC;
    dtDMAPPS DMAPPS;
    dtDMALCA DMALCA;
    uint16_t DSADRL;
    dtDSADRH DSADRH;
} dtDMA;

#endif	/* DMA_MEMMAP_H */