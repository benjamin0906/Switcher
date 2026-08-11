#include "MemMap.h"
#include "PWM.h"

static void Set_IOCON(dtIOCON value, uint8_t gen_id)
{
    PWM->PWMKEY = 0xabcd;
    PWM->PWMKEY = 0x4321;
    PWM->GEN[gen_id].IOCON = value;
}

void PWM_Config(const dtPWM_Cfg *const cfg)
{
    uint8_t i;
    PWM->PTCON.U = 0;
    PWM->PTCON2.U = 0;
    
    PWM->PTCON2.B.PCLKDIV = cfg->Presc;
    PWM->PTPER = cfg->PrimaryPeriod;
    PWM->SEVTCMP = cfg->SpecialCmp;
    PWM->MDC = cfg->MasterDuty;
    PWM->CHOP.U = 0;
    
    for(i = 0; i < 3; i++)
    {
        if(cfg->Generators[i] != 0)
        {
            dtIOCON tIOCON = {.U = 0};
            
            PWM->GEN[i].PWMCON.U = 0;
            PWM->GEN[i].PWMCON.B.MDCS = cfg->Generators[i]->MasterDuty;
            
            PWM->GEN[i].PDC = cfg->Generators[i]->Duty;
            PWM->GEN[i].PHASE = cfg->Generators[i]->Phase;
            PWM->GEN[i].TRIG = cfg->Generators[i]->Trigger;
            
            tIOCON.B.PENH = cfg->Generators[i]->PWMxH_EN;
            tIOCON.B.PENL = cfg->Generators[i]->PWMxL_EN;
            tIOCON.B.POLH = cfg->Generators[i]->PWMxH_POL;
            tIOCON.B.POLL = cfg->Generators[i]->PWMxL_POL;
            
            Set_IOCON(tIOCON, i);
        }
    }
    PWM->PTCON.B.PTEN = 1;
}