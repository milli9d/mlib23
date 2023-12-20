/**
 * @brief
 *
 * 1.2 Check Permutation: Given two strings, write a method to
 * decide if one is a permutation of the other
 *
 */
// BUDT

#include <iostream>
#include <string>
#include <unordered_set>
#include <assert.h>

#include "logging.h"
LOG_TAG(EX1_2);

namespace ctci {

class is_permutation {
  public:
    /**
     * @brief Evaluate if one string is permutation of another
     * @param in
     * @return
     */
    static const bool eval(const std::string& in1, const std::string& in2)
    {
        int32_t _memo[26u]{};
        int32_t _count = 0;

        if (in1.size() != in2.size()) {
            return false;
        }

        /* fill memo */
        for (char ch: in1) {
            _memo[tolower(ch)]++;
            _count++;
        }

        /* empty memo */
        for (char ch: in2) {
            _memo[tolower(ch)]--;
            _count--;
            if (_memo[tolower(ch)] < 0) {
                return false;
            }
        }
        return true;
    }
};

} // namespace ctci

int main(int argc, char** argv)
{
    /* test cases */

    /* empty string */
    bool ret = false;
    ret = ctci::is_permutation::eval("", "");
    assert(ret == true);

    /* nominal case */
    ret = ctci::is_permutation::eval("tacocat", "catocat");
    assert(ret == true);
    ret = ctci::is_permutation::eval("Hello, World!", "feege");
    assert(ret == false);

    return 0;
}