/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "es670_peripheral_board.h"
#include "buzzer_hal.h"
#include "util.h"
#include "tc_hal.h"
#include "fsl_tpm_hal.h"
#include "timer_counter.h"
#include "pwm.h"
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "mcg_hal.h"
#include "sensor_linha.h"
#include "adc.h"

#define CYCLIC_EXECUTIVE_PERIOD         1000 * 100

int light=12;
char cString[2];
char done1[1];
int done;
int bin;
int exc_clic=CYCLIC_EXECUTIVE_PERIOD;
int iVel;
int iInterpolation;

volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */

void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */
    uiFlagNextPeriod = 1;
}

//#define TPM_MODULE 3275


int main(void)
{
	iInterpolation=(1000*1000)/exc_clic;
	initTac();
	adc_init( _8BIT );
	mcg_clockInit();
	debugUart_init();
	buzzer_init();
	sensor_linha_init();
	//adc_initADCModule();
	//pwm_tpm_Init(TPM1_BASE_PTR, TPM_PLLFLL , TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);
	//pwm_tpm_Ch_Init(TPM1, 1, TPM_PWM_H,GPIOA,13);
	//pwm_tpm_CnV(TPM1, 1, 100);

    /* Write your code here */
    /* This for loop should be replaced. By default this loop allows a single stepping. */

	 /* configure cyclic executive interruption */
	    tc_installLptmr0(CYCLIC_EXECUTIVE_PERIOD, main_cyclicExecuteIsr);

  /* cooperative cyclic executive main loop */
  while (1U){

		   //PUTCHAR('R');
		   //PUTCHAR('A');

	  //adc_initADCModule();
	  buzzer_setBuzz();
	  sensor_linha_set();
	  iVel=getCoolerSpeed(iInterpolation);

	  light = adc_read( ADC_1 );
	  if(light>40){
		  bin=1;
	  }else
		  bin=0;
	  intToString((int)iVel, cString);

	  PUTCHAR(' ');
	  PUTCHAR(' ');
	  PUTCHAR(' ');
	  PUTCHAR(cString[0]);
	  PUTCHAR(cString[1]);
	  PUTCHAR(cString[2]);


		   /*


	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
	util_genDelay1s();
*/


	 while(!uiFlagNextPeriod);
	 	 uiFlagNextPeriod = 0;


   }


	buzzer_clearBuzz();


    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
