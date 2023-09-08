
/*Transmitter*/
#define F_CPU 8000000UL

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_Int.h"
#include "../HAL/LM35/LM35_Init.h"

#include "../MCAL/DIO/DIO_Init.h"
#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/SPI/SPI_Init.h"

#include <util/delay.h>

u8 G_Temp=18;

int main(void)
{
	u8 L_u8_D[8] = {7, 5, 7, 0, 0, 0, 0};

	HLCD_VoidInit();
	HLM35_VoidLM35Init();

	MADC_VoidADCInit();
	MSPI_VoidInit();

	HLCD_VoidSaveCustomChar(0, L_u8_D);

	HLCD_VoidSendString("Temperature=");

	while(1)
	{
		G_Temp = HLM35_u16LM35Read();

		MSPI_voidTransmit(G_Temp);

		HLCD_VoidCursor(12,LINE0);
		if (G_Temp<10) {HLCD_VoidSendData(' ');}
		HLCD_VoidSendNumber(G_Temp);

		HLCD_VoidDisplayCustomChar(0);
		HLCD_VoidSendData('c');
		_delay_ms(100);
	}
}

