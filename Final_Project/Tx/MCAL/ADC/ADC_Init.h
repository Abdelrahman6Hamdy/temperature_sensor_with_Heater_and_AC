/* ADC_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_Conf.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define ADC_CHANNEL_0              0
#define ADC_CHANNEL_1              1
#define ADC_CHANNEL_2              2
#define ADC_CHANNEL_3              3
#define ADC_CHANNEL_4              4
#define ADC_CHANNEL_5              5
#define ADC_CHANNEL_6              6
#define ADC_CHANNEL_7              7

void MADC_VoidADCInit();
u16  MADC_VoidADCRead(u8 A_u8_ADCChannel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
