/*
 * ADC_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "ADC_Init.h"
#include "ADC_Priv.h"

#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)

void MADC_Void_ADCInit(void)
{
#if   ADC_VREF   ==   AVCC
	SET_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_VREF   ==   AREF_PIN
	CLR_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_VREF   ==   _2V5
	SET_BIT(ADMUX_REG,REFS0_BIT);
	SET_BIT(ADMUX_REG,REFS1_BIT);
#endif
	/* TO SELECT RIGHT ADJUST */
	CLR_BIT(ADMUX_REG,ADLAR_BIT);
#if   ADC_PRESCALER_DV   ==   128
	SET_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
#elif ADC_PRESCALER_DV   ==   64
	CLR_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
#endif

	/* TO ENABLE AUTO TRIGGER MODE */
	SET_BIT(ADCSRA_REG,ADATE_BIT);
	/* TO ENABLE ADC CIRCUIT */
	SET_BIT(ADCSRA_REG,ADEN_BIT);
	/* TO START CONVERSION */
	SET_BIT(ADCSRA_REG,ADSC_BIT);
}

u16  MADC_Void_ADCRead(u8 Copy_U8_ADCChannel)
{

	    u16 read_val;

		SET_BIT(ADCSRA_REG,ADSC_BIT);
		while(IS_BIT_CLR(ADCSRA_REG,ADIF_BIT));		//stay in your position till ADIF become 1
		SET_BIT(ADCSRA_REG,ADIF_BIT); 				// clear ADIF
		read_val=(ADCL_REG);
		read_val|=(ADCH_REG<<8);
		return read_val ;
}
