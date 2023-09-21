#include <cstdio>
#include <cstdint>

#include <string>
#include <vector>

#include "logging.h"

LOG_TAG(recursion);

namespace recursion {

static std::string reverse(std::string str);
static bool palindrome(std::string str);
static std::string dec_to_bin(uint32_t val);
static uint64_t sum_n_nums(uint32_t n);

/**
 * @brief Recursive algorithm to reverse string
 * @param str
 * @return
 */
static std::string reverse(std::string str) {
    /* base case */
    if (str == "") {
        return str;
    }

    /* atomic work */
    return reverse(str.substr(1u)) + str.at(0u);
}

/**
 * @brief Detect palindrome by recursion
 * @param str
 * @return
 */
static bool palindrome(std::string str) {
    /* base case */
    if (str.length() == 0u) {
        return true;
    }

    /* atomic work */
    /* move past non alpha chars (front) */
    if (!isalpha(str.front())) {
        return palindrome(str.substr(1u, str.length()));
    }

    /* move past non alpha chars (back) */
    if (!isalpha(str.back())) {
        return palindrome(str.substr(0u, str.length() - 1u));
    }

    /* check if current two heads are equal */
    if (std::tolower(str.front()) == std::tolower(str.back())) {
        return palindrome(str.substr(1u, str.length() - 2u));
    }

    return false;
}

/**
 * @brief Convert from decimal to binary
 * @param val
 * @return
 */
static std::string dec_to_bin(uint32_t val) {
    /* base case */
    if (val == 0u || val == 1u) {
        return std::to_string(val);
    }

    /* atomic work */
    uint32_t curr = val % 2;
    return std::string(dec_to_bin(val / 2) + std::to_string(curr));
}

/**
 * @brief
 * @param n
 * @return
 */
static uint64_t sum_n_nums(uint32_t n) {
    /* base case */
    if (n == 0u || n == 1u) {
        return n;
    }

    /* atomic work*/
    return sum_n_nums(n - 1u) + n;
}

/**
 * @brief Binary search for value in data array
 * @param arr
 * @param left
 * @param right
 * @param val
 * @return
 */
static size_t binary_search(std::vector<int>& arr, size_t left, size_t right, int val) {
    /* if we crossed each other , not found */
    if (left > right) {
        /* not found */
        return -1;
    }

    /* find mid point , and then search in partitions */
    size_t mid = (left + right) / 2u;
    if (arr[mid] == val) {
        return mid;
    } else if (arr[mid] < val) {
        return binary_search(arr, mid + 1u, right, val);
    } else {
        return binary_search(arr, left, mid - 1u, val);
    }
}

} // namespace recursion

int main(int argc, char** argv) {
    LOG_INFO("Hello World! %s", recursion::reverse("Hello World").c_str());
    LOG_INFO("Palindrome %d", recursion::palindrome("r@$#%#  ace car"));
    LOG_INFO("Palindrome %d", recursion::palindrome("r  ase car"));

    uint32_t x = 0b1010'1010;
    LOG_INFO("%d == 0b%s", x, recursion::dec_to_bin(x).c_str());

    x = 1000u;
    LOG_INFO("%d == %lld", x, recursion::sum_n_nums(x));

    std::vector<int> in = { 1, 2, 4, 6, 8, 10, 34, 65, 78, 99 };
    LOG_INFO("%d", recursion::binary_search(in, 0, in.size(), 65u));
    LOG_INFO("%d", recursion::binary_search(in, 0, in.size(), 11u));
}