#ifndef _TIMER_H_
#define _TIMER_H_

/*Represents a timer to be used in main*/

#include <stddef.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//starts the timer
void Timer_start(int time);

//gets time left for timer
int Timer_get();

//pauses timer if not paused, unpauses timer if paused.
void Timer_flip_pause();

//making sure time is over
bool Timer_isOver(); 


#endif
