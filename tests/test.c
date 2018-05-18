#include "umock_c.h"

#define ENABLE_MOCKS
#include "azure_c_shared_utility/httpapi.h"
#undef ENALBE_MOCKS

#include "ctest.h"
#include "conquerWorld.h"

CTEST_BEGIN_TEST_SUITE(SimpleTestSuiteOneTest)

CTEST_SUITE_INITIALIZE()
{
	umock_c_init(NULL);
	REGISTER_UMOCK_ALIAS_TYPE(HTTPAPI_RESULT, int);
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
	STRICT_EXPECTED_CALL(HTTPAPI_Deinit());

	// act
	int ret = frobnicate();

	// assert
	CTEST_ASSERT_ARE_EQUAL(char_ptr, umock_c_get_actual_calls(), umock_c_get_expected_calls());
}

CTEST_END_TEST_SUITE(SimpleTestSuiteOneTest)
