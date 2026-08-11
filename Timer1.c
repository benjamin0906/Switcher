#include "MemMap.h"
#include "Timer1.h"

static void (*Isr)(void);

void T1_Config(const dtT1_Cfg *const cfg)
{
    dtT1CON tT1CON = {.U = 0};
    T1->T1CON.U = 0;
    T1->TMR = 0;
    T1->PR = 0;
    
    Isr = cfg->Handler;
    T1->PR = cfg->Period;
    tT1CON.B.TCKPS = cfg->Presc;
    tT1CON.B.TSIDL = cfg->StopInIdle;
    tT1CON.B.TCS = cfg->ExtClk;
    tT1CON.B.TON = cfg->On;
    
    T1->T1CON = tT1CON;
}

void __attribute__((interrupt)) _T1Interrupt(void)
{
    if(Isr != 0)
    {
        Isr();
    }
}