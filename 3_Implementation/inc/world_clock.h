/**
 * @file world_clock.h
 * @author Shubham Santosh 
 * @brief Program to calculate time of major cities/states
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __WORLD_CLOCK_H__
#define __WORLD_CLOCK_H__

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1   // return condition for display functions
#define MAX_VALUE 22   // number of cities/states in the program
#define MAX_CHAR_VALUE 20  //max number of characters in city/state 


/**
 * creating a basic time structure having hours and minutes and the epoch time in seconds.
 * @param hour
 * @param minutes
 * @param epoch_seconds
 */
typedef struct time_struct
{
    int hours;
    int minutes;
    unsigned long epoch_seconds;
}time_struct;

/**
 * @brief Displays the serial no and name of the city/state 
 * 
 * @param b pointer pointing to char utc_offset
 * @param m number of cities/states
 * @param n max size of each character elements
 */
int display(const char (*b)[MAX_CHAR_VALUE],int m,int n);

/**
 * @brief creating a structure function that calculates utc_offset time of the given city/state
 * @param get_offset contains the utc offset in hours and minutes and utc epoch time in seconds
 * 
 * @return times 
 */
time_struct add_subtract_utc_offset(time_struct* get_offset);

/**
 * @brief Display the time, day and date of the given city/state depending on the format
 * @param time_to_display contains the local time and epoch time(in seconds) of the city/state 
 * @param format_type if '1' then selects 12hr format and if '0' then selects 24hr format
 * @param serial_no serial number of the city/state to be displayed
 * @param b char pointer pointing to cities_states
 * 
 */
int display_time_format(time_struct* time_to_display,int format_type,int serial_no,const char (*b)[MAX_CHAR_VALUE]);


#endif  /* #define __WORLD_CLOCK_H__ */