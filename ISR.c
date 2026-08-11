#include "MemMap.h"
#include "ISR.h"

void ISR_Enable(dtISR_Vector vector)
{
    uint8_t reg_id = vector >> 4;
    uint16_t mask = 1 << (vector - (reg_id << 4));
    ISR->IEC[reg_id] |= mask;
}

void ISR_Disable(dtISR_Vector vector)
{
    uint8_t reg_id = vector >> 4;
    uint16_t mask = ~(1 << (vector - (reg_id << 4)));
    ISR->IEC[reg_id] &= mask;
}

void ISR_ClearFlag(dtISR_Vector vector)
{
    uint8_t reg_id = vector >> 4;
    uint16_t mask = ~(1 << (vector - (reg_id << 4)));
    ISR->IFS[reg_id] &= mask;
}

void ISR_EnableGlobal(void)
{
    ISR->INTCON2.B.GIE = 1;
}

void ISR_DisableGlobal(void)
{
    ISR->INTCON2.B.GIE = 0;
}
