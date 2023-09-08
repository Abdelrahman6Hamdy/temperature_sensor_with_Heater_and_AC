/*
 * SPI_Priv.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_

#define SPI_Master		1
#define SPI_Slave		2

#define SPI_Mode		SPI_Master

#define SPIF 7
#define SPCR_Master		0b01010001
#define SPCR_Slave		0b01000000


#define SPCR	*((volatile u8*) 0x2D )
#define SPSR	*((volatile u8*) 0x2E )
#define SPDR	*((volatile u8*) 0x2F )

#endif /* MCAL_SPI_SPI_PRIV_H_ */
