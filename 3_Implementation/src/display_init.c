#include "world_clock.h"
#include<stdio.h>


/**
 * @brief Displays the serial no and name of the city/state 
 * 
 * @param b pointer pointing to char utc_offset
 * @param m number of cities/states
 * @param n max size of each character elements
 */
int display(const char (*b)[MAX_CHAR_VALUE],int m,int n)
{
    printf("Here is the list of cities/states\n\n");
    printf("Sr.no    City/state\n");
	for(int i=0;i<m;i++)
    {
    printf("%d         ",i);
	printf("%s  \n",b[i]);
    }
    return SUCCESS;
}