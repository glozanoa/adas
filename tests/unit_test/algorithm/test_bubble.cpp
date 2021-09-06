/*
 * Boost test for bubble algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#include <vector>
#include <algorithm>
#include "adas/algorithm/sort/serial.hpp"
namespace as = adas::algorithm::sort::serial;

#define BOOST_TEST_MODULE
#include <boost/test/unit_test.hpp>

template<class T>
bool same_vector(vector<T> a, vector<T> b)
{
  if(a.size() != b.size())
    return false;

  for(int k=0; k < a.size(); k++)
    {
      if(a[k] != b[k])
        return false;
    }

  return true;
}


BOOST_AUTO_TEST_SUITE ( bubble_tests )

BOOST_AUTO_TEST_CASE( test_vector )
{
  vector<int> numbers = {18, 14, 12, 6, 16, 13, 7, 9, 3, 11};
  vector<int> copy_numbers(numbers.size());
  copy(numbers.begin(), numbers.end(), copy_numbers.begin());

  bool verbose = true;

  //sorting numbers vector using adas library
  as::bubble(numbers.begin(), numbers.end(), verbose);

  //sorting numbers is copy using <algorith> library
  sort(copy_numbers.begin(), copy_numbers.end());

  BOOST_CHECK(same_vector(numbers, copy_numbers));
}

BOOST_AUTO_TEST_SUITE_END()
