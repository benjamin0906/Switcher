#include "MemMap.h"
#include "GPIO.h"

void Gpio_Config(const dtGpioConfig *const cfg)
{
    uint8_t port_id = cfg->Gpio_Id >> 4;
    uint16_t pin_mask = 1 << (cfg->Gpio_Id & 0x0F);
    uint16_t pin_mask_clear = ~pin_mask;
    dtGPIO_PortDef *ptr = &Ports->PortDesc[port_id];
    
    ptr->ANS.U &= pin_mask_clear;
    if(cfg->Mode == GpioMode_Analog)
    {
        ptr->ANS.U |= pin_mask;
    }
    else
    {
        if(cfg->Mode == GpioMode_Input)
        {
            ptr->TRIS.U |= pin_mask;
        }
        else
        {
            ptr->TRIS.U &= pin_mask_clear;
            ptr->ODC.U &= pin_mask_clear;
            if(cfg->Mode == GpioMode_Output_OC)
            {
                ptr->ODC.U |= pin_mask;
            }
        }
    }
    
    ptr->CNPD.U &= pin_mask_clear;
    ptr->CNPU.U &= pin_mask_clear;
    if((cfg->Gpio_Pull != PullCfg_Down) || (cfg->Gpio_Pull == PullCfg_Both))
    {
        ptr->CNPD.U |= pin_mask;
    }
    
    if((cfg->Gpio_Pull == PullCfg_Up) || (cfg->Gpio_Pull == PullCfg_Both))
    {
        ptr->CNPU.U |= pin_mask;
    }
}

void Gpio_Set(dtGPIO_Pins pin, uint8_t value)
{
    uint8_t port_id = pin >> 4;
    uint16_t pin_mask;
    uint16_t pin_mask_clear;
    dtGPIO_PortDef *ptr = &Ports->PortDesc[port_id];
    
    pin_mask = (value != 0) << (pin & 0x0F);
    pin_mask_clear = ~((value == 0) << (pin & 0x0F));
    
    ptr->LAT.U &= pin_mask_clear;
    ptr->LAT.U |= pin_mask;
}

uint8_t Gpio_Get(dtGPIO_Pins pin)
{
    uint8_t port_id = pin >> 4;
    uint16_t pin_mask = 1 << (pin & 0x0F);
    dtGPIO_PortDef *ptr = &Ports->PortDesc[port_id];
    
    return (ptr->PORT.U & pin_mask) != 0;
}