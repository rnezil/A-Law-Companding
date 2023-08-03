#include <stdio.h>
#include <stdint.h>

#include <valgrind/callgrind.h>

#include "alaw.h"

#define TEST_LEN 4
int16_t test_data [TEST_LEN] = { 0xFFED, 0x0003, 0x0CDE, 0xFF01 };
int main(void) 
{
	printf("Starting test\n");
	int8_t result[TEST_LEN];

	CALLGRIND_START_INSTRUMENTATION;
  	CALLGRIND_TOGGLE_COLLECT;

	// For every piece of test data
	for(int i = 0; i < TEST_LEN; i++)
		result[i] = a_law_convert(test_data[i]);

  	CALLGRIND_TOGGLE_COLLECT;
  	CALLGRIND_STOP_INSTRUMENTATION;
	printf("Test complete\n");
	for(int i = 0; i < TEST_LEN; i++)
	{
		printf("Input [%d]: %X\n", i, test_data[i]);
		printf("Test [%d]: %X\n", i, result[i]);
	}
}