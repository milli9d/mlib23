/**
 * @brief URLify: Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters,and that you are
 * given the "true" length of the string.
 *
 * (Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
 *
 * EXAMPLE",
 *      Input:"Mr John Smith
 *      Output:"Mr%20John%20Smith"
 */
// BUDT

#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

#include "logging.h"
LOG_TAG(EX1_3);

namespace ctci {

class URLify {
  public:
    /**
     * @brief Evaluate if all chars in string are unique
     * @param in
     * @return
     */
    static const std::string eval(const std::string& in)
    {
        std::ostringstream os{};

        for(char ch : in) {
            if(ch == ' ') {
                os << "%20";
            } else {
                os << ch;
            }
        }

        return os.str();
    }
};

} // namespace ctci

int main(int argc, char** argv)
{
    /* test cases */
    LOG_INFO("Ex1_3 tests");

    /* empty string */
    LOG_INFO("%s", ctci::URLify::eval("").c_str());

    /* nominal case */
    LOG_INFO("%s", ctci::URLify::eval("Hi, World!").c_str());
    LOG_INFO("%s", ctci::URLify::eval("Hello, World!").c_str());

    return 0;
}