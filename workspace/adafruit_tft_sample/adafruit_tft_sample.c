/*
 *  $Id: adafruit_tft_sample.c
 */

/*
 *  ボード上のPushSWによりLED2の表示間隔を変更させる
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "adafruit_tft_sample.h"

#include "stm32f7xx_nucleo_144.h"

/*
 *  サービスコールのエラーのログ出力
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))

//uint8_t BlinkSpeed = 0, str[20];
uint8_t BlinkSpeed = 0;


/*
 *  処理本体のタスク
 */
void task(intptr_t exinf)
{
  /* Configure LED2 on Nucleo */
  BSP_LED_Init(LED2);

  /* Configure the User Button in EXTI Mode */
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
  
  /* Initiate BlinkSpeed variable */ 
  BlinkSpeed = 0;  
  
  /* Infinite loop */
  while(1)
  {
	  syslog(LOG_NOTICE, "Integrate test.");
    /* Test on blink speed */
    if(BlinkSpeed == 0)
    {
      BSP_LED_Toggle(LED2);
      /* Wait for 500ms */      
      HAL_Delay(500);      
    }      
    else if(BlinkSpeed == 1)
    {
      BSP_LED_Toggle(LED2);
      /* Wait for 100ms */
      HAL_Delay(100); 
    }
    else if(BlinkSpeed == 2)
    {
      BSP_LED_Toggle(LED2);    
      /* Wait for 50ms */
      HAL_Delay(50);  
    }
    
	}
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	char	c;
	ER_UINT	ercd;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Adafruit_TFT_Shield Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  シリアルポートの初期化
	 *
	 *  システムログタスクと同じシリアルポートを使う場合など，シリアル
	 *  ポートがオープン済みの場合にはここでE_OBJエラーになるが，支障は
	 *  ない．
	 */
	ercd = serial_opn_por(TASK_PORTID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));

	/*
 	 *  タスクの起動
	 */
	SVC_PERROR(act_tsk(TASK1));
	
  /*
 	 *  メインループ
	 */
	do {
		SVC_PERROR(serial_rea_dat(TASK_PORTID, &c, 1));
		switch (c) {

		default:
			break;
		}
	} while (c != '\003' && c != 'Q');

	syslog(LOG_NOTICE, "Adafruit_TFT_Shield Sample program ends.");
	SVC_PERROR(ext_ker());
	assert(0);
}

/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(BlinkSpeed == 2)
  {
    BlinkSpeed = 0;
  }
  else
  {
    BlinkSpeed ++;
  }
}
