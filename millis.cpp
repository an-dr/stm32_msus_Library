/*
 * @file millis.cpp
 *
 * @breaf millis.cpp
 * 
 * @date Jan 6, 2019
 * @author Andrey Gramakov
 */

#include "millis.h"


volatile uint32_t millis_var;

bool millis_Init(void)
{
    if (!SysTick_Config(SystemCoreClock / 1000)) //1ms per interrupt
    {
        return false;
    }

    //set systick interrupt priority
    // TODO add preprocessor for NVIC_PriorityGroupConfig
    //    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);    //4 bits for preemp priority 0 bit for sub priority
    NVIC_SetPriority(SysTick_IRQn, 0); //i want to make sure systick has highest priority amount all other interrupts
    millis_var = 0; //reset
    return true;
}

uint32_t millis(void)
{
    return millis_var;
}

uint32_t micros(void)
{
    uint32_t ms = (millis_var * 1000) +
                  (1000 - SysTick->VAL / (SystemCoreClock / 1000000));
    return ms;

}

void millisInc()
{
    millis_var++;
}
