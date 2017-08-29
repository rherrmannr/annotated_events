#include "Arduino.h"
#include "ManualExample.h"
#include "src-gen/ManualExampleInterruptHandler.h"
#include "avr/sleep.h"

ManualExample sc;

void setup()
{
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
	manualExample_init(&sc);
	manualExample_enter(&sc);
	manualExample_runCycle(&sc);
}

void loop()
{
	manualExample_InterruptHandler(&sc);
	manualExample_runCycle(&sc);
	interrupts();
	sleep_cpu();
	noInterrupts();
}
