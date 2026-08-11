#include "MemMap.h"

dtGPIO_Ports    *const Ports    = (dtGPIO_Ports*)   0x0E00;
dtT1            *const T1       = (dtT1*)           0x0100;
dtISR           *const ISR      = (dtISR*)          0x0800;
dtSC            *const SC       = (dtSC*)           0x0740;
dtPWM           *const PWM      = (dtPWM*)          0x0C00;