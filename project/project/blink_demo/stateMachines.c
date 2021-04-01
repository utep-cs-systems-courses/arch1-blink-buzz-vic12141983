#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"



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
   
  default: state  = 0;

  }
  
  led_changed = 1;
  led_update();
}

 
void buzzer_state_advance(){
   if(switch_1){
     play_sound();
   }
   if(switch_2){
     play_sound_1();
   }else{
     buzzer_set_period(0);
   }
 }
 void play_sound(){
   static char buzz_state = 0;
   switch(buzz_state){
   case 0: buzzer_set_period(3500); buzz_state++; break;
   case 1: buzzer_set_period(4322); buzz_state++; break;
   case 2: buzzer_set_period(1945); buzz_state++; break;
   case 3: buzzer_set_period(2351); buzz_state++; break;
   case 4: buzzer_set_period(2152); buzz_state = 0; break;
   default: buzz_state = 0;
   }
     
 }
 void play_sound_1(){
   static char buzz_state = 0;
   switch(buzz_state){
   case 0: buzzer_set_period(3830); buzz_state++; break;
   case 1: buzzer_set_period(3400); buzz_state++; break;
   case 2: buzzer_set_period(3038); buzz_state++; break;
   case 3: buzzer_set_period(2864); buzz_state++; break;
   case 4: buzzer_set_period(2550); buzz_state++; break;
   case 5: buzzer_set_period(2272); buzz_state++; break;
   case 6: buzzer_set_period(2028); buzz_state++; break;  
   case 7: buzzer_set_period(1912); buzz_state = 0; break;
   default: buzz_state = 0;
   }

 }
 void play_sound_2(){
   static char buzz_state = 0;
   switch(buzz_state){
   case 0: buzzer_set_period(3322); buzz_state++; break;
   case 1: buzzer_set_period(1322); buzz_state++; break;
   case 2: buzzer_set_period(3322); buzz_state++; break;
   }
 }
 

