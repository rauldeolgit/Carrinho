/* ****************************************************************** */
/* File name:        timer_counter.h                                  */
/* File description: This file has a couple of useful functions to    */
/*                   init and crontol PWM source.                     */
/* Author name:      Raul and Vitor                                   */
/* Creation date:    21jun2018                                        */
/* Revision date:    21jun2018                                        */
/* ****************************************************************** */

#ifndef SOURCES_TIMER_COUNTER_H_
#define SOURCES_TIMER_COUNTER_H_

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */

void timer_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void);

/* ************************************************ */
/* Method name:        timer_changeHeaterPwm        */
/* Method description: Change Duty Cycle of PWM     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_changeHeaterPwm(int iPwm);

/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_initHeater(void);

#endif /* SOURCES_TIMER_COUNTER_H_ */
