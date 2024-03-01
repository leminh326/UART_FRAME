/*
 * fletcher.c
 *
 *  Created on: Mar 1, 2024
 *      Author: lemin
 */

#include "main.h"

bool CheckFletcher16(uint8_t *data, uint8_t count,uint8_t check1,uint8_t check2)
{
	uint16_t sum1 = 0;
	uint16_t sum2 = 0;

	for (uint8_t i = 0; i < count; ++i)
	{
		sum1 = (sum1 + data[i]) % 255;
		sum2 = (sum2 + sum1) % 255;
	}

	if ((check1 == sum1)&&(check2 == sum2))
	{
		return true;
	}
	return false;
}

uint16_t CalculFletcher16(uint8_t *data, uint8_t count,uint8_t *check1,uint8_t *check2)
{
	uint16_t sum1 = 0;
	uint16_t sum2 = 0;
	uint16_t checksum = 0;

	for (uint8_t i = 0; i < count; ++i)
	{
		sum1 = (sum1 + data[i]) % 255;
		sum2 = (sum2 + sum1) % 255;
	}

	*check1 = sum2;
	*check2 = sum1;
	checksum = (sum2 << 8) | sum1;

	return checksum;
}
