/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */


/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT        PORTD                                   /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT        PTD                                     /* peripheral gpio base pointer */

#define BUZZER_PIN                  1U                                      /* buzzer pin */
#define BUZZER_DIR                  kGpioDigitalOutput
#define BUZZER_ALT                  0x01u
/*                 END OF BUZZER definitions             */


/*                 LED and SWITCH Definitions                    */
#define LS_PORT_BASE_PNT            PORTA                                   /* peripheral port base pointer */
#define LS_GPIO_BASE_PNT            PTA                                     /* peripheral gpio base pointer */

/* THIS PIN CONFLICTS WITH PTA1 USED AS UART0_RX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS1_PIN                     1U                                      /* led/switch #1 pin */
#define LS1_DIR_OUTPUT              (GPIO_OUTPUT << LS1_PIN)
#define LS1_DIR_INPUT               (GPIO_OUTPUT << LS1_PIN)
#define LS1_ALT                     0x01u                                   /* GPIO alternative */

/* THIS PIN CONFLICTS WITH PTA2 USED AS UART0_TX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS2_PIN                     2U                                      /* led/switch #2 pin */
#define LS2_DIR_OUTPUT              (GPIO_OUTPUT << LS2_PIN)
#define LS2_DIR_INPUT               (GPIO_OUTPUT << LS2_PIN)
#define LS2_ALT                     LS1_ALT

#define LS3_PIN                     4U                                      /* led/switch #3 pin */
#define LS3_DIR_OUTPUT              (GPIO_OUTPUT << LS3_PIN)
#define LS3_DIR_INPUT               (GPIO_OUTPUT << LS3_PIN)
#define LS3_ALT                     LS1_ALT

#define LS4_PIN                     5U                                      /* led/switch #4 pin */
#define LS4_DIR_OUTPUT              (GPIO_OUTPUT << LS4_PIN)
#define LS4_DIR_INPUT               (GPIO_OUTPUT << LS4_PIN)
#define LS4_ALT                     LS1_ALT

/*                 END OF LED and SWITCH definitions             */

/*                 LED and SWITCH Definitions                    */
#define SS_ALT						0x01u

#define SS_PORT_BASE_PNT            PORTC                                   /* peripheral port base pointer */
#define SS_GPIO_BASE_PNT            PTC                                     /* peripheral gpio base pointer */

/* segments definition */
#define SSA_PIN                     0U
#define SSA_DIR_OUTPUT              (GPIO_OUTPUT << SSA_PIN)
#define SSA_ALT                     SS_ALT

#define SSB_PIN                     1U
#define SSB_DIR_OUTPUT              (GPIO_OUTPUT << SSB_PIN)
#define SSB_ALT                     SS_ALT

#define SSC_PIN                     2U
#define SSC_DIR_OUTPUT              (GPIO_OUTPUT << SSC_PIN)
#define SSC_ALT                     SS_ALT

#define SSD_PIN                     3U
#define SSD_DIR_OUTPUT              (GPIO_OUTPUT << SSD_PIN)
#define SSD_ALT                     SS_ALT

#define SSE_PIN                     4U
#define SSE_DIR_OUTPUT              (GPIO_OUTPUT << SSE_PIN)
#define SSE_ALT                     SS_ALT

#define SSF_PIN                     5U
#define SSF_DIR_OUTPUT              (GPIO_OUTPUT << SSF_PIN)
#define SSF_ALT                     SS_ALT

#define SSG_PIN                     6U
#define SSG_DIR_OUTPUT              (GPIO_OUTPUT << SSG_PIN)
#define SSG_ALT                     SS_ALT

#define SSDP_PIN                    7U
#define SSDP_DIR_OUTPUT              (GPIO_OUTPUT << SSDP_PIN)
#define SSDP_ALT                     SS_ALT

/* display definitions */
#define SS1_PIN                     13U
#define SS1_DIR_OUTPUT              (GPIO_OUTPUT << SS1_PIN)
#define SS1_ALT                     SS_ALT

#define SS2_PIN                     12U
#define SS2_DIR_OUTPUT              (GPIO_OUTPUT << SS2_PIN)
#define SS2_ALT                     SS_ALT

#define SS3_PIN                     11U
#define SS3_DIR_OUTPUT              (GPIO_OUTPUT << SS3_PIN)
#define SS3_ALT                     SS_ALT

#define SS4_PIN                     10U
#define SS4_DIR_OUTPUT              (GPIO_OUTPUT << SS4_PIN)
#define SS4_ALT                     SS_ALT
/*       END OF 7SEGMENTS definitions           */

/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT           PORTC                                   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

#define LCD_RS_PIN                  8U                                      /* register selector */
#define LCD_RS_DIR                  (GPIO_OUTPUT << LCD_RS_PIN)
#define LCD_RS_ALT                  0x01u

#define LCD_ENABLE_PIN              9U                                      /* enable pin */
#define LCD_ENABLE_DIR              (GPIO_OUTPUT << LCD_ENABLE_PIN)
#define LCD_ENABLE_ALT              0x01u

#define LCD_RS_HIGH                 1U
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0U
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1U
#define LCD_DISABLED                0U

#define LCD_DATA_DIR                kGpioDigitalOutput                      /* LCD data pins */
#define LCD_DATA_ALT                kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0U
#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)

#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)

#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)

#define LCD_DATA_DB3_PIN            3U
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)

#define LCD_DATA_DB4_PIN            4U
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)

#define LCD_DATA_DB5_PIN            5U
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)

#define LCD_DATA_DB6_PIN            6U
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)

#define LCD_DATA_DB7_PIN            7U
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)

#define LCD_DATA_DBN_PIN_ALT		0x01u
/*                 END OF LCD definitions                 */

/*                   Cooler definitions                						 */
#define COOLER_PORT_BASE_PNT         PORTA                                   /* peripheral port base pointer */
#define COOLER_GPIO_BASE_PNT         PTA                                     /* peripheral gpio base pointer */

#define COOLER_PIN                  13U
#define COOLER_DIR_OUTPUT           (GPIO_OUTPUT << COOLER_PIN)
#define COOLER_ALT                  0x01u                               	    /* GPIO alternative */
/*                 END OF Cooler definitions                 */

/*                Definições do TACOMETRO              						 */
#define TAC_PORT_BASE_PNT           PORTE                                   /* peripheral port base pointer */
#define TAC_GPIO_BASE_PNT           PTE                                     /* peripheral gpio base pointer */

#define TAC_PIN                  29U
#define TAC_ALT                  0x04u                               	    /* GPIO alternative */

/*                 END OF TACOMETRO definitions                 */

#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
