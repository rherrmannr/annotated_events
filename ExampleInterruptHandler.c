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
