#include<stdlib.h>
#include "world_clock.h"
#include<time.h>

time_struct add_subtract_utc_offset(time_struct* get_offset)
{
time_struct return_time={0,0,0};
get_offset->epoch_seconds+=get_offset->hours*60*60+get_offset->minutes*60;
struct tm *ptm = gmtime ((time_t *)&(get_offset->epoch_seconds));   
return_time.hours= ptm->tm_hour;
return_time.minutes= ptm->tm_min;
return_time.epoch_seconds=get_offset->epoch_seconds;
return return_time;
}