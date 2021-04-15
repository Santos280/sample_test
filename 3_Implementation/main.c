#include<stdlib.h>
#include "world_clock.h"
#include<time.h>
#include<stdio.h>

const char cities_states[MAX_VALUE][MAX_CHAR_VALUE]=
/**
 * @brief stores the list of cities/states
 * 
 */
{
"LOS ANGELES",
"MEXICO CITY",
"MIAMI",
"SANTIAGO",
"NEW YORK",
"RIO",
"LISBON",
"LONDON",
"PARIS",
"MOSCOW",
"DUBAI",
"KARACHI",
"NEW DELHI",
"COLOMBO",
"DHAKA",
"BANGKOK",
"BEIJING",
"HONGKONG",
"SINGAPORE",
"TOKYO",
"SYDNEY",
"AUCKLAND"
};
const int utc_offset[MAX_VALUE][2]=
{
    /**
     * @brief stores the UTC offset of the respective city/state
     * format is {utc offset hour, utc offset minutes}
     * 
     */
    {-7,0},
    {-5,0},
    {-4,0},
    {-4,0},
    {-4,0},
    {-3,0},
    {1,0},
    {1,0},
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {5,30},
    {5,30},
    {5,45},
    {7,0},
    {8,0},
    {8,0},
    {8,0},
    {9,0},
    {10,0},
    {12,0}
};


int main()
{
    int time_format=1; // 12 or 24 hr format
    int serial_no;   // stores serial number of city/state
    int close_condition;   // to break the loop
    time_struct current_time={0,0,0}; //stores time of city/state and the epoch time
    time_struct utc_time={0,0,0};  // stores time utc offset of city/state and utc epoch time
    printf("---------------World Clock--------------------\n");
    printf("Initialising\n");
    time_t now = time(&now);
    time_t seconds;
    seconds=time(NULL);    
    if (now == -1) 
    {
        puts("The time() function failed");
    }
    struct tm *ptm = gmtime(&now);
    if (ptm == NULL) 
    {    
       puts("The gmtime() function failed");
    }
    printf("%ld\n",seconds);
    printf("Enter time format\n");
    printf("'1' for 12hr and '0' for 24 hr format:");
    scanf("%d",&time_format);
    while(1)
    {
        if(time_format>1)
        {
        printf("Value out of range,");
        printf("Enter correct no:");
        scanf("%d",&time_format);
        }
        else
        break;
    }
    while(1)
    {
    display(cities_states,MAX_VALUE,MAX_CHAR_VALUE); //display list of cities/states
    printf("Enter the Sr.no of the city/state whose time you would want to see:");
    scanf("%d",&serial_no);
    while(1)
    {
        /**
         * @brief executes if wrong input is entered
         * 
         */
        if(serial_no>21 || serial_no<0)
        {
        printf("Value out of range,");
        printf("Enter correct no:");
        scanf("%d",&serial_no);
        }
        else
        break;
    }
    utc_time.hours= utc_offset[serial_no][0];  
    utc_time.minutes=utc_offset[serial_no][1];
    utc_time.epoch_seconds=seconds;

    current_time = add_subtract_utc_offset(&utc_time); //calculate UTC time of the city/state
   
   display_time_format(&current_time,time_format,serial_no,cities_states); //display time,day and date
    printf("To close enter '99'\n");
    printf("To continue enter any number except '99':");
    scanf("%d",&close_condition);
    if(close_condition==99)  // break the loop
    break;
    else
    continue;
    }
    return 0;
}