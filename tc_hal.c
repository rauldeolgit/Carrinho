/* ***************************************************************** */
/* File name:        tc_hal.c                                        */
/* File description: This file has a couple of useful functions to   */
/*                   timer and counter hardware abstraction layer    */
/*                   from the FRDM-KL25Z board                       */
/* Author name:      Raul e Vitor                                    */
/* Creation date:    17mai2018                                       */
/* Revision date:    24mai2018                                       */
/* ***************************************************************** */

/* system includes */
#include "fsl_lptmr_driver.h"
#include "es670_peripheral_board.h"
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"
#include "tc_hal.h"

static int iVel, iCounter;

/* LPTMR configurations */
lptmr_user_config_t lptmrConfig =
{
    .timerMode              = kLptmrTimerModeTimeCounter,
    .freeRunningEnable      = false,
    .prescalerEnable        = true,
    .prescalerClockSource   = kClockLptmrSrcLpoClk,
    .prescalerValue         = kLptmrPrescalerDivide2,
    .isInterruptEnabled     = true,
};

/* LPTMR driver state information */
lptmr_state_t lptmrState;


/* LPTMR IRQ handler that would cover the same name's APIs in startup code */
/* Do not edit this part */

/* *************************************************** */
/* Method name:        initCooler                      */
/* Method description: Initialize the Cooler function  */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */

void initCooler(void){
   SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED); //Ativa o clock do cooler.
   PORTA_PCR13 = PORT_PCR_MUX(COOLER_ALT); //Escolhe o pino como GPIO.
   GPIOA_PDDR |= GPIO_PDDR_PDD( COOLER_DIR_OUTPUT ); //Seta como output.
   GPIOA_PSOR = GPIO_PSOR_PTSO( COOLER_DIR_OUTPUT ); //Liga o cooler.
}

/* *************************************************** */
/* Method name:        getCoolerSpeed                  */
/* Method description: This method calculates the      */
/*                     speed of the cooler.            */
/* Input params:       int iInterpolation:             */
/*                     Allows the calculation of       */
/*                     velocity independent of the     */
/*                     period of the cyclic executive  */
/* Output params:      int iVel:Cooler velocity.       */
/* *************************************************** */

int getCoolerSpeed(int iInterpolation){
   iCounter = TPM0_CNT;
   TPM0_CNT=0;
   iVel = iInterpolation*iCounter*10/7;
   return iVel;
}

/* ******************************************************** */
/* Method name:        intToString                          */
/* Method description: this method converts int to string.  */
/* Input params:       int i:                               */
/*                     int that will be converted           */
/*                     char b[]:                            */
/*                     char vector                          */
/* Output params:      char b[]:int converted               */
/* ******************************************************** */

char* intToString(int i, char b[]){
   char const digit[] = "0123456789";
   char* p = b;
   if(i<0){
      *p++ = '-';
      i *= -1;
    }
   int iShifter = i;
   do{ //Move to where representation ends
      ++p;
      iShifter = iShifter/10;
   }while(iShifter);
   *p = '\0';
   do{ //Move back, inserting digits as u go
      *--p = digit[i%10];
      i = i/10;
   }while(i);
   return b;
}

/* ******************************************************* */
/* Method name:        initTac                             */
/* Method description: Initialize the tachometer function  */
/* Input params:       n/a                                 */
/* Output params:      n/a                                 */
/* ******************************************************* */

void initTac(){
   /*Ativa o clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);

   /*Ativa o clock do TPM0*/
   SIM_SCGC6 |= SIM_SCGC6_TPM0(CGC_CLOCK_ENABLED);

   /*Escolhe o pino como contador*/
   PORTE_PCR29 = PORT_PCR_MUX(TAC_ALT);

   /*Liga o TPM_CLKIN0 no clock externo do TPM0*/
   SIM_SOPT4 |= SIM_SOPT4_TPM0CLKSEL(0U);

   /*Seta CMOD*/
   TPM0_SC |= TPM_SC_CMOD(0x2u);

   /*Setando Prescaler */
   TPM0_SC |= TPM_SC_PS(0x0U);

   /* Seta TPM Source OSCERCLK clock */
   SIM_SOPT2 |= SIM_SOPT2_TPMSRC(0x2u);
}

void LPTMR0_IRQHandler(void)
{
   LPTMR_DRV_IRQHandler(0U);
}

/* dummy code for hardware debug purpose */
void tc_testDelaySetup(void)
{
   CLOCK_SYS_EnablePortClock(PORTE_IDX);
   PORT_HAL_SetMuxMode(PORTE, 0u, kPortMuxAsGpio);
   GPIO_HAL_SetPinDir(PTE, 0u, kGpioDigitalOutput);
   GPIO_HAL_ClearPinOutput(PTE, 0u);
}
/* dummy code for hardware debug purpose */
void tc_TestDelay(void)
{
   static char cTest = 0;
   if(!cTest)
      GPIO_HAL_ClearPinOutput(PTE, 0u);
   else
      GPIO_HAL_SetPinOutput(PTE, 0u);

   cTest ^= 1u;
}

/* dummy code for hardware debug purpose */
void tc_lptmrCallBack(void)
{
   tc_TestDelay();
}

/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                     initialization and start     */
/* Input params:       uiTimeInUs:                  */
/*                     time in micro seconds        */
/*                     tUserCallback:               */
/*                     function pointer to be called*/
/*                     when counter achieves        */
/*                     uiTimeInUs                   */
/* Output params:      n/a                          */
/* ************************************************ */
void tc_installLptmr0(uint32_t uiTimeInUs, lptmr_callback_t tUserCallback)
{
   /* Initialize LPTMR */
   LPTMR_DRV_Init(LPTMR0_IDX, &lptmrState, &lptmrConfig);

   /* Set timer period for TMR_PERIOD micro seconds */
   LPTMR_DRV_SetTimerPeriodUs(LPTMR0_IDX, uiTimeInUs);

   /* Install interrupt call back function for LPTMR */
   LPTMR_DRV_InstallCallback(LPTMR0_IDX, tUserCallback);

   /* Start LPTMR */
   LPTMR_DRV_Start(LPTMR0_IDX);
}
