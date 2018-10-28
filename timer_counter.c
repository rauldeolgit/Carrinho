/* ****************************************************************** */
/* File name:        timer_counter.c                                  */
/* File description: This file has a couple of useful functions to    */
/*                   init and crontol PWM source.                     */
/* Author name:      Raul and Vitor                                   */
/* Creation date:    21jun2018                                        */
/* Revision date:    21jun2018                                        */
/* ****************************************************************** */

#include "es670_peripheral_board.h"
#include "fsl_tpm_hal.h"
#include <MKL25Z4.h>

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Output params:	   n/a 		              */
/* ************************************************** */

void timer_initTPM1AsPWM(){
   /* un-gate port clock*/
   SIM_SCGC6 |= SIM_SCGC6_TPM1(CGC_CLOCK_ENABLED); //Enable clock for TPM1

   TPM1_SC |= TPM_SC_CPWMS(0u);   //up counting mode
   TPM1_SC |= TPM_SC_CMOD(0x01u); //LPTPM Counter increments on every LPTPM counter clock
   TPM1_SC |= TPM_SC_PS(0x0u);    //Prescale 1:1

   TPM1_C1SC |= TPM_CnSC_MSB(0x01u)| TPM_CnSC_MSA(0x00u) | TPM_CnSC_ELSB(0x01u)| TPM_CnSC_ELSA(0x00u);

   //SIM_SOPT4 |= SIM_SOPT4_TPM0CLKSEL(0U);
   SIM_SOPT2 |= SIM_SOPT2_TPMSRC(0x2u);

   TPM1_CNT = TPM_CNT_COUNT(0x0u);
   TPM1_MOD = TPM_MOD_MOD(99u);
   TPM1_C1V = TPM_CnV_VAL(100u); //PWM 100%
   //TPM1_C1V = TPM_CnV_VAL(30u); //PWM 75%
   //TPM1_C1V = TPM_CnV_VAL(iDutyCycle); //PWM 50%
   //TPM1_C1V = TPM_CnV_VAL(25u); //PWM 25%
   //TPM1_C1V = TPM_CnV_VAL(0u); //PWM 0%

   /* Channel 0 Config - Heater */
  TPM1_C0SC |= (TPM_CnSC_MSB(0b1) | TPM_CnSC_MSA(0b0) | TPM_CnSC_ELSB(0b1) | TPM_CnSC_ELSA(0b0));

  //TPM1_C1V = 0x100; //PWM 00%
  }

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void)
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

   /* set pin as PWM */
   PORTA_PCR13 |= PORT_PCR_MUX(0x03u);
}

/* ************************************************ */
/* Method name:        timer_changeHeaterPwm        */
/* Method description: Change Duty Cycle of PWM     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_changeHeaterPwm(int iPwm)
{
	if(iPwm<=50){
	//iPwm = (iPwm/100)*TPM1_MOD;
		TPM1_C0V = iPwm;
	}else{
		TPM1_C0V=50;
	}
}

/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_initHeater(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR12 |= PORT_PCR_MUX(0x03);
}


