#define BOOST_TEST_MODULE base_library_test
#include <boost/test/included/unit_test.hpp>

#include "log_test.hpp"

BOOST_AUTO_TEST_CASE(log_test)
{
  BOOST_CHECK(log_test_1());
}
