/* 
 * File:   GPIO.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 12:30
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        GPIO_PA0    = 0x00,
        GPIO_PA1    = 0x01,
        GPIO_PA2    = 0x02,
        GPIO_PA3    = 0x03,
        GPIO_PA4    = 0x04,
        GPIO_PA5    = 0x05,
        GPIO_PA6    = 0x06,
        GPIO_PA7    = 0x07,

        GPIO_PB0    = 0x10,
        GPIO_PB1    = 0x11,
        GPIO_PB2    = 0x12,
        GPIO_PB3    = 0x13,
        GPIO_PB5    = 0x15,
        GPIO_PB6    = 0x16,
        GPIO_PB7    = 0x17,
        GPIO_PB8    = 0x18,
        GPIO_PB9    = 0x19,
        
        GPIO_PC0    = 0x20,
        GPIO_PC1    = 0x21,
        GPIO_PC2    = 0x22,
        GPIO_PC3    = 0x23,
        GPIO_PC4    = 0x24,
        GPIO_PC5    = 0x25,
        GPIO_PC6    = 0x26,
        GPIO_PC7    = 0x27,
                
        GPIO_PD0    = 0x30,
        GPIO_PD1    = 0x31,
        GPIO_PD2    = 0x32,
        GPIO_PD3    = 0x33,
        GPIO_PD4    = 0x34,
        GPIO_PD5    = 0x35,
        GPIO_PD6    = 0x36,
        GPIO_PD7    = 0x37,
                
        GPIO_PE0    = 0x40,
        GPIO_PE1    = 0x41,
        GPIO_PE2    = 0x42,
        GPIO_PE3    = 0x43,
        GPIO_PE4    = 0x44,
        GPIO_PE5    = 0x45,
        GPIO_PE6    = 0x46,
        GPIO_PE7    = 0x47,
    } dtGPIO_Pins;
    
    typedef enum ePullCfg
    {
        PullCfg_None,
        PullCfg_Up,
        PullCfg_Down,
        PullCfg_Both,
    } dtPullCfg;
    typedef enum eGpioMode
    {
        GpioMode_Input,
        GpioMode_Output,
        GpioMode_Output_OC,
        GpioMode_Analog,
    } dtGpioMode;
    
    typedef struct sGpioConfig
    {
        dtGPIO_Pins Gpio_Id;
        dtPullCfg   Gpio_Pull;
        dtGpioMode  Mode;
    } dtGpioConfig;
    
    extern void Gpio_Config(const dtGpioConfig *const cfg);
    extern void Gpio_Set(dtGPIO_Pins pin, uint8_t value);
#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

