#include "timer.h"

static int time_in_seconds;
static int initial_time;
static int paused_time;

//starts the timer
void Timer_start(int input_time){
	time_in_seconds = input_time*60;
	initial_time = time(NULL);
}

//gets time left for timer in format min:seconds (eg. "5:36" for 5 min 36 sec left)
int Timer_get(){
	return time_in_seconds - difftime(time(NULL), initial_time);
}

//pauses timer if not paused, unpauses timer if paused.
void Timer_flip_pause(){
	return;
}

//making sure time is over
bool Timer_isOver(){
	return Timer_get() <= 0;
}