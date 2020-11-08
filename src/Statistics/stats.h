#ifndef _STATS_H_
#define _STATS_H_

/*Represents statistics module*/

void Stats_add_new_session_length_in_minutes(long length);

long Stats_get_total();
long Stats_get_mean();
long Stats_get_recent();

#endif