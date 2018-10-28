
#include "sensor_linha.h"
#include "es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void sensor_linha_init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

    /* set pin as gpio */
    PORTC_PCR2 = PORT_PCR_MUX(BUZZER_ALT);

    /* set pin as digital output */
    GPIOC_PDDR |= GPIO_PDDR_PDD(BUZZER_PIN);

}



/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void sensor_linha_clear(void)
{
    /* clear desired led */
    GPIOC_PCOR = GPIO_PCOR_PTCO(0x01);

}



/* ************************************************ */
/* Method name:        buzzer_setBuz                */
/* Method description: Set the buzzer device ON     */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
void sensor_linha_set(void)
{
    /* set desired led */
    GPIOC_PSOR = GPIO_PSOR_PTSO(0x01);

}
