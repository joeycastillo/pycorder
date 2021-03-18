#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#define CRYSTALLESS    1

#define VENDOR_NAME "Oddly Specific Objects"
#define PRODUCT_NAME "The Pycorder"
#define VOLUME_LABEL "PYCOBOOT"
#define INDEX_URL "https://github.com/joeycastillo/pycorder"
#define BOARD_ID "OSO-PYCO-A1-02"

#define USB_VID 0x239A
#define USB_PID 0x007D

#define LED_PIN PIN_PA06

#define BOOT_USART_MODULE                 SERCOM3
#define BOOT_USART_MASK                   APBBMASK
#define BOOT_USART_BUS_CLOCK_INDEX        MCLK_APBBMASK_SERCOM3
#define BOOT_USART_PAD_SETTINGS           UART_RX_PAD3_TX_PAD2
#define BOOT_USART_PAD3                   PINMUX_PA19D_SERCOM3_PAD3
#define BOOT_USART_PAD2                   PINMUX_PA18D_SERCOM3_PAD2
#define BOOT_USART_PAD1                   PINMUX_UNUSED
#define BOOT_USART_PAD0                   PINMUX_UNUSED
#define BOOT_GCLK_ID_CORE                 SERCOM3_GCLK_ID_CORE
#define BOOT_GCLK_ID_SLOW                 SERCOM3_GCLK_ID_SLOW

#endif
