/*
 * BSP_PB の割込みラインは EXTI15_10 に接続されている
 */
//./Drivers/CMSIS/Device/ST/STM32F7xx/Include/stm32f767xx.h:117:
//EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
/* 
 *  ExternalLine[15:10]割込みハンドラ登録のための定数
 */
#define INHNO_EXTI15_10     40+16    /* 割込みハンドラ番号 */
#define INTNO_EXTI15_10     40+16    /* 割込み番号 */
#define INTPRI_EXTI15_10    (-15) /* 割込み優先度 */
#define INTATR_EXTI15_10    0U    /* 割込み属性 */

