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

#include "logging.h"
LOG_TAG(EX1_2);

namespace ctci {

class something {
  public:
    /**
     * @brief Evaluate if all chars in string are unique
     * @param in
     * @return
     */
    static const std::string your_ques(const std::string& in) {
        bool res = true;

        return res ? "True" : "False";
    }
};

} // namespace ctci

int main(int argc, char** argv) {
    /* test cases */

    /* empty string */
    ctci::something::eval("");

    /* nominal case */
    ctci::something::eval("Hi, World!");
    ctci::something::eval("Hello, World!");
    return 0;
}