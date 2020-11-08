#include "timer.h"
#include <time.h>
#include <string.h>
//starts timer


//gets time left for timer in format min:seconds (eg. "5:36" for 5 min 36 sec left)
char* Timer_get(int time, clock_t time_consumed){
	int time_get,len,j;
	char minutes, seconds;
	time_get=time*60 - time_consumed;
	minutes=(char)time_get/60;
	seconds=(char)time_get%60;
	len = strlen(minutes)+strlen(seconds);
	
	j=0; //a counter for len for seconds
	char* display[len]={};
	
	for(int i=0;i<=strlen;i++){
		if(i<strlen(minutes)){
			display[i]=minutes[i];
		}
		else if(i==strlen(minutes)){
			display[i]=":"
		}
		else if(i<len){
			display[i]=seconds[j];
			j++;
		}
	}

	return display;
}

//pauses timer if not paused, unpauses timer if paused.
void Timer_flip_pause(){
	return;
}

//making sure time is over
bool Timer_isOver(int time, clock_t time_consumed){
	if(time==time_consumed){
		return true;
	}
	else{
		return false;
	}
}