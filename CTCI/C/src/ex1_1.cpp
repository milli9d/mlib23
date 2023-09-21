/**
 * @brief
 *
 * 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 *
 *
 */
// BUDT

#include <iostream>
#include <string>
#include <unordered_set>

#include "logging.h"
LOG_TAG(EX1_1);

namespace ctci {

class is_unique {
  public:
    /**
     * @brief Evaluate if all chars in string are unique
     * @param in
     * @return
     */
    static const std::string eval(const std::string& in) {
        /* sanity check */
        if (in.empty()) {
            LOG_ERR("String in empty.");
            return "ERR";
        }

        /* populate a map with entries , if found, then not unique */
        bool res = true;
        std::unordered_set<char> map{};
        for (const char ch: in) {
            if (map.find(ch) != map.end()) {
                res = false;
                break;
            } else {
                map.insert(ch);
            }
        }

        LOG_INFO("String in = %s , result = %s", in.c_str(), (res ? "True" : "False"));
        return res ? "True" : "False";
    }
};

} // namespace ctci

int main(int argc, char** argv) {
    /* test cases */

    /* empty string */
    ctci::is_unique::eval("");

    /* nominal case */
    ctci::is_unique::eval("Hi, World!");
    ctci::is_unique::eval("Hello, World!");

    /* long string with match at begin */
    ctci::is_unique::eval("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    /* all unique */
    std::string in{};
    for (int i = 0; i < UINT8_MAX; i++) { in.push_back(i); }
    ctci::is_unique::eval(in);

    /* all unique + 'a' */
    in.push_back('a');
    ctci::is_unique::eval(in);

    return 0;
}