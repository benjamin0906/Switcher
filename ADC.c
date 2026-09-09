#include "MemMap.h"

void ADC_Init()
{
    uint16_t result = 0x0000;
    uint8_t i = 0;
    
    ADC1->AD1CON1.U = 0;
    ADC1->AD1CON2.U = 0;
    ADC1->AD1CON3.U = 0;
    ADC1->AD1CON4.U = 0;
    
    ADC1->AD1CON1.B.FORM = 0;
    ADC1->AD1CON1.B.AD12B = 1;
    
    ADC1->AD1CON1.B.SSRCG = 0;
    ADC1->AD1CON1.B.SSRC = 0x7;
    
    ADC1->AD1CON1.B.ASAM = 0;
    
    ADC1->AD1CON2.B.VCFG = 0;
    ADC1->AD1CON2.B.SMPI = 0;
    
    ADC1->AD1CON3.B.ADRC = 0;
    ADC1->AD1CON3.B.SAMC = 0x1F;
    ADC1->AD1CON3.B.ADCS = 0xFF;
    
    ADC1->AD1CON4.U = 0;
    ADC1->AD1CON1.B.ADON = 1;
    
    for(i = 0; i<50; i++)
    {
        ADC1->AD1CON1.B.SAMP = 1;
    
        while(ADC1->AD1CON1.B.DONE == 0);
        result = ADC1->ADC1BUF[0];
    }
}

void __attribute__((interrupt)) _AD1Interrupt(void)
{
    
}