#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
int main() {
    configureClocks();
    led_init();
    buzzer_init();
    buzzer_set_period(0);	/* start buzzing!!! */

    or_sr(0x18);          // CPU off, GIE on
}
