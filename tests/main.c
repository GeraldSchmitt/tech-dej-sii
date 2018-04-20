
#include "ctest.h"

int main(void)
{
	size_t failed_test_count = 0;
	CTEST_RUN_TEST_SUITE(SimpleTestSuiteOneTest);
	return failed_test_count;
}