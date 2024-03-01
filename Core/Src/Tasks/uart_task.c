/*
 * uart_task.c
 *
 *  Created on: Mar 1, 2024
 *      Author: lemin
 */
#include "main.h"
#include "Utilities/fletcher.h"

#define UART_FRAME_LENGTH 256
extern UART_HandleTypeDef huart2;
uint8_t uart_tx_buffer[UART_FRAME_LENGTH] = {0};

void StartUartTask(void *argument)
{
	// Header
	uart_tx_buffer[0] = 'U';
	uart_tx_buffer[1] = 'A';
	uart_tx_buffer[2] = 'R';
	uart_tx_buffer[3] = 'T';

	// Data length
	uart_tx_buffer[4] = 10;

	// Data
	for (int i = 5; i < UART_FRAME_LENGTH; ++i)
	{
		uart_tx_buffer[i] = 'M';
	}

	// Checksum
	for(;;)
	{
		osDelay(1000);

		uint8_t checklength = UART_FRAME_LENGTH - 2;
		CalculFletcher16(uart_tx_buffer, checklength,&uart_tx_buffer[UART_FRAME_LENGTH-2],&uart_tx_buffer[UART_FRAME_LENGTH-1]);
		HAL_UART_Transmit_DMA(&huart2, uart_tx_buffer, UART_FRAME_LENGTH);

//		uint8_t tx_buff[]={'0','1','2','3','4','5','6','7','8','9'};
//		HAL_UART_Transmit_DMA(&huart2, tx_buff, 10);
	}

}
