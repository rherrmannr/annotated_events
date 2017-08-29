#include "Arduino.h"
#include "src-gen/Example.h"
#include "src-gen/ExampleInterruptHandler.h"
#include "avr/sleep.h"
#include "avr/interrupt.h"

Example sc;

void setup()
{
	example_init(&sc);
	example_enter(&sc);
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
}

void loop()
{
	example_InterruptHandler(&sc);
	example_runCycle(&sc);
	interrupts();
	sleep_cpu();
	noInterrupts();
}
