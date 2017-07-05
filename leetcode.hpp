/**
 *  leetcode header file
 */
#ifndef __LEETCODE_HPP__
#define __LEETCODE_HPP__

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <typeinfo>
#include <limits>
#include <algorithm>
#include <complex>
#include <deque>
#include <queue>
#include <cassert>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static int test_count = 0;
static int test_pass = 0;


template <class T>
std::ostream& operator<<(ostream& os, const std::vector<T>& vec)
{
    for (auto &e : vec)
        os << e << ' ';
    return os;
}

#define TRACK std::cerr << __FILE__ << " " << __LINE__ << std::endl;

#define MAKE_STRING(S) #S

inline void verify_impl(bool codition, const char *file, int line, const char *condition_as_string)
{
    if (codition)
    {
        std::cout << "\nTest " << test_count << " passed: " << condition_as_string << std::endl;
        test_pass++;
    }
    else 
    {
        std::cerr << "\n  in " << file << " (" << line << ")"
                  << std::endl << "     " << condition_as_string << std::endl;
    }
    test_count++;
}

#define VERIFY(a) ::verify_impl(a, __FILE__, __LINE__, MAKE_STRING(a))

#define VERIFY_GE(a, b) ::verify_impl(a >= b, __FILE__, __LINE__, MAKE_STRING(a >= b));
#define VERIFY_LE(a, b) ::verify_impl(a <= b, __FILE__, __LINE__, MAKE_STRING(a <= b));

#define VERIFY_IS_EQUAL(a, b) VERIFY(test_is_equal(a, b, true))
#define VERIFY_IS_NOT_EQUAL(a, b) VERIFY(test_is_equal(a, b, false))

template <typename T, typename U>
bool test_is_equal(const T& actual, const U& expected, bool expect_equal = true);

template <typename T, typename U>
bool test_is_equal(const T& actual, const U& expected, bool expect_equal)
{
    if ((actual == expected) == expect_equal)
        return true;
    std::cerr << "\nTest " << test_count << " failed :" << '\n';

    std::cerr << "\n    actual   = " << actual
              << "\n    expected " << (expect_equal ? "= " : "!=") << expected << '\n';
    return false;
}

#define VERIFY_REPORT()                                                                 \
        do {                                                                            \
            std::cout << "=============================" << '\n';                       \
            std::cout << test_count << " test, " << test_pass << " test passed" << '\n';\
            return test_count ? -1 : 0;                                                 \
        }                                                                               \
        while (0)


#endif
