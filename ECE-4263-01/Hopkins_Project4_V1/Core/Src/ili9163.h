#ifndef __ILI9163_H
#define __ILI9163_H

#include "main.h"
#include <string.h>
#include <stdio.h>
#include "colors.h"
#include "fonts.h"

#define ILI9163_HEIGHT 		128
#define ILI9163_WIDTH 		160

#define DISP_CS_Pin			GPIO_PIN_8
#define DISP_CS_Port		GPIOB

#define DISP_DC_Pin			GPIO_PIN_9
#define DISP_DC_Port		GPIOB

#define DISP_RST_Pin 		GPIO_PIN_14
#define DISP_RST_Port 		GPIOD

#define DISP_SPI			hspi1

#define BUFSIZE (ILI9163_WIDTH)*(ILI9163_HEIGHT)

// ILI9163 LCD Controller Commands
#define ILI9163_CMD_NOP                     0x00
#define ILI9163_CMD_SOFT_RESET              0x01
#define ILI9163_CMD_GET_RED_CHANNEL         0x06
#define ILI9163_CMD_GET_GREEN_CHANNEL       0x07
#define ILI9163_CMD_GET_BLUE_CHANNEL        0x08
#define ILI9163_CMD_GET_PIXEL_FORMAT        0x0C
#define ILI9163_CMD_GET_POWER_MODE          0x0A
#define ILI9163_CMD_GET_ADDRESS_MODE        0x0B
#define ILI9163_CMD_GET_DISPLAY_MODE        0x0D
#define ILI9163_CMD_GET_SIGNAL_MODE         0x0E
#define ILI9163_CMD_GET_DIAGNOSTIC_RESULT   0x0F
#define ILI9163_CMD_ENTER_SLEEP_MODE        0x10
#define ILI9163_CMD_EXIT_SLEEP_MODE         0x11
#define ILI9163_CMD_ENTER_PARTIAL_MODE      0x12
#define ILI9163_CMD_ENTER_NORMAL_MODE       0x13
#define ILI9163_CMD_EXIT_INVERT_MODE        0x20
#define ILI9163_CMD_ENTER_INVERT_MODE       0x21
#define ILI9163_CMD_SET_GAMMA_CURVE         0x26
#define ILI9163_CMD_SET_DISPLAY_OFF         0x28
#define ILI9163_CMD_SET_DISPLAY_ON          0x29
#define ILI9163_CMD_SET_COLUMN_ADDRESS      0x2A
#define ILI9163_CMD_SET_PAGE_ADDRESS        0x2B
#define ILI9163_CMD_WRITE_MEMORY_START      0x2C
#define ILI9163_CMD_WRITE_LUT               0x2D
#define ILI9163_CMD_READ_MEMORY_START       0x2E
#define ILI9163_CMD_SET_PARTIAL_AREA        0x30
#define ILI9163_CMD_SET_SCROLL_AREA         0x33
#define ILI9163_CMD_SET_TEAR_OFF            0x34
#define ILI9163_CMD_SET_TEAR_ON             0x35
#define ILI9163_CMD_SET_ADDRESS_MODE        0x36
#define ILI9163_CMD_SET_SCROLL_START        0X37
#define ILI9163_CMD_EXIT_IDLE_MODE          0x38
#define ILI9163_CMD_ENTER_IDLE_MODE         0x39
#define ILI9163_CMD_SET_PIXEL_FORMAT        0x3A
#define ILI9163_CMD_WRITE_MEMORY_CONTINUE   0x3C
#define ILI9163_CMD_READ_MEMORY_CONTINUE    0x3E
#define ILI9163_CMD_SET_TEAR_SCANLINE       0x44
#define ILI9163_CMD_GET_SCANLINE            0x45
#define ILI9163_CMD_READ_ID1                0xDA
#define ILI9163_CMD_READ_ID2                0xDB
#define ILI9163_CMD_READ_ID3                0xDC
#define ILI9163_CMD_FRAME_RATE_CONTROL1     0xB1
#define ILI9163_CMD_FRAME_RATE_CONTROL2     0xB2
#define ILI9163_CMD_FRAME_RATE_CONTROL3     0xB3
#define ILI9163_CMD_DISPLAY_INVERSION       0xB4
#define ILI9163_CMD_SOURCE_DRIVER_DIRECTION 0xB7
#define ILI9163_CMD_GATE_DRIVER_DIRECTION   0xB8
#define ILI9163_CMD_POWER_CONTROL1          0xC0
#define ILI9163_CMD_POWER_CONTROL2          0xC1
#define ILI9163_CMD_POWER_CONTROL3          0xC2
#define ILI9163_CMD_POWER_CONTROL4          0xC3
#define ILI9163_CMD_POWER_CONTROL5          0xC4
#define ILI9163_CMD_VCOM_CONTROL1           0xC5
#define ILI9163_CMD_VCOM_CONTROL2           0xC6
#define ILI9163_CMD_VCOM_OFFSET_CONTROL     0xC7
#define ILI9163_CMD_WRITE_ID4_VALUE         0xD3
#define ILI9163_CMD_NV_MEMORY_FUNCTION1     0xD7
#define ILI9163_CMD_NV_MEMORY_FUNCTION2     0xDE
#define ILI9163_CMD_POSITIVE_GAMMA_CORRECT  0xE0
#define ILI9163_CMD_NEGATIVE_GAMMA_CORRECT  0xE1
#define ILI9163_CMD_GAM_R_SEL               0xF2


void ILI9163_init(int rotation);

void ILI9163_newFrame();
void ILI9163_render();

void ILI9163_drawPixel(uint8_t x, uint8_t y, uint16_t color);
void ILI9163_drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color);
void ILI9163_drawRect(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2, uint8_t thickness, uint16_t color);
void ILI9163_fillRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void ILI9163_drawCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint16_t color);
void ILI9163_fillCircle(uint8_t centerX, uint8_t centerY, uint8_t radius, uint16_t color);
void ILI9163_fillDisplay(uint16_t color);

void ILI9163_drawChar(uint8_t x, uint8_t y, char ch, FontDef font, uint16_t color);

void ILI9163_drawString(uint8_t x, uint8_t y, FontDef font, uint16_t color, const char *string);
void ILI9163_drawStringF(uint8_t x, uint8_t y, FontDef font, uint16_t color, char *szFormat, ...);

#endif
