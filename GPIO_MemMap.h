/* 
 * File:   GPIO_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 10., 19:55
 */

#ifndef GPIO_MEMMAP_H
#define	GPIO_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

    typedef union
    {
        uint16_t U;
        int16_t  I;
        struct
        {
            uint16_t PIN_0    :1;
            uint16_t PIN_1    :1;
            uint16_t PIN_2    :1;
            uint16_t PIN_3    :1;
            uint16_t PIN_4    :1;
            uint16_t PIN_5    :1;
            uint16_t PIN_6    :1;
            uint16_t PIN_7    :1;
            uint16_t PIN_8    :1;
            uint16_t PIN_9    :1;
            uint16_t PIN_10    :1;
            uint16_t PIN_11    :1;
            uint16_t PIN_12    :1;
            uint16_t PIN_13    :1;
            uint16_t PIN_14    :1;
            uint16_t PIN_15    :1;
        } B;
    } dtGPIO_PinDef;
    
    
    typedef struct
    {
        /*dtGPIO_PinDef   SR0;
        dtGPIO_PinDef   SR1;
        dtGPIO_PinDef   ANS;
        dtGPIO_PinDef   CNPD;
        dtGPIO_PinDef   CNPU;
        dtGPIO_PinDef   CNEN;
        dtGPIO_PinDef   ODC;
        dtGPIO_PinDef   LAT;
        dtGPIO_PinDef   PORT;
        dtGPIO_PinDef   TRIS;*/
        dtGPIO_PinDef   TRIS;//direction
        dtGPIO_PinDef   PORT;//input
        dtGPIO_PinDef   LAT;//output
        dtGPIO_PinDef   ODC;
        dtGPIO_PinDef   CNEN;
        dtGPIO_PinDef   CNPU;//pull up
        dtGPIO_PinDef   CNPD;//pull down
        dtGPIO_PinDef   ANS;//analog
        dtGPIO_PinDef   SR1;//slew rate 1
        dtGPIO_PinDef   SR0;//slew rate 0
    } dtGPIO_PortDef;
    
    typedef struct
    {
        dtGPIO_PortDef PortDesc[7];
    } dtGPIO_Ports;

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_MEMMAP_H */

