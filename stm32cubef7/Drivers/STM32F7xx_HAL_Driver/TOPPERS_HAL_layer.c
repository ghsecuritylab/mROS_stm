/*
 *  $Id: TOPPERS_HAL_layer.c
 *    Functions to convert STM32 HAL drivers as TOPPERS APIs
 */
#include "stm32f7xx_hal.h"


/**
  * @original_brief: 
  *        This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note call dly_tsk()
  */
void HAL_Delay(uint32_t Delay)
{
  dly_tsk(Delay);
}

