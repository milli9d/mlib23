/**
 * @brief Palindrome Permutation
 *
 * Given a string, write a function to check if it is a permutation of a palin­drome. A
 * palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 *
 * EXAMPLE
 *
 * Input:
 * Tact Coa
 *
 * Output:
 * True
 *
 * (permutations: "taco cat", "atco eta", etc.) Hints: #106, #121, #134, #136
 *
 */
// BUDT

#include <iostream>
#include <string>
#include <unordered_set>

#include "logging.h"
LOG_TAG(EX1_4);

namespace ctci {

class is_palindrome {
  public:
    /**
     * @brief Evaluate if all chars in string are unique
     * @param in
     * @return
     */
    static const bool eval(const std::string& in)
    {
        for (int i = 0; i < in.size(); i++) {}
    }
};

} // namespace ctci

int main(int argc, char** argv)
{
    /* test cases */

    /* empty string */
    ctci::something::eval("");

    /* nominal case */
    ctci::something::eval("Hi, World!");
    ctci::something::eval("Hello, World!");
    return 0;
}