/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : CANalog: CAN to analog converter
 ******************************************************************************
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "dac.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "can_signal.h"
#include "can_bit_timing.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DEVICE_NAME				"CANalog"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define HW_VERSION				"V0.0.2.0"
#define FW_VERSION				"V0.0.4.0"

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
SPI_HandleTypeDef hspi2;
DAC_HandleTypeDef hdac;
CAN_HandleTypeDef hcan;

CAN_FilterTypeDef canFilter;
CAN_RxHeaderTypeDef canRxHeader;

Signal_Handle_t signal;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void can_filter_init(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *canFilter);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_CAN_Init();
	MX_DAC_Init();
	MX_SPI2_Init();
	/* USER CODE BEGIN 2 */
	signal_init(&signal); /* initialize signal to default values */

	can_filter_init(&hcan, &canFilter);

	if (HAL_CAN_Start(&hcan) != HAL_OK) {
		Error_Handler();
	}

	/* set DAC */
	HAL_DAC_SetValue(&hdac, DAC1_CHANNEL_1, DAC_ALIGN_12B_R, 0);
	HAL_DAC_Start(&hdac, DAC1_CHANNEL_1);

	/* for now turn on CAN terminating resistor */
	HAL_GPIO_WritePin(CAN_TERM_GPIO_Port, CAN_TERM_Pin, GPIO_PIN_SET);

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		/* SPI Check ---------------------------------------------------------*/
		if (HAL_GPIO_ReadPin(CS_GPIO_Port, CS_Pin) == 0) { /* esp8266 wants to talk */
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(RDY_GPIO_Port, RDY_Pin, GPIO_PIN_RESET); /* signal to esp8266 we are ready to talk */

			uint8_t command_bit = 0;
			if (HAL_SPI_Receive(&hspi2, &command_bit, sizeof(command_bit), 1) != HAL_OK) {
				Error_Handler();
			}

			switch (command_bit) {
			case SPI_SIGNAL_READ: /* esp is requesting parameters */
				if (HAL_SPI_Transmit(&hspi2, (uint8_t*) &signal, sizeof(Signal_Handle_t), 5) != HAL_OK) {
					Error_Handler();
				}
				break;
			case SPI_SIGNAL_WRITE: /* esp is sending new parameters*/
				if (HAL_SPI_Receive(&hspi2, (uint8_t*) &signal, sizeof(Signal_Handle_t), 5) != HAL_OK) {
					Error_Handler();
				}

				signal_update(&signal); /* recalculate signal values */
				/* restart CAN interface with new baud rate -----------------------*/
				if (HAL_CAN_Stop(&hcan) != HAL_OK) {
					Error_Handler();
				}
				/* stop CAN and deinit so we can configure it */
				if (HAL_CAN_DeInit(&hcan) != HAL_OK) {
					Error_Handler();
				}
				/* set new bit timing */
				can_set_bit_timing(&signal, &hcan);
				/* reinitialize CAN */
				if (HAL_CAN_Init(&hcan) != HAL_OK) {
					Error_Handler();
				}
				/* restart can */
				if (HAL_CAN_Start(&hcan) != HAL_OK) {
					Error_Handler();
				}
				/* set DAC to zero */
				HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);
				break;
			case SPI_GET_FW_VERSION:
				if (HAL_SPI_Transmit(&hspi2, (uint8_t*) FW_VERSION, sizeof(FW_VERSION), 5) != HAL_OK) {
					Error_Handler();
				}
				break;
			case SPI_GET_HW_VERSION:
				if (HAL_SPI_Transmit(&hspi2, (uint8_t*) HW_VERSION, sizeof(HW_VERSION), 5) != HAL_OK) {
					Error_Handler();
				}
				break;
			default:
				break;
			}

			HAL_GPIO_WritePin(RDY_GPIO_Port, RDY_Pin, GPIO_PIN_SET); /* return ready pin to high */

			while (HAL_GPIO_ReadPin(CS_GPIO_Port, CS_Pin) == 0)
				; /* loop until esp8266 pulls CS high */
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		}

		/* CAN ---------------------------------------------------------------*/
		if (HAL_CAN_GetRxFifoFillLevel(&hcan, CAN_RX_FIFO0) != 0) {
			if (HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &canRxHeader, signal.frame) != HAL_OK) {
				Error_Handler();
			} // end HAL_CAN_GetRxMessage

			switch (signal.can_type) {
			case ID_TYPE_11BIT:
				if (canRxHeader.StdId == signal.can_id) {
					signal_calc(&signal);
					HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, signal.dac_out);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
				}
				break;
			case ID_TYPE_29BIT:
				if (canRxHeader.ExtId == signal.can_id) {
					signal_calc(&signal);
					HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, signal.dac_out);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
				}
				break;
			default:
				break;
			} // end switch(signal.can_type)
		} // end HAL_CAN_GetRxFifoFillLevel
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
/* Initialize CAN Filter */
void can_filter_init(CAN_HandleTypeDef *hcan, CAN_FilterTypeDef *canFilter) {
	canFilter->FilterBank = 0;
	canFilter->FilterMode = CAN_FILTERMODE_IDMASK;
	canFilter->FilterScale = CAN_FILTERSCALE_32BIT;
	canFilter->FilterIdHigh = 0;
	canFilter->FilterIdLow = 0;
	canFilter->FilterMaskIdHigh = 0;
	canFilter->FilterMaskIdLow = 0;
	canFilter->FilterFIFOAssignment = CAN_RX_FIFO0;
	canFilter->FilterActivation = ENABLE;

	if (HAL_CAN_ConfigFilter(hcan, canFilter) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
