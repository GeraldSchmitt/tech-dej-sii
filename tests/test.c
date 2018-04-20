#include "ctest.h"


CTEST_BEGIN_TEST_SUITE(SimpleTestSuiteOneTest)

CTEST_FUNCTION(Test1)
{
    // arrange

    // act
    int x = 2 * 21;

    // assert
    CTEST_ASSERT_ARE_EQUAL(int, 42, x);
}

CTEST_END_TEST_SUITE(SimpleTestSuiteOneTest)