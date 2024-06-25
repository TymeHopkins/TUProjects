#ifndef HAL_Flash_H
#define HAL_Flash_H

#include "stm32f7xx_hal.h"

#include "ctype.h"
#include "stdio.h"
#include "ili9163.h"
#include "fonts.h"
#include "colors.h"
#include "stdlib.h"

void writeDataToFlash(uint32_t* data, uint32_t size);
void readDataFromFlash(uint32_t* data, uint32_t size);

#endif
