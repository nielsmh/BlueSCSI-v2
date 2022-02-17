// GPIO definitions for AzulSCSI v1.1

#pragma once

// SCSI data output port.
// The output data is written using BSRR mechanism, so all data pins must be on same GPIO port.
// The output pins are open-drain in hardware, using separate buffer chips for driving.
#define SCSI_OUT_PORT GPIOD
#define SCSI_OUT_DB7  GPIO_PIN_9
#define SCSI_OUT_DB6  GPIO_PIN_10
#define SCSI_OUT_DB5  GPIO_PIN_11
#define SCSI_OUT_DB4  GPIO_PIN_12
#define SCSI_OUT_DB3  GPIO_PIN_13
#define SCSI_OUT_DB2  GPIO_PIN_14
#define SCSI_OUT_DB1  GPIO_PIN_0
#define SCSI_OUT_DB0  GPIO_PIN_1
#define SCSI_OUT_DBP  GPIO_PIN_8
#define SCSI_OUT_REQ  GPIO_PIN_4
#define SCSI_OUT_DATA_MASK (SCSI_OUT_DB0 | SCSI_OUT_DB1 | SCSI_OUT_DB2 | SCSI_OUT_DB3 | SCSI_OUT_DB4 | SCSI_OUT_DB5 | SCSI_OUT_DB6 | SCSI_OUT_DB7 | SCSI_OUT_DBP)
#define SCSI_OUT_REQ_IDX 4

// Control signals to optional PLD device
#define SCSI_OUT_PLD1 GPIO_PIN_15
#define SCSI_OUT_PLD2 GPIO_PIN_3
#define SCSI_OUT_PLD3 GPIO_PIN_5
#define SCSI_OUT_PLD4 GPIO_PIN_7

// SCSI input data port
#define SCSI_IN_PORT  GPIOE
#define SCSI_IN_DB7   GPIO_PIN_15
#define SCSI_IN_DB6   GPIO_PIN_14
#define SCSI_IN_DB5   GPIO_PIN_13
#define SCSI_IN_DB4   GPIO_PIN_12
#define SCSI_IN_DB3   GPIO_PIN_11
#define SCSI_IN_DB2   GPIO_PIN_10
#define SCSI_IN_DB1   GPIO_PIN_9
#define SCSI_IN_DB0   GPIO_PIN_8
#define SCSI_IN_DBP   GPIO_PIN_7
#define SCSI_IN_MASK  (SCSI_IN_DB7|SCSI_IN_DB6|SCSI_IN_DB5|SCSI_IN_DB4|SCSI_IN_DB3|SCSI_IN_DB2|SCSI_IN_DB1|SCSI_IN_DB0|SCSI_IN_DBP)
#define SCSI_IN_SHIFT 8

// SCSI output status lines
#define SCSI_OUT_IO_PORT  GPIOA
#define SCSI_OUT_IO_PIN   GPIO_PIN_4
#define SCSI_OUT_CD_PORT  GPIOA
#define SCSI_OUT_CD_PIN   GPIO_PIN_5
#define SCSI_OUT_SEL_PORT GPIOA
#define SCSI_OUT_SEL_PIN  GPIO_PIN_6
#define SCSI_OUT_MSG_PORT GPIOA
#define SCSI_OUT_MSG_PIN  GPIO_PIN_7
#define SCSI_OUT_RST_PORT GPIOB
#define SCSI_OUT_RST_PIN  GPIO_PIN_14
#define SCSI_OUT_BSY_PORT GPIOB
#define SCSI_OUT_BSY_PIN  GPIO_PIN_15
#define SCSI_OUT_REQ_PORT SCSI_OUT_PORT
#define SCSI_OUT_REQ_PIN  SCSI_OUT_REQ

// SCSI input status signals
#define SCSI_SEL_PORT GPIOB
#define SCSI_SEL_PIN  GPIO_PIN_11
#define SCSI_ACK_PORT GPIOA
#define SCSI_ACK_PIN  GPIO_PIN_0
#define SCSI_ATN_PORT GPIOB
#define SCSI_ATN_PIN  GPIO_PIN_12
#define SCSI_IN_ACK_IDX 0

// BSY pin uses EXTI interrupt
#define SCSI_BSY_PORT GPIOB
#define SCSI_BSY_PIN  GPIO_PIN_10
#define SCSI_BSY_EXTI EXTI_10
#define SCSI_BSY_EXTI_SOURCE_PORT GPIO_PORT_SOURCE_GPIOB
#define SCSI_BSY_EXTI_SOURCE_PIN  GPIO_PIN_SOURCE_10
#define SCSI_BSY_IRQ  EXTI10_15_IRQHandler
#define SCSI_BSY_IRQn EXTI10_15_IRQn

// RST pin uses EXTI interrupt
#define SCSI_RST_PORT GPIOB
#define SCSI_RST_PIN  GPIO_PIN_13
#define SCSI_RST_EXTI EXTI_13
#define SCSI_RST_EXTI_SOURCE_PORT GPIO_PORT_SOURCE_GPIOB
#define SCSI_RST_EXTI_SOURCE_PIN GPIO_PIN_SOURCE_13
#define SCSI_RST_IRQ  EXTI10_15_IRQHandler
#define SCSI_RST_IRQn EXTI10_15_IRQn

// Terminator enable/disable config, active low
#define SCSI_TERM_EN_PORT GPIOB
#define SCSI_TERM_EN_PIN  GPIO_PIN_0

// SD card pins
#define SD_USE_SDIO 1
#define SD_SDIO_DATA_PORT GPIOC
#define SD_SDIO_D0        GPIO_PIN_8
#define SD_SDIO_D1        GPIO_PIN_9
#define SD_SDIO_D2        GPIO_PIN_10
#define SD_SDIO_D3        GPIO_PIN_11
#define SD_SDIO_CLK_PORT  GPIOC
#define SD_SDIO_CLK       GPIO_PIN_12
#define SD_SDIO_CMD_PORT  GPIOD
#define SD_SDIO_CMD       GPIO_PIN_2

// DIP switches
#define DIP_PORT     GPIOB
#define DIPSW1_PIN   GPIO_PIN_4
#define DIPSW2_PIN   GPIO_PIN_5
#define DIPSW3_PIN   GPIO_PIN_6

// Status LED pins
#define LED_PORT     GPIOC
#define LED_I_PIN    GPIO_PIN_4
#define LED_E_PIN    GPIO_PIN_5
#define LED_PINS     (LED_I_PIN | LED_E_PIN)
#define LED_ON()     gpio_bit_reset(LED_PORT, LED_PINS)
#define LED_OFF()    gpio_bit_set(LED_PORT, LED_PINS)