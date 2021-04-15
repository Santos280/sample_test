#include<stdio.h>
#include "world_clock.h"
#include<time.h>

const char week[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
const char month[12][20]={"January","February","March","April","May","June","July","August","September","October"
,"November","December"};
int display_time_format(time_struct* time_to_display,int format_type,int serial_no,const char (*b)[MAX_CHAR_VALUE])
{   
    printf("\n++++++++++++++++++++++++++++++++++\n");
    if(format_type==1)
    {
     char am_pm[3]={0,'m','\0'};
     if(time_to_display->hours==0)
     {
         time_to_display->hours=12;
         am_pm[0]='a';
     }
     else if(time_to_display->hours>12)
     {
     time_to_display->hours=time_to_display->hours-12;
     am_pm[0]='p';
     }
     else
     am_pm[0]='a';
     printf("Time in %s : %d:%d %s\n",b[serial_no],time_to_display->hours,time_to_display->minutes,am_pm);
    }
    else
    {
        printf("Time in %s : %d:%d\n",b[serial_no],time_to_display->hours,time_to_display->minutes);
    }
    struct tm *ptm = gmtime ((time_t *)&(time_to_display->epoch_seconds));
    int day=ptm->tm_mday;
    int m_no=ptm->tm_mon+1;
    int year=ptm->tm_year+1900;
    printf("Date : %d-%s-%d\n",day,month[m_no-1],year);
    printf("Day : %s\n",week[ptm->tm_wday]);
    printf("++++++++++++++++++++++++++++++++++\n");
    printf("\n");
    return SUCCESS;
}   