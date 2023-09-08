/*Receiver*/
#define F_CPU 8000000UL

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_Int.h"

#include "../MCAL/DIO/DIO_Init.h"
#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/SPI/SPI_Init.h"


u8 G_ReceivedKey;



int main(void)
{
	u8 L_u8_D[8] = {7, 5, 7, 0, 0, 0, 0};

	HLCD_VoidInit();
	MSPI_VoidInit();

	HLCD_VoidSaveCustomChar(0, L_u8_D);

	HLCD_VoidSendString("Temperature=");
	while(1){

		G_ReceivedKey=MSPI_u8Receive();

	if (G_ReceivedKey<10)
		{
			HLCD_VoidCursor(12,LINE0);
			HLCD_VoidSendData(' ');
			HLCD_VoidSendNumber(G_ReceivedKey);
			HLCD_VoidDisplayCustomChar(0);
			HLCD_VoidSendData('c');
		}
		else if(G_ReceivedKey<100)
		{
			HLCD_VoidCursor(12,LINE0);
			HLCD_VoidSendNumber(G_ReceivedKey);

			HLCD_VoidDisplayCustomChar(0);
			HLCD_VoidSendData('c');
		}

		if(G_ReceivedKey<20)
		{
			MDIO_voidSetPinValue(PORTC,PIN1,HIGH);
			MDIO_voidSetPinValue(PORTC,PIN0,LOW);

			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("   HEATER ON!   ");
		}
		else if (G_ReceivedKey>30)
		{
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("     AC ON!     ");

			MDIO_voidSetPinValue(PORTC,PIN0,HIGH);
			MDIO_voidSetPinValue(PORTC,PIN1,LOW);

		}
		else
		{
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("                ");

			MDIO_voidSetPinValue(PORTC,PIN0,LOW);
			MDIO_voidSetPinValue(PORTC,PIN1,LOW);
		}
}
}

