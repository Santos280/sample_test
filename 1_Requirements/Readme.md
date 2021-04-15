# Requirements
## Introduction
A world clock is a utility tool that provides the time and date of several major cities/states across the world. The program can provide local time of 20+ major cities and states. The list can be elaborated even more.

## Research
#UTC time(Coordinated Universal Time)
UTC Time is a primary time standard which is used to regulate time of other countries.
UTC is the basis for civil time today. This 24-hour time standard is kept using highly precise atomic clocks combined with the Earth's rotation.

#UTC offset time
UTC offset is the time difference in hours and minutes from the UTC time of a particular place. It can be "+-[hours]:[+-minutes]". 
Eg: the UTC offset time in India is +5 Hours and +30 minutes. If the UTC time is 1:00pm, then the time in India will be 1+5:00+30 = 6:30pm.

The image given below describes the difference in UTC offset of different time zones. Image source-[24Timezones](https://24timezones.com/gmt-vs-utc#gref)
![time_zones](https://github.com/Santos280/Step-In-Mini-Project/blob/master/1_Requirements/UTC%20offset.jpg)



## Cost and Features
| Time Complexity | Features |
|-----------------|----------|
|  O(n)      | display time,date and day of given city/state |

## Defining Our System
The following tasks is done be the system:
1. Ask user for the time format(12 hour or 24 hour).
2. Provide the predefined list of cities/states whose local time the user would like to see.
3. Provide the time in the specified format.
4. Provide the date and day from the epoch time of the city/state.

![System Design](https://github.com/Santos280/Step-In-Mini-Project/blob/master/1_Requirements/System%20Diagram.png)

   
## SWOT ANALYSIS
![SWOT_Image](https://github.com/Santos280/Step-In-Mini-Project/blob/master/1_Requirements/SWOT%20analysis%20(1).png)

# 4W&#39;s and 1&#39;H

## Who:
* People who want to monitor time of different geographic areas.

## What:
* A program to provide time of a geographical location based on user input.

## When:
* From the adoption of UTC in 1970 and its implementaton from 1972. 

## Where:
* Across the whole world.

## How:
* Using a menu driven program that will ask the user input to display time.

# Detail requirements

## High Level Requirements:

| ID | Description                    | Status (Implemented/Future)|
|----|--------------------------------|----------------------------|
|HR-1| User provides time format      | Implimented                |
|HR-2| User gets list of cities/states| Implimented                |
|HR-3| obtaining time of given city/state| Implimented           |
|HR-4| The program must throw errors if any uncertainities | Implimented|
|HR-5| User can update list of cities/states | Future|


##  Low level Requirements:

|ID  | Description | HLR-ID | Status (Implemented/Future)|
|----|-------------|--------|----------------------------|
|LR-1| User provides key for 12 or 24 hour format | HR-1 | Implimented |
|LR-2| Throw an error if a wrong key is pressed | HR-1 | Implimented |
|LR-3| User must select the serial number of the city/state displayed| HR-2 | Implemented |
|LR-4| Throw an error if the input is not matching the limits | HR-2 | Implemented |
|LR-5| User gets time in 12/24 hr format along with day and date| HR-3 | Implimented |
|LR-6| If program is unable to obtain the time, then display the error| HR-4 | Implimented |
|LR-7| User can delete,append,modify the list of cities/states | HR-5 | Future | 
