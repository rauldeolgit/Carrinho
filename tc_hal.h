/* ***************************************************************** */
/* File name:        tc_hal.h                                        */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling timers and counter      */
/*                   from the FRDM-KL25Z board                       */
/* Author name:      Raul e Vitor                                    */
/* Creation date:    17mai2018                                       */
/* Revision date:    24mai2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_TC_HAL_H_
#define SOURCES_TC_HAL_H_

#include "fsl_lptmr_driver.h"

/* ************************************************ */
/* Method name:        tc_installLptmr              */
/* Method description: Low power timer 0            */
/*                    initialization and start      */
/* Input params:      uiTimeInUs:                   */
/*                    time in micro seconds         */
/*                    tUserCallback                 */
/*                    function pointer to be called */
/*                    when counter achieves         */
/*                    uiTimeInUs                    */
/* Output params:     n/a                           */
/* ************************************************ */
void tc_installLptmr0(uint32_t uiTimeInUs, lptmr_callback_t tUserCallback);

/* *************************************************** */
/* Method name:        initCooler                      */
/* Method description: Initialize the Cooler function  */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */
void initCooler(void);

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
int getCoolerSpeed(int interpolation);

/* ******************************************************** */
/* Method name:        intToString                          */
/* Method description: this method converts int to string.  */
/* Input params:       int i:                               */
/*                     int that will be converted           */
/*                     char b[]:                            */
/*                     char vector                          */
/* Output params:      char b[]:int converted               */
/* ******************************************************** */
char* intToString(int i, char b[]);

/* ******************************************************* */
/* Method name:        initTac                             */
/* Method description: Initialize the tachometer function  */
/* Input params:       n/a                                 */
/* Output params:      n/a                                 */
/* ******************************************************* */
void initTac(void);

void LPTMR0_IRQHandler(void);

void tc_testDelaySetup(void);

void tc_TestDelay(void);

void tc_lptmrCallBack(void);

#endif /* SOURCES_TC_HAL_H_ */
