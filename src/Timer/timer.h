#ifndef _TIMER_H_
#define _TIMER_H_

/*Represents a timer to be used in main*/

//starts timer
void Timer_start(int time);

//gets time left for timer in format min:seconds (eg. "5:36" for 5 min 36 sec left)
char* Timer_get();

//pauses timer if not paused, unpauses timer if paused.
void Timer_flip_pause();


#endif