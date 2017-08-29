/* 
 * Platform interrupt support
 * Manufactor:		Atmel
 * Derivate:		NONE
 * Family:			NONE
 * Name:			ATMmega
 * Architecture:	NONE
*/

#include "ExampleInterruptHandler.h"

InterruptMem im;

void example_InterruptHandler(Example* handle){
	switch (im.vector_flag){
		case ADC_vect_num: {
			exampleIface_raise_adc(handle);
			im.vector_flag = 0; 
			break;
		}
		
		case INT0_vect_num: {
			exampleIface_raise_button1(handle);
			im.vector_flag = 0; 
			break;
		}
		
		case INT1_vect_num: {
			exampleIface_raise_button2(handle);
			im.vector_flag = 0; 
			break;
		}
		
		case TIMER1_COMPA_vect_num: {
			exampleIface_raise_timer1(handle);
			im.vector_flag = 0; 
			break;
		}
		
		default: {break;}
	}
}

ISR (ADC_vect){
	im.vector_flag = ADC_vect_num;
	example_ADC_vect_num_ISR(&im);
}
ISR (INT0_vect){
	im.vector_flag = INT0_vect_num;
	example_INT0_vect_num_ISR(&im);
}
ISR (INT1_vect){
	im.vector_flag = INT1_vect_num;
	example_INT1_vect_num_ISR(&im);
}
ISR (TIMER1_COMPA_vect){
	im.vector_flag = TIMER1_COMPA_vect_num;
	example_TIMER1_COMPA_vect_num_ISR(&im);
}
