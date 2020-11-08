#ifndef _TIMER_H_
#define _TIMER_H_

/*Represents a timer to be used in main*/

<<<<<<< HEAD
//starts timer, in minutes

=======
#include <stddef.h>

//starts timer
void Timer_start(int time);
>>>>>>> a1a271fadaec4729fbaf96d807d879f766a81580

//gets time left for timer in format min:seconds (eg. "5:36" for 5 min 36 sec left)
char* Timer_get();

//pauses timer if not paused, unpauses timer if paused.
void Timer_flip_pause();
//making sure time is over
bool Timer_isOver(); 


#endif
