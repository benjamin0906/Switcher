/* 
 * File:   PWM.h
 * Author: Benjamin
 *
 * Created on 2026. augusztus 10., 16:49
 */

#ifndef PWM_H
#define	PWM_H

#include <stdint.h>

typedef enum ePWM_Presc
{
    PWM_Presc_1,
    PWM_Presc_2,
    PWM_Presc_4,
    PWM_Presc_8,
    PWM_Presc_16,
    PWM_Presc_32,
    PWM_Presc_64,
} dtPWM_Presc;

typedef struct sGen
{
    uint16_t Phase;
    uint16_t Duty;
    uint16_t Trigger;
    uint16_t MasterDuty :1;
    uint16_t PWMxH_EN   :1;
    uint16_t PWMxL_EN   :1;
    uint16_t PWMxH_POL  :1;
    uint16_t PWMxL_POL  :1;
} dtGen;

typedef struct sPWM_Cfg
{
    dtPWM_Presc Presc;
    uint16_t PrimaryPeriod;
    uint16_t MasterDuty;
    uint16_t SpecialCmp;
    dtGen *Generators[3];
} dtPWM_Cfg;

extern void PWM_Config(const dtPWM_Cfg *const cfg);

#endif	/* PWM_H */

