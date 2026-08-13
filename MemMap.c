#include "MemMap.h"

dtGPIO_Ports    *const Ports    = (dtGPIO_Ports*)   0x0E00;
dtT1            *const T1       = (dtT1*)           0x0100;
dtISR           *const ISR      = (dtISR*)          0x0800;
dtSC            *const SC       = (dtSC*)           0x0740;
dtPWM           *const PWM      = (dtPWM*)          0x0C00;
dtADC1          *const ADC1     = (dtADC1*)         0x0300;
dtDMA           *const DMA      = (dtDMA*)          0x0B00;