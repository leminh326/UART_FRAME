/*
 * fletcher.h
 *
 *  Created on: Mar 1, 2024
 *      Author: lemin
 */

#ifndef INC_UTILITIES_FLETCHER_H_
#define INC_UTILITIES_FLETCHER_H_

bool CheckFletcher16(uint8_t *data, uint8_t count,uint8_t check1,uint8_t check2);
uint16_t CalculFletcher16(uint8_t *data, uint8_t count,uint8_t *check1,uint8_t *check2);

#endif /* INC_UTILITIES_FLETCHER_H_ */
