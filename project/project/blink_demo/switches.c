#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down,period, switch_state_changed; /* effectively boolean */
short noise;
static char 
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void switch_init()			/* setup switch */
{  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  char switch_1 = (p1val & SW1) ? 0 : SW1;

  char switch_2 = (p1val & SW2) ? 0 : SW2;

  char switch_3 = (p1val & SW3) ? 0 : SW3;

  char switch_4 = (p1val & SW4) ? 0 : SW4;

  if(switch_1){

    state_of_led = 0;

    noise = 1000;

    period = 10;

    buzzer_play_sound();

    led_changed = 1;

    led_advance();

    led_update();

    switch_state_down = 1;

  }



  if(switch_2){

    state_of_led = 0;

    noise = 2000;

    period = 20;

    buzzer_play_sound();

    led_changed = 1;

    led_advance();

    led_update();

    switch_state_down = 1;

  }



  if(switch_3){

    state_of_led = 0;

    noise = 3000;

    period = 30;

    buzzer_play_sound();

    led_changed = 1;

    led_advance();

    led_update();

    switch_state_down = 1;

  }



  if(switch_4){

    state_of_led = 0;

    noise = 4000;

    period = 40;

    buzzer_play_sound();

    led_changed = 1;

    led_advance();

    led_update();

    switch_state_down = 1;

  }


}
