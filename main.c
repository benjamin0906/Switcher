/* 
 * File:   main.c
 * Author: Benjamin
 *
 * Created on 2026. augusztus 8., 15:48
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "GPIO.h"
#include "ISR.h"
#include "Timer1.h"
#include "SC.h"
#include "PWM.h"

#pragma config FCKSM = CSECME           // Clock Switching Mode Bits (Both Clock Switching and Fail-safe Clock Monitor are enabled)
#pragma config IOL1WAY = OFF

void Timer1_Handler(void)
{
    if(Gpio_Get(GPIO_PB8) == 0)
    {
        Gpio_Set(GPIO_PB8, 1);
    }
    else
    {
        Gpio_Set(GPIO_PB8, 0);
    }
    ISR_ClearFlag(ISR_Vector_T1);
}

/*
 * 
 */
int main(void)
{
    volatile uint8_t i;
    volatile uint8_t j;
    dtGpioConfig test_pin1 = {.Gpio_Id = GPIO_PB8, .Gpio_Pull = PullCfg_None, .Mode = GpioMode_Output};
    dtGpioConfig test_pin2 = {.Gpio_Id = GPIO_PB9, .Gpio_Pull = PullCfg_None, .Mode = GpioMode_Output};
    dtGpioConfig test_pin3 = {.Gpio_Id = GPIO_PA0, .Gpio_Pull = PullCfg_None, .Mode = GpioMode_Analog};
    dtT1_Cfg T1_Cfg = {.ExtClk = 0, .On = 1, .StopInIdle = 1, .Presc = T1_Presc_8, .Handler = Timer1_Handler, .Period = 8749};
    dtClockConfig ClockCfg = {.ClockSrc = ClockSrc_FRC_DivN_PLL, .DOZEN = 0, .FRCDIV = 0, .PLLPOST = 0, .PLLPRE = 0, .PLLDIV = 74};
    dtGen GenCfg = {.MasterDuty = 1, .PWMxH_EN = 1, .PWMxH_POL = 0, .PWMxL_EN = 0, .PWMxL_POL = 0, .Trigger = 0, .Duty = 1000, .Phase = 0};
    dtPWM_Cfg PWM_Cfg = {.SpecialCmp = 0, .PrimaryPeriod = 8749, .Presc = PWM_Presc_8, .MasterDuty = 100, .Generators = {&GenCfg, 0, 0}};
    
    SC_ClockConfig(&ClockCfg);
    
    Gpio_Config(&test_pin1);
    Gpio_Config(&test_pin2);
    
    T1_Config(&T1_Cfg);
    
    ISR_Enable(ISR_Vector_T1);
    ISR_EnableGlobal();
    
    PWM_Config(&PWM_Cfg);
    
    ADC_Init();
    
    while(1)
    {
        Gpio_Set(GPIO_PB9, 1);
        for(j = 0; j < 250; j++) for(i = 0; i < 250; i++);
        Gpio_Set(GPIO_PB9, 0);
        for(j = 0; j < 250; j++) for(i = 0; i < 250; i++);
    }
    return (EXIT_SUCCESS);
}

