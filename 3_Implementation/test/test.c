#include "unity.h"
#include "world_clock.h"
#include<stdlib.h>


//#define PROJECT_NAME    "Calculator"
/* Prototypes for all the test functions */
void test_time_calc(void);
void test_output_init(void);
void test_output_final(void);

const char test_cities_states[7][MAX_CHAR_VALUE]=
/**
 * @brief stores the list of cities/states
 * 
 */
{
"JUNEAU" ,
"LOS ANGELES",
"MEXICO CITY",
"MIAMI",
"SANTIAGO",
"NEW YORK",
"AUCKLAND",
};

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_time_calc);
  RUN_TEST(test_output_init);
  RUN_TEST(test_output_final);
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/**
 * @brief Testing the Local time of individual city/state
 * 
 */
void test_time_calc(void) {
  /**
   * @brief Testing local time of Los Angeles
   * UTC offset is -7 hrs and 0 mins
   * 
   */
  time_struct time_test={-7,0,1618327104};
  time_struct output_test={0,0,0};
  output_test=add_subtract_utc_offset(&time_test);
  TEST_ASSERT_EQUAL(8,output_test.hours);
  TEST_ASSERT_EQUAL(18, output_test.minutes);
  TEST_ASSERT_EQUAL(1618327104-7*60*60,output_test.epoch_seconds);

  /**
   * @brief Testing local time of Mexico
   * UTC offset is -5hrs and 0 mins 
   * the epoch time is a sample epoch time
   * 
   */
   time_struct time_test1={-5,0,1618327806};
   time_struct output_test1={0,0,0};
  output_test1=add_subtract_utc_offset(&time_test1);
  TEST_ASSERT_EQUAL(10,output_test1.hours);
  TEST_ASSERT_EQUAL(30, output_test1.minutes);
  TEST_ASSERT_EQUAL(1618327806-5*60*60,output_test1.epoch_seconds);

  /**
   * @brief Testing loccal time of Auckland
   * UTC offset is +12hr and 0 mins
   * the epoch time is a sample epoch time
   * 
   */
  time_struct time_test2={12,0,1618392140};
  time_struct output_test2={0,0,0};
  output_test2=add_subtract_utc_offset(&time_test2);
  TEST_ASSERT_EQUAL(21,output_test2.hours);
  TEST_ASSERT_EQUAL(22, output_test2.minutes);
  TEST_ASSERT_EQUAL(1618392140+12*60*60,output_test2.epoch_seconds);
}

/**
 * @brief Testing if initial list of cities/states is printed
 * 
 */
void test_output_init(void)
{ 
  TEST_ASSERT_EQUAL(SUCCESS,display(test_cities_states,7,MAX_CHAR_VALUE));
}

/**
 * @brief Testing for output that ptints time,day and date
 * 
 */
void test_output_final(void)
{
  
  time_struct test_time={8,0,1618383902};
  int format=1; // 12 hour
  int serial_no=1; 
  TEST_ASSERT_EQUAL(SUCCESS,display_time_format(&test_time,format,serial_no,test_cities_states));

  format=0; //24 hour 
  time_struct test_time1={8,0,1618383902};
  TEST_ASSERT_EQUAL(SUCCESS,display_time_format(&test_time1,format,serial_no,test_cities_states));
}