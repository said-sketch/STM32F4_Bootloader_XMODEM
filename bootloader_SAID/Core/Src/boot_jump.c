/*
 * boot_jump.c
 *
 *  Created on: Feb 10, 2026
 *      Author: HP
 */


#include "boot_jump.h"
#include "stm32f4xx_hal.h"

typedef void (*pFunction)(void);

typedef void(*pFunction)(void);

void Boot_JumpToApplication(uint32_t app_address)
{
    //uint32_t app_stack = *(__IO uint32_t*) app_address;
    uint32_t app_reset = *(__IO uint32_t*) (app_address + 4);

    // sanity check
   /* if ((app_stack & 0x2FFE0000) != 0x20000000)
   /{
        UART_SendBuffer((uint8_t*)"INVALID APP\r\n", 14);
        return;
    } */

    __disable_irq();
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL  = 0;

    //__set_MSP(app_stack);
    SCB->VTOR = app_address;

    __DSB();
    __DMB();
    __ISB();

    pFunction app_entry = (pFunction)app_reset;
    app_entry(); // jump
}


