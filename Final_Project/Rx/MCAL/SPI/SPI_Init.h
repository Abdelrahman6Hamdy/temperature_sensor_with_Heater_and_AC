/*
 * SPI_Init.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

#include "../DIO/DIO_Init.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "SPI_Priv.h"

void MSPI_VoidInit();

u8	MSPI_u8Receive();

void	MSPI_voidTransmit(u8 A_u8_Data);


#endif /* MCAL_SPI_SPI_INIT_H_ */
