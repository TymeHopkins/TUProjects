/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f7xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f7xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdbool.h"
#include "stdio.h"
#include "ctype.h"
#include "ili9163.h"
#include "fonts.h"
#include "colors.h"
#include "stdlib.h"
#include "GUI.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern char keyChar;
extern uint16_t key;
extern int enterFlag;
extern int setPassFlag;
extern int backspaceFlag;
extern int screenClrFlag;

extern char operands[];
extern char operators[];

extern char password[10];
extern char inputPassword[10];

///Pinout, looking at back of keypad, left to right
// / PC8 , PC7 , PC6 , PC9 , PB15 , PB4 , PB13 , PB1

const GPIO_TypeDef* _KEYPAD_COLUMN_GPIO_PORT[] =
{
  GPIOB,
  GPIOB,
  GPIOB,
  GPIOB
};

const uint16_t _KEYPAD_COLUMN_GPIO_PIN[] =
{
  GPIO_PIN_1,
  GPIO_PIN_13,
  GPIO_PIN_4,
  GPIO_PIN_15
};

const GPIO_TypeDef* _KEYPAD_ROW_GPIO_PORT[] =
{
  GPIOC,
  GPIOC,
  GPIOC,
  GPIOC
};

const uint16_t _KEYPAD_ROW_GPIO_PIN[] =
{
  GPIO_PIN_9,
  GPIO_PIN_6,
  GPIO_PIN_7,
  GPIO_PIN_8
};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
char KeyPadGetChar(uint16_t key);
void append(char* input, char keyChar);
void screenClear();
void backspace();
void setPassword();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_spi1_tx;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M7 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */
	key = 0;
	for(uint8_t c=0 ; c<4 ; c++)
	{
		for(uint8_t i=0 ; i<4 ; i++)
		{
			HAL_GPIO_WritePin((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[i], _KEYPAD_COLUMN_GPIO_PIN[i], GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)_KEYPAD_COLUMN_GPIO_PORT[c], _KEYPAD_COLUMN_GPIO_PIN[c], GPIO_PIN_RESET);
		for(uint8_t r=0 ; r<4 ; r++)
		{
			if(HAL_GPIO_ReadPin((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[r], _KEYPAD_ROW_GPIO_PIN[r]) == GPIO_PIN_RESET)
			{
				if(HAL_GPIO_ReadPin((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[r], _KEYPAD_ROW_GPIO_PIN[r]) == GPIO_PIN_RESET)
				{
					key |= 1<<c;
					key |= 1<<(r+8);
					while(HAL_GPIO_ReadPin((GPIO_TypeDef*)_KEYPAD_ROW_GPIO_PORT[r], _KEYPAD_ROW_GPIO_PIN[r]) == GPIO_PIN_RESET)
					{

					}
				}
			}
		}
	}
//
//	if (shiftFlag == 0)
//	{
//		keyChar = KeyPadGetChar(key);
//		append(input, keyChar);
//		key = 0;
//	}
//	else
//	{
	keyChar = KeyPadGetChar(key);
	append(inputPassword, keyChar);
	key = 0;
//	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_13|GPIO_PIN_4|GPIO_PIN_15, GPIO_PIN_RESET);

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream3 global interrupt.
  */
void DMA2_Stream3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream3_IRQn 0 */

  /* USER CODE END DMA2_Stream3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_spi1_tx);
  /* USER CODE BEGIN DMA2_Stream3_IRQn 1 */

  /* USER CODE END DMA2_Stream3_IRQn 1 */
}

/* USER CODE BEGIN 1 */
char KeyPadGetChar(uint16_t	key)
{
  switch(key)
  {
    case 0x0000:
    	return 0;
	case 0x0101:
		return '1';
	case 0x0201:
		return '2';
	case 0x0401:
		return '3';
	case 0x0801:
		setPassword(); //Was 'A' changed to setPassword() function
		return 0;
	case 0x0102:
		return '4';
	case 0x0202:
		return '5';
	case 0x0402:
		return '6';
	case 0x0802:
		backspace();
		return 0; ////Was 'B' changed to backspace() function
	case 0x0104:
		return '7';
	case 0x0204:
		return '8';
	case 0x0404:
		return '9';
	case 0x0804:
		screenClear();
		return 0; //Was 'C' changed to screenClear() function
	case 0x0108:
		return '*'; //Shift key
	case 0x0208:
		return '0';
	case 0x0408:
		enterFlag = 1;
		return 0; //Was '#' changed to enterFlag = 1
	case 0x0808:
		return 0; //Was 'D' changed to return 0
	default:
		return 0;
	}
}

void append(char* input, char keyChar)
{
	int len = strlen(input);
	input[len] = keyChar;
	input[len+1] = '\0';
}
void screenClear()
{
	inputPassword[0] = '\0';
	screenClrFlag = 1;
}
void backspace()
{
	int len = strlen(inputPassword);
	inputPassword[len-1] = '\0';
	backspaceFlag = 1;
}
void setPassword()
{
	password[0] = '\0';
	for(int i = 0; i <= strlen(inputPassword); i++)
	{
		password[i] = inputPassword[i];
	}
	int len = strlen(password);
	password[len] = '\0';
	setPassFlag = 1;
}
/* USER CODE END 1 */
