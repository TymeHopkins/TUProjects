#include "HAL_FLASH.h"
#include "stm32f7xx_hal.h"

// Define the address where you want to store your data
#define FLASH_DATA_ADDRESS ((uint32_t)0x08040000) // Address within sector 6

// Function to write data to flash memory
void writeDataToFlash(uint32_t* data, uint32_t size)
{
    HAL_FLASH_Unlock();

    for (uint32_t i = 0; i < size; i += 4)
    {
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, FLASH_DATA_ADDRESS + i, data[i / 4]);
    }

    HAL_FLASH_Lock();
}

// Function to read data from flash memory
void readDataFromFlash(uint32_t* data, uint32_t size)
{
    for (uint32_t i = 0; i < size; i += 4)
    {
        data[i / 4] = *(__IO uint32_t*)(FLASH_DATA_ADDRESS + i);
    }
}
