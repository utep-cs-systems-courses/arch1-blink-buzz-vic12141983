#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
void state_advance(){
  // both ligths off
  // red
  // green
  // both
  char changed = 0;
  static char state = 0;

  switch(state){
  case 0: red_on = 0; green_on = 0; state++; break;
  case 1: red_on = 1; green_on = 0; state++; break; 
  case 2: red_on = 1; green_on = 0; state++; break;
  case 3: red_on = 1; green_on = 0; state++; break;
  case 4: red_on = 0; green_on = 0; state++; break;  
  case 5: red_on = 0; green_on = 1; state++; break;
  case 6: red_on = 0; green_on = 1; state++; break;
  case 7: red_on = 0; green_on = 1; state++; break;
  case 8: red_on = 0; green_on = 0; state++; break;
  case 9: red_on = 0; green_on = 1; state++; break;
  case 10: red_on = 0; green_on = 1; state++; break;
  case 11: red_on = 0; green_on = 1; state++; break;
  case 12: red_on = 0; green_on = 0; state++; break;
  case 13: red_on = 0; green_on = 1; state++; break;
  case 14: red_on = 0; green_on = 1; state++; break;
  case 15: red_on = 0; green_on = 1; state++; break;
  case 16: red_on = 0; green_on = 0; state++; break;
  case 17: red_on = 1; green_on = 0; state++; break;
  case 18: red_on = 1; green_on = 0; state++; break;
  case 19: red_on = 1; green_on = 0; state++; break;
  case 20: red_on = 0; green_on = 0; state++; break;  
   
  default: state  = 0;

  }
  
  led_changed = 1;
  led_update();
}


void state_buzz(){
  static char buzz_state = 0;
  switch(buzz_state){
  case 0: buzzer_set_period(3822); buzz_state++;break;
  case 1: buzzer_set_period(3222); buzz_state++;break;
  case 2: buzzer_set_period(3822); buzz_state++;break;
  case 3: buzzer_set_period(3214); buzz_state++;break;
  case 4: buzzer_set_period(3212); buzz_state++;break;
  case 5: buzzer_set_period(3214); buzz_state++;break; 
  case 6: buzzer_set_period(2551); buzz_state++;break;
  case 7: buzzer_set_period(3822); buzz_state++;break;
  case 8: buzzer_set_period(3214); buzz_state++;break;
  case 9: buzzer_set_period(3555); buzz_state = 0; break;  
  default: buzz_state = 0;

  }
}
