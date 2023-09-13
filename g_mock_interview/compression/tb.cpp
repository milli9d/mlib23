/**
 * @brief
 *
 * In this exercise, you're going to decompress a compressed string.
 * Your input is a compressed string of the format number[string] and the decompressed output form should be the string
 * written number times.
 *
 * For example: The input
 *      3[abc]4[ab]c
 *
 * Would be output as
 *      abcabcabcababababc
 *
 * Other rules
 *
 *  1. Number can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa
 *  2. One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab
 *  3. Characters allowed as input include digits, small English letters and brackets [ ].
 *  4. Digits are only to represent amount of repetitions.
 *  5. Letters are just letters.
 *  6. Brackets are only part of syntax of writing repeated substring.
 *  7. Input is always valid, so no need to check its validity.
 *
 * Learning objectives
 *
 *  This question gives you the chance to practice with strings, recursion, algorithm, compilers, automata, and loops.
 *  It’s also an opportunity to work on coding with better efficiency.
 */
#include <iostream>
#include <cstdint>
#include <cstring>

#include "decompress.hpp"

/**
 * @brief
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv)
{
    {
        std::string in = "[1a]";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    {
        std::string in = "[1a[2b]]";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    {
        std::string in = "3a";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    {
        std::string in = "3abc";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    {
        std::string in = "3abc4xyz";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    {
        std::string in = "3abc4xyz5u";
        g_app::decompress sol = g_app::decompress(in.c_str(), in.length());
    }

    return 0;
}