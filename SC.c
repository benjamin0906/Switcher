#include "MemMap.h"
#include "SC.h"

static void write_osccon(dtOSCCON value)
{
    __asm__("push w2 \n"
            "push w3 \n"
            "push w4 \n"
            "mov %0, W0 \n"
            "mov %1, W1 \n"
            "mov %2, w4 \n"
            "mov #0x78, W2 \n"
            "mov #0x9a, W3 \n"
            "mov.b W2, [W1+1] \n"
            "mov.b W3, [W1+1] \n"
            "mov.b w0, [w1+1] \n"
            "mov.b #0x46, W2 \n"
            "mov.b #0x57, W3 \n"
            
            "mov.b W2, [W1] \n"
            "mov.b W3, [W1] \n"
            "mov.b w4, [w1] \n"
            "pop w4 \n"
            "pop w3 \n"
            "pop w2 \n"
            ::"r"(value.U >> 8), "r"(&SC->OSCCON.U), "r"(value.U & 0xFF));
}

void SC_ClockConfig(const dtClockConfig *const cfg)
{
    dtOSCCON tOSCCON = {.U = 0};
    if(cfg->DOZEN != 0)
    {
        SC->CLKDIV.B.DOZE = cfg->DOZE;
    }
    SC->CLKDIV.B.DOZEN = cfg->DOZEN;
    
    if(cfg->ClockSrc == ClockSrc_FRC_DivN && cfg->ClockSrc == ClockSrc_FRC_DivN_PLL)
    {
        SC->CLKDIV.B.FRCDIV = cfg->FRCDIV;    
    }
    if((cfg->ClockSrc == ClockSrc_FRC_DivN_PLL) || (cfg->ClockSrc == ClockSrc_Primary_PLL))
    {
        SC->CLKDIV.B.PLLPRE = cfg->PLLPRE;
        SC->CLKDIV.B.PLLPOST = cfg->PLLPOST;
        SC->PLLFBD.B.PLLDIV = cfg->PLLDIV;
    }
    
    tOSCCON.B.NOSC = cfg->ClockSrc;
    tOSCCON.B.OSWEN = 1;
    write_osccon(tOSCCON);
    while(SC->OSCCON.B.COSC != cfg->ClockSrc);
    while(((cfg->ClockSrc == ClockSrc_FRC_DivN_PLL) || (cfg->ClockSrc == ClockSrc_Primary_PLL)) && (SC->OSCCON.B.LOCK == 0));
}