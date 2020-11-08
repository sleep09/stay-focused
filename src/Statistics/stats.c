#include "stats.h"

static long total_minutes = 0;
static long number_of_sessions = 0;
static long most_recent = 0;

void Stats_add_new_session_length_in_minutes(long length){
	most_recent = length;
	total_minutes += length;
	number_of_sessions++;
}

long Stats_get_total(){
	return total_minutes;
}
long Stats_get_mean(){
	if(number_of_sessions == 0) return 0;
	return total_minutes/number_of_sessions;
}
long Stats_get_recent(){
	return most_recent;
}
