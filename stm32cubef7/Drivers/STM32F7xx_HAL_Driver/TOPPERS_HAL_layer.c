/*
 *  $Id: TOPPERS_HAL_layer.c
 *    Functions to convert STM32 HAL drivers as TOPPERS APIs
 */
#include "stm32f7xx_hal.h"


/**
  * @ORIGINAL COMMENT:
  *
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @param Delay  specifies the delay time length, in milliseconds.
  * @retval None
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief call TOPPERS dly_tsk()
  */
void HAL_Delay(uint32_t Delay)
{
  dly_tsk(Delay);
}



/*
 * Copied from stm32f7xx_hal_cortex.c
 */

/**
  * @ORIGINAL COMMENT:
  *
  * @brief  Sets the priority grouping field (preemption priority and subpriority)
  *         using the required unlock sequence.
  * @param  PriorityGroup The priority grouping bits length. 
  *         This parameter can be one of the following values:
  *         @arg NVIC_PRIORITYGROUP_0: 0 bits for preemption priority
  *                                    4 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_1: 1 bits for preemption priority
  *                                    3 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_2: 2 bits for preemption priority
  *                                    2 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_3: 3 bits for preemption priority
  *                                    1 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_4: 4 bits for preemption priority
  *                                    0 bits for subpriority
  * @note   When the NVIC_PriorityGroup_0 is selected, IRQ preemption is no more possible. 
  *         The pending IRQ priority will be managed only by the subpriority. 
  * @retval None
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief  none (TOPPERS initializes interrupt statically by .cfg)
  */
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
#if 0
  /* Check the parameters */
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
  
  /* Set the PRIGROUP[10:8] bits according to the PriorityGroup parameter value */
  NVIC_SetPriorityGrouping(PriorityGroup);
#endif
}

/**
  * @ORIGINAL COMMENT:
  *
  * @brief  Sets the priority of an interrupt.
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32f7xxxx.h))
  * @param  PreemptPriority The preemption priority for the IRQn channel.
  *         This parameter can be a value between 0 and 15
  *         A lower priority value indicates a higher priority 
  * @param  SubPriority the subpriority level for the IRQ channel.
  *         This parameter can be a value between 0 and 15
  *         A lower priority value indicates a higher priority.          
  * @retval None
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief  none (TOPPERS initializes interrupt statically by .cfg)
  */
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{ 
#if 0
  uint32_t prioritygroup = 0x00;
  
  /* Check the parameters */
  assert_param(IS_NVIC_SUB_PRIORITY(SubPriority));
  assert_param(IS_NVIC_PREEMPTION_PRIORITY(PreemptPriority));
  
  prioritygroup = NVIC_GetPriorityGrouping();
  
  NVIC_SetPriority(IRQn, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
#endif
}

/**
  * @ORIGINAL COMMENT:
  *
  * @brief  Enables a device specific interrupt in the NVIC interrupt controller.
  * @note   To configure interrupts priority correctly, the NVIC_PriorityGroupConfig()
  *         function should be called before. 
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32f7xxxx.h))
  * @retval None
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief  call TOPPERS ena_int()
  */
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
#if 0
  /* Check the parameters */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
  /* Enable interrupt */
  NVIC_EnableIRQ(IRQn);
#endif
  ena_int(IRQn);
}

/**
  * @ORIGINAL COMMENT:
  *
  * @brief  Disables a device specific interrupt in the NVIC interrupt controller.
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32f7xxxx.h))
  * @retval None
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief  call TOPPERS dis_int()
  */
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
#if 0
  /* Check the parameters */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
  /* Disable interrupt */
  NVIC_DisableIRQ(IRQn);
#endif
  dis_int(IRQn);
}

/**
  * @ORIGINAL COMMENT:
  *
  * @brief  Initializes the System Timer and its interrupt, and starts the System Tick Timer.
  *         Counter is in free running mode to generate periodic interrupts.
  * @param  TicksNumb Specifies the ticks Number of ticks between two interrupts.
  * @retval status:  - 0  Function succeeded.
  *                  - 1  Function failed.
  *
  *
  * @INTEGRATION METHOD:
  *
  * @brief  none (TOPPERS uses target_timer as SysTickTimer)
  */
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
#if 0
   return SysTick_Config(TicksNumb);
#endif
}

