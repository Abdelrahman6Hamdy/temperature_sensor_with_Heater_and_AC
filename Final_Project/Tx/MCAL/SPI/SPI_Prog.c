/*
 * SPI_Prog.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Abdelrahman
 */

#include "SPI_Priv.h"
#include "SPI_Init.h"


void MSPI_VoidInit()
{
#if SPI_Mode == SPI_Master
	/* Set MOSI and SCK output, all others input */

		MDIO_voidSetPinDirection(PORTB,PIN4,OUTPUT);
		MDIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);
		MDIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
		MDIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);


	/* Enable SPI, Master, set clock rate fck/16 */
		SPCR = SPCR_Master;
		MDIO_voidSetPinValue(PORTB,PIN4,HIGH);

#elif SPI_Mode == SPI_Slave

		MDIO_voidSetPinDirection(PORTB,PIN4,INPUT);
		MDIO_voidSetPinDirection(PORTB,PIN5,INPUT);
		MDIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
		MDIO_voidSetPinDirection(PORTB,PIN7,INPUT);
		SPCR = SPCR_Slave;

#else
#error "Wrong mode"
#endif
}

void	MSPI_voidTransmit(u8 A_u8_Data)
{
	MDIO_voidSetPinValue(PORTB,PIN4,LOW);
	/* Start transmission */
	SPDR = A_u8_Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR , SPIF)==0);
}

u8	MSPI_u8Receive()
{
	/* Wait for reception complete */
	while(GET_BIT(SPSR , SPIF)==0);

	/* Return data register */
	return SPDR;
}
