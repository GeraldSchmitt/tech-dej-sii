#include "umock_c.h"
#include "umock_c_negative_tests.h"

#define ENABLE_MOCKS
#include "azure_c_shared_utility/httpapi.h"
#include "myMemory.h"
#undef ENALBE_MOCKS

#include "ctest.h"
#include "conquerWorld.h"

int fakeData = 0;

CTEST_BEGIN_TEST_SUITE(SimpleTestSuiteOneTest)

CTEST_SUITE_INITIALIZE()
{
	umock_c_init(NULL);
	REGISTER_UMOCK_ALIAS_TYPE(HTTPAPI_RESULT, int);

	REGISTER_GLOBAL_MOCK_RETURN(HTTPAPI_Init, HTTPAPI_OK);
	REGISTER_GLOBAL_MOCK_FAIL_RETURN(HTTPAPI_Init, HTTPAPI_ERROR);

	REGISTER_GLOBAL_MOCK_RETURNS(my_malloc, &fakeData, NULL);
}

CTEST_FUNCTION_INITIALIZE()
{
	umock_c_reset_all_calls();
}

CTEST_FUNCTION(TestFrobnicate_SUCCEEDS)
{
	// arrange
	STRICT_EXPECTED_CALL(HTTPAPI_Init()).SetReturn(HTTPAPI_OK);

	// act
	int ret = frobnicate();

	// assert
	CTEST_ASSERT_ARE_EQUAL(int, 43, ret);
}


CTEST_FUNCTION(TestFrobnicate_FAILS_when_httpinit_fails)
{
	// arrange
	STRICT_EXPECTED_CALL(HTTPAPI_Init()).SetReturn(HTTPAPI_ERROR);
	
	// act
	int ret = frobnicate();
	
	// assert
	CTEST_ASSERT_ARE_EQUAL(int, 0, ret);
}

CTEST_FUNCTION(TestFrobnicate_expected_calls)
{
	// arrange
	STRICT_EXPECTED_CALL(HTTPAPI_Init());
	STRICT_EXPECTED_CALL(malloc(8));
	STRICT_EXPECTED_CALL(free(IGNORED_PTR_ARG));
	STRICT_EXPECTED_CALL(HTTPAPI_Deinit());

	// act
	int ret = frobnicate();

	// assert
	CTEST_ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls());
}

CTEST_FUNCTION(TestFrobnicate_negative_test)
{
	// arrange
	umock_c_negative_tests_init();
	STRICT_EXPECTED_CALL(HTTPAPI_Init());
	STRICT_EXPECTED_CALL(my_malloc(8));
	STRICT_EXPECTED_CALL(my_free(IGNORED_PTR_ARG));
	STRICT_EXPECTED_CALL(HTTPAPI_Deinit());

	umock_c_negative_tests_snapshot();

	for (unsigned int i = 0; i < umock_c_negative_tests_call_count(); i++)
	{
		printf("Testing when call %d fails\n", i);
		if (i == 2 || i == 3)
		{
			printf("free or deinit cannot fail\n");
			continue;
		}
		umock_c_negative_tests_reset();
		umock_c_negative_tests_fail_call(i);

		int ret = frobnicate();

		CTEST_ASSERT_ARE_EQUAL(int, 0, ret);
	}

	umock_c_negative_tests_deinit();
}

CTEST_END_TEST_SUITE(SimpleTestSuiteOneTest)
